#include <stdio.h>
#include <string.h>

#include "astree.h"
#include "postorder_dfs.h"
#include "symbol_table.h"
#include "lyutils.h"
//#include "attrs.h"

using namespace std;

extern FILE *sym_file;

attr_bitset types = 0;

void setAttributes (attr_bitset dest, attr_bitset src)
{
  if (src.test(ATTR_array))
    { 
      dest.set(ATTR_array);
    }
  else if (src.test(ATTR_bool))
    { 
      dest.set(ATTR_bool);
    }
  else if (src.test(ATTR_char))
    {
      dest.set(ATTR_char);
    }
  else if (src.test(ATTR_int))
    {
      dest.set(ATTR_int);
    }
  else if (src.test(ATTR_string))
    { 
      dest.set(ATTR_string);
    }
  else if (src.test(ATTR_struct))
    {
      dest.set(ATTR_struct);
    }
}

void dfsTraversalStruct (astree* tree, symbol* struct_symbol,
                         string* struct_name) {

  symbol* temp_field = (symbol*)malloc(sizeof(struct symbol));
  if(struct_symbol->fields == NULL) {
    struct_symbol->fields = new symbol_table;
  }
  temp_field->fields = NULL;
  temp_field->parameters = NULL;
  if (tree->symbol == TOK_ARRAY)
    { 
      tree->attributes.set(ATTR_array);
      tree->children.back()->attributes.set(ATTR_array);

      if (tree->children.at(0)->symbol == TOK_BOOL)
        {
          tree->children.at(0)->attributes.set(ATTR_bool);
          tree->children.back()->attributes.set(ATTR_bool);
        }

      else if (tree->children.at(0)->symbol == TOK_CHAR)
        {
          tree->children.at(0)->attributes.set(ATTR_char);
          tree->children.back()->attributes.set(ATTR_char);
        }

      else if (tree->children.at(0)->symbol == TOK_INT)
        {
          tree->children.at(0)->attributes.set(ATTR_int);
          tree->children.back()->attributes.set(ATTR_int);
        }

      else if (tree->children.at(0)->symbol == TOK_STRING)
        { 
          tree->children.at(0)->attributes.set(ATTR_string);
          tree->children.back()->attributes.set(ATTR_string);
        }

      else if (tree->children.at(0)->symbol == TOK_TYPEID)
        {
          tree->children.at(0)->attributes.set(ATTR_struct);
          tree->children.back()->type = (string *)tree->children.at(0)->lexinfo;
          tree->children.back()->attributes.set(ATTR_struct);
        }
    }

  else if (tree->symbol == TOK_BOOL)
    {
      tree->attributes.set(ATTR_bool);
      tree->children.back()->attributes.set(ATTR_bool);
    }

  else if (tree->symbol == TOK_CHAR)
    {
      tree->attributes.set(ATTR_char);
      tree->children.back()->attributes.set(ATTR_char);
    }

  else if (tree->symbol == TOK_INT)
    {
      tree->attributes.set(ATTR_int);
      tree->children.back()->attributes.set(ATTR_int);
    }

  else if (tree->symbol == TOK_STRING)
    { 
      tree->attributes.set(ATTR_string);
      tree->children.back()->attributes.set(ATTR_string);
    }

  else if (tree->symbol == TOK_TYPEID)
    {
      tree->attributes.set(ATTR_struct);
      tree->children.back()->attributes.set(ATTR_struct);
      tree->children.back()->type = (string *)tree->lexinfo;      
    }

  tree->children.back()->attributes.set(ATTR_field);
  temp_field->attributes = tree->children.back()->attributes;
  temp_field->type_id = tree->children.back()->type;

  temp_field->lloc.blocknr = 0;
  temp_field->lloc.filenr = tree->lloc.filenr;
  temp_field->lloc.linenr = tree->lloc.linenr;
  temp_field->lloc.offset = tree->lloc.offset;
  struct_symbol->fields->insert ({tree->children.back()->lexinfo,
        temp_field});
  fprintf(sym_file, "   %s (%zu.%zu.%zu) "
 ,
          tree->children.back()->lexinfo->c_str(),
          temp_field->lloc.filenr, temp_field->lloc.linenr,
          temp_field->lloc.offset
          );
  print_attrs (sym_file, temp_field->attributes,
               temp_field->type_id, struct_name);
  fprintf(sym_file, "\n");
}

astree *first_typeid;
astree *second_typeid;

string *global_lexinfo = nullptr;
astree *declid;
astree *fun_declid;


bool compatible(attr_bitset first, attr_bitset second,
                string *first_typeid, string *second_typeid)
{
  bool ret = false;
  if ((first & types) == (second & types))
    {
      // they are structs so need to check typeid
      if (first[ATTR_struct] && second[ATTR_struct])
        {
          // same typeid
          if (first_typeid == second_typeid) ret = true;
        }
      else ret = true;
    }

  // ref type and null
  else if (   (first[ATTR_null]   &&   second[ATTR_null])
              || (first[ATTR_string] &&   second[ATTR_null])
              || (first[ATTR_struct] &&   second[ATTR_null])
              || (first[ATTR_array]  &&   second[ATTR_null])
              || (first[ATTR_null]   && second[ATTR_string])
              || (first[ATTR_null]   && second[ATTR_struct])
              || (first[ATTR_null]   &&  second[ATTR_array]))
    {
      ret = true;
    }

  return ret;
  // one is array and one isn't
  //  else if (first[ATTR_array] != second[ATTR_array]) return false;
}

bool any(attr_bitset attributes)
{
  // if its void then it isn't 'any'
  if (attributes[ATTR_void]) return false;

  // if its not void it us 'any'
  return true;
}

bool base(attr_bitset attributes)
{
  // base type cannot be void
  if (attributes[ATTR_void]) return false;

  // base type cannot be an array type
  if (attributes[ATTR_array]) return false;
  
  // not void or array: its a valid base
  return true;
}

bool primitive(attr_bitset attributes)
{
  // cannot be array
  if (attributes[ATTR_array]) return false;

  // is either bool, char or int
  if (attributes[ATTR_bool] || attributes[ATTR_char]
      || attributes[ATTR_int])
    { return true; }

  // wasn't any of the above
  return false;
}

// newstring
// index
// call
// newarray
// field

struct dfs_ret
{
  attr_bitset attributes;
  string *type;
};

dfs_ret *dfs_traversal(astree* tree)
{
  //print
  printf("dfs start\n");
  
  if (tree == NULL)
    {
      printf("Oh bother!\n");
      return 0;
    }
  // Root case
  if (tree->symbol == TOK_ROOT)
    {
      printf("dfs root start\n");  
      symbolStackInit();
      for(auto it = tree->children.begin();
          it < tree->children.end(); it++)
        {
          dfs_traversal(*it);
        }
      printf("dfs root end\n");
  
    }

  // Cases where something needs to be put in a sym table
  else if (tree->symbol == TOK_STRUCT)
    { //HANDLE CASE OF STRUCT PROTOTYPE
      // put it in the struct sym table
      // put children in field sym table
      printf("dfs struct start\n");
      symbol* test_struct = find_typeTable(tree->children.at(0)->lexinfo);
      if (test_struct != NULL && test_struct->fields != NULL)
	{
	  fprintf(stderr, "oc: double declaration of struct %s\n",
                  tree->children.at(0)->lexinfo->c_str());
	} else {
	if(test_struct != NULL){
	  myFunctionToDoThatThing (tree);
	}
	symbol* struct_symbol;
	int blocNum;
	symbolStackPush();
	blocNum = getCurrentBloc();
	symbolStackPop();
	struct_symbol = intern_typeTable (tree);
	if (struct_symbol != NULL) {
	  tree->attributes.set(ATTR_struct);
	  tree->children.at(0)->attributes.set(ATTR_struct);
	  fprintf(sym_file, "%s (%zu.%zu.%zu) {%zu} struct \"%s\"\n",
		  tree->children.at(0)->lexinfo->c_str(),
		  struct_symbol->lloc.filenr, struct_symbol->lloc.linenr,
		  struct_symbol->lloc.offset, struct_symbol->lloc.blocknr,
		  tree->children.at(0)->lexinfo->c_str());
	  for(u_int i = 1; i < tree->children.size(); i++)
	    {
	      tree->children.at(i)->lloc.blocknr = blocNum;
	      tree->children.at(i)->children.back()->lloc.blocknr = blocNum;
	      tree->children.at(i)->children.at(0)->lloc.blocknr = blocNum;
	      dfsTraversalStruct (tree->children.at(i), struct_symbol,
				  (string *)tree->children.at(0)->lexinfo);
	    }
	}
      }
      printf("dfs struct end\n");
    }
  else if (tree->symbol == TOK_PROTOTYPE)
    {
      printf("dfs prototype start\n");
      symbolStackAddPrototype (tree, sym_file);
      printf("dfs prototype end\n");
    }
  else if (tree->symbol == TOK_FUNCTION) 
    {
      printf("dfs function start\n");
      int added = symbolStackAddFunction (tree, sym_file);

      if(added){
      fun_declid = tree->children.at(0)->children.back();
      for(auto it = tree->children.at(2)->children.begin();
          it < tree->children.at(2)->children.end(); it++)
        {
          dfs_traversal(*it);
        } 
      symbolStackPop ();
      }
      printf("dfs function end\n");
    }
  else if (tree->symbol == TOK_VARDECL) 
    {
      printf("dfs vardecl start\n");
      // eval left, get attr and astree node of declid
 
      //printf("dfs vardecl left declaration start\n"); 
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      //printf("dfs vardecl left declaration end\n");

      
      //printf("dfs vardecl global_lexinfo if\n");
      if (global_lexinfo != nullptr)
        {
          declid->type = global_lexinfo;
          global_lexinfo = nullptr;
        }
      
      
      //printf("dfs vardecl location data\n");
      tree->lloc.blocknr = getCurrentBloc();
      declid->attributes = left->attributes;
      declid->attributes.set(ATTR_variable);
      declid->attributes.set(ATTR_lval);
      declid->lloc.blocknr = getCurrentBloc();

      //printf("dfs vardecl symbolStackAddVardecl start\n");
      symbolStackAddVardecl (declid, sym_file);
      //printf("dfs vardecl symbolStackAddVardecl end\n");
      
      //printf("dfs vardecl right declaration start\n");
      dfs_ret *right = dfs_traversal(tree->children.at(1));
      //printf("dfs vardecl left declaration end\n");

      
      //printf("dfs vardecl left compatible check\n");
      if (!compatible(declid->attributes, right->attributes,
                      declid->type, right->type))
        {
          fprintf(stderr, "variable declaration of %s is assigned "
                  "an invalid type\n", declid->lexinfo->c_str());
        }
      printf("dfs vardecl end\n");
    }

  // Cases that do not require putting something in sym table
  else if (tree->symbol == TOK_BLOCK)
    {
      printf("dfs block start\n");
      tree->lloc.blocknr = getCurrentBloc();
      symbolStackPush ();
      // increment block count
      // do every child
      
      for(auto it = tree->children.begin();
          it < tree->children.end(); it++)
        {
          dfs_traversal(*it);
        } 
      symbolStackPop ();
      printf("dfs block end\n");
    }

  else if (tree->symbol == TOK_WHILE)
    {
      printf("dfs while start\n");
      // first child needs to be bool
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      tree->lloc.blocknr = getCurrentBloc();
      if (!left->attributes[ATTR_bool] || left->attributes[ATTR_array])
        {
          fprintf(stderr, "expression in while must be a bool\n");
        }
      dfs_traversal(tree->children.at(1));
      printf("dfs while end\n");
    }

  else if (tree->symbol == TOK_IF || tree->symbol == TOK_IFELSE)
    {
      printf("dfs if/ifelse start\n");
      // first child needs to be bool
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      tree->lloc.blocknr = getCurrentBloc();
      if (!left->attributes[ATTR_bool] || left->attributes[ATTR_array])
        {
          fprintf(stderr, "expression in while must be a bool\n");
        }
      // do 1 or 2 more depending on IF or IFELSE
      dfs_traversal(tree->children.at(1));
      if (tree->children.size() > 2){
	dfs_traversal(tree->children.at(2));
      }
      printf("dfs if/ifelse end\n");
    }

  // find me
  else if (tree->symbol == TOK_RETURN)
    {
      printf("dfs return start\n");
      //CHECK CHILD AGAINST RETURN TYPE
      dfs_ret *child = dfs_traversal(tree->children.at(0));
      tree->lloc.blocknr = getCurrentBloc();
      if(child == NULL)
	{
	  fprintf(stderr, "returned value does not exist\n");
	  return nullptr;
	}
      if(!compatible(fun_declid->attributes, child->attributes,
                     fun_declid->type, child->type))
        {
          fprintf(stderr, "returned value does not match" 
                  "function return type\n");
        }
      printf("dfs return end\n");
    }

  else if (tree->symbol == TOK_RETURNVOID)
    {
      printf("dfs returnvoid start\n");
      //CHECK CHILD AGAINST RETURN TYPE
      tree->lloc.blocknr = getCurrentBloc();
      if (!fun_declid->attributes[ATTR_void])
        {
          fprintf(stderr, "returned value does not match" 
                  "function return type\n");
        }
      printf("dfs returnvoid end\n");
    }


  else if (tree->symbol == '=')
    {
      printf("dfs = start\n");
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      dfs_ret *right = dfs_traversal(tree->children.at(1));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;

      if(left == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate identifier\n");
	  return retval;
	}
      if(right == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate identifier\n");
	  return retval;
	}

      if (any(left->attributes) && left->attributes[ATTR_lval] 
          && any(right->attributes))
        {
          if (compatible(left->attributes, right->attributes,
                         left->type, right->type))
            {
              setAttributes(retval->attributes, left->attributes);
              retval->type = left->type;
              retval->attributes.set(ATTR_vreg);
            }
          else
            {
              fprintf(stderr, "operands of '=' aren't compatible\n");
            }
        }
      else
        {
          fprintf(stderr, "operands of '=' aren't valid\n");
        }
      printf("dfs = end\n");
      return retval;
    }


  else if (tree->symbol == TOK_EQ || tree->symbol == TOK_NE)
    {
      printf("dfs eq start\n");
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      dfs_ret *right = dfs_traversal(tree->children.at(1));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;

      if(left == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}
      if(right == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}

      char *op = NULL;
      if (tree->symbol == TOK_EQ) { op = (char*)"=="; }
      else if (tree->symbol == TOK_NE) { op = (char*)"!="; }

      if (!any(left->attributes))
        { 
          fprintf(stderr, "left operand of %s is not 'any'\n", op);
        }

      if (!any(right->attributes))
        { 
          fprintf(stderr, "right operand of %s is not 'any\n", op);
        }

      // both 'any'
      if (any(left->attributes) && any(right->attributes))
        {
          // compatible
          // NEED TYPEID !!!!!!!!!
          if (compatible(left->attributes, right->attributes, 
                         left->type, right->type))
            {
              tree->attributes.set(ATTR_bool);
              tree->attributes.set(ATTR_vreg);
              retval->attributes.set(ATTR_bool);
              retval->attributes.set(ATTR_vreg);
            }
          // not compatible
          else
            {
              fprintf(stderr, "operands of %s not compatible\n", op);
            }
        }
      printf("dfs eq end\n");
      return retval;
    }

  else if (tree->symbol == TOK_LT || tree->symbol == TOK_LE
           || tree->symbol == TOK_GT || tree->symbol == TOK_GE)
    {
      printf("dfs comparison start\n");
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      dfs_ret *right = dfs_traversal(tree->children.at(1));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;

      if(left == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}
      if(right == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}

      char *op = NULL;
      if (tree->symbol == TOK_LT) { op = (char*)"<"; }
      else if (tree->symbol == TOK_LE) { op = (char*)"<="; }
      else if (tree->symbol == TOK_GT) { op = (char*)">"; }
      else if (tree->symbol == TOK_GE) { op = (char*)">="; }

      if (!primitive(left->attributes))
        { 
          fprintf(stderr, "left operand of %s is not primitive\n", op);
        }

      if (!primitive(right->attributes))
        { 
          fprintf(stderr, "right operand of %s is not primitive\n", op);
        }

      // both primitive
      if (primitive(left->attributes) && primitive(right->attributes))
        {
          // compatible, typeids not needed since both primitive
          if (compatible(left->attributes, right->attributes, 
                         left->type, right->type))
            {
              tree->attributes.set(ATTR_bool);
              tree->attributes.set(ATTR_vreg);
              retval->attributes.set(ATTR_bool);
              retval->attributes.set(ATTR_vreg);
            }
          // primitive but not compatible
          else
            {
              fprintf(stderr, "operands of %s not compatible\n", op);
            }
        }
      else
        {
          fprintf(stderr, "operands of %s are not primitive\n", op);
        }
      printf("dfs comparison end\n");
      return retval;
    }

  else if (tree->symbol == '+' || tree->symbol == '-'
           || tree->symbol == '*' || tree->symbol == '/'
           || tree->symbol == '%')
    {
      printf("dfs operator start\n");
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      dfs_ret *right = dfs_traversal(tree->children.at(1));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();

      if(left == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}
      if(right == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}

      if ((left->attributes[ATTR_int] && right->attributes[ATTR_int])
          && (!left->attributes[ATTR_array] && !right->attributes[ATTR_array]))
        {
          tree->attributes.set(ATTR_int);
          tree->attributes.set(ATTR_vreg);
          retval->attributes.set(ATTR_int);
          retval->attributes.set(ATTR_vreg);
        }
      else
        {
          if (tree->symbol == '+')
            { fprintf(stderr, "invalid type: binary +\n"); }
          else if (tree->symbol == '-')
            { fprintf(stderr, "invalid type: binary -\n"); }
          else if (tree->symbol == '*')
            { fprintf(stderr, "invalid type: *\n"); }
          else if (tree->symbol == '/')
            { fprintf(stderr, "invalid type: /\n"); }
          else if (tree->symbol == '%')
            { fprintf(stderr, "invalid type: %%\n"); }
        }
      printf("dfs operator end\n");
      return retval;
    }

  else if (tree->symbol == TOK_POS || tree->symbol == TOK_NEG)
    {
      printf("dfs pos/neg start\n");
      dfs_ret *child = dfs_traversal(tree->children.at(0));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();

      if (child->attributes[ATTR_int] && !child->attributes[ATTR_array])
        {
          tree->attributes.set(ATTR_int);
          tree->attributes.set(ATTR_vreg);
          retval->attributes.set(ATTR_int);
          retval->attributes.set(ATTR_vreg);
        }
      else
        {
          if (tree->symbol == TOK_POS) 
            { fprintf(stderr, "invalid type: unary +\n"); }
          else if (tree->symbol == TOK_NEG)
            { fprintf(stderr, "invalid type: unary -\n"); }
        }
      printf("dfs pos/neg end\n");
      return retval;
    }

  else if (tree->symbol == '!')
    {
      printf("dfs ! start\n");
      dfs_ret *child = dfs_traversal(tree->children.at(0));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      if(child == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}
      if (child->attributes[ATTR_bool] && !child->attributes[ATTR_array])
        {
          tree->attributes.set(ATTR_bool);
          tree->attributes.set(ATTR_vreg);
          retval->attributes.set(ATTR_bool);
          retval->attributes.set(ATTR_vreg);
        }
      else
        {
          fprintf(stderr, "invalid type: !\n");
        }
      printf("dfs ! end\n");
      return retval;	
    }

  else if (tree->symbol == TOK_ORD)
    {
      printf("dfs ord start\n");
      dfs_ret *child = dfs_traversal(tree->children.at(0));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();

      if(child == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}

      if (child->attributes[ATTR_char] && !child->attributes[ATTR_array])
        {
          tree->attributes.set(ATTR_int);
          tree->attributes.set(ATTR_vreg);
          retval->attributes.set(ATTR_int);
          retval->attributes.set(ATTR_vreg);
        }
      else
        {
          fprintf(stderr, "invalid type: ord\n");
        }
      printf("dfs ord end\n");
      return retval;
    }

  else if (tree->symbol == TOK_CHR)
    {
      printf("dfs chr start\n");
      dfs_ret *child = dfs_traversal(tree->children.at(0));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();

      if(child == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}

      if (child->attributes[ATTR_char] && !child->attributes[ATTR_array])
        {
          tree->attributes.set(ATTR_char);
          tree->attributes.set(ATTR_vreg);
          retval->attributes.set(ATTR_char);
          retval->attributes.set(ATTR_vreg);
        }
      else
        {
          fprintf(stderr, "invalid type: chr\n");
        }
      printf("dfs chr end\n");
      return retval;
    }

  // 'new' cases
  
  // for typeid
  else if (tree->symbol == TOK_NEW)
    {
      printf("dfs new start\n");
      dfs_ret *child = dfs_traversal(tree->children.at(0));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->attributes = 0;

      if(child == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}

      retval->attributes |= (child->attributes & types);
      // setAttributes(retval->attributes, child->attributes);
      retval->attributes.set(ATTR_vreg);
      retval->type = child->type;
      tree->attributes = retval->attributes;
      tree->type = retval->type;

      printf("dfs new end\n");
      return retval;
    }

  // string
  else if (tree->symbol == TOK_NEWSTRING)
    {
      printf("dfs newstring start\n");
      dfs_ret *child = dfs_traversal(tree->children.at(0));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->attributes = 0;

      if(child == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}

      // not an int or its an array
      if (child->attributes[ATTR_int] && !child->attributes[ATTR_array])
        {
          retval->attributes.set(ATTR_string);
          retval->attributes.set(ATTR_vreg);
          tree->attributes = retval->attributes;
        }
      else
        {
          fprintf(stderr, "expression in parenthesis of"
                  "string allocation must evaluate to an int\n");
        }
      printf("dfs newstring end\n");
      return retval;
    }

  //  array
  else if (tree->symbol == TOK_NEWARRAY)
    {
      printf("dfs newarray start\n");
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      printf("dfs newarray left declaration\n");
      dfs_ret *right = dfs_traversal(tree->children.at(1));
      printf("dfs newarray right declaration\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->attributes = 0;

      if(left == NULL)
	{
	  printf("newarray left start\n");
	  fprintf(stderr, "oc: Variable %s not declared\n", tree->children.at(0)->lexinfo->c_str());
	  printf("newarray left end\n"); 
	  return retval;
	}
      if(right == NULL)
	{
	  printf("newarray right start\n");
	  fprintf(stderr, "oc: Variable %s not declared\n", tree->children.at(1)->lexinfo->c_str());
	  printf("newarray right end\n");
	  return retval;
	}

      if (base(left->attributes))
        {
	  printf("newarray left->attributes start\n");
          if (right->attributes[ATTR_int]
              && !right->attributes[ATTR_array])
            {
              retval->attributes |= (left->attributes & types);
              retval->type = left->type;              
              retval->attributes.set(ATTR_array);
              retval->attributes.set(ATTR_vreg);
              tree->attributes = retval->attributes;
              tree->type = retval->type;
            }
          else
            {
              fprintf(stderr, "expression in brackets of"
                      "array allocation must evaluate to an int\n");
            }
	  printf("newarray left->attributes end\n");
        }
      else
        {
          fprintf(stderr, "cannot make an array of array types\n");
        }

      printf("dfs newarray end\n");
      return retval;
    }

  else if (tree->symbol == TOK_INDEX)
    {
      printf("dfs index start\n");
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      dfs_ret *right = dfs_traversal(tree->children.at(1));
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;

      if(left == NULL)
	{
	  fprintf(stderr, "oc: Variable %s not declared\n", tree->children.at(0)->lexinfo->c_str());
	  return retval;
	}
      if(right == NULL)
	{
	  fprintf(stderr, "oc: Variable %s not declared\n", tree->children.at(1)->lexinfo->c_str());
	  return retval;
	}

      // right side is int
      if (right->attributes[ATTR_int] &&
           !right->attributes[ATTR_array])
        {
          if(left->attributes[ATTR_string] &&
                  !left->attributes[ATTR_array])
            {
              retval->attributes.set(ATTR_char);
              retval->attributes.set(ATTR_vaddr);
              retval->attributes.set(ATTR_lval);
              tree->attributes = retval->attributes;
            }
          else if (left->attributes[ATTR_array])
            {
              retval->attributes |= (left->attributes & types);
              retval->attributes.flip(ATTR_array);
              retval->attributes.set(ATTR_vaddr);
              retval->attributes.set(ATTR_lval);
              retval->type = left->type;
              tree->attributes = retval->attributes;
            }
          else
            {
              fprintf(stderr, "left side of index not valid\n");
            }
        }
      else
        {
          fprintf(stderr, "index of an array/string must be an int\n");
        }
      printf("dfs index end\n");
      return retval;
    }

  // ...
  else if (tree->symbol == '.')
    {
      printf("dfs . start\n");
      // ident
      dfs_ret *left = dfs_traversal(tree->children.at(0));
      // field
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      symbol *fieldptr = nullptr;

      if(left == NULL)
	{
	  fprintf(stderr, "oc: Failed to locate symbol\n");
	  return retval;
	}

      if (left->attributes[ATTR_struct] && !left->attributes[ATTR_array])
        {
          
          symbol *selector_struct = grabStructSymbol(left->type);
          if (nullptr != selector_struct)
            {

              auto table_check = 
                selector_struct->fields->find(tree->children.at(1)->lexinfo);
              if (selector_struct->fields->end() == table_check)
                {
                  fprintf(stderr, "didn't find given field in struct\n");
                }
              else
                {
                  // set current node stuff
                  fieldptr = table_check->second;
                  retval->attributes |= (fieldptr->attributes & types);
                  retval->attributes.set(ATTR_vaddr);
                  retval->attributes.set(ATTR_lval);
                  retval->type = fieldptr->type_id;
                  tree->attributes = retval->attributes;
                  tree->type = retval->type;

                  // set field node stuff
                  tree->children.at(1)->attributes =
                    fieldptr->attributes;
                }
            }
          else
            {
              fprintf(stderr, "type does not exist\n");
            }
          
        }
      else
        {
          fprintf(stderr, "left side of field selector must"
                  "be a struct type");
        }
      printf("dfs . end\n");
      return retval;
    }


  else if (tree->symbol == TOK_DECLID)
    {
      printf("dfs declid start\n");
      declid = tree;
      tree->lloc.blocknr = getCurrentBloc();
      printf("dfs declid end\n");
      return NULL;
    }
  
  // array

  else if (tree->symbol == TOK_ARRAY)
    {
      printf("dfs array start\n");
      dfs_ret *retval = dfs_traversal(tree->children.at(0));
      dfs_traversal(tree->children.at(1));
      tree->lloc.blocknr = getCurrentBloc();

      tree->attributes.set(ATTR_array);
      retval->attributes.set(ATTR_array);
      
      printf("dfs array end\n");
      return retval;
    }

  // types

  else if (tree->symbol == TOK_VOID)
    {
      printf("dfs void start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();
      
      retval->attributes.set(ATTR_void);
      tree->attributes.set(ATTR_void);

      if (!tree->children.empty())
        {
          dfs_traversal(tree->children.at(0));
        }

      printf("dfs void end\n");
      return retval;
    }

  else if (tree->symbol == TOK_BOOL)
    {
      printf("dfs bool start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();
      
      retval->attributes.set(ATTR_bool);
      tree->attributes.set(ATTR_bool);
      if (!tree->children.empty())
        {
          dfs_traversal(tree->children.at(0));
        }
      printf("dfs bool end\n");
      return retval;
    }

  else if (tree->symbol == TOK_CHAR)
    {
      printf("dfs char start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();
      
      retval->attributes.set(ATTR_char);
      tree->attributes.set(ATTR_char);
      if (!tree->children.empty())
        {
          dfs_traversal(tree->children.at(0));
        }

      printf("dfs char end\n");
      return retval;
    }

  else if (tree->symbol == TOK_INT)
    {
      printf("dfs int start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();
      
      retval->attributes.set(ATTR_int);
      tree->attributes.set(ATTR_int);
      if (!tree->children.empty())
        {
          dfs_traversal(tree->children.at(0));
        }
      
      printf("dfs int end\n");
      return retval;
    }

  else if (tree->symbol == TOK_STRING)
    {
      printf("dfs string start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;
      tree->lloc.blocknr = getCurrentBloc();
      
      retval->attributes.set(ATTR_string);
      tree->attributes.set(ATTR_string);
      if (!tree->children.empty())
        {
          dfs_traversal(tree->children.at(0));
        }

      printf("dfs string end\n");
      return retval;
    }

  else if (tree->symbol == TOK_TYPEID)
    {
      printf("dfs typeid start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->type = (string *)tree->lexinfo;
      retval->attributes = 0;
      retval->attributes.set(ATTR_struct);
      tree->type = (string *)tree->lexinfo;
      global_lexinfo = tree->type;
      tree->attributes.set(ATTR_struct);
      if (!tree->children.empty())
        {
          dfs_traversal(tree->children.at(0));
        }
      printf("dfs typeid end\n");
      return retval;
    }

  else if (tree->symbol == TOK_CHARCON)
    {
      printf("dfs charcon start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;
      retval->attributes.set(ATTR_const);
      retval->attributes.set(ATTR_char);
      tree->attributes.set(ATTR_const);
      tree->attributes.set(ATTR_char);
      
      printf("dfs charcon end\n");
      return retval;
    }

  else if (tree->symbol == TOK_STRINGCON)
    {
      printf("dfs stringcon start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;
      retval->attributes.set(ATTR_const);
      retval->attributes.set(ATTR_string);
      tree->attributes.set(ATTR_const);
      tree->attributes.set(ATTR_string);

       printf("dfs stringcon end\n");
      return retval;
    }

  else if (tree->symbol == TOK_INTCON)
    {
      printf("dfs intcon start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;
      retval->attributes.set(ATTR_const);
      retval->attributes.set(ATTR_int);
      tree->attributes.set(ATTR_const);
      tree->attributes.set(ATTR_int);

      printf("dfs intcon end\n");
      return retval;
    }

  else if (tree->symbol == TOK_CHARCON)
    {
      printf("dfs charcon\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;
      retval->attributes.set(ATTR_const);
      retval->attributes.set(ATTR_char);
      tree->attributes.set(ATTR_const);
      tree->attributes.set(ATTR_char);

      printf("dfs charcon end\n");
      return retval;
    }

  else if (tree->symbol == TOK_STRINGCON)
    {
      printf("dfs stringcon end\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;
      retval->attributes.set(ATTR_const);
      retval->attributes.set(ATTR_string);
      tree->attributes.set(ATTR_const);
      tree->attributes.set(ATTR_string);

      printf("dfs stringcon end\n");
      return retval;
    }

  else if (tree->symbol == TOK_TRUE || tree->symbol == TOK_FALSE)
    {
      printf("dfs true/false start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;
      retval->attributes.set(ATTR_const);
      retval->attributes.set(ATTR_bool);
      tree->attributes.set(ATTR_const);
      tree->attributes.set(ATTR_bool);

      printf("dfs true/false end\n");
      return retval;
    }

  else if (tree->symbol == TOK_IDENT)
    {
      printf("dfs indent start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      retval->attributes = 0;

      symbol* ident_stuff = getInfo(tree->lexinfo);
      if(ident_stuff == NULL)
	{
	  fprintf(stderr, "ident %s not found\n", tree->lexinfo->c_str());
	  return NULL;
	}
      tree->attributes = ident_stuff->attributes;
      tree->lloc.blocknr = ident_stuff->lloc.blocknr;
      tree->dec_loc.filenr = ident_stuff->lloc.filenr;
      tree->dec_loc.linenr = ident_stuff->lloc.linenr;
      tree->dec_loc.offset = ident_stuff->lloc.offset;
      tree->printdecs = 1;
      retval->attributes = ident_stuff->attributes;

      if (tree->attributes.test(ATTR_struct))
	{
	  tree->type = ident_stuff->type_id;
          retval->type = ident_stuff->type_id;
	}

      printf("dfs indent end\n");
      return retval;
    }

  else if (tree->symbol == TOK_CALL)
    {
      printf("dfs call start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      for(u_int i = 0; i < tree->children.size(); i++)
	{
	  dfs_traversal(tree->children.at(i));
	}
      symbol* temp_symb = grabFunctionSymbol(tree->children.at(0));
      if(temp_symb == NULL)
	{
	  retval->attributes = 0;
	  return retval;
	}
      if (!compatible(temp_symb->attributes, tree->children.at(0)->attributes,
                      temp_symb->type_id, tree->children.at(0)->type))
	{
	  fprintf(stderr, "oc: Error with function type declaration\n");
	}
      for(u_int k = 1; k < tree->children.size(); k++)
	{
	  if (!compatible(temp_symb->parameters->at(k-1)->attributes, tree->children.at(k)->attributes,
			  temp_symb->parameters->at(k-1)->type_id, tree->children.at(k)->type))
	    {
	      fprintf(stderr, "oc: Invalid argument sent into function %s\n", tree->children.at(0)->lexinfo->c_str());
	    }
	} 
      tree->dec_loc.filenr = temp_symb->lloc.filenr;
      tree->dec_loc.linenr = temp_symb->lloc.linenr;
      tree->dec_loc.offset = temp_symb->lloc.offset;
      tree->printdecs = 1;
      retval->attributes = tree->children.at(0)->attributes;
      retval->type = tree->children.at(0)->type;
      printf("dfs call end\n");
      return retval;
    }

  else if (tree->symbol == TOK_NULL)
    {
      printf("dfs null start\n");
      dfs_ret *retval = (dfs_ret *)malloc(sizeof(*retval));
      tree->lloc.blocknr = getCurrentBloc();
      retval->attributes = 0;
      retval->attributes.set(ATTR_const);
      retval->attributes.set(ATTR_null);
      tree->attributes.set(ATTR_const);
      tree->attributes.set(ATTR_null);

      printf("dfs null end\n");
      return retval;

    }

    return nullptr;
}

void dfsTraversal(astree* tree)
{
  types.set(ATTR_bool);
  types.set(ATTR_char);
  types.set(ATTR_int);
  types.set(ATTR_null);
  types.set(ATTR_string);
  types.set(ATTR_struct);
  types.set(ATTR_array);

  dfs_traversal(tree);
}

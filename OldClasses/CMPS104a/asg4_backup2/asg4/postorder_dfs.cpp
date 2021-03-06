#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>

#include "astree.h"
#include "postorder_dfs.h"
#include "symbol_table.h"
#include "lyutils.h"

using namespace std;

FILE *fd_sym = NULL;

attr_bitset types = 0;

astree *typeid_one;
astree *typeid_two;

string *global_lexinfo = nullptr;
astree *declid;
astree *function_declid;


void set_attribs (attr_bitset destination, attr_bitset source)
{
  vector<Attrs> attrs = {ATTR_array, ATTR_int, ATTR_string, ATTR_struct};
  for (size_t i = 0; i < attrs.size(); ++i)
    {
      if (source.test(attrs[i]))
	{ 
	  destination.set(attrs[i]);
	}
    }
}

void traversal_struct (astree* tree, symbol* symbol_struct,
		       string* symbol_name) 
{
  printf("traversal_struct top\n");
  symbol* temp_sym = (symbol*)malloc(sizeof(struct symbol));
  if(symbol_struct->fields == NULL) {
    symbol_struct->fields = new symbol_table;
  }
  temp_sym->parameters = NULL;
  temp_sym->fields = NULL;

  std::map<int, Attrs> attr_str_map;
  attr_str_map[TOK_INT]      = ATTR_int;
  attr_str_map[TOK_STRING]   = ATTR_string;
  attr_str_map[TOK_TYPEID]   = ATTR_struct;
  
  if (tree->symbol == TOK_ARRAY) { 
    tree->attribs.set(ATTR_array);
    tree->children.back()->attribs.set(ATTR_array);
      
    if (attr_str_map.count(tree->children.at(0)->symbol) == 1) {
      Attrs attr = attr_str_map[tree->children.at(0)->symbol];
      tree->children.at(0)->attribs.set(attr);
      tree->children.back()->attribs.set(attr);
    }

    if (tree->children.at(0)->symbol == TOK_TYPEID) {
      tree->children.back()->type = (string *)tree->children.at(0)->lexinfo;
    }
  }

  else {
    if (attr_str_map.count(tree->symbol) == 1) {
      Attrs attr = attr_str_map[tree->symbol];
      tree->attribs.set(attr);
      tree->children.back()->attribs.set(attr);
    }

    if (tree->symbol == TOK_TYPEID) {
      tree->children.back()->type = (string *)tree->lexinfo;
    }
  }

  tree->children.back()->attribs.set(ATTR_field);
  temp_sym->attribs = tree->children.back()->attribs;
  temp_sym->type_id = tree->children.back()->type;

  temp_sym->lloc.blocknr = 0;
  temp_sym->lloc.offset = tree->lloc.offset;
  temp_sym->lloc.linenr = tree->lloc.linenr;
  temp_sym->lloc.filenr = tree->lloc.filenr;
  symbol_struct->fields->insert ({tree->children.back()->lexinfo,
        temp_sym});
  fprintf(fd_sym, "   %s (%zu.%zu.%zu) "
	  ,
          tree->children.back()->lexinfo->c_str(),
          temp_sym->lloc.filenr, temp_sym->lloc.linenr,
          temp_sym->lloc.offset
          );
  print_attributes (fd_sym, temp_sym->attribs,
		    temp_sym->type_id, symbol_name);
  fprintf(fd_sym, "\n");
  
  printf("traversal_struct bottom\n");
}

bool is_compat(attr_bitset one, attr_bitset two,
	       string *typeid_one, string *typeid_two)
{
  bool isCompat = false;
  if ((one & types) == (two & types))
    {
      if (one[ATTR_struct] && two[ATTR_struct])
        {
          if (typeid_one == typeid_two)
	    {
	      isCompat = true;
	    }
        }
      else
	{
	  isCompat = true;
	}
    }

  else if (      (one[ATTR_null]   &&   two[ATTR_null])
		 || (one[ATTR_string] &&   two[ATTR_null])
		 || (one[ATTR_struct] &&   two[ATTR_null])
		 || (one[ATTR_array]  &&   two[ATTR_null])
		 || (one[ATTR_null]   &&   two[ATTR_string])
		 || (one[ATTR_null]   &&   two[ATTR_struct])
		 || (one[ATTR_null]   &&   two[ATTR_array]))
    {
      isCompat = true;
    }

  return isCompat;
}

bool non_void(attr_bitset attribs)
{
  if (attribs[ATTR_void])
    {
      return false;
    }
  else
    {
      return true;
    }
}

bool base(attr_bitset attribs)
{
  if (attribs[ATTR_void])
    { 
      return false;
    }

  if (attribs[ATTR_array])
    {
      return false;
    }
  else
    {
      return true;
    }
}

bool primitive(attr_bitset attribs)
{
  if (attribs[ATTR_array])
    {
      return false;
    }

  if (attribs[ATTR_int])
    { 
      return true; 
    }
  return false;
}

struct dfs_return_value
{
  attr_bitset attribs;
  string *type;
};

dfs_return_value *postorder_dfs_traversal(astree* tree)
{ 
  map<int, Attrs> types_map;
  types_map[TOK_VOID]     = ATTR_void;
  types_map[TOK_INT]      = ATTR_int;
  types_map[TOK_STRING]   = ATTR_string;
  types_map[TOK_TYPEID]   = ATTR_struct;

  map<int, Attrs> consts_map;
  consts_map[TOK_INTCON]    = ATTR_int;
  consts_map[TOK_CHARCON]   = ATTR_int;
  consts_map[TOK_STRINGCON] = ATTR_string;

  if (tree == NULL)
    {
      return 0;
    }
  if (tree->symbol == TOK_ROOT)
    {
      symbol_create();
      for(auto it = tree->children.begin();
          it < tree->children.end(); it++)
        {
          postorder_dfs_traversal(*it);
        }
    }
 
  else if (tree->symbol == TOK_STRUCT)
    {
      printf("tok_struct top\n");
      symbol* symbol_test = locate_table(tree->children.at(0)->lexinfo);
      if (symbol_test != NULL && symbol_test->fields != NULL)
	{
	  fprintf(stderr, "Structure has two declarations %s\n",
                  tree->children.at(0)->lexinfo->c_str());
	} else {
	if(symbol_test != NULL){
	  delete_table_info (tree);
	}
	symbol* symbol_struct;
	int block_number;
	symbol_push();
	block_number = current_block();
	symbol_pop();
	symbol_struct = hold_table (tree);
	if (symbol_struct != NULL) {
	  tree->attribs.set(ATTR_struct);
	  tree->children.at(0)->attribs.set(ATTR_struct);
	  fprintf(fd_sym, "%s (%zu.%zu.%zu) {%zu} struct \"%s\"\n",
		  tree->children.at(0)->lexinfo->c_str(),
		  symbol_struct->lloc.filenr, symbol_struct->lloc.linenr,
		  symbol_struct->lloc.offset, symbol_struct->lloc.blocknr,
		  tree->children.at(0)->lexinfo->c_str());
	  for(u_int i = 1; i < tree->children.size(); i++)
	    {
	      tree->children.at(i)->lloc.blocknr = block_number;
	      tree->children.at(i)->children.back()->lloc.blocknr = block_number;
	      tree->children.at(i)->children.at(0)->lloc.blocknr = block_number;
	      traversal_struct (tree->children.at(i), symbol_struct,
				(string *)tree->children.at(0)->lexinfo);
	    }
	}
      }
      printf("tok_struct end\n");
    }
  else if (tree->symbol == TOK_PROTOTYPE)
    {
      symbol_prototype (tree, fd_sym);
    }
  else if (tree->symbol == TOK_FUNCTION) 
    {
      int add_to_tree = symbol_function (tree, fd_sym);

      if(add_to_tree){
	function_declid = tree->children.at(0)->children.back();
	for(auto it = tree->children.at(2)->children.begin();
	    it < tree->children.at(2)->children.end(); it++)
	  {
	    postorder_dfs_traversal(*it);
	  } 
	symbol_pop ();
      }
    }
  else if (tree->symbol == TOK_VARDECL) 
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      if (global_lexinfo != nullptr)
        {
          declid->type = global_lexinfo;
          global_lexinfo = nullptr;
        }
      
      tree->lloc.blocknr = current_block();
      declid->attribs = left_child->attribs;
      declid->attribs.set(ATTR_variable);
      declid->attribs.set(ATTR_lval);
      declid->lloc.blocknr = current_block();

      symbol_vardecl (declid, fd_sym);
    }

  else if (tree->symbol == TOK_BLOCK)
    {
      tree->lloc.blocknr = current_block();
      symbol_push ();
      
      for(auto it = tree->children.begin();
          it < tree->children.end(); it++)
        {
          postorder_dfs_traversal(*it);
        } 
      symbol_pop ();
    }

  else if (tree->symbol == TOK_WHILE)
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      tree->lloc.blocknr = current_block();
      if (!left_child->attribs[ATTR_int] || left_child->attribs[ATTR_array])
        {
          fprintf(stderr, "while expression must be a boolean\n");
        }
      postorder_dfs_traversal(tree->children.at(1));
    }

  else if (tree->symbol == TOK_IF || tree->symbol == TOK_IFELSE)
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      tree->lloc.blocknr = current_block();
      if (!left_child->attribs[ATTR_int] || left_child->attribs[ATTR_array])
        {
          fprintf(stderr, "while expression must be a boolean\n");
        }
      postorder_dfs_traversal(tree->children.at(1));
      if (tree->children.size() > 2){
	postorder_dfs_traversal(tree->children.at(2));
      }
    }

  else if (tree->symbol == TOK_RETURN)
    {
      dfs_return_value *child = postorder_dfs_traversal(tree->children.at(0));
      tree->lloc.blocknr = current_block();
      if(child == NULL)
	{
	  fprintf(stderr, "The value returned is invalid\n");
	  return nullptr;
	}
      if(!is_compat(function_declid->attribs, child->attribs,
		    function_declid->type, child->type))
        {
          fprintf(stderr, "Returned value and function" 
		  "type do not match\n");
        }
    }

  else if (tree->symbol == TOK_RETURNVOID)
    {
      tree->lloc.blocknr = current_block();
      if (!function_declid->attribs[ATTR_void])
        {
          fprintf(stderr, "Returned value and function" 
		  "typ do not match\n");
        }
    }


  else if (tree->symbol == '=')
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *right_child = postorder_dfs_traversal(tree->children.at(1));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      tree->lloc.blocknr = current_block();
      return_value->attribs = 0;

      if(left_child == NULL)
	{
	  fprintf(stderr, "Cannot find identifier\n");
	  return return_value;
	}
      if(right_child == NULL)
	{
	  fprintf(stderr, "Cannot find identifier\n");
	  return return_value;
	}

      if (non_void(left_child->attribs) && left_child->attribs[ATTR_lval] 
          && non_void(right_child->attribs))
        {
          if (is_compat(left_child->attribs, right_child->attribs,
			left_child->type, right_child->type))
            {
              set_attribs(return_value->attribs, left_child->attribs);
              return_value->type = left_child->type;
              return_value->attribs.set(ATTR_vreg);
            }
          else
            {
              fprintf(stderr, " = operands do not match\n");
            }
        }
      else
        {
          fprintf(stderr, " = operands do not match\n");
        }
      return return_value;
    }


  else if (tree->symbol == TOK_EQ || tree->symbol == TOK_NE)
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *right_child = postorder_dfs_traversal(tree->children.at(1));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      tree->lloc.blocknr = current_block();
      return_value->attribs = 0;

      if(left_child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}
      if(right_child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}

      char *op = NULL;
      if (tree->symbol == TOK_EQ) { op = (char*)"=="; }
      else if (tree->symbol == TOK_NE) { op = (char*)"!="; }

      if (!non_void(left_child->attribs))
        { 
          fprintf(stderr, "left_child operand of %s is not 'non_void'\n", op);
        }

      if (!non_void(right_child->attribs))
        { 
          fprintf(stderr, "right_child operand of %s is not 'non_void\n", op);
        }

      if (non_void(left_child->attribs) && non_void(right_child->attribs))
        {
          if (is_compat(left_child->attribs, right_child->attribs, 
			left_child->type, right_child->type))
            {
	      tree->attribs.set(ATTR_int);
              tree->attribs.set(ATTR_vreg);
              return_value->attribs.set(ATTR_int);
              return_value->attribs.set(ATTR_vreg);
            }
          else
            {
              fprintf(stderr, "operands of %s not compatable\n", op);
            }
        }
      return return_value;
    }

  else if (tree->symbol == TOK_LT || tree->symbol == TOK_LE
           || tree->symbol == TOK_GT || tree->symbol == TOK_GE)
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *right_child = postorder_dfs_traversal(tree->children.at(1));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      tree->lloc.blocknr = current_block();
      return_value->attribs = 0;

      if(left_child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}
      if(right_child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}

      char *op = NULL;
      if (tree->symbol == TOK_LT) { op = (char*)"<"; }
      else if (tree->symbol == TOK_LE) { op = (char*)"<="; }
      else if (tree->symbol == TOK_GT) { op = (char*)">"; }
      else if (tree->symbol == TOK_GE) { op = (char*)">="; }

      if (!primitive(left_child->attribs))
        { 
          fprintf(stderr, "left_child %s is not primitive\n", op);
        }

      if (!primitive(right_child->attribs))
        { 
          fprintf(stderr, "right_child %s is not primitive\n", op);
        }

      if (primitive(left_child->attribs) && primitive(right_child->attribs))
        {
          if (is_compat(left_child->attribs, right_child->attribs, 
			left_child->type, right_child->type))
            {
	      
              tree->attribs.set(ATTR_int);
              tree->attribs.set(ATTR_vreg);
              return_value->attribs.set(ATTR_int);
              return_value->attribs.set(ATTR_vreg);
            }
          else
            {
              fprintf(stderr, "%s operands are not compatible\n", op);
            }
        }
      else
        {
          fprintf(stderr, "%s operands are not primitiv type\n", op);
        }
      return return_value;
    }

  else if (tree->symbol == '+' || tree->symbol == '-'
           || tree->symbol == '*' || tree->symbol == '/'
           || tree->symbol == '%')
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *right_child = postorder_dfs_traversal(tree->children.at(1));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;
      tree->lloc.blocknr = current_block();

      if(left_child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}
      if(right_child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}

      if ((left_child->attribs[ATTR_int] && right_child->attribs[ATTR_int])
          && (!left_child->attribs[ATTR_array] && !right_child->attribs[ATTR_array]))
        {
          return_value->attribs.set(ATTR_int);
          return_value->attribs.set(ATTR_vreg);
          tree->attribs.set(ATTR_int);
          tree->attribs.set(ATTR_vreg);
        } 
      else
        {
          if (tree->symbol == '+')
            { fprintf(stderr, "Not valid: addition\n"); }
          else if (tree->symbol == '-')
            { fprintf(stderr, "Not valid: subtraction\n"); }
          else if (tree->symbol == '*')
            { fprintf(stderr, "Not valid: multiplication\n"); }
          else if (tree->symbol == '/')
            { fprintf(stderr, "Not valid: division\n"); }
          else if (tree->symbol == '%')
            { fprintf(stderr, "Not valid: %%\n"); }
        }
      return return_value;
    }

  else if (tree->symbol == TOK_POS || tree->symbol == TOK_NEG)
    {
      dfs_return_value *child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;
      tree->lloc.blocknr = current_block();

      if (child->attribs[ATTR_int] && !child->attribs[ATTR_array])
        {
	  
          return_value->attribs.set(ATTR_int);
          return_value->attribs.set(ATTR_vreg);
          tree->attribs.set(ATTR_int);
          tree->attribs.set(ATTR_vreg);
        }
      else
        {
          if (tree->symbol == TOK_POS) 
            { fprintf(stderr, "Not valid: unary +\n"); }
          else if (tree->symbol == TOK_NEG)
            { fprintf(stderr, "Not valid: unary -\n"); }
        }
      return return_value;
    }

  else if (tree->symbol == '!')
    {
      dfs_return_value *child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;
      if(child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}
      if (child->attribs[ATTR_int] && !child->attribs[ATTR_array])
        {
          return_value->attribs.set(ATTR_int);
          return_value->attribs.set(ATTR_vreg);
          tree->attribs.set(ATTR_int);
          tree->attribs.set(ATTR_vreg);
        }
      else
        {
          fprintf(stderr, "Not valid: !\n");
        }
      return return_value;	
    }

  else if (tree->symbol == TOK_NEW)
    {
      dfs_return_value *child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;
      tree->attribs = 0;

      if(child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}

      tree->attribs = return_value->attribs;
      tree->type = return_value->type;
      return_value->attribs |= (child->attribs & types);
      return_value->attribs.set(ATTR_vreg);
      return_value->type = child->type;

      return return_value;
    }

  else if (tree->symbol == TOK_NEWSTRING)
    {
      dfs_return_value *child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;
      tree->attribs = 0;

      if(child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}

      if (child->attribs[ATTR_int] && !child->attribs[ATTR_array])
        {
	  tree->attribs = return_value->attribs;
          return_value->attribs.set(ATTR_string);
          return_value->attribs.set(ATTR_vreg);
        }
      else
        {
          fprintf(stderr, "Values in string parenthesis must equal an int\n");
        }
      return return_value;
    }

  else if (tree->symbol == TOK_NEWARRAY)
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *right_child = postorder_dfs_traversal(tree->children.at(1));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;
      tree->attribs = 0;

      if(left_child == NULL)
	{
	  fprintf(stderr, "%s is undeclared\n", tree->children.at(0)->lexinfo->c_str());
	  return return_value;
	}
      if(right_child == NULL)
	{
	  fprintf(stderr, "%s is undeclared\n", tree->children.at(1)->lexinfo->c_str());
	  return return_value;
	}

      if (base(left_child->attribs))
        {
          if (right_child->attribs[ATTR_int]
              && !right_child->attribs[ATTR_array])
            {
	      return_value->attribs |= (left_child->attribs & types);
              return_value->type = left_child->type;              
              return_value->attribs.set(ATTR_array);
              return_value->attribs.set(ATTR_vreg);
	      tree->attribs = return_value->attribs;
	      tree->type = return_value->type;
	    }
          else
            {
              fprintf(stderr, "Value in brackets of an array must equal an int\n");
            }
        }
      else
        {
          fprintf(stderr, "cannot make an array of array types\n");
        }

      return return_value;
    }

  else if (tree->symbol == TOK_INDEX)
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *right_child = postorder_dfs_traversal(tree->children.at(1));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;

      if(left_child == NULL)
	{
	  fprintf(stderr, "Variable not declared %s\n", tree->children.at(0)->lexinfo->c_str());
	  return return_value;
	}
      if(right_child == NULL)
	{
	  fprintf(stderr, "Variable not declared %s\n", tree->children.at(1)->lexinfo->c_str());
	  return return_value;
	}

      if (right_child->attribs[ATTR_int] &&
	  !right_child->attribs[ATTR_array])
        {
          if(left_child->attribs[ATTR_string] &&
	     !left_child->attribs[ATTR_array])
            {
              return_value->attribs.set(ATTR_int);
              return_value->attribs.set(ATTR_vaddr);
              return_value->attribs.set(ATTR_lval);
              tree->attribs = return_value->attribs;
            }
          else if (left_child->attribs[ATTR_array])
            {
              tree->attribs = return_value->attribs;
              return_value->attribs |= (left_child->attribs & types);
              return_value->attribs.flip(ATTR_array);
              return_value->attribs.set(ATTR_vaddr);
              return_value->attribs.set(ATTR_lval);
              return_value->type = left_child->type;
            }
          else
            {
              fprintf(stderr, "left_child side of index invalid\n");
            }
        }
      else
        {
          fprintf(stderr, "Array or string index  must be an int\n");
        }
      return return_value;
    }

  else if (tree->symbol == '.')
    {
      dfs_return_value *left_child = postorder_dfs_traversal(tree->children.at(0));
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;
      symbol *fieldptr = nullptr;

      if(left_child == NULL)
	{
	  fprintf(stderr, "Cannot find symbol\n");
	  return return_value;
	}

      if (left_child->attribs[ATTR_struct] && !left_child->attribs[ATTR_array])
        {
          
          symbol *selector_struct = get_structsymbol(left_child->type);
          if (nullptr != selector_struct)
            {

              auto table_check = 
                selector_struct->fields->find(tree->children.at(1)->lexinfo);
              if (selector_struct->fields->end() == table_check)
                {
                  fprintf(stderr, "Field does not exist in structure\n");
                }
              else
                {
		  tree->attribs = return_value->attribs;
                  tree->type = return_value->type;
                  fieldptr = table_check->second;
                  return_value->attribs |= (fieldptr->attribs & types);
                  return_value->attribs.set(ATTR_vaddr);
                  return_value->attribs.set(ATTR_lval);
                  return_value->type = fieldptr->type_id;

                  tree->children.at(1)->attribs = fieldptr->attribs;
                }
            }
          else
            {
              fprintf(stderr, "Invalid type\n");
            }
          
        }
      else
        {
          fprintf(stderr, "left_child side of field selector must be a struct");
        }
      return return_value;
    }


  else if (tree->symbol == TOK_DECLID)
    {
      declid = tree;
      tree->lloc.blocknr = current_block();
      return NULL;
    }
  
 
  else if (tree->symbol == TOK_ARRAY)
    {
      dfs_return_value *return_value = postorder_dfs_traversal(tree->children.at(0));
      postorder_dfs_traversal(tree->children.at(1));
      tree->lloc.blocknr = current_block();
      
      
      return_value->attribs.set(ATTR_array);
      tree->attribs.set(ATTR_array);
      
      return return_value;
    }

  else if (types_map.count(tree->symbol) == 1) {
    printf("type top\n");
    dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
    return_value->attribs = 0;
    tree->lloc.blocknr = current_block();  

    return_value->attribs.set(types_map[tree->symbol]);
    tree->attribs.set(types_map[tree->symbol]);
 
    if (TOK_TYPEID == tree->symbol) {
      printf("typeid\n");
      return_value->type = (string *)tree->lexinfo;      
      tree->type = (string *)tree->lexinfo;
      global_lexinfo = tree->type;
    }

    if (!tree->children.empty())
      {
        postorder_dfs_traversal(tree->children.at(0));
      }

    printf("type bottom\n");
    return return_value;
  }

  else if (consts_map.count(tree->symbol) == 1) {
    dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
    tree->lloc.blocknr = current_block();
    return_value->attribs = 0;
    return_value->attribs.set(ATTR_const);
    return_value->attribs.set(consts_map[tree->symbol]);
    tree->attribs.set(ATTR_const);
    tree->attribs.set(consts_map[tree->symbol]);
      
    return return_value;
  }

  else if (tree->symbol == TOK_TRUE || tree->symbol == TOK_FALSE)
    {
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      tree->lloc.blocknr = current_block();
      return_value->attribs = 0;
      tree->attribs.set(ATTR_const);
      tree->attribs.set(ATTR_int);
 
      return_value->attribs.set(ATTR_const);
      return_value->attribs.set(ATTR_int);
 
      return return_value;
    }

  else if (tree->symbol == TOK_IDENT)
    {
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      return_value->attribs = 0;

      symbol* ident_stuff = get_info(tree->lexinfo);
     
      tree->attribs = ident_stuff->attribs;
      tree->lloc.blocknr = ident_stuff->lloc.blocknr;
      tree->dec_loc.offset = ident_stuff->lloc.offset;
      tree->dec_loc.linenr = ident_stuff->lloc.linenr;
      tree->dec_loc.filenr = ident_stuff->lloc.filenr;
      tree->printdecs = 1;
      return_value->attribs = ident_stuff->attribs;

      if (tree->attribs.test(ATTR_struct))
	{
	  tree->type = ident_stuff->type_id;
          return_value->type = ident_stuff->type_id;
	}

      return return_value;
    }

  else if (tree->symbol == TOK_CALL)
    {
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      tree->lloc.blocknr = current_block();
      for(u_int i = 0; i < tree->children.size(); i++)
	{
	  postorder_dfs_traversal(tree->children.at(i));
	}
      symbol* temp_symb = get_funcsymbol(tree->children.at(0));
      if(temp_symb == NULL)
	{
	  return_value->attribs = 0;
	  return return_value;
	}
      if (!is_compat(temp_symb->attribs, tree->children.at(0)->attribs,
		     temp_symb->type_id, tree->children.at(0)->type))
	{
	  fprintf(stderr, "Function type declaration error\n");
	}

      tree->printdecs = 1;
      return_value->attribs = tree->children.at(0)->attribs;
      return_value->type = tree->children.at(0)->type;
      tree->dec_loc.filenr = temp_symb->lloc.filenr;
      tree->dec_loc.linenr = temp_symb->lloc.linenr;
      tree->dec_loc.offset = temp_symb->lloc.offset;

      return return_value;
    }

  else if (tree->symbol == TOK_NULL)
    {
      dfs_return_value *return_value = (dfs_return_value *)malloc(sizeof(*return_value));
      tree->lloc.blocknr = current_block();
      return_value->attribs = 0;
      return_value->attribs.set(ATTR_const);
      return_value->attribs.set(ATTR_null);
      tree->attribs.set(ATTR_const);
      tree->attribs.set(ATTR_null);
 
      return return_value;

    }

  return nullptr;
}

void postorder_traversal(astree* tree)
{
  types.set(ATTR_int);
  types.set(ATTR_null);
  types.set(ATTR_string);
  types.set(ATTR_struct);
  types.set(ATTR_array);

  postorder_dfs_traversal(tree);
}

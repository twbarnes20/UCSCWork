#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdio.h>

#include "symbol_table.h"
#include "astree.h"
#include "attrs.h"
#include "lyutils.h"

using namespace std;

symbol_table table;

vector<symbol_table*> symbol_stack;
vector<int> block_stack;

int block_depth = 1;
int indent = 0;

int getCurrentBloc()
{
  return block_stack.back();
}

void myFunctionToDoThatThing (astree* tree)
{
  table.erase(tree->children.at(0)->lexinfo);  
}

symbol* intern_table (astree* tree)
{
  symbol* temp_sym = (symbol*)malloc(sizeof(struct symbol));
  temp_sym->fields = NULL;
  temp_sym->parameters = NULL;
  temp_sym->attributes = ATTR_struct;
  temp_sym->lloc.blocknr = 0;
  temp_sym->lloc.filenr = tree->lloc.filenr;
  temp_sym->lloc.linenr = tree->lloc.linenr;
  temp_sym->lloc.offset = tree->lloc.offset;
  temp_sym->initialize = 0;
  table.insert ({tree->children.at(0)->lexinfo, temp_sym});

  return temp_sym;
}

symbol* find_table (const string* key) 
{
  auto found = table.find(key);
  if (found == table.end())
    {
      return NULL;
    } 
  else 
    {
      return found->second;
    }
}

void symbolStackInit()
{
  symbol_table* temp_table = NULL;
  symbol_stack.push_back(temp_table);
  block_stack.push_back(0);
}

void symbolStackPush()
{
  symbol_table* temp_table = NULL;
  symbol_stack.push_back(temp_table);
  block_stack.push_back(block_depth);
  block_depth++;
  indent++;
}

void symbolStackPop()
{
  symbol_stack.pop_back();
  block_stack.pop_back();
  indent--;
}

void symbolStackAddVardecl(astree* tree, FILE* sym_file)
{
  if (symbol_stack.back() == NULL)
    {
      symbol_table* temp_table = new symbol_table;
      symbol_stack.back() = temp_table;
    }

  auto table_check = symbol_stack.back()->find(tree->lexinfo);

  if (table_check != symbol_stack.back()->end()) 
    {
      fprintf (stderr, "Variable Initialized Twice %s\n", tree->lexinfo->c_str());
      return;
    }

  symbol* temp_sym = (symbol*)malloc(sizeof(struct symbol));
  temp_sym->type_id = tree->type;  
  temp_sym->fields = NULL;
  temp_sym->parameters = NULL;
  temp_sym->attributes = tree->attributes;
  temp_sym->lloc.blocknr = block_stack.back();
  tree->lloc.blocknr = block_stack.back();
  temp_sym->lloc.filenr = tree->lloc.filenr;
  temp_sym->lloc.linenr = tree->lloc.linenr;
  temp_sym->lloc.offset = tree->lloc.offset;
  temp_sym->initialize = 0;
  symbol_stack.back()->insert ({tree->lexinfo, temp_sym});

  for(int n = 0; n < indent; n++)
    {
      fprintf(sym_file, "   ");
    }

  fprintf(sym_file, "%s (%zu.%zu.%zu) {%d} ",
          tree->lexinfo->c_str(),
          temp_sym->lloc.filenr, temp_sym->lloc.linenr,
          temp_sym->lloc.offset, block_stack.back());
  print_attrs (sym_file, temp_sym->attributes,
               temp_sym->type_id, NULL);
  fprintf(sym_file, "\n");
}

void symbolStackAddPrototype(astree* tree, FILE* sym_file) {
  if (symbol_stack.back() == NULL) {
    symbol_table* temp_table = new symbol_table;
    symbol_stack.back() = temp_table;
  }

  auto table_check = symbol_stack.back()->find(tree->children.at(0)->children.back()->lexinfo);
  if (table_check != symbol_stack.back()->end())
    {
      fprintf (stderr, "Function has two definitions %s\n", 
	       tree->children.at(0)->children.back()->lexinfo->c_str());
      return;
    }
  
  symbol* temp_sym = (symbol*)malloc(sizeof(struct symbol));
  temp_sym->fields = NULL;
  temp_sym->attributes = tree->attributes;
  temp_sym->attributes.set(ATTR_function);
  if (tree->children.at(0)->symbol == TOK_ARRAY)
    { 
      temp_sym->attributes.set(ATTR_array);
      tree->children.at(0)->attributes.set(ATTR_array);
      tree->children.at(0)->children.back()->attributes.set(ATTR_array);
      if (tree->children.at(0)->children.at(0)->symbol == TOK_BOOL)
        {
          temp_sym->attributes.set(ATTR_bool);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_bool);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_bool);
        }
      else if (tree->children.at(0)->children.at(0)->symbol == TOK_CHAR)
        {
          temp_sym->attributes.set(ATTR_char);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_char);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_char);
        }
      else if (tree->children.at(0)->children.at(0)->symbol == TOK_INT)
        {
          temp_sym->attributes.set(ATTR_int);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_int);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_int);
        }
      else if (tree->children.at(0)->children.at(0)->symbol == TOK_STRING)
        { 
          temp_sym->attributes.set(ATTR_string);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_string);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_string);
        }
      else if (tree->children.at(0)->children.at(0)->symbol == TOK_TYPEID)
        {
          temp_sym->attributes.set(ATTR_struct);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_struct);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_struct);
	  tree->children.at(0)->children.back()->type = (string *)tree->children.at(0)->children.at(0)->lexinfo;
	  tree->children.at(0)->children.at(0)->type = (string *)tree->children.at(0)->children.at(0)->lexinfo;
          temp_sym->type_id = (string *)tree->children.at(0)->children.back()->lexinfo;
        }
      else
	{
	  fprintf(stderr, "Incorrect Array Construction");
	  return;
	}
    }
  else if (tree->children.at(0)->symbol == TOK_BOOL)
    {
      temp_sym->attributes.set(ATTR_bool);
      tree->children.at(0)->attributes.set(ATTR_bool);
      tree->children.at(0)->children.back()->attributes.set(ATTR_bool);
    }
  else if (tree->children.at(0)->symbol == TOK_CHAR)
    {
      temp_sym->attributes.set(ATTR_char);
      tree->children.at(0)->attributes.set(ATTR_char);
      tree->children.at(0)->children.back()->attributes.set(ATTR_char);
    }
  else if (tree->children.at(0)->symbol == TOK_INT)
    {
      temp_sym->attributes.set(ATTR_int);
      tree->children.at(0)->attributes.set(ATTR_int);
      tree->children.at(0)->children.back()->attributes.set(ATTR_int);
    }
  else if (tree->children.at(0)->symbol == TOK_STRING)
    { 
      temp_sym->attributes.set(ATTR_string);
      tree->children.at(0)->attributes.set(ATTR_string);
      tree->children.at(0)->children.back()->attributes.set(ATTR_string);
    }
  else if (tree->children.at(0)->symbol == TOK_VOID)
    { 
      temp_sym->attributes.set(ATTR_void);
      tree->children.at(0)->attributes.set(ATTR_void);
      tree->children.at(0)->children.back()->attributes.set(ATTR_void);
    }
  else if (tree->children.at(0)->symbol == TOK_TYPEID)
    {
      temp_sym->attributes.set(ATTR_struct);
      tree->children.at(0)->attributes.set(ATTR_struct);
      tree->children.at(0)->children.back()->attributes.set(ATTR_struct);
      tree->children.at(0)->children.back()->type = (string *)tree->children.at(0)->lexinfo;
      tree->children.at(0)->type = (string *)tree->children.at(0)->lexinfo;
      temp_sym->type_id = (string *)tree->children.at(0)->children.back()->lexinfo;
    }
  temp_sym->lloc.blocknr = block_stack.back();
  temp_sym->lloc.filenr = tree->lloc.filenr;
  temp_sym->lloc.linenr = tree->lloc.linenr;
  temp_sym->lloc.offset = tree->lloc.offset;
  temp_sym->initialize = 0;
  for(int n = 0; n < indent; n++){
    fprintf(sym_file, "   ");
  }
  fprintf(sym_file, "%s (%zu.%zu.%zu) {%d} ",
	  tree->children.at(0)->children.back()->lexinfo->c_str(),
	  temp_sym->lloc.filenr, temp_sym->lloc.linenr,
          temp_sym->lloc.offset, block_stack.back());
  print_attrs (sym_file, temp_sym->attributes,
	       temp_sym->type_id, NULL);
  fprintf(sym_file, "\n");
  temp_sym->parameters = new vector<symbol*>;
  for(u_int i = 0; i < tree->children.at(1)->children.size(); i++)
    {
      if (symbol_stack.back() == NULL) 
	{
	  symbol_table* diff_table = new symbol_table;
	  symbol_stack.back() = diff_table ;
	}

      symbol* sym_param        = (symbol*)malloc(sizeof(struct symbol));    
      astree* temp_params = tree->children.at(1)->children.at(i);
      sym_param->fields = NULL;
      sym_param->parameters = NULL;
      sym_param->attributes = temp_params->attributes;
      sym_param->attributes.set(ATTR_lval);
      sym_param->attributes.set(ATTR_variable);
      sym_param->attributes.set(ATTR_param);
      if (temp_params->symbol == TOK_ARRAY)
	{ 
	  sym_param->attributes.set(ATTR_array);
	  temp_params->attributes.set(ATTR_array);
	  temp_params->children.back()->attributes.set(ATTR_array);
	  if (temp_params->children.at(0)->symbol == TOK_BOOL)
	    {
	      sym_param->attributes.set(ATTR_bool);
	      temp_params->children.at(0)->attributes.set(ATTR_bool);
	      temp_params->children.back()->attributes.set(ATTR_bool);
	    }
	  else if (temp_params->children.at(0)->symbol == TOK_CHAR)
	    {
	      sym_param->attributes.set(ATTR_char);
	      temp_params->children.at(0)->attributes.set(ATTR_char);
	      temp_params->children.back()->attributes.set(ATTR_char);
	    }
	  else if (temp_params->children.at(0)->symbol == TOK_INT)
	    {
	      sym_param->attributes.set(ATTR_int);
	      temp_params->children.at(0)->attributes.set(ATTR_int);
	      temp_params->children.back()->attributes.set(ATTR_int);
	    }
	  else if (temp_params->children.at(0)->symbol == TOK_STRING)
	    { 
	      sym_param->attributes.set(ATTR_string);
	      temp_params->children.at(0)->attributes.set(ATTR_string);
	      temp_params->children.back()->attributes.set(ATTR_string);
	    }
	  else if (temp_params->children.at(0)->symbol == TOK_TYPEID)
	    {
	      sym_param->attributes.set(ATTR_struct);
	      temp_params->children.at(0)->attributes.set(ATTR_struct);
	      temp_params->children.back()->attributes.set(ATTR_struct);
	      temp_params->children.back()->type = (string *)temp_params->children.at(0)->lexinfo;
	      temp_params->children.at(0)->type = (string *)temp_params->children.at(0)->lexinfo;
	      sym_param->type_id = (string *)temp_params->children.at(0)->lexinfo;
	    }
	}
      else if (temp_params->symbol == TOK_BOOL)
	{
	  sym_param->attributes.set(ATTR_bool);
	  temp_params->attributes.set(ATTR_bool);
	  temp_params->children.back()->attributes.set(ATTR_bool);
	}
      else if (temp_params->symbol == TOK_CHAR)
	{
	  sym_param->attributes.set(ATTR_char);
	  temp_params->attributes.set(ATTR_char);
	  temp_params->children.back()->attributes.set(ATTR_char);
	}
      else if (temp_params->symbol == TOK_INT)
	{
	  sym_param->attributes.set(ATTR_int);
	  temp_params->attributes.set(ATTR_int);
	  temp_params->children.back()->attributes.set(ATTR_int);
	}
      else if (temp_params->symbol == TOK_STRING)
	{ 
	  sym_param->attributes.set(ATTR_string);
	  temp_params->attributes.set(ATTR_string);
	  temp_params->children.back()->attributes.set(ATTR_string);
	}
      else if (temp_params->symbol == TOK_TYPEID)
	{
	  sym_param->attributes.set(ATTR_struct);
	  temp_params->attributes.set(ATTR_struct);
	  temp_params->children.back()->attributes.set(ATTR_struct);
	  temp_params->children.back()->type = (string *)temp_params->lexinfo;
	  temp_params->type = (string *)temp_params->lexinfo;
	  sym_param->type_id = (string *)temp_params->lexinfo;
	}
      sym_param->lloc.blocknr = block_depth;
      temp_params->lloc.blocknr = block_depth;
      temp_params->children.at(0)->lloc.blocknr = block_depth;
      temp_params->children.back()->lloc.blocknr = block_depth;
      sym_param->lloc.filenr = temp_params->lloc.filenr;
      sym_param->lloc.linenr = temp_params->lloc.linenr;
      sym_param->lloc.offset = temp_params->lloc.offset;
      temp_sym->parameters->push_back(sym_param);
      for(int n = 0; n < (indent + 1); n++)
	{
	  fprintf(sym_file, "   ");
	}
    
      fprintf(sym_file, "%s (%zu.%zu.%zu) {%d} ",
	      temp_params->children.back()->lexinfo->c_str(),
	      sym_param->lloc.filenr, sym_param->lloc.linenr,
	      sym_param->lloc.offset, block_depth);
      print_attrs (sym_file, sym_param->attributes,
		   sym_param->type_id, NULL);
      fprintf(sym_file, "\n");
    }
  symbolStackPush();
  symbolStackPop();
  fprintf(sym_file, "\n");
  symbol_stack.back()->insert ({tree->children.at(0)->children.back()->lexinfo, temp_sym});
}

int symbolStackAddFunction(astree* tree, FILE* sym_file)
{
  if (symbol_stack.back() == NULL)
    {
      symbol_table* temp_table = new symbol_table;
      symbol_stack.back() = temp_table;
    }
  auto table_check = symbol_stack.back()->find(tree->children.at(0)->children.back()->lexinfo);

  if (table_check != symbol_stack.back()->end() && !table_check->second->attributes.test(ATTR_function)) 
    {
      fprintf (stderr, "oc: %s Not a function\n", tree->children.at(0)->children.back()->lexinfo->c_str());
      return 0;
    }
  else if (table_check != symbol_stack.back()->end() && table_check->second->initialize == 1)
    {
      fprintf (stderr, "Function created twice %s\n",
	       tree->children.at(0)->children.back()->lexinfo->c_str());
      return 0;
    }

  else 
    {
      symbol_stack.back()->erase(tree->children.at(0)->children.back()->lexinfo);
    }

  symbol* temp_sym = (symbol*)malloc(sizeof(struct symbol));
  temp_sym->fields = NULL;
  temp_sym->initialize = 1;
  temp_sym->attributes = tree->attributes;
  temp_sym->attributes.set(ATTR_function);
  if (tree->children.at(0)->symbol == TOK_ARRAY)
    {
      temp_sym->attributes.set(ATTR_array);
      tree->children.at(0)->attributes.set(ATTR_array);
      tree->children.at(0)->children.back()->attributes.set(ATTR_array);
      if (tree->children.at(0)->children.at(0)->symbol == TOK_BOOL)
        {
          temp_sym->attributes.set(ATTR_bool);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_bool);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_bool);
        }
      else if (tree->children.at(0)->children.at(0)->symbol == TOK_CHAR)
        {
          temp_sym->attributes.set(ATTR_char);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_char);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_char);
        }
      else if (tree->children.at(0)->children.at(0)->symbol == TOK_INT)
        {
          temp_sym->attributes.set(ATTR_int);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_int);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_int);
        }
      else if (tree->children.at(0)->children.at(0)->symbol == TOK_STRING)
        { 
          temp_sym->attributes.set(ATTR_string);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_string);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_string);
        }
      else if (tree->children.at(0)->children.at(0)->symbol == TOK_TYPEID)
        {
          temp_sym->attributes.set(ATTR_struct);
	  tree->children.at(0)->children.at(0)->attributes.set(ATTR_struct);
	  tree->children.at(0)->children.back()->attributes.set(ATTR_struct);
	  tree->children.at(0)->children.back()->type = (string *)tree->children.at(0)->children.at(0)->lexinfo;
	  tree->children.at(0)->children.at(0)->type = (string *)tree->children.at(0)->children.at(0)->lexinfo;
          temp_sym->type_id = (string *)tree->children.at(0)->children.back()->lexinfo;
        }
      else
	{
	  fprintf(stderr, "Not valid array");
	  return 0;
	}
    }
  else if (tree->children.at(0)->symbol == TOK_BOOL)
    {
      temp_sym->attributes.set(ATTR_bool);
      tree->children.at(0)->attributes.set(ATTR_bool);
      tree->children.at(0)->children.back()->attributes.set(ATTR_bool);
    }
  else if (tree->children.at(0)->symbol == TOK_CHAR)
    {
      temp_sym->attributes.set(ATTR_char);
      tree->children.at(0)->attributes.set(ATTR_char);
      tree->children.at(0)->children.back()->attributes.set(ATTR_char);
    }
  else if (tree->children.at(0)->symbol == TOK_INT)
    {
      temp_sym->attributes.set(ATTR_int);
      tree->children.at(0)->attributes.set(ATTR_int);
      tree->children.at(0)->children.back()->attributes.set(ATTR_int);
    }
  else if (tree->children.at(0)->symbol == TOK_STRING)
    { 
      temp_sym->attributes.set(ATTR_string);
      tree->children.at(0)->attributes.set(ATTR_string);
      tree->children.at(0)->children.back()->attributes.set(ATTR_string);
    }
  else if (tree->children.at(0)->symbol == TOK_VOID)
    { 
      temp_sym->attributes.set(ATTR_void);
      tree->children.at(0)->attributes.set(ATTR_void);
      tree->children.at(0)->children.back()->attributes.set(ATTR_void);
    }
  else if (tree->children.at(0)->symbol == TOK_TYPEID)
    {
      temp_sym->attributes.set(ATTR_struct);
      tree->children.at(0)->attributes.set(ATTR_struct);
      tree->children.at(0)->children.back()->attributes.set(ATTR_struct);
      tree->children.at(0)->children.back()->type = (string *)tree->children.at(0)->lexinfo;
      tree->children.at(0)->type = (string *)tree->children.at(0)->lexinfo;
      temp_sym->type_id = (string *)tree->children.at(0)->children.back()->lexinfo;
    }
  temp_sym->lloc.blocknr = block_stack.back();
  temp_sym->lloc.filenr = tree->lloc.filenr;
  temp_sym->lloc.linenr = tree->lloc.linenr;
  temp_sym->lloc.offset = tree->lloc.offset;
  for(int n = 0; n < indent; n++){
    fprintf(sym_file, "   ");
  }
  fprintf(sym_file, "%s (%zu.%zu.%zu) {%d} ",
	  tree->children.at(0)->children.back()->lexinfo->c_str(),
	  temp_sym->lloc.filenr, temp_sym->lloc.linenr,
          temp_sym->lloc.offset, block_stack.back());
  print_attrs (sym_file, temp_sym->attributes,
	       temp_sym->type_id, NULL);
  fprintf(sym_file, "\n");

  temp_sym->parameters = new vector<symbol*>;
  for(u_int i = 0; i < tree->children.at(1)->children.size(); i++)
    {
      if (symbol_stack.back() == NULL)
	{
	  symbol_table* diff_table = new symbol_table;
	  symbol_stack.back() = diff_table;
	}
      symbol* sym_param = (symbol*)malloc(sizeof(struct symbol));
      astree* temp_params = tree->children.at(1)->children.at(i);
      
      sym_param->attributes = temp_params->attributes;
      sym_param->attributes.set(ATTR_lval);
      sym_param->attributes.set(ATTR_variable);
      sym_param->attributes.set(ATTR_param);
      if (temp_params->symbol == TOK_ARRAY)
	{ 
	  sym_param->attributes.set(ATTR_array);
	  temp_params->attributes.set(ATTR_array);
	  temp_params->children.back()->attributes.set(ATTR_array);
	  if (temp_params->children.at(0)->symbol == TOK_BOOL)
	    {
	      sym_param->attributes.set(ATTR_bool);
	      temp_params->children.at(0)->attributes.set(ATTR_bool);
	      temp_params->children.back()->attributes.set(ATTR_bool);
	    }
	  else if (temp_params->children.at(0)->symbol == TOK_CHAR)
	    {
	      sym_param->attributes.set(ATTR_char);
	      temp_params->children.at(0)->attributes.set(ATTR_char);
	      temp_params->children.back()->attributes.set(ATTR_char);
	    }
	  else if (temp_params->children.at(0)->symbol == TOK_INT)
	    {
	      sym_param->attributes.set(ATTR_int);
	      temp_params->children.at(0)->attributes.set(ATTR_int);
	      temp_params->children.back()->attributes.set(ATTR_int);
	    }
	  else if (temp_params->children.at(0)->symbol == TOK_STRING)
	    { 
	      sym_param->attributes.set(ATTR_string);
	      temp_params->children.at(0)->attributes.set(ATTR_string);
	      temp_params->children.back()->attributes.set(ATTR_string);
	    }
	  else if (temp_params->children.at(0)->symbol == TOK_TYPEID)
	    {
	      sym_param->attributes.set(ATTR_struct);
	      temp_params->children.at(0)->attributes.set(ATTR_struct);
	      temp_params->children.back()->attributes.set(ATTR_struct);
	      temp_params->children.back()->type = (string *)temp_params->children.at(0)->lexinfo;
	      temp_params->children.at(0)->type = (string *)temp_params->children.at(0)->lexinfo;
	      sym_param->type_id = (string *)temp_params->children.at(0)->lexinfo;
	    }
	}
      else if (temp_params->symbol == TOK_BOOL)
	{
	  sym_param->attributes.set(ATTR_bool);
	  temp_params->attributes.set(ATTR_bool);
	  temp_params->children.back()->attributes.set(ATTR_bool);
	}
      else if (temp_params->symbol == TOK_CHAR)
	{
	  sym_param->attributes.set(ATTR_char);
	  temp_params->attributes.set(ATTR_char);
	  temp_params->children.back()->attributes.set(ATTR_char);
	}
      else if (temp_params->symbol == TOK_INT)
	{
	  sym_param->attributes.set(ATTR_int);
	  temp_params->attributes.set(ATTR_int);
	  temp_params->children.back()->attributes.set(ATTR_int);
	}
      else if (temp_params->symbol == TOK_STRING)
	{ 
	  sym_param->attributes.set(ATTR_string);
	  temp_params->attributes.set(ATTR_string);
	  temp_params->children.back()->attributes.set(ATTR_string);
	}
      else if (temp_params->symbol == TOK_TYPEID)
	{
	  sym_param->attributes.set(ATTR_struct);
	  temp_params->attributes.set(ATTR_struct);
	  temp_params->children.back()->attributes.set(ATTR_struct);
	  temp_params->children.back()->type = (string *)temp_params->lexinfo;
	  temp_params->type = (string *)temp_params->lexinfo;
	  sym_param->type_id = (string *)temp_params->lexinfo;
	}
      sym_param->fields = NULL;
      sym_param->parameters = NULL;
      sym_param->lloc.blocknr = block_depth;
      temp_params->lloc.blocknr = block_depth;
      temp_params->children.at(0)->lloc.blocknr = block_depth;
      temp_params->children.back()->lloc.blocknr = block_depth;
      sym_param->lloc.filenr = temp_params->lloc.filenr;
      sym_param->lloc.linenr = temp_params->lloc.linenr;
      sym_param->lloc.offset = temp_params->lloc.offset;
      temp_sym->parameters->push_back(sym_param);
    }
  symbol_stack.back()->insert ({tree->children.at(0)->children.back()->lexinfo, temp_sym});
  tree->children.at(2)->lloc.blocknr = getCurrentBloc();
  symbolStackPush();
  for(u_int i = 0; i < tree->children.at(1)->children.size(); i++) {
    if (symbol_stack.back() == NULL)
      {
	symbol_table* diff_table = new symbol_table;
	symbol_stack.back() = diff_table;
      }
    symbol* sym_param = (symbol*)malloc(sizeof(struct symbol));
    astree* temp_params = tree->children.at(1)->children.at(i);
    sym_param->fields = NULL;
    sym_param->parameters = NULL;
    sym_param->attributes = temp_params->attributes;
    sym_param->attributes.set(ATTR_lval);
    sym_param->attributes.set(ATTR_variable);
    sym_param->attributes.set(ATTR_param);
    if (temp_params->symbol == TOK_ARRAY)
      { 
	sym_param->attributes.set(ATTR_array);
	if (temp_params->children.at(0)->symbol == TOK_BOOL)
	  {
	    sym_param->attributes.set(ATTR_bool);
	  }
	else if (temp_params->children.at(0)->symbol == TOK_CHAR)
	  {
	    sym_param->attributes.set(ATTR_char);
	  }
	else if (temp_params->children.at(0)->symbol == TOK_INT)
	  {
	    sym_param->attributes.set(ATTR_int);
	  }
	else if (temp_params->children.at(0)->symbol == TOK_STRING)
	  { 
	    sym_param->attributes.set(ATTR_string);
	  }
	else if (temp_params->children.at(0)->symbol == TOK_TYPEID)
	  {
	    sym_param->attributes.set(ATTR_struct);
	    sym_param->type_id = (string *)temp_params->children.at(0)->lexinfo;
	  }
      }
    else if (temp_params->symbol == TOK_BOOL)
      {
	sym_param->attributes.set(ATTR_bool);
      }
    else if (temp_params->symbol == TOK_CHAR)
      {
	sym_param->attributes.set(ATTR_char);
      }
    else if (temp_params->symbol == TOK_INT)
      {
	sym_param->attributes.set(ATTR_int);
      }
    else if (temp_params->symbol == TOK_STRING)
      { 
	sym_param->attributes.set(ATTR_string);
      }
    else if (temp_params->symbol == TOK_VOID)
      { 
	sym_param->attributes.set(ATTR_void);
      }
    else if (temp_params->symbol == TOK_TYPEID)
      {
	sym_param->attributes.set(ATTR_struct);
	sym_param->type_id = (string *)temp_params->lexinfo;
      }
    sym_param->lloc.blocknr = block_depth;
    sym_param->lloc.filenr = temp_params->lloc.filenr;
    sym_param->lloc.linenr = temp_params->lloc.linenr;
    sym_param->lloc.offset = temp_params->lloc.offset;
    symbol_stack.back()->insert ({temp_params->children.back()->lexinfo, sym_param});
    for(int n = 0; n < indent; n++){
      fprintf(sym_file, "   ");
    }
    
    fprintf(sym_file, "%s (%zu.%zu.%zu) {%d} ",
	    temp_params->children.back()->lexinfo->c_str(),
	    sym_param->lloc.filenr, sym_param->lloc.linenr,
	    sym_param->lloc.offset, block_stack.back());
    print_attrs (sym_file, sym_param->attributes,
		 sym_param->type_id, NULL);
    fprintf(sym_file, "\n");
  }
  fprintf(sym_file, "\n");
  return 1;
}

symbol* getInfo (const string* ident)
{
  int i = (symbol_stack.size() - 1);
  for(; i >= 0; i--)
    {
      if(symbol_stack.at(i) == NULL) 
	{
	  continue;
	}
      auto table_check = symbol_stack.at(i)->find(ident);
      if(table_check != symbol_stack.at(i)->end())
	{
	  return table_check->second;
	}
    }
  fprintf(stderr, "oc: no %s found\n", ident->c_str());
  return NULL;
}

symbol* grabFunctionSymbol (astree* tree)
{
  if(symbol_stack.at(0) == NULL) {
    return NULL;
  }
  auto table_check = symbol_stack.at(0)->find(tree->lexinfo);
  if(table_check != symbol_stack.at(0)->end())
    {
      return table_check->second;
    }
  fprintf(stderr, "oc: %s function does not exist\n", tree->lexinfo->c_str());
  return NULL;
}

symbol* grabStructSymbol (const string* ident)
{
  auto table_check = table.find(ident);
  if(table_check != table.end())
    {
      return table_check->second;
    }
  fprintf(stderr, "oc: %s struct does not exist\n", ident->c_str());
  return NULL;
}

symbol* intern_typeTable (astree* tree) 
{
  symbol* temp_sym = (symbol*)malloc(sizeof(struct symbol));
  temp_sym->fields = NULL;
  temp_sym->parameters = NULL;
  temp_sym->attributes = ATTR_struct;
  temp_sym->lloc.blocknr = 0;
  temp_sym->lloc.filenr = tree->lloc.filenr;
  temp_sym->lloc.linenr = tree->lloc.linenr;
  temp_sym->lloc.offset = tree->lloc.offset;
  temp_sym->initialize = 0;
  table.insert ({tree->children.at(0)->lexinfo, temp_sym});
  return temp_sym;
}

symbol* find_typeTable (const string* key) {
  auto found = table.find(key);
  if (found == table.end())
    {
      return NULL;
    } 
  else 
    {
      return found->second;
    }
}

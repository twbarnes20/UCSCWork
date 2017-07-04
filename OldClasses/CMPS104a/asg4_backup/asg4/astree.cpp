// $Id: astree.cpp,v 1.8 2016-09-21 17:13:03-07 - - $

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"
#include "symbol_table.h"

astree::astree (int symbol_, const location& lloc_, const char* info){
   symbol = symbol_;
   lloc = lloc_;
   lexinfo = string_set::intern (info);
   // vector defaults to empty -- no children
}

astree::~astree() {
   while (not children.empty()) {
      astree* child = children.back();
      children.pop_back();
      delete child;
   }
   if (yydebug) {
      fprintf (stderr, "Deleting astree (");
      astree::dump (stderr, this);
      fprintf (stderr, ")\n");
   }
}

astree* astree::adopt (astree* child1, astree* child2, astree* child3) {
   if (child1 != nullptr) children.push_back (child1);
   if (child2 != nullptr) children.push_back (child2);
   if (child3 != nullptr) children.push_back (child3);
   return this;
}

astree* astree::adopt_sym (astree* child, int symbol_) {
   symbol = symbol_;
   return adopt (child);
}

astree* astree::change_sym (int symbol_) {
   symbol = symbol_;
   return this; 
}


void astree::dump_node (FILE* outfile) {
   fprintf (outfile, "%p->{%s %zd.%zd.%zd \"%s\":",
            this, parser::get_tname (symbol),
            lloc.filenr, lloc.linenr, lloc.offset,
            lexinfo->c_str());
   for (size_t child = 0; child < children.size(); ++child) {
      fprintf (outfile, " %p", children.at(child));
   }
}

void astree::dump_tree (FILE* outfile, int depth) {
   fprintf (outfile, "%*s", depth * 3, "");
   dump_node (outfile);
   fprintf (outfile, "\n");
   for (astree* child: children) child->dump_tree (outfile, depth + 1);
   fflush (NULL);
}

void astree::dump (FILE* outfile, astree* tree) {
   if (tree == nullptr) fprintf (outfile, "nullptr");
                   else tree->dump_node (outfile);
}

void astree::print (FILE* outfile, astree* tree, int depth) {
   fprintf (outfile, "; %*s", depth * 3, "");
   
   fprintf (outfile, "%s \"%s\" (%zd.%zd.%zd) {%d} ",
            parser::get_tname (tree->symbol), tree->lexinfo->c_str(),
            tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset, 
	    tree->lloc.blocknr);
   print_attrs(outfile, tree->attributes, tree->type, NULL);
   fprintf(outfile," \n");
   for (astree* child: tree->children) {
      astree::print (outfile, child, depth + 1);
   }
}

void destroy (astree* tree1, astree* tree2) {
   if (tree1 != nullptr) delete tree1;
   if (tree2 != nullptr) delete tree2;
}

void errllocprintf (const location& lloc, const char* format,
                    const char* arg) {
   static char buffer[0x1000];
   assert (sizeof buffer > strlen (format) + strlen (arg));
   snprintf (buffer, sizeof buffer, format, arg);
   errprintf ("%s:%zd.%zd: %s", 
              lexer::filename (lloc.filenr), lloc.linenr, lloc.offset,
              buffer);
}

static void print_attr(FILE *out, string attr, string *extra)
{
  fprintf(out, "%s ", attr.c_str());
  if (attr == "field" && nullptr != extra)
    {
      fprintf(out, "{%s} ", extra->c_str());
    }
  else if (attr == "struct" && nullptr != extra)
    {
      fprintf(out, "\"%s\" ", extra->c_str());
    }
   
}

void print_attrs (FILE *out, attr_bitset attributes, string *type, string *fieldof)
{
  std::map<Attrs, std::string> attr_str_map;
  attr_str_map[ATTR_void]     = "void";
  attr_str_map[ATTR_bool]     = "bool";
  attr_str_map[ATTR_char]     = "char";
  attr_str_map[ATTR_int]      = "int";
  attr_str_map[ATTR_null]     = "null";
  attr_str_map[ATTR_string]   = "string";
  attr_str_map[ATTR_struct]   = "struct";
  attr_str_map[ATTR_array]    = "array";
  attr_str_map[ATTR_function] = "function";
  attr_str_map[ATTR_variable] = "variable";
  attr_str_map[ATTR_field]    = "field";
  attr_str_map[ATTR_typeid]   = "typeid";
  attr_str_map[ATTR_param]    = "param";
  attr_str_map[ATTR_lval]     = "lval";
  attr_str_map[ATTR_const]    = "const";
  attr_str_map[ATTR_vreg]     = "vreg";
  attr_str_map[ATTR_vaddr]    = "vaddr";            

  for (size_t i = 0; i < attributes.size(); ++i)
    {
      if (attributes.test(i))
        {
          Attrs attri = static_cast<Attrs>(i);
          string *extra = nullptr;
          if (ATTR_struct == i) { extra = type; }
          else if (ATTR_field == i) { extra = fieldof; }
          print_attr(out, attr_str_map[attri], extra);
        }
    }
}

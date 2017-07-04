// $Id: astree.h,v 1.7 2016-10-06 16:13:39-07 - - $

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include <bitset>

#include "auxlib.h"
#include "attrs.h"

using namespace std;

struct symbol;
using attr_bitset = bitset<ATTR_bitset_size>;

struct astree {

   // Fields.
   int symbol;               // token code
   location lloc;            // source location
   location dec_loc;         // keeps track of declation location
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
   struct symbol* table_node;
   attr_bitset attribs;
   string* type;
   int printdecs;

   // Functions.
   astree (int symbol,const location&, const char* lexinfo);
   ~astree();
   astree* adopt (astree* child1, astree* child2 = nullptr, astree* child3 = nullptr);
   astree* adopt_sym (astree* child, int symbol);
   astree* change_sym (int symbol_);
   void dump_node (FILE*);
   void dump_tree (FILE*, int depth = 0);
   static void dump (FILE* outfile, astree* tree);
   static void print (FILE* outfile, astree* tree, int depth = 0);
};


void print_attributes (FILE *out, attr_bitset attribs,string *type, string *fieldof);

void destroy (astree* tree1, astree* tree2 = nullptr);

void errllocprintf (const location&, const char* format, const char*);

#endif


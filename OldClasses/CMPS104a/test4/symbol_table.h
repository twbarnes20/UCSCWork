#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <bitset>
#include <string>
#include <vector>

#include "attrs.h"

using namespace std;

struct symbol;
struct astree;

using attr_bitset = bitset<ATTR_bitset_size>;

using symbol_table = unordered_map<const string*, symbol*>;
using symbol_entry = symbol_table::value_type;

struct symbol{
  location lloc;
  attr_bitset attribs;
  symbol_table* fields;
  size_t filenr;
  size_t linenr;
  size_t offset;
  size_t blocknr;
  string* type_id;
  int initialize;
  vector<symbol*>* parameters;
};

int current_block();

void delete_table_info (astree* tree);

symbol* hold_table (astree* tree);

symbol* locate_table (const string* key);

void symbol_create ();

void symbol_push ();

void symbol_pop ();

void symbol_vardecl (astree* tree, FILE* fd_sym);

void symbol_prototype (astree* tree, FILE* fd_sym);

int symbol_function (astree* tree, FILE* fd_sym);

symbol* get_info(const string* ident);

symbol* get_funcsymbol (astree* tree);

symbol* get_structsymbol (const string* ident);
#endif

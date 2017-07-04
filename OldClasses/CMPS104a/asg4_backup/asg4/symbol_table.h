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
  attr_bitset attributes;
  symbol_table* fields;
  size_t filenr;
  size_t linenr;
  size_t offset;
  size_t blocknr;
  string* type_id;
  int initialize;
  vector<symbol*>* parameters;
};

//Change
int getCurrentBloc();

void myFunctionToDoThatThing (astree* tree);

symbol* intern_typeTable (astree* tree);

symbol* find_typeTable (const string* key);

void symbolStackInit ();

void symbolStackPush ();

void symbolStackPop ();

void symbolStackAddVardecl (astree* tree, FILE* sym_file);

void symbolStackAddPrototype (astree* tree, FILE* sym_file);

int symbolStackAddFunction (astree* tree, FILE* sym_file);

symbol* getInfo(const string* ident);

symbol* grabFunctionSymbol (astree* tree);

symbol* grabStructSymbol (const string* ident);
#endif

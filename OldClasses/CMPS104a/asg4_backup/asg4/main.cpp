// $Id: main.cpp,v 1.2 2016-08-18 15:13:48-07 - - $
//Trevor Barnes
 
#include <string>
using namespace std;

#include <iostream>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

#include "auxlib.h"
#include "string_set.h"
#include "astree.h"
#include "lyutils.h"
#include "postorder_dfs.h"

constexpr size_t LINESIZE = 1024;
FILE* fd_tok;
extern FILE* sym_file = NULL;

int main (int argc, char** argv) {
  
  int option = 0;
  const string cpp = "/opt/rh/devtoolset-4/root/usr/bin/cpp";
  int yy_flex_debug = 0;
  int yydebug = 0;
  (void) yy_flex_debug;
  (void) yydebug;
  string cpp_args = "";
  string_set token_set;

  while((option = getopt(argc, argv, "ly@:D:")) != 1){
    if(option == EOF){
      break;
    }
    switch(option){
    case '@':{
      set_debugflags (optarg);
      break;
    }
    case 'D':{
      string D_arg = optarg;
      cpp_args = "-D " + D_arg;
      break;
    }
    case 'l':{
      yy_flex_debug = 1;
      break;
    }
    case 'y':{
      yydebug = 1;
      break;
    }
    default: break;
    }
  }
    
  if (optind >= argc){
    fprintf(stderr, "Missing input file\n");
    return EXIT_FAILURE;
  }

  string file = argv[optind];
  string combined = cpp + " " + cpp_args + " " + file;

  yyin = popen (combined.c_str(), "r");
 
  if(NULL == yyin){
    fprintf(stderr, "Pipe could not be opened\n");
    return EXIT_FAILURE; 
  }   
  string str_base = file.substr(0, file.find("."));
  string tok_base = file.substr(0, file.find("."));
  string ast_base = file.substr(0, file.find("."));
  string sym_base = file.substr(0, file.find("."));
    
  string str_name = str_base.append(".str");
  string tok_name = tok_base.append(".tok");
  string ast_name = ast_base.append(".ast"); 
  string sym_name = sym_base.append(".sym");
  
  FILE* fd_str = fopen(str_name.c_str(), "w");
  fd_tok = fopen(tok_name.c_str(), "w"); 
  FILE* fd_ast = fopen(ast_name.c_str(), "w");  
  sym_file = fopen(sym_base.c_str(), "w");

  yyparse();
  dfsTraversal(parser::root);
  parser::root -> print(fd_ast, parser::root, 0); 
  pclose(yyin);
 
  yyin = NULL;
  
  yyin = popen (combined.c_str(), "r");
  
  if(NULL == yyin){
    fprintf(stderr, "Pipe could not be opened\n");
    return EXIT_FAILURE; 
  }
    
  for(;;){
    char buffer[LINESIZE];
    char* fgets_rc = fgets(buffer, LINESIZE, yyin);
      
    if (fgets_rc == NULL){
      break; 
    }
      
    char* savepos = NULL;
    char* bufptr = buffer;
    for (int tokenct = 1 ; ; ++tokenct){
      char* token = strtok_r (bufptr, " \t\n", &savepos);
      bufptr = NULL;
      if (token == NULL) break;
      token_set.intern(token);
    }
      
    token_set.dump(fd_str); 
    
  }
  
  pclose(yyin);
  fclose(fd_str);
  fclose(fd_tok);
  fclose(fd_ast);
  fclose(sym_file);
  
  return 0;
}

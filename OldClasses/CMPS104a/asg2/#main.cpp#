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

constexpr size_t LINESIZE = 1024;
FILE* fd_tok;

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
  string str_base = file.substr(0, file.find("."));
  string tok_base = file.substr(0, file.find("."));
  string str_str = str_base.append(".str");
  string tok_str = tok_base.append(".tok");

  string combined = cpp + " " + cpp_args + " " + file;

  yyin = popen (combined.c_str(), "r");
 
  if(NULL == yyin){
    fprintf(stderr, "Pipe could not be opened\n");
    return EXIT_FAILURE; 
  }  
  else{
    fd_tok = fopen(tok_base.c_str(), "w");
    
    int count;

    for(count = yylex(); count != 0; count = yylex()){}
  }
  fclose(fd_tok);
  
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
  }
  FILE* fd = fopen(str_str.c_str(), "w");
  token_set.dump(fd);
  pclose(yyin); 
}


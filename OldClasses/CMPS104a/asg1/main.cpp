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

constexpr size_t LINESIZE = 1024;

int main (int argc, char** argv) {
  
  int option = 0;
  const string cpp = "/opt/rh/devtoolset-4/root/usr/bin/cpp";
  int yy_flex_debug = 0;
  int yydebug = 0;
  (void) yy_flex_debug;
  (void) yydebug;
  string cpp_args = "";
  FILE* pipe_in = NULL;
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
  string base = file.substr(0, file.find("."));
  base.append(".str");

  string combined = cpp + " " + cpp_args + " " + file;
  cout<<combined<<"\n";

  pipe_in = popen (combined.c_str(), "r");

  if(NULL == pipe_in){
    fprintf(stderr, "Pipe could not be opened\n");
    return EXIT_FAILURE;
  }

  for(;;){
    char buffer[LINESIZE];
    char* fgets_rc = fgets(buffer, LINESIZE, pipe_in);

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
  FILE* fd = fopen(base.c_str(), "w");
  token_set.dump(fd);
}


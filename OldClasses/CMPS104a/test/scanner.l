%{

#include "lyutils.h"
#include "auxlib.h"

#define YY_USER_ACTION {lexer::advance();}

%}

%option 8bit
%option debug
%option nodefault
%option nounput
%option noyywrap
%option verbose
%option warn

LETTER                  [A-Za-z_]
DIGIT                   [0-9]
INT_CONST               ([0-9]+)
IDENT                   ({LETTER}({LETTER}|{DIGIT})*)
INVALID_IDENT           ({DIGIT}({LETTER}|{DIGIT})*)
CHAR                    [^\\"\n]
ESC_CHAR                (\\[\\'"0nt])
INVALID_ESC             (\\[^\\'"0nt]?)
CHAR_CONST              ('({CHAR}|{ESC_CHAR})')
INVALID_CHARCONST       ('({CHAR}|{ESC_CHAR}|{INVALID_ESC})?'?)
STRING_CONST            (\"({CHAR}|{ESC_CHAR})*\")
INVALID_STRING          (\"({CHAR}|{ESC_CHAR}|{INVALID_ESC})*\"?)

%%

"#".*                   {lexer::include();}
[ \t]+                  {}
\n                      {lexer::newline();}

"char"                  {return yylval_token (TOK_CHAR);}
"else"                  {return yylval_token (TOK_ELSE);}
"if"                    {return yylval_token (TOK_IF);}
"int"                   {return yylval_token (TOK_INT);}
"new"                   {return yylval_token (TOK_NEW);}
"null"                  {return yylval_token (TOK_NULL);}
"return"                {return yylval_token (TOK_RETURN);}
"string"                {return yylval_token (TOK_STRING);}
"struct"                {return yylval_token (TOK_STRUCT);}
"void"                  {return yylval_token (TOK_VOID);}
"while"                 {return yylval_token (TOK_WHILE);}
"ord"                   {return yylval_token (TOK_ORD);}
"chr"                   {return yylval_token (TOK_CHAR);}
"[]"                    {return yylval_token (TOK_NEWARRAY);}
"="                     {return yylval_token ('=');}
"=="                    {return yylval_token (TOK_EQ);}
"!="                    {return yylval_token (TOK_NE);}
"!"                     {return yylval_token ('!');}
"<"                     {return yylval_token (TOK_LT);}
"<="                    {return yylval_token (TOK_LE);}
">"                     {return yylval_token (TOK_GT);}
">="                    {return yylval_token (TOK_GE);}
"{"                     {return yylval_token ('{');}
"}"                     {return yylval_token ('}');}
"("                     {return yylval_token ('(');}
")"                     {return yylval_token (')');}
"["                     {return yylval_token ('[');}
"]"                     {return yylval_token (']');}
","                     {return yylval_token (',');}
"."                     {return yylval_token ('.');}
";"                     {return yylval_token (';');}
"+"                     {return yylval_token ('+');}
"-"                     {return yylval_token ('-');}
"*"                     {return yylval_token ('*');}
"%"                     {return yylval_token ('%');}
"/"                     {return yylval_token ('/');}

{IDENT}                 {return yylval_token (TOK_IDENT);}
{INT_CONST}             {return yylval_token (TOK_INTCON);}       
{CHAR_CONST}            {return yylval_token (TOK_CHARCON);}
{STRING_CONST}          {return yylval_token (TOK_STRINGCON);}

{INVALID_IDENT}         {lexer::badtoken(yytext); 
                         return yylval_token(TOK_IDENT);}
{INVALID_CHARCONST}     {lexer::badtoken(yytext);
                         return yylval_token(TOK_CHARCON);}
{INVALID_STRING}        {lexer::badtoken(yytext);
                         return yylval_token(TOK_STRINGCON);}
.                       {lexer::badchar(*yytext);}

%%


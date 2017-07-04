/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_ELSE = 258,
     TOK_IF = 259,
     TOK_INT = 260,
     TOK_NEW = 261,
     TOK_NULL = 262,
     TOK_RETURN = 263,
     TOK_STRING = 264,
     TOK_STRUCT = 265,
     TOK_VOID = 266,
     TOK_WHILE = 267,
     TOK_ORD = 268,
     TOK_ARRAY = 269,
     TOK_EQ = 270,
     TOK__NE = 271,
     TOK_LT = 272,
     TOK_GT = 273,
     TOK_GE = 274,
     TOK_NEWARRAY = 275,
     TOK_IDENT = 276,
     TOK_INTCON = 277,
     TOK_CHARCON = 278,
     TOK_STRINGCON = 279,
     TOK_ROOT = 280,
     TOK_DECLID = 281,
     TOK_TYPEID = 282,
     TOK_FIELD = 283,
     TOK_NEWARRY = 284,
     TOK_NEWSTRING = 285,
     TOK_RETURNVOID = 286,
     TOK_VARDECL = 287,
     TOK_FUNCTION = 288,
     TOK_PARAMLIST = 289,
     TOK_PROTOTYPE = 290,
     TOK_BLOCK = 291,
     TOK_IFELSE = 292,
     TOK_INDEX = 293,
     TOK_INITDECL = 294,
     TOK_POS = 295,
     TOK_NEG = 296,
     TOK_TRUE = 297,
     TOK_FALSE = 298,
     TOK_CALL = 299,
     TOK_CHR = 300,
     TOK_LE = 301,
     TOK_NE = 302
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

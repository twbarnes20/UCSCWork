/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"


#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <cstdio>

#include "astree.h"
#include "lyutils.h"


/* Line 371 of yacc.c  */
#line 80 "yyparse.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 193 "yyparse.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   547

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    53,     2,     2,
      59,    58,    51,    49,    60,    50,    64,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    55,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      28,    31,    34,    38,    44,    48,    50,    52,    54,    56,
      61,    66,    68,    72,    75,    78,    80,    83,    87,    90,
      92,    94,    96,    98,   100,   102,   104,   107,   112,   118,
     126,   132,   135,   139,   143,   147,   151,   155,   159,   163,
     167,   171,   175,   179,   183,   187,   191,   194,   197,   200,
     202,   204,   208,   210,   212,   217,   223,   229,   233,   236,
     240,   244,   246,   251,   255,   257,   259,   261,   263,   265
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    67,    68,    -1,    67,    72,
      -1,    67,    78,    -1,    67,     1,    55,    -1,    67,     1,
      56,    -1,    -1,    10,    21,    57,    55,    -1,    70,    55,
      -1,    71,    21,    -1,    71,    14,    21,    -1,    10,    21,
      57,    69,    56,    -1,    70,    69,    56,    -1,    21,    -1,
       5,    -1,     9,    -1,    11,    -1,    76,    73,    58,    74,
      -1,    76,    73,    58,    56,    -1,    59,    -1,    73,    60,
      76,    -1,    73,    76,    -1,    75,    55,    -1,    57,    -1,
      75,    78,    -1,    71,    14,    21,    -1,    71,    21,    -1,
      74,    -1,    56,    -1,    77,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    56,    -1,    76,    46,    83,
      56,    -1,    12,    59,    83,    58,    78,    -1,     4,    59,
      83,    58,    78,     3,    78,    -1,     4,    59,    83,    58,
      78,    -1,     8,    56,    -1,     8,    83,    56,    -1,    83,
      46,    83,    -1,    83,    15,    83,    -1,    83,    17,    83,
      -1,    83,    47,    83,    -1,    83,    18,    83,    -1,    83,
      19,    83,    -1,    83,    48,    83,    -1,    83,    49,    83,
      -1,    83,    50,    83,    -1,    83,    51,    83,    -1,    83,
      52,    83,    -1,    83,    61,    83,    -1,    83,    53,    83,
      -1,    54,    83,    -1,    49,    83,    -1,    50,    83,    -1,
      84,    -1,    85,    -1,    59,    83,    58,    -1,    87,    -1,
      88,    -1,     6,    21,    59,    58,    -1,     6,     9,    59,
      83,    58,    -1,     6,    71,    62,    83,    63,    -1,    21,
      59,    58,    -1,    86,    58,    -1,    21,    59,    83,    -1,
      86,    60,    83,    -1,    21,    -1,    83,    62,    83,    63,
      -1,    83,    64,    21,    -1,    22,    -1,    23,    -1,    24,
      -1,    42,    -1,    43,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    54,    55,    56,    57,    59,    61,    64,
      67,    71,    74,    78,    82,    86,    87,    88,    89,    92,
      96,   102,   103,   105,   108,   112,   113,   116,   119,   123,
     124,   127,   128,   129,   130,   131,   132,   136,   141,   146,
     151,   156,   158,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   182,   183,   186,   189,   193,   199,   202,   206,
     208,   212,   213,   216,   220,   221,   222,   223,   224,   225
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ELSE", "TOK_IF", "TOK_INT",
  "TOK_NEW", "TOK_NULL", "TOK_RETURN", "TOK_STRING", "TOK_STRUCT",
  "TOK_VOID", "TOK_WHILE", "TOK_ORD", "TOK_ARRAY", "TOK_EQ", "TOK__NE",
  "TOK_LT", "TOK_GT", "TOK_GE", "TOK_NEWARRAY", "TOK_IDENT", "TOK_INTCON",
  "TOK_CHARCON", "TOK_STRINGCON", "TOK_ROOT", "TOK_DECLID", "TOK_TYPEID",
  "TOK_FIELD", "TOK_NEWARRY", "TOK_NEWSTRING", "TOK_RETURNVOID",
  "TOK_VARDECL", "TOK_FUNCTION", "TOK_PARAMLIST", "TOK_PROTOTYPE",
  "TOK_BLOCK", "TOK_IFELSE", "TOK_INDEX", "TOK_INITDECL", "TOK_POS",
  "TOK_NEG", "TOK_TRUE", "TOK_FALSE", "TOK_CALL", "TOK_CHR", "'='",
  "TOK_LE", "TOK_NE", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'}'",
  "';'", "'{'", "')'", "'('", "','", "'^'", "'['", "']'", "'.'", "$accept",
  "start", "program", "structdef", "fielddecl", "structdec", "basetype",
  "function", "parameter", "blocklist", "funcblock", "identdecl", "block",
  "statement", "vardecl", "while", "ifelse", "return", "expr", "allocator",
  "call", "call_args", "variable", "constant", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    61,   301,   302,    43,
      45,    42,    47,    37,    33,   125,    59,   123,    41,    40,
      44,    94,    91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    73,    73,    73,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    78,    78,    79,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     4,
       2,     2,     3,     5,     3,     1,     1,     1,     1,     4,
       4,     1,     3,     2,     2,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     5,     7,
       5,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     1,
       1,     3,     1,     1,     4,     5,     5,     3,     2,     3,
       3,     1,     4,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,     0,    16,     0,    79,     0,
      17,     0,    18,     0,    71,    74,    75,    76,    77,    78,
       0,     0,     0,    30,    25,     0,     3,     0,     0,     4,
      29,     0,     0,    31,     5,    32,    33,    34,    35,     0,
      59,    60,     0,    62,    63,     6,     7,     0,    17,    15,
       0,    71,    41,     0,     0,     0,     0,    57,    58,    56,
       0,    15,    10,     0,     0,     0,    28,    24,     0,    26,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,    68,
       0,     0,     0,     0,     0,    42,     0,     0,    67,    69,
      61,    14,     0,    11,    27,     0,     0,     0,    23,    44,
      45,    47,    48,    43,    46,    49,    50,    51,    52,    53,
      55,    54,     0,    73,    70,     0,     0,    64,     0,     9,
       0,     0,    12,    37,    20,    19,    22,    72,    40,    65,
      66,    13,    38,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    26,    63,    27,    28,    29,    72,    30,
      31,    68,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -54
static const yytype_int16 yypact[] =
{
     -54,    31,   109,   -54,   -47,   -22,   -54,    87,   -54,    -3,
     -54,    24,   -54,   -11,    15,   -54,   -54,   -54,   -54,   -54,
     234,   234,   234,   -54,   -54,   234,   -54,     6,    -8,   -54,
     -54,   132,   -16,   -54,   -54,   -54,   -54,   -54,   -54,   249,
     -54,   -54,   -53,   -54,   -54,   -54,   -54,   234,   -10,    -7,
      -2,    -4,   -54,   272,     0,   234,   211,   -29,   -29,   -29,
     297,   -54,   -54,     8,    20,    41,   -54,   -54,    22,   -54,
     234,   -54,     5,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   -54,   234,   234,    48,   -54,
     234,   320,   234,    12,   234,   -54,    33,   345,   -54,   483,
     -54,   -54,    51,   -54,   -54,   368,    10,   162,   -54,   152,
     152,   152,   152,   483,   152,   152,   397,   397,   -29,   -29,
     -29,   483,   393,   -54,   483,   188,   416,   -54,   464,   -54,
      19,   188,   -54,   -54,   -54,   -54,   -54,   -54,    96,   -54,
     -54,   -54,   -54,   188,   -54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,   -54,   -54,     7,   -54,    -5,   -54,   -54,     1,
     -54,    -1,   -54,   -31,   -54,   -54,   -54,   -54,     3,   -54,
     -54,   -54,   -54,   -54
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -16
static const yytype_int16 yytable[] =
{
      69,    32,    50,     7,     8,    89,    65,    90,    45,    46,
       6,     6,    53,    66,    10,    10,    12,    12,    51,    15,
      16,    17,    64,    57,    58,    59,    61,    61,    60,   -15,
      70,     3,    86,    87,   102,    88,   -15,    47,     6,    18,
      19,   103,    10,    71,    12,    54,    20,    21,    55,    92,
      91,    22,    93,    52,    61,    56,    25,    96,    97,    99,
      94,    62,   104,   106,   101,   107,   134,    24,    70,   123,
     127,   108,   132,   105,    56,   141,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   129,   121,
     122,    64,     6,   124,   138,   126,    48,   128,    12,   143,
     142,     0,     0,   130,     0,     0,   136,   135,    49,    -2,
       4,     0,   144,     5,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,    16,    17,     0,     0,     5,     6,     7,     8,
       9,    10,     0,    12,    13,     0,     0,     0,     0,     0,
       0,    18,    19,    14,    15,    16,    17,     0,    20,    21,
       0,     0,     0,    22,     0,    23,    24,     6,    25,     0,
       0,    10,     0,    12,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    61,     0,     0,    22,    67,    23,    24,
       0,    25,     5,     6,     7,     8,     9,    10,     0,    12,
      13,    80,    81,    82,    83,    84,     0,     0,     0,    14,
      15,    16,    17,    86,    87,     0,    88,     7,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    51,    15,    16,    17,     0,    20,    21,     0,
       7,     8,    22,     0,    23,    24,     0,    25,     0,     0,
       0,     0,     0,    18,    19,    51,    15,    16,    17,     0,
      20,    21,     0,     0,    73,    22,    74,    75,    76,    98,
      25,     0,     0,     0,     0,     0,    18,    19,     0,     0,
       0,     0,     0,    20,    21,     0,     0,    73,    22,    74,
      75,    76,     0,    25,     0,    77,    78,    79,    80,    81,
      82,    83,    84,     0,     0,    85,     0,     0,     0,     0,
      86,    87,    73,    88,    74,    75,    76,     0,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,    95,     0,
       0,     0,     0,    86,    87,    73,    88,    74,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,   100,     0,     0,    86,    87,
      73,    88,    74,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,   125,     0,
       0,    86,    87,    73,    88,    74,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,   131,     0,     0,    86,    87,    73,    88,
      74,    75,    76,     0,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,   133,     0,     0,     0,     0,    86,
      87,    73,    88,    74,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    82,    83,
      84,     0,     0,     0,    86,    87,   137,    88,    86,    87,
       0,    88,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,   139,     0,     0,    86,    87,    73,
      88,    74,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
      74,    75,    76,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,    86,    87,   140,    88,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,    86,    87,     0,    88
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      31,     2,     7,     6,     7,    58,    14,    60,    55,    56,
       5,     5,     9,    21,     9,     9,    11,    11,    21,    22,
      23,    24,    27,    20,    21,    22,    21,    21,    25,    14,
      46,     0,    61,    62,    14,    64,    21,    59,     5,    42,
      43,    21,     9,    59,    11,    21,    49,    50,    59,    59,
      47,    54,    59,    56,    21,    59,    59,    57,    55,    56,
      62,    55,    21,    58,    56,    60,    56,    57,    46,    21,
      58,    72,    21,    70,    59,    56,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    55,    86,
      87,    96,     5,    90,   125,    92,     9,    94,    11,     3,
     131,    -1,    -1,    96,    -1,    -1,   107,   106,    21,     0,
       1,    -1,   143,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    21,    22,    23,    24,    -1,    49,    50,
      -1,    -1,    -1,    54,    -1,    56,    57,     5,    59,    -1,
      -1,     9,    -1,    11,    42,    43,    -1,    -1,    -1,    -1,
      -1,    49,    50,    21,    -1,    -1,    54,    55,    56,    57,
      -1,    59,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    49,    50,    51,    52,    53,    -1,    -1,    -1,    21,
      22,    23,    24,    61,    62,    -1,    64,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    21,    22,    23,    24,    -1,    49,    50,    -1,
       6,     7,    54,    -1,    56,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    42,    43,    21,    22,    23,    24,    -1,
      49,    50,    -1,    -1,    15,    54,    17,    18,    19,    58,
      59,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    49,    50,    -1,    -1,    15,    54,    17,
      18,    19,    -1,    59,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      61,    62,    15,    64,    17,    18,    19,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    61,    62,    15,    64,    17,    18,    19,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,
      15,    64,    17,    18,    19,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    15,    64,    17,    18,    19,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    15,    64,
      17,    18,    19,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    61,
      62,    15,    64,    17,    18,    19,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    51,    52,
      53,    -1,    -1,    -1,    61,    62,    63,    64,    61,    62,
      -1,    64,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    15,
      64,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,     1,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    21,    22,    23,    24,    42,    43,
      49,    50,    54,    56,    57,    59,    68,    70,    71,    72,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    55,    56,    59,     9,    21,
      71,    21,    56,    83,    21,    59,    59,    83,    83,    83,
      83,    21,    55,    69,    71,    14,    21,    55,    76,    78,
      46,    59,    73,    15,    17,    18,    19,    46,    47,    48,
      49,    50,    51,    52,    53,    56,    61,    62,    64,    58,
      60,    83,    59,    59,    62,    56,    57,    83,    58,    83,
      58,    56,    14,    21,    21,    83,    58,    60,    76,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    21,    83,    58,    83,    58,    83,    55,
      69,    58,    21,    56,    56,    74,    76,    63,    78,    58,
      63,    56,    78,     3,    78
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      case 3: /* TOK_ELSE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 923 "yyparse.cpp"
        break;
      case 4: /* TOK_IF */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 930 "yyparse.cpp"
        break;
      case 5: /* TOK_INT */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 937 "yyparse.cpp"
        break;
      case 6: /* TOK_NEW */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 944 "yyparse.cpp"
        break;
      case 7: /* TOK_NULL */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 951 "yyparse.cpp"
        break;
      case 8: /* TOK_RETURN */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 958 "yyparse.cpp"
        break;
      case 9: /* TOK_STRING */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 965 "yyparse.cpp"
        break;
      case 10: /* TOK_STRUCT */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 972 "yyparse.cpp"
        break;
      case 11: /* TOK_VOID */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 979 "yyparse.cpp"
        break;
      case 12: /* TOK_WHILE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 986 "yyparse.cpp"
        break;
      case 13: /* TOK_ORD */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 993 "yyparse.cpp"
        break;
      case 14: /* TOK_ARRAY */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1000 "yyparse.cpp"
        break;
      case 15: /* TOK_EQ */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1007 "yyparse.cpp"
        break;
      case 16: /* TOK__NE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1014 "yyparse.cpp"
        break;
      case 17: /* TOK_LT */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1021 "yyparse.cpp"
        break;
      case 18: /* TOK_GT */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1028 "yyparse.cpp"
        break;
      case 19: /* TOK_GE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1035 "yyparse.cpp"
        break;
      case 20: /* TOK_NEWARRAY */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1042 "yyparse.cpp"
        break;
      case 21: /* TOK_IDENT */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1049 "yyparse.cpp"
        break;
      case 22: /* TOK_INTCON */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1056 "yyparse.cpp"
        break;
      case 23: /* TOK_CHARCON */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1063 "yyparse.cpp"
        break;
      case 24: /* TOK_STRINGCON */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1070 "yyparse.cpp"
        break;
      case 25: /* TOK_ROOT */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1077 "yyparse.cpp"
        break;
      case 26: /* TOK_DECLID */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1084 "yyparse.cpp"
        break;
      case 27: /* TOK_TYPEID */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1091 "yyparse.cpp"
        break;
      case 28: /* TOK_FIELD */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1098 "yyparse.cpp"
        break;
      case 29: /* TOK_NEWARRY */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1105 "yyparse.cpp"
        break;
      case 30: /* TOK_NEWSTRING */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1112 "yyparse.cpp"
        break;
      case 31: /* TOK_RETURNVOID */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1119 "yyparse.cpp"
        break;
      case 32: /* TOK_VARDECL */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1126 "yyparse.cpp"
        break;
      case 33: /* TOK_FUNCTION */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1133 "yyparse.cpp"
        break;
      case 34: /* TOK_PARAMLIST */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1140 "yyparse.cpp"
        break;
      case 35: /* TOK_PROTOTYPE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1147 "yyparse.cpp"
        break;
      case 36: /* TOK_BLOCK */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1154 "yyparse.cpp"
        break;
      case 37: /* TOK_IFELSE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1161 "yyparse.cpp"
        break;
      case 38: /* TOK_INDEX */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1168 "yyparse.cpp"
        break;
      case 39: /* TOK_INITDECL */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1175 "yyparse.cpp"
        break;
      case 40: /* TOK_POS */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1182 "yyparse.cpp"
        break;
      case 41: /* TOK_NEG */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1189 "yyparse.cpp"
        break;
      case 42: /* TOK_TRUE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1196 "yyparse.cpp"
        break;
      case 43: /* TOK_FALSE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1203 "yyparse.cpp"
        break;
      case 44: /* TOK_CALL */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1210 "yyparse.cpp"
        break;
      case 45: /* TOK_CHR */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1217 "yyparse.cpp"
        break;
      case 46: /* '=' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1224 "yyparse.cpp"
        break;
      case 47: /* TOK_LE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1231 "yyparse.cpp"
        break;
      case 48: /* TOK_NE */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1238 "yyparse.cpp"
        break;
      case 49: /* '+' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1245 "yyparse.cpp"
        break;
      case 50: /* '-' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1252 "yyparse.cpp"
        break;
      case 51: /* '*' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1259 "yyparse.cpp"
        break;
      case 52: /* '/' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1266 "yyparse.cpp"
        break;
      case 53: /* '%' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1273 "yyparse.cpp"
        break;
      case 54: /* '!' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1280 "yyparse.cpp"
        break;
      case 55: /* '}' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1287 "yyparse.cpp"
        break;
      case 56: /* ';' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1294 "yyparse.cpp"
        break;
      case 57: /* '{' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1301 "yyparse.cpp"
        break;
      case 58: /* ')' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1308 "yyparse.cpp"
        break;
      case 59: /* '(' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1315 "yyparse.cpp"
        break;
      case 60: /* ',' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1322 "yyparse.cpp"
        break;
      case 61: /* '^' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1329 "yyparse.cpp"
        break;
      case 62: /* '[' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1336 "yyparse.cpp"
        break;
      case 63: /* ']' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1343 "yyparse.cpp"
        break;
      case 64: /* '.' */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1350 "yyparse.cpp"
        break;
      case 66: /* start */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1357 "yyparse.cpp"
        break;
      case 67: /* program */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1364 "yyparse.cpp"
        break;
      case 68: /* structdef */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1371 "yyparse.cpp"
        break;
      case 69: /* fielddecl */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1378 "yyparse.cpp"
        break;
      case 70: /* structdec */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1385 "yyparse.cpp"
        break;
      case 71: /* basetype */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1392 "yyparse.cpp"
        break;
      case 72: /* function */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1399 "yyparse.cpp"
        break;
      case 73: /* parameter */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1406 "yyparse.cpp"
        break;
      case 74: /* blocklist */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1413 "yyparse.cpp"
        break;
      case 75: /* funcblock */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1420 "yyparse.cpp"
        break;
      case 76: /* identdecl */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1427 "yyparse.cpp"
        break;
      case 77: /* block */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1434 "yyparse.cpp"
        break;
      case 78: /* statement */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1441 "yyparse.cpp"
        break;
      case 79: /* vardecl */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1448 "yyparse.cpp"
        break;
      case 80: /* while */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1455 "yyparse.cpp"
        break;
      case 81: /* ifelse */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1462 "yyparse.cpp"
        break;
      case 82: /* return */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1469 "yyparse.cpp"
        break;
      case 83: /* expr */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1476 "yyparse.cpp"
        break;
      case 84: /* allocator */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1483 "yyparse.cpp"
        break;
      case 85: /* call */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1490 "yyparse.cpp"
        break;
      case 86: /* call_args */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1497 "yyparse.cpp"
        break;
      case 87: /* variable */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1504 "yyparse.cpp"
        break;
      case 88: /* constant */
/* Line 823 of yacc.c  */
#line 20 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1511 "yyparse.cpp"
        break;
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* TOK_ELSE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1912 "yyparse.cpp"
        break;
      case 4: /* TOK_IF */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1919 "yyparse.cpp"
        break;
      case 5: /* TOK_INT */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1926 "yyparse.cpp"
        break;
      case 6: /* TOK_NEW */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1933 "yyparse.cpp"
        break;
      case 7: /* TOK_NULL */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1940 "yyparse.cpp"
        break;
      case 8: /* TOK_RETURN */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1947 "yyparse.cpp"
        break;
      case 9: /* TOK_STRING */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1954 "yyparse.cpp"
        break;
      case 10: /* TOK_STRUCT */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1961 "yyparse.cpp"
        break;
      case 11: /* TOK_VOID */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1968 "yyparse.cpp"
        break;
      case 12: /* TOK_WHILE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1975 "yyparse.cpp"
        break;
      case 13: /* TOK_ORD */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1982 "yyparse.cpp"
        break;
      case 14: /* TOK_ARRAY */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1989 "yyparse.cpp"
        break;
      case 15: /* TOK_EQ */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1996 "yyparse.cpp"
        break;
      case 16: /* TOK__NE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2003 "yyparse.cpp"
        break;
      case 17: /* TOK_LT */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2010 "yyparse.cpp"
        break;
      case 18: /* TOK_GT */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2017 "yyparse.cpp"
        break;
      case 19: /* TOK_GE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2024 "yyparse.cpp"
        break;
      case 20: /* TOK_NEWARRAY */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2031 "yyparse.cpp"
        break;
      case 21: /* TOK_IDENT */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2038 "yyparse.cpp"
        break;
      case 22: /* TOK_INTCON */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2045 "yyparse.cpp"
        break;
      case 23: /* TOK_CHARCON */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2052 "yyparse.cpp"
        break;
      case 24: /* TOK_STRINGCON */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2059 "yyparse.cpp"
        break;
      case 25: /* TOK_ROOT */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2066 "yyparse.cpp"
        break;
      case 26: /* TOK_DECLID */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2073 "yyparse.cpp"
        break;
      case 27: /* TOK_TYPEID */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2080 "yyparse.cpp"
        break;
      case 28: /* TOK_FIELD */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2087 "yyparse.cpp"
        break;
      case 29: /* TOK_NEWARRY */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2094 "yyparse.cpp"
        break;
      case 30: /* TOK_NEWSTRING */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2101 "yyparse.cpp"
        break;
      case 31: /* TOK_RETURNVOID */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2108 "yyparse.cpp"
        break;
      case 32: /* TOK_VARDECL */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2115 "yyparse.cpp"
        break;
      case 33: /* TOK_FUNCTION */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2122 "yyparse.cpp"
        break;
      case 34: /* TOK_PARAMLIST */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2129 "yyparse.cpp"
        break;
      case 35: /* TOK_PROTOTYPE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2136 "yyparse.cpp"
        break;
      case 36: /* TOK_BLOCK */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2143 "yyparse.cpp"
        break;
      case 37: /* TOK_IFELSE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2150 "yyparse.cpp"
        break;
      case 38: /* TOK_INDEX */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2157 "yyparse.cpp"
        break;
      case 39: /* TOK_INITDECL */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2164 "yyparse.cpp"
        break;
      case 40: /* TOK_POS */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2171 "yyparse.cpp"
        break;
      case 41: /* TOK_NEG */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2178 "yyparse.cpp"
        break;
      case 42: /* TOK_TRUE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2185 "yyparse.cpp"
        break;
      case 43: /* TOK_FALSE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2192 "yyparse.cpp"
        break;
      case 44: /* TOK_CALL */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2199 "yyparse.cpp"
        break;
      case 45: /* TOK_CHR */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2206 "yyparse.cpp"
        break;
      case 46: /* '=' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2213 "yyparse.cpp"
        break;
      case 47: /* TOK_LE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2220 "yyparse.cpp"
        break;
      case 48: /* TOK_NE */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2227 "yyparse.cpp"
        break;
      case 49: /* '+' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2234 "yyparse.cpp"
        break;
      case 50: /* '-' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2241 "yyparse.cpp"
        break;
      case 51: /* '*' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2248 "yyparse.cpp"
        break;
      case 52: /* '/' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2255 "yyparse.cpp"
        break;
      case 53: /* '%' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2262 "yyparse.cpp"
        break;
      case 54: /* '!' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2269 "yyparse.cpp"
        break;
      case 55: /* '}' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2276 "yyparse.cpp"
        break;
      case 56: /* ';' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2283 "yyparse.cpp"
        break;
      case 57: /* '{' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2290 "yyparse.cpp"
        break;
      case 58: /* ')' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2297 "yyparse.cpp"
        break;
      case 59: /* '(' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2304 "yyparse.cpp"
        break;
      case 60: /* ',' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2311 "yyparse.cpp"
        break;
      case 61: /* '^' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2318 "yyparse.cpp"
        break;
      case 62: /* '[' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2325 "yyparse.cpp"
        break;
      case 63: /* ']' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2332 "yyparse.cpp"
        break;
      case 64: /* '.' */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2339 "yyparse.cpp"
        break;
      case 66: /* start */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2346 "yyparse.cpp"
        break;
      case 67: /* program */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2353 "yyparse.cpp"
        break;
      case 68: /* structdef */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2360 "yyparse.cpp"
        break;
      case 69: /* fielddecl */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2367 "yyparse.cpp"
        break;
      case 70: /* structdec */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2374 "yyparse.cpp"
        break;
      case 71: /* basetype */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2381 "yyparse.cpp"
        break;
      case 72: /* function */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2388 "yyparse.cpp"
        break;
      case 73: /* parameter */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2395 "yyparse.cpp"
        break;
      case 74: /* blocklist */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2402 "yyparse.cpp"
        break;
      case 75: /* funcblock */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2409 "yyparse.cpp"
        break;
      case 76: /* identdecl */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2416 "yyparse.cpp"
        break;
      case 77: /* block */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2423 "yyparse.cpp"
        break;
      case 78: /* statement */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2430 "yyparse.cpp"
        break;
      case 79: /* vardecl */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2437 "yyparse.cpp"
        break;
      case 80: /* while */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2444 "yyparse.cpp"
        break;
      case 81: /* ifelse */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2451 "yyparse.cpp"
        break;
      case 82: /* return */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2458 "yyparse.cpp"
        break;
      case 83: /* expr */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2465 "yyparse.cpp"
        break;
      case 84: /* allocator */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2472 "yyparse.cpp"
        break;
      case 85: /* call */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2479 "yyparse.cpp"
        break;
      case 86: /* call_args */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2486 "yyparse.cpp"
        break;
      case 87: /* variable */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2493 "yyparse.cpp"
        break;
      case 88: /* constant */
/* Line 1398 of yacc.c  */
#line 19 "parser.y"
        {destroy((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 2500 "yyparse.cpp"
        break;

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
/* Line 1575 of yacc.c  */
#line 22 "parser.y"
{
  parser::root = new astree (TOK_ROOT, {0, 0, 0, 0}, "<<ROOT>>");
 }
/* Line 1575 of yacc.c  */
#line 2618 "yyparse.cpp"
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 51 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]) = nullptr;}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 54 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> adopt ((yyvsp[(2) - (2)]));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 55 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> adopt ((yyvsp[(2) - (2)]));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 56 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> adopt ((yyvsp[(2) - (2)]));}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 57 "parser.y"
    {destroy ((yyvsp[(3) - (3)])); 
                                          (yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 59 "parser.y"
    {destroy ((yyvsp[(3) - (3)]));
	                                  (yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    {(yyval) = parser::root;}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    {(yyval) = (yyvsp[(1) - (4)]) -> adopt((yyvsp[(2) - (4)]));
                                         (yyvsp[(2) - (4)]) -> change_sym(TOK_TYPEID);
                                         destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]);
                                         destroy((yyvsp[(2) - (2)]));}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 71 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]);
                                         (yyvsp[(1) - (2)]) -> adopt((yyvsp[(2) - (2)]));
					 (yyvsp[(2) - (2)]) -> change_sym(TOK_FIELD);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                                         (yyvsp[(3) - (3)]) -> change_sym(TOK_FIELD);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    {(yyval) = (yyvsp[(1) - (5)]) -> adopt((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                                         (yyvsp[(2) - (5)]) -> change_sym(TOK_TYPEID);
                                         destroy((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]) -> adopt((yyvsp[(2) - (3)]));
                                         destroy((yyvsp[(3) - (3)]));}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]) -> change_sym(TOK_TYPEID);}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 87 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 88 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    {(yyval) = new astree (TOK_FUNCTION, (yyvsp[(1) - (4)])->lloc, (yyvsp[(1) - (4)])->lexinfo->c_str());
					 (yyval) -> adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
					 destroy((yyvsp[(3) - (4)]));}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    {(yyval) = new astree (TOK_PROTOTYPE, (yyvsp[(1) - (4)])->lloc, (yyvsp[(1) - (4)])->lexinfo->c_str());
					 (yyval) -> adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
					 destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 102 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]) -> change_sym(TOK_PARAMLIST);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]) -> adopt((yyvsp[(3) - (3)]));
                                         destroy((yyvsp[(2) - (3)]));}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> adopt((yyvsp[(2) - (2)]));}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]);
                               	         destroy((yyvsp[(2) - (2)]));}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 112 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]) -> change_sym(TOK_BLOCK);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> adopt((yyvsp[(2) - (2)]));}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    {(yyvsp[(3) - (3)]) -> change_sym (TOK_DECLID);  
					 (yyval) = (yyvsp[(2) - (3)]) -> adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 119 "parser.y"
    {(yyvsp[(2) - (2)]) -> change_sym (TOK_DECLID);
	                                 (yyval) = (yyvsp[(1) - (2)]) -> adopt((yyvsp[(2) - (2)]));}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 124 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]) -> change_sym(TOK_BLOCK);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 128 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 129 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 130 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 131 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]);
                                        destroy((yyvsp[(2) - (2)]));}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 136 "parser.y"
    {(yyval) = (yyvsp[(2) - (4)]) -> adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
                                        (yyvsp[(2) - (4)]) -> change_sym(TOK_VARDECL);
					destroy ((yyvsp[(4) - (4)]));}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    {(yyval) = (yyvsp[(1) - (5)]) -> adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); 
                                        destroy((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    {(yyval) = (yyvsp[(1) - (7)]) -> adopt((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
                                        (yyvsp[(1) - (7)]) -> change_sym(TOK_IFELSE);
                                        destroy((yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]));
                                        destroy((yyvsp[(6) - (7)]));}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    {(yyval) = (yyvsp[(1) - (5)]) -> adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
					destroy((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> change_sym(TOK_RETURNVOID);
                                        destroy((yyvsp[(2) - (2)]));}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 158 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]) -> adopt((yyvsp[(2) - (3)]));
                                        destroy((yyvsp[(3) - (3)]));}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 163 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 165 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 166 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 167 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 171 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> adopt_sym ((yyvsp[(2) - (2)]), '!');}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> adopt_sym ((yyvsp[(2) - (2)]), TOK_POS);}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]) -> adopt_sym ((yyvsp[(2) - (2)]), TOK_NEG);}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 178 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 179 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    {destroy ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); 
                                        (yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 182 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    {(yyvsp[(2) - (4)]) -> change_sym(TOK_TYPEID);
				        (yyval) = (yyvsp[(1) - (4)]) -> adopt((yyvsp[(2) - (4)]));
                                        destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    {(yyval) = (yyvsp[(1) - (5)]) -> change_sym(TOK_NEWSTRING);
					(yyvsp[(1) - (5)]) -> adopt((yyvsp[(4) - (5)]));
				        destroy((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 194 "parser.y"
    {(yyval) = (yyvsp[(1) - (5)]) -> change_sym(TOK_NEWARRAY);
                                        (yyvsp[(1) - (5)]) -> adopt((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                                        destroy((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 199 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> change_sym(TOK_CALL);
                                        (yyvsp[(2) - (3)]) -> adopt((yyvsp[(1) - (3)]));
					destroy((yyvsp[(3) - (3)]));}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]);
					destroy((yyvsp[(2) - (2)]));}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 206 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> change_sym(TOK_CALL);
                                        (yyvsp[(2) - (3)]) -> adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]) -> adopt((yyvsp[(3) - (3)]));
                                        destroy((yyvsp[(2) - (3)]));}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 212 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 213 "parser.y"
    {(yyval) = (yyvsp[(2) - (4)]) -> change_sym(TOK_INDEX);
                                        (yyvsp[(2) - (4)]) -> adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
					destroy((yyvsp[(4) - (4)]));}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 216 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)]) -> adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                                        (yyvsp[(3) - (3)]) -> change_sym(TOK_FIELD);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 220 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 222 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 223 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 224 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 225 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;


/* Line 1792 of yacc.c  */
#line 3311 "yyparse.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 228 "parser.y"
  

const char *parser::get_tname (int symbol) {
  return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
  return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

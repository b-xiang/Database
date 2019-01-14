/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs


/* Copy the first part of user declarations.  */
#line 1 "bison_parser.y" /* yacc.c:339  */

/**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 *
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>
#include <string.h>

using namespace hsql;

int yyerror(YYLTYPE* llocp, SQLParserResult* result, yyscan_t scanner, const char *msg) {
	result->setIsValid(false);
	result->setErrorDetails(_strdup(msg), llocp->first_line, llocp->first_column);
	return 0;
}


#line 103 "bison_parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "bison_parser.tab.h".  */
#ifndef YY_HSQL_BISON_PARSER_TAB_H_INCLUDED
# define YY_HSQL_BISON_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef HSQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HSQL_DEBUG 1
#  else
#   define HSQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HSQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HSQL_DEBUG */
#if HSQL_DEBUG
extern int hsql_debug;
#endif
/* "%code requires" blocks.  */
#line 35 "bison_parser.y" /* yacc.c:355  */

// %code requires block

#include "../sql/statements.h"
#include "../SQLParserResult.h"
#include "parser_typedef.h"

// Auto update column and line number
#define YY_USER_ACTION \
		yylloc->first_line = yylloc->last_line; \
		yylloc->first_column = yylloc->last_column; \
		for(int i = 0; yytext[i] != '\0'; i++) { \
			yylloc->total_column++; \
			yylloc->string_length++; \
				if(yytext[i] == '\n') { \
						yylloc->last_line++; \
						yylloc->last_column = 0; \
				} \
				else { \
						yylloc->last_column++; \
				} \
		}

#line 165 "bison_parser.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_IDENTIFIER = 258,
    SQL_STRING = 259,
    SQL_FLOATVAL = 260,
    SQL_INTVAL = 261,
    SQL_DEALLOCATE = 262,
    SQL_PARAMETERS = 263,
    SQL_INTERSECT = 264,
    SQL_TEMPORARY = 265,
    SQL_TIMESTAMP = 266,
    SQL_DISTINCT = 267,
    SQL_NVARCHAR = 268,
    SQL_RESTRICT = 269,
    SQL_TRUNCATE = 270,
    SQL_ANALYZE = 271,
    SQL_BETWEEN = 272,
    SQL_CASCADE = 273,
    SQL_COLUMNS = 274,
    SQL_CONTROL = 275,
    SQL_DEFAULT = 276,
    SQL_EXECUTE = 277,
    SQL_EXPLAIN = 278,
    SQL_HISTORY = 279,
    SQL_INTEGER = 280,
    SQL_NATURAL = 281,
    SQL_PREPARE = 282,
    SQL_PRIMARY = 283,
    SQL_SCHEMAS = 284,
    SQL_SPATIAL = 285,
    SQL_VARCHAR = 286,
    SQL_VIRTUAL = 287,
    SQL_BEFORE = 288,
    SQL_COLUMN = 289,
    SQL_CREATE = 290,
    SQL_DELETE = 291,
    SQL_DIRECT = 292,
    SQL_DOUBLE = 293,
    SQL_ESCAPE = 294,
    SQL_EXCEPT = 295,
    SQL_EXISTS = 296,
    SQL_EXTRACT = 297,
    SQL_GLOBAL = 298,
    SQL_HAVING = 299,
    SQL_IMPORT = 300,
    SQL_INSERT = 301,
    SQL_ISNULL = 302,
    SQL_OFFSET = 303,
    SQL_RENAME = 304,
    SQL_SCHEMA = 305,
    SQL_SELECT = 306,
    SQL_SORTED = 307,
    SQL_TABLES = 308,
    SQL_UNIQUE = 309,
    SQL_UNLOAD = 310,
    SQL_UPDATE = 311,
    SQL_VALUES = 312,
    SQL_AFTER = 313,
    SQL_ALTER = 314,
    SQL_CROSS = 315,
    SQL_DELTA = 316,
    SQL_FLOAT = 317,
    SQL_GROUP = 318,
    SQL_INDEX = 319,
    SQL_INNER = 320,
    SQL_LIMIT = 321,
    SQL_LOCAL = 322,
    SQL_MERGE = 323,
    SQL_MINUS = 324,
    SQL_ORDER = 325,
    SQL_OUTER = 326,
    SQL_RIGHT = 327,
    SQL_TABLE = 328,
    SQL_UNION = 329,
    SQL_USING = 330,
    SQL_WHERE = 331,
    SQL_CALL = 332,
    SQL_CASE = 333,
    SQL_CHAR = 334,
    SQL_DATE = 335,
    SQL_DESC = 336,
    SQL_DROP = 337,
    SQL_ELSE = 338,
    SQL_FILE = 339,
    SQL_FROM = 340,
    SQL_FULL = 341,
    SQL_HASH = 342,
    SQL_HINT = 343,
    SQL_INTO = 344,
    SQL_JOIN = 345,
    SQL_LEFT = 346,
    SQL_LIKE = 347,
    SQL_LOAD = 348,
    SQL_LONG = 349,
    SQL_NULL = 350,
    SQL_PLAN = 351,
    SQL_SHOW = 352,
    SQL_TEXT = 353,
    SQL_THEN = 354,
    SQL_TIME = 355,
    SQL_VIEW = 356,
    SQL_WHEN = 357,
    SQL_WITH = 358,
    SQL_ADD = 359,
    SQL_ALL = 360,
    SQL_AND = 361,
    SQL_ASC = 362,
    SQL_CSV = 363,
    SQL_END = 364,
    SQL_FOR = 365,
    SQL_INT = 366,
    SQL_KEY = 367,
    SQL_NOT = 368,
    SQL_OFF = 369,
    SQL_SET = 370,
    SQL_TBL = 371,
    SQL_TOP = 372,
    SQL_AS = 373,
    SQL_BY = 374,
    SQL_IF = 375,
    SQL_IN = 376,
    SQL_IS = 377,
    SQL_OF = 378,
    SQL_ON = 379,
    SQL_OR = 380,
    SQL_TO = 381,
    SQL_ARRAY = 382,
    SQL_CONCAT = 383,
    SQL_ILIKE = 384,
    SQL_SECOND = 385,
    SQL_MINUTE = 386,
    SQL_HOUR = 387,
    SQL_DAY = 388,
    SQL_MONTH = 389,
    SQL_YEAR = 390,
    SQL_TRUE = 391,
    SQL_FALSE = 392,
    SQL_DATABASES = 393,
    SQL_USE = 394,
    SQL_EQUALS = 395,
    SQL_NOTEQUALS = 396,
    SQL_LESS = 397,
    SQL_GREATER = 398,
    SQL_LESSEQ = 399,
    SQL_GREATEREQ = 400,
    SQL_NOTNULL = 401,
    SQL_UMINUS = 402
  };
#endif

/* Value type.  */
#if ! defined HSQL_STYPE && ! defined HSQL_STYPE_IS_DECLARED

union HSQL_STYPE
{
#line 95 "bison_parser.y" /* yacc.c:355  */

	double fval;
	int64_t ival;
	char* sval;
	uintmax_t uval;
	bool bval;

	hsql::SQLStatement* statement;
	hsql::SelectStatement* 	select_stmt;
	hsql::ImportStatement* 	import_stmt;
	hsql::CreateStatement* 	create_stmt;
	hsql::InsertStatement* 	insert_stmt;
	hsql::DeleteStatement* 	delete_stmt;
	hsql::UpdateStatement* 	update_stmt;
	hsql::DropStatement*   	drop_stmt;
	hsql::PrepareStatement* prep_stmt;
	hsql::ExecuteStatement* exec_stmt;
	hsql::ShowStatement*    show_stmt;
	hsql::UseStatement* use_stmt;

	hsql::TableName table_name;
	hsql::TableRef* table;
	hsql::Expr* expr;
	hsql::OrderDescription* order;
	hsql::OrderType order_type;
	hsql::DatetimeField datetime_field;
	hsql::LimitDescription* limit;
	hsql::ColumnDefinition* column_t;
	hsql::ColumnType column_type_t;
	hsql::GroupByDescription* group_t;
	hsql::UpdateClause* update_t;
	hsql::Alias* alias_t;

	std::vector<hsql::SQLStatement*>* stmt_vec;

	std::vector<char*>* str_vec;
	std::vector<hsql::TableRef*>* table_vec;
	std::vector<hsql::ColumnDefinition*>* column_vec;
	std::vector<hsql::UpdateClause*>* update_vec;
	std::vector<hsql::Expr*>* expr_vec;
	std::vector<hsql::OrderDescription*>* order_vec;

#line 368 "bison_parser.tab.c" /* yacc.c:355  */
};

typedef union HSQL_STYPE HSQL_STYPE;
# define HSQL_STYPE_IS_TRIVIAL 1
# define HSQL_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HSQL_LTYPE && ! defined HSQL_LTYPE_IS_DECLARED
typedef struct HSQL_LTYPE HSQL_LTYPE;
struct HSQL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HSQL_LTYPE_IS_DECLARED 1
# define HSQL_LTYPE_IS_TRIVIAL 1
#endif



int hsql_parse (hsql::SQLParserResult* result, yyscan_t scanner);

#endif /* !YY_HSQL_BISON_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 398 "bison_parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   630

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  442

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   402

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   154,     2,     2,
     159,   160,   152,   150,   163,   151,   161,   153,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   162,
     143,   140,   144,   164,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   157,     2,   158,   155,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   141,   142,   145,   146,   147,
     148,   149,   156
};

#if HSQL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   256,   256,   277,   283,   292,   296,   300,   303,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   327,   328,
     333,   334,   338,   342,   354,   361,   364,   368,   380,   389,
     393,   403,   406,   411,   422,   433,   440,   447,   455,   459,
     468,   469,   473,   474,   478,   484,   485,   486,   487,   488,
     489,   490,   491,   495,   496,   497,   507,   513,   519,   527,
     528,   537,   546,   559,   566,   577,   578,   588,   597,   598,
     602,   614,   615,   616,   633,   634,   638,   639,   643,   653,
     670,   674,   675,   676,   680,   681,   685,   697,   698,   702,
     706,   707,   710,   715,   716,   720,   725,   729,   730,   733,
     734,   738,   739,   743,   747,   748,   749,   755,   756,   760,
     761,   762,   763,   764,   765,   766,   767,   774,   775,   779,
     780,   784,   794,   795,   796,   797,   798,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   815,   816,   820,
     821,   822,   823,   824,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   842,   843,   847,   848,   849,
     850,   856,   857,   858,   859,   863,   864,   868,   869,   873,
     874,   875,   876,   877,   878,   879,   883,   884,   888,   892,
     893,   894,   895,   896,   897,   900,   904,   908,   912,   913,
     914,   915,   919,   920,   921,   922,   923,   927,   931,   932,
     936,   937,   941,   945,   949,   961,   962,   972,   973,   977,
     978,   987,   988,   993,  1004,  1013,  1014,  1019,  1020,  1025,
    1026,  1030,  1031,  1036,  1037,  1045,  1053,  1063,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1096,  1105,
    1106,  1111,  1112
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "FLOATVAL",
  "INTVAL", "DEALLOCATE", "PARAMETERS", "INTERSECT", "TEMPORARY",
  "TIMESTAMP", "DISTINCT", "NVARCHAR", "RESTRICT", "TRUNCATE", "ANALYZE",
  "BETWEEN", "CASCADE", "COLUMNS", "CONTROL", "DEFAULT", "EXECUTE",
  "EXPLAIN", "HISTORY", "INTEGER", "NATURAL", "PREPARE", "PRIMARY",
  "SCHEMAS", "SPATIAL", "VARCHAR", "VIRTUAL", "BEFORE", "COLUMN", "CREATE",
  "DELETE", "DIRECT", "DOUBLE", "ESCAPE", "EXCEPT", "EXISTS", "EXTRACT",
  "GLOBAL", "HAVING", "IMPORT", "INSERT", "ISNULL", "OFFSET", "RENAME",
  "SCHEMA", "SELECT", "SORTED", "TABLES", "UNIQUE", "UNLOAD", "UPDATE",
  "VALUES", "AFTER", "ALTER", "CROSS", "DELTA", "FLOAT", "GROUP", "INDEX",
  "INNER", "LIMIT", "LOCAL", "MERGE", "MINUS", "ORDER", "OUTER", "RIGHT",
  "TABLE", "UNION", "USING", "WHERE", "CALL", "CASE", "CHAR", "DATE",
  "DESC", "DROP", "ELSE", "FILE", "FROM", "FULL", "HASH", "HINT", "INTO",
  "JOIN", "LEFT", "LIKE", "LOAD", "LONG", "NULL", "PLAN", "SHOW", "TEXT",
  "THEN", "TIME", "VIEW", "WHEN", "WITH", "ADD", "ALL", "AND", "ASC",
  "CSV", "END", "FOR", "INT", "KEY", "NOT", "OFF", "SET", "TBL", "TOP",
  "AS", "BY", "IF", "IN", "IS", "OF", "ON", "OR", "TO", "ARRAY", "CONCAT",
  "ILIKE", "SECOND", "MINUTE", "HOUR", "DAY", "MONTH", "YEAR", "TRUE",
  "FALSE", "DATABASES", "USE", "'='", "EQUALS", "NOTEQUALS", "'<'", "'>'",
  "LESS", "GREATER", "LESSEQ", "GREATEREQ", "NOTNULL", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "UMINUS", "'['", "']'", "'('", "')'", "'.'", "';'",
  "','", "'?'", "$accept", "input", "statement_list", "statement",
  "preparable_statement", "opt_hints", "hint_list", "hint",
  "prepare_statement", "prepare_target_query", "execute_statement",
  "import_statement", "import_file_type", "file_path", "show_statement",
  "use_statement", "create_statement", "opt_not_exists",
  "column_def_commalist", "column_def", "column_type",
  "opt_column_nullable", "drop_statement", "opt_exists",
  "delete_statement", "truncate_statement", "insert_statement",
  "opt_column_list", "update_statement", "update_clause_commalist",
  "update_clause", "select_statement", "select_with_paren",
  "select_paren_or_clause", "select_no_paren", "set_operator", "set_type",
  "opt_all", "select_clause", "opt_distinct", "select_list",
  "opt_from_clause", "from_clause", "opt_where", "opt_group", "opt_having",
  "opt_order", "order_list", "order_desc", "opt_order_type", "opt_top",
  "opt_limit", "expr_list", "literal_list", "expr_alias", "expr",
  "operand", "scalar_expr", "unary_expr", "binary_expr", "logic_expr",
  "in_expr", "case_expr", "case_list", "exists_expr", "comp_expr",
  "function_expr", "extract_expr", "datetime_field", "array_expr",
  "array_index", "between_expr", "column_name", "literal",
  "string_literal", "bool_literal", "num_literal", "int_literal",
  "null_literal", "param_expr", "table_ref", "table_ref_atomic",
  "nonjoin_table_ref_atomic", "table_ref_commalist", "table_ref_name",
  "table_ref_name_no_alias", "table_name", "table_alias",
  "opt_table_alias", "alias", "opt_alias", "join_clause", "opt_join_type",
  "join_condition", "opt_semicolon", "ident_commalist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
      61,   395,   396,    60,    62,   397,   398,   399,   400,   401,
      43,    45,    42,    47,    37,    94,   402,    91,    93,    40,
      41,    46,    59,    44,    63
};
# endif

#define YYPACT_NINF -346

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-346)))

#define YYTABLE_NINF -238

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-238)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,    11,    46,    55,    77,    42,    36,    44,   -18,   -26,
      46,   -40,    23,    46,   -43,   140,   -32,  -346,    39,    39,
    -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,    28,  -346,    15,   161,    29,  -346,    50,    88,    46,
      91,    66,    66,    46,   119,    46,   211,   219,   125,  -346,
     121,   121,    46,  -346,  -346,  -346,    82,    94,  -346,    21,
    -346,   160,  -346,  -346,  -346,  -346,  -346,   -43,   151,   141,
     -43,    56,  -346,   262,    25,   269,  -346,    46,   174,    46,
      46,   218,  -346,   224,   157,  -346,  -346,  -346,   229,   316,
     281,    46,    46,  -346,  -346,  -346,  -346,   166,  -346,   250,
    -346,  -346,  -346,   229,   250,   211,    12,  -346,  -346,  -346,
    -346,  -346,  -346,  -346,  -346,    16,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,  -346,  -346,   168,   288,   -71,   157,   229,
    -346,   336,   340,    27,    62,   185,   186,    93,   272,   189,
     276,  -346,   196,   264,   190,  -346,     8,   304,  -346,  -346,
    -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,  -346,  -346,   212,   -63,  -346,  -346,  -346,  -346,   354,
      56,   198,  -346,   101,    56,  -346,   311,   314,   320,  -346,
      25,    46,  -346,   253,   367,   254,    79,   285,  -346,  -346,
      65,   216,  -346,     7,    13,   325,   204,   229,    68,   -39,
     220,   276,   418,   229,   131,   222,   -86,     4,   218,  -346,
     229,  -346,   229,   375,   229,  -346,  -346,   276,  -346,   276,
     -46,   225,    18,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   211,   229,
     316,  -346,   227,    98,  -346,  -346,   229,  -346,  -346,  -346,
    -346,   211,   211,   211,  -346,   223,   303,   279,   104,  -346,
     -43,    46,  -346,   388,    25,  -346,   229,  -346,  -346,   232,
    -346,  -346,  -346,  -346,  -346,  -346,   309,    69,    89,   229,
     229,  -346,   325,   305,   -31,  -346,  -346,   -43,  -346,   378,
    -346,   235,  -346,     6,  -346,   332,  -346,  -346,  -346,   294,
     371,   456,   276,   242,   196,  -346,   307,   248,   456,   456,
     456,   456,   473,   473,   473,   473,   131,   131,   -19,   -19,
     -19,  -107,   249,    79,  -346,    25,  -346,   354,  -346,  -346,
    -346,  -346,  -346,   336,  -346,   247,  -346,  -346,   251,  -346,
    -346,  -346,    74,  -346,   367,  -346,  -346,  -346,   109,   129,
    -346,   229,   229,   229,  -346,   130,    97,   255,  -346,   256,
     321,  -346,  -346,  -346,   343,   348,   349,   331,     4,   419,
    -346,  -346,  -346,   310,  -346,   276,   456,   196,   270,   133,
    -346,  -346,   138,  -346,  -346,   428,   433,  -346,   346,  -346,
    -346,  -346,  -346,   -74,    79,   137,  -346,   229,  -346,     6,
       4,  -346,  -346,  -346,     4,   411,   283,   229,   418,   293,
     139,  -346,  -346,  -346,   300,   302,  -346,  -346,  -346,    79,
    -346,  -346,   240,   340,   -38,  -346,  -346,  -346,  -346,   308,
     229,   143,   229,  -346,    14,    79,  -346,  -346,    79,   312,
     306,  -346
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,   240,     3,    19,    19,
      17,    10,     7,     8,    11,    16,    13,    14,    12,    15,
       9,    71,    72,   100,     0,   215,    62,    26,     0,     0,
       0,    41,    41,     0,     0,     0,     0,    88,     0,   214,
      60,    60,     0,    33,    31,    34,     0,     0,     1,   239,
       2,     0,     6,     5,    82,    83,    81,     0,    85,     0,
       0,   116,    58,     0,     0,     0,    38,     0,     0,     0,
       0,    94,    29,     0,    66,   202,   107,    87,     0,     0,
       0,     0,     0,    32,    75,    74,     4,     0,    76,   100,
      77,    84,    80,     0,   100,     0,     0,    78,   216,   197,
     200,   203,   198,   199,   204,     0,   119,   192,   193,   194,
     201,   195,   196,    25,    24,     0,     0,     0,    66,     0,
      61,     0,     0,     0,   188,     0,     0,     0,     0,     0,
       0,   190,     0,    91,    89,   117,   224,   122,   129,   130,
     131,   124,   126,   132,   125,   144,   133,   134,   135,   128,
     123,   137,   138,     0,    94,    68,    59,    56,    57,     0,
     116,    99,   101,   106,   116,   111,   113,   112,   109,    27,
       0,     0,    40,     0,     0,     0,    93,     0,    30,   241,
       0,     0,    64,    88,     0,     0,     0,     0,     0,     0,
       0,     0,   140,     0,   139,     0,     0,     0,    94,    90,
       0,   222,     0,     0,     0,   223,   121,     0,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,    22,     0,    20,    73,     0,   105,   104,   103,
      79,     0,     0,     0,   120,     0,     0,     0,     0,    42,
       0,     0,    65,     0,     0,   176,     0,   189,   191,     0,
     179,   180,   181,   182,   183,   184,     0,     0,     0,     0,
       0,   163,     0,     0,     0,   136,   127,     0,    92,   205,
     207,     0,   209,   220,   208,    96,   118,   155,   221,   156,
       0,   151,     0,     0,     0,   142,     0,   154,   153,   169,
     170,   171,   172,   173,   174,   175,   146,   145,   148,   147,
     149,   150,     0,    70,    69,     0,    18,     0,   102,   115,
     114,   110,    39,     0,    46,     0,    49,    48,     0,    47,
      52,    45,    55,    36,     0,    37,    28,   242,     0,     0,
     167,     0,     0,     0,   161,     0,     0,     0,   185,     0,
       0,   236,   228,   234,   232,   235,   230,     0,     0,     0,
     219,   213,   217,     0,    86,     0,   152,     0,     0,     0,
     143,   186,     0,    21,    35,     0,     0,    53,     0,    44,
      43,    63,   177,     0,   165,     0,   164,     0,   168,   220,
       0,   231,   233,   229,     0,   206,   221,     0,   187,     0,
       0,   159,   157,    23,     0,     0,    54,   178,   162,   166,
     210,   225,   237,     0,    98,   160,   158,    50,    51,     0,
       0,     0,     0,    95,     0,   238,   226,   218,    97,   188,
       0,   227
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -346,  -346,  -346,   413,  -346,   451,  -346,   147,  -346,  -346,
    -346,  -346,  -346,   142,  -346,  -346,  -346,   436,  -346,   135,
    -346,  -346,  -346,   429,  -346,  -346,  -346,   353,  -346,  -346,
     245,  -234,    20,   416,   -14,   454,  -346,  -346,   149,   295,
    -346,  -346,  -346,  -139,  -346,  -346,   114,  -346,   243,  -346,
    -346,   -69,  -193,  -242,   280,  -102,   -78,  -346,  -346,  -346,
    -346,  -346,  -346,   296,  -346,  -346,  -346,  -346,  -346,  -346,
    -346,  -346,    57,   -72,  -128,  -346,  -346,   -41,  -346,  -346,
    -346,  -345,    92,  -346,  -346,  -346,     2,  -346,    96,   350,
    -346,  -346,  -346,  -346,  -346,    75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    62,   243,   244,    19,   124,
      20,    21,    83,   187,    22,    23,    24,    79,   258,   259,
     342,   389,    25,    91,    26,    27,    28,   133,    29,   164,
     165,    30,    31,    99,    32,    67,    68,   102,    33,    88,
     143,   208,   209,   130,   374,   433,    71,   171,   172,   249,
      47,   107,   144,   115,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   199,   154,   155,   156,   157,   276,   158,
     159,   160,   161,   162,   117,   118,   119,   120,   121,   122,
     288,   289,   290,   291,   292,    48,   293,   370,   371,   372,
     216,   294,   367,   436,    60,   190
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   173,   116,   188,    36,    86,   432,    35,     9,   211,
     284,   211,    49,   129,   183,    55,   267,   439,    85,    87,
     212,   223,   348,   405,    64,   241,   345,   186,     1,   109,
     110,    85,   212,    50,    56,   198,     2,    64,    34,   214,
     206,    76,    52,     3,   279,    81,   302,    84,     4,    35,
     238,   214,    53,   359,    93,    65,     5,     6,    37,   422,
     202,    51,   204,   280,   175,   178,     7,     8,    65,   295,
     281,    45,     9,   349,   286,   303,    54,    10,     9,   125,
      38,   127,   128,   382,   191,    69,   417,    98,   184,    66,
      98,    46,    39,   167,   168,   277,   134,   109,   110,    85,
     240,   245,    66,    11,   105,   250,    40,   176,   254,   223,
     297,   379,   299,   305,   212,    41,    14,   177,    12,   192,
     111,    43,   106,   202,   369,   210,   213,   358,   205,    44,
      59,   306,   210,   214,   135,   136,   237,   323,   238,   300,
      58,   301,    61,    42,   173,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
      13,   112,   113,   287,    72,   268,   141,   265,   352,   387,
     197,   137,   353,    75,   212,   212,   179,   355,   356,   180,
      14,   269,   247,   255,   410,   212,    78,   388,   111,   114,
      73,   280,   116,   214,   214,   197,   397,   322,   354,   134,
     109,   110,    85,   212,   214,   188,   138,   212,   248,    74,
     329,   330,   331,   170,   424,    77,   100,    85,   174,   100,
     139,   193,   214,   194,   376,   262,   214,    82,   263,   112,
     113,    87,   134,   109,   110,    85,   212,   135,   136,   396,
      89,    90,    94,   212,   140,   141,   418,     9,    97,   393,
     394,   395,   142,   116,    95,   214,   101,   114,   326,   223,
     103,   327,   214,   346,   343,   108,   360,   344,   357,   391,
     135,   136,   180,   123,   137,   134,   109,   110,    85,   134,
     109,   110,    85,   234,   235,   236,   237,   126,   238,   392,
     378,   111,   210,   412,   129,   419,   210,   408,   413,   426,
     361,   180,   210,   437,   334,   362,   263,   137,   131,   138,
     335,   363,   364,   200,   136,   429,   132,   336,   136,   163,
      69,   217,   166,   139,   111,   169,   365,   181,   435,   182,
     438,   366,   112,   113,   270,   271,   272,   273,   274,   275,
     109,   337,   138,   189,   195,   196,   203,   140,   141,   207,
     137,   218,   239,   210,   137,   142,   139,   242,   338,   251,
     114,   246,   252,   409,   430,   112,   113,   111,   253,   256,
     257,   111,   260,   339,   261,   264,     9,   340,   298,   282,
     140,   141,   285,   332,   304,   201,   325,   333,   142,   201,
     341,   347,   350,   114,   351,   373,   219,   302,   368,   139,
     212,   377,   380,   139,   360,   238,   385,   381,   112,   113,
     386,   400,   112,   113,   401,   398,   399,   220,   218,   402,
     403,   404,   406,   140,   141,   221,   222,   140,   141,   407,
     411,   142,   223,   224,   414,   142,   114,   360,   361,   415,
     114,   416,   423,   362,   225,   226,   227,   228,   229,   363,
     364,   230,   231,   425,   232,   233,   234,   235,   236,   237,
     427,   238,   428,   219,   365,   218,   441,   434,  -237,   366,
      63,   361,    96,   194,   383,   384,   362,   375,    80,   390,
      92,   185,   363,   364,   283,   324,   104,    70,   266,   328,
     296,   440,   421,   222,   278,   420,   215,   365,   431,   223,
     224,  -237,   366,   218,     0,     0,     0,     0,     0,     0,
     219,   225,   226,   227,   228,   229,     0,     0,   230,   231,
     218,   232,   233,   234,   235,   236,   237,     0,   238,     0,
       0,   283,     0,     0,     0,     0,     0,     0,     0,     0,
     222,  -211,     0,     0,     0,     0,   223,   224,  -238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   226,
     227,   228,   229,     0,     0,   230,   231,     0,   232,   233,
     234,   235,   236,   237,  -212,   238,     0,     0,   222,     0,
       0,     0,     0,     0,   223,  -238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,  -238,  -238,  -238,   228,
     229,   223,     0,   230,   231,     0,   232,   233,   234,   235,
     236,   237,     0,   238,     0,     0,  -238,  -238,     0,     0,
    -238,  -238,     0,   232,   233,   234,   235,   236,   237,     0,
     238
};

static const yytype_int16 yycheck[] =
{
      14,   103,    74,   131,     2,    46,    44,     3,    51,     3,
     203,     3,    10,    76,    85,    13,     3,     3,     6,    12,
     106,   128,   264,   368,     9,   164,   260,   129,     7,     4,
       5,     6,   106,    73,    14,   137,    15,     9,    27,   125,
     142,    39,    19,    22,    83,    43,    92,    45,    27,     3,
     157,   125,    29,   287,    52,    40,    35,    36,     3,   404,
     138,   101,   140,   102,   105,   106,    45,    46,    40,   208,
     109,    89,    51,   266,   160,   121,    53,    56,    51,    77,
       3,    79,    80,   325,    57,    70,   160,    67,   159,    74,
      70,   117,    50,    91,    92,   197,     3,     4,     5,     6,
     163,   170,    74,    82,    48,   174,    64,    95,   180,   128,
     212,   304,   214,    95,   106,    73,   159,   105,    97,   133,
      95,    85,    66,   201,   118,   163,   118,   158,   142,    85,
     162,   113,   163,   125,    41,    42,   155,   239,   157,   217,
       0,   219,   103,   101,   246,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     139,   136,   137,   159,     3,   152,   152,   160,    99,    95,
     102,    78,    83,    85,   106,   106,   160,   279,   280,   163,
     159,   195,    81,   181,   377,   106,   120,   113,    95,   164,
     161,   102,   264,   125,   125,   102,    99,   238,   109,     3,
       4,     5,     6,   106,   125,   333,   113,   106,   107,   159,
     251,   252,   253,    99,   407,   124,    67,     6,   104,    70,
     127,   159,   125,   161,   302,   160,   125,   108,   163,   136,
     137,    12,     3,     4,     5,     6,   106,    41,    42,   109,
     115,   120,   160,   106,   151,   152,   109,    51,    88,   351,
     352,   353,   159,   325,   160,   125,   105,   164,   160,   128,
     119,   163,   125,   261,   160,     3,    26,   163,   282,   160,
      41,    42,   163,     4,    78,     3,     4,     5,     6,     3,
       4,     5,     6,   152,   153,   154,   155,   113,   157,   160,
     304,    95,   163,   160,    76,   397,   163,   375,   160,   160,
      60,   163,   163,   160,    25,    65,   163,    78,    84,   113,
      31,    71,    72,    41,    42,    75,   159,    38,    42,     3,
      70,    17,    41,   127,    95,   159,    86,   159,   430,    41,
     432,    91,   136,   137,   130,   131,   132,   133,   134,   135,
       4,    62,   113,     3,   159,   159,   157,   151,   152,    85,
      78,    47,   140,   163,    78,   159,   127,     3,    79,    48,
     164,   163,    48,   377,   124,   136,   137,    95,    48,   116,
       3,    95,   118,    94,    89,   159,    51,    98,     3,   159,
     151,   152,   160,   160,   159,   113,   159,    84,   159,   113,
     111,     3,   160,   164,    85,    63,    92,    92,   163,   127,
     106,   159,    95,   127,    26,   157,   159,   158,   136,   137,
     159,    90,   136,   137,    71,   160,   160,   113,    47,    71,
      71,    90,     3,   151,   152,   121,   122,   151,   152,   119,
     160,   159,   128,   129,     6,   159,   164,    26,    60,     6,
     164,    95,   159,    65,   140,   141,   142,   143,   144,    71,
      72,   147,   148,   160,   150,   151,   152,   153,   154,   155,
     160,   157,   160,    92,    86,    47,   160,   159,    90,    91,
      19,    60,    59,   161,   327,   333,    65,   106,    42,   344,
      51,   128,    71,    72,   113,   240,    70,    33,   193,   246,
     210,   434,   400,   122,   198,   399,   146,    86,   423,   128,
     129,    90,    91,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      92,   140,   141,   142,   143,   144,    -1,    -1,   147,   148,
      47,   150,   151,   152,   153,   154,   155,    -1,   157,    -1,
      -1,   113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   163,    -1,    -1,    -1,    -1,   128,   129,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,    -1,    -1,   147,   148,    -1,   150,   151,
     152,   153,   154,   155,   163,   157,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   140,   141,   142,   143,
     144,   128,    -1,   147,   148,    -1,   150,   151,   152,   153,
     154,   155,    -1,   157,    -1,    -1,   143,   144,    -1,    -1,
     147,   148,    -1,   150,   151,   152,   153,   154,   155,    -1,
     157
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     7,    15,    22,    27,    35,    36,    45,    46,    51,
      56,    82,    97,   139,   159,   166,   167,   168,   169,   173,
     175,   176,   179,   180,   181,   187,   189,   190,   191,   193,
     196,   197,   199,   203,    27,     3,   251,     3,     3,    50,
      64,    73,   101,    85,    85,    89,   117,   215,   250,   251,
      73,   101,    19,    29,    53,   251,   197,   199,     0,   162,
     259,   103,   170,   170,     9,    40,    74,   200,   201,    70,
     200,   211,     3,   161,   159,    85,   251,   124,   120,   182,
     182,   251,   108,   177,   251,     6,   242,    12,   204,   115,
     120,   188,   188,   251,   160,   160,   168,    88,   197,   198,
     203,   105,   202,   119,   198,    48,    66,   216,     3,     4,
       5,    95,   136,   137,   164,   218,   238,   239,   240,   241,
     242,   243,   244,     4,   174,   251,   113,   251,   251,    76,
     208,    84,   159,   192,     3,    41,    42,    78,   113,   127,
     151,   152,   159,   205,   217,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   229,   230,   231,   232,   234,   235,
     236,   237,   238,     3,   194,   195,    41,   251,   251,   159,
     211,   212,   213,   220,   211,   242,    95,   105,   242,   160,
     163,   159,    41,    85,   159,   192,   220,   178,   239,     3,
     260,    57,   199,   159,   161,   159,   159,   102,   220,   228,
      41,   113,   221,   157,   221,   199,   220,    85,   206,   207,
     163,     3,   106,   118,   125,   254,   255,    17,    47,    92,
     113,   121,   122,   128,   129,   140,   141,   142,   143,   144,
     147,   148,   150,   151,   152,   153,   154,   155,   157,   140,
     163,   208,     3,   171,   172,   216,   163,    81,   107,   214,
     216,    48,    48,    48,   238,   251,   116,     3,   183,   184,
     118,    89,   160,   163,   159,   160,   204,     3,   152,   199,
     130,   131,   132,   133,   134,   135,   233,   220,   228,    83,
     102,   109,   159,   113,   217,   160,   160,   159,   245,   246,
     247,   248,   249,   251,   256,   208,   219,   220,     3,   220,
     221,   221,    92,   121,   159,    95,   113,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   242,   220,   195,   159,   160,   163,   213,   242,
     242,   242,   160,    84,    25,    31,    38,    62,    79,    94,
      98,   111,   185,   160,   163,   196,   251,     3,   218,   217,
     160,    85,    99,    83,   109,   220,   220,   199,   158,   196,
      26,    60,    65,    71,    72,    86,    91,   257,   163,   118,
     252,   253,   254,    63,   209,   106,   221,   159,   199,   217,
      95,   158,   218,   172,   178,   159,   159,    95,   113,   186,
     184,   160,   160,   220,   220,   220,   109,    99,   160,   160,
      90,    71,    71,    71,    90,   246,     3,   119,   221,   199,
     217,   160,   160,   160,     6,     6,    95,   160,   109,   220,
     253,   247,   246,   159,   217,   160,   160,   160,   160,    75,
     124,   260,    44,   210,   159,   220,   258,   160,   220,     3,
     237,   160
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   165,   166,   167,   167,   168,   168,   168,   168,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   174,   175,   175,   176,   177,
     178,   179,   179,   179,   180,   181,   181,   181,   181,   181,
     182,   182,   183,   183,   184,   185,   185,   185,   185,   185,
     185,   185,   185,   186,   186,   186,   187,   187,   187,   188,
     188,   189,   190,   191,   191,   192,   192,   193,   194,   194,
     195,   196,   196,   196,   197,   197,   198,   198,   199,   199,
     200,   201,   201,   201,   202,   202,   203,   204,   204,   205,
     206,   206,   207,   208,   208,   209,   209,   210,   210,   211,
     211,   212,   212,   213,   214,   214,   214,   215,   215,   216,
     216,   216,   216,   216,   216,   216,   216,   217,   217,   218,
     218,   219,   220,   220,   220,   220,   220,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   222,   222,   223,
     223,   223,   223,   223,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   225,   225,   226,   226,   226,
     226,   227,   227,   227,   227,   228,   228,   229,   229,   230,
     230,   230,   230,   230,   230,   230,   231,   231,   232,   233,
     233,   233,   233,   233,   233,   234,   235,   236,   237,   237,
     237,   237,   238,   238,   238,   238,   238,   239,   240,   240,
     241,   241,   242,   243,   244,   245,   245,   246,   246,   247,
     247,   248,   248,   249,   250,   251,   251,   252,   252,   253,
     253,   254,   254,   255,   255,   256,   256,   256,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   258,   259,
     259,   260,   260
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     0,
       1,     3,     1,     4,     4,     1,     2,     5,     7,     1,
       1,     2,     3,     2,     2,     8,     7,     7,     3,     7,
       3,     0,     1,     3,     3,     1,     1,     1,     1,     1,
       4,     4,     1,     1,     2,     0,     4,     4,     3,     2,
       0,     4,     2,     8,     5,     3,     0,     5,     1,     3,
       3,     1,     1,     5,     3,     3,     1,     1,     3,     5,
       2,     1,     1,     1,     1,     0,     7,     1,     0,     1,
       1,     0,     2,     2,     0,     4,     0,     2,     0,     3,
       0,     1,     3,     2,     1,     1,     0,     2,     0,     2,
       4,     2,     2,     2,     4,     4,     0,     1,     3,     1,
       3,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     2,
       2,     2,     3,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     3,     3,     3,     5,     6,     5,
       6,     4,     6,     3,     5,     4,     5,     4,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     6,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       4,     1,     3,     2,     1,     1,     3,     1,     5,     1,
       0,     2,     1,     1,     0,     4,     6,     8,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     0,     1,     1,
       0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if HSQL_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, scanner);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, hsql::SQLParserResult* result, yyscan_t scanner)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLParserResult* result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* IDENTIFIER  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1708 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 4: /* STRING  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1714 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 5: /* FLOATVAL  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1720 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 6: /* INTVAL  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1726 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 167: /* statement_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).stmt_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).stmt_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).stmt_vec));
}
#line 1739 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 168: /* statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).statement)); }
#line 1745 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 169: /* preparable_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).statement)); }
#line 1751 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 170: /* opt_hints  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1764 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 171: /* hint_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1777 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 172: /* hint  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1783 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 173: /* prepare_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).prep_stmt)); }
#line 1789 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 174: /* prepare_target_query  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1795 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 175: /* execute_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).exec_stmt)); }
#line 1801 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 176: /* import_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).import_stmt)); }
#line 1807 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 177: /* import_file_type  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1813 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 178: /* file_path  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1819 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 179: /* show_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).show_stmt)); }
#line 1825 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 180: /* use_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).use_stmt)); }
#line 1831 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 181: /* create_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).create_stmt)); }
#line 1837 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 182: /* opt_not_exists  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1843 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 183: /* column_def_commalist  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).column_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).column_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).column_vec));
}
#line 1856 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 184: /* column_def  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).column_t)); }
#line 1862 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 185: /* column_type  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1868 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 186: /* opt_column_nullable  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1874 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 187: /* drop_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).drop_stmt)); }
#line 1880 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 188: /* opt_exists  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1886 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 189: /* delete_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1892 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 190: /* truncate_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1898 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 191: /* insert_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).insert_stmt)); }
#line 1904 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 192: /* opt_column_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 1917 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 193: /* update_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).update_stmt)); }
#line 1923 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 194: /* update_clause_commalist  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).update_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).update_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).update_vec));
}
#line 1936 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 195: /* update_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).update_t)); }
#line 1942 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 196: /* select_statement  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1948 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 197: /* select_with_paren  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1954 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 198: /* select_paren_or_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1960 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 199: /* select_no_paren  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1966 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 203: /* select_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1972 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 204: /* opt_distinct  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1978 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 205: /* select_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1991 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 206: /* opt_from_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 1997 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 207: /* from_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2003 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 208: /* opt_where  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2009 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 209: /* opt_group  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).group_t)); }
#line 2015 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 210: /* opt_having  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2021 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 211: /* opt_order  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).order_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 2034 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 212: /* order_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).order_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 2047 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 213: /* order_desc  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).order)); }
#line 2053 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 214: /* opt_order_type  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 2059 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 215: /* opt_top  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).limit)); }
#line 2065 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 216: /* opt_limit  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).limit)); }
#line 2071 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 217: /* expr_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2084 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 218: /* literal_list  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2097 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 219: /* expr_alias  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2103 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 220: /* expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2109 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 221: /* operand  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2115 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 222: /* scalar_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2121 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 223: /* unary_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2127 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 224: /* binary_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2133 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 225: /* logic_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2139 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 226: /* in_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2145 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 227: /* case_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2151 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 228: /* case_list  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2157 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 229: /* exists_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2163 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 230: /* comp_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2169 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 231: /* function_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2175 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 232: /* extract_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2181 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 233: /* datetime_field  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 2187 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 234: /* array_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2193 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 235: /* array_index  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2199 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 236: /* between_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2205 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 237: /* column_name  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2211 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 238: /* literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2217 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 239: /* string_literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2223 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 240: /* bool_literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2229 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 241: /* num_literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2235 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 242: /* int_literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2241 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 243: /* null_literal  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2247 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 244: /* param_expr  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2253 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 245: /* table_ref  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2259 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 246: /* table_ref_atomic  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2265 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 247: /* nonjoin_table_ref_atomic  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2271 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 248: /* table_ref_commalist  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).table_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).table_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).table_vec));
}
#line 2284 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 249: /* table_ref_name  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2290 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 250: /* table_ref_name_no_alias  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2296 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 251: /* table_name  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2302 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 252: /* table_alias  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).alias_t)); }
#line 2308 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 253: /* opt_table_alias  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).alias_t)); }
#line 2314 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 254: /* alias  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).alias_t)); }
#line 2320 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 255: /* opt_alias  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).alias_t)); }
#line 2326 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 256: /* join_clause  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2332 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 257: /* opt_join_type  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 2338 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 258: /* join_condition  */
#line 153 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2344 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 260: /* ident_commalist  */
#line 145 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 2357 "bison_parser.tab.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (hsql::SQLParserResult* result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 73 "bison_parser.y" /* yacc.c:1429  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
	yylloc.total_column = 0;
	yylloc.string_length = 0;
}

#line 2476 "bison_parser.tab.c" /* yacc.c:1429  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  *++yylsp = yylloc;
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 256 "bison_parser.y" /* yacc.c:1646  */
    {
			for (SQLStatement* stmt : *(yyvsp[-1].stmt_vec)) {
				// Transfers ownership of the statement.
				result->addStatement(stmt);
			}

			unsigned param_id = 0;
			for (void* param : yyloc.param_list) {
				if (param != nullptr) {
					Expr* expr = (Expr*) param;
					expr->ival = param_id;
					result->addParameter(expr);
					++param_id;
				}
			}
			delete (yyvsp[-1].stmt_vec);
		}
#line 2681 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 277 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[0].statement)->stringLength = yylloc.string_length;
			yylloc.string_length = 0;
			(yyval.stmt_vec) = new std::vector<SQLStatement*>();
			(yyval.stmt_vec)->push_back((yyvsp[0].statement));
		}
#line 2692 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 283 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[0].statement)->stringLength = yylloc.string_length;
			yylloc.string_length = 0;
			(yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
			(yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
		}
#line 2703 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 292 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.statement) = (yyvsp[-1].prep_stmt);
			(yyval.statement)->hints = (yyvsp[0].expr_vec);
		}
#line 2712 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 296 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.statement) = (yyvsp[-1].statement);
			(yyval.statement)->hints = (yyvsp[0].expr_vec);
		}
#line 2721 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 300 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.statement) = (yyvsp[0].show_stmt);
		}
#line 2729 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 303 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.statement) = (yyvsp[0].use_stmt);
	}
#line 2737 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 310 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 2743 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 311 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 2749 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 312 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 2755 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 313 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 2761 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 314 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2767 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 315 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2773 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 316 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 2779 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 317 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 2785 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 318 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 2791 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 327 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 2797 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 328 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = nullptr; }
#line 2803 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 333 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 2809 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 334 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 2815 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 338 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = Expr::make(kExprHint);
			(yyval.expr)->name = (yyvsp[0].sval);
		}
#line 2824 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 342 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = Expr::make(kExprHint);
			(yyval.expr)->name = (yyvsp[-3].sval);
			(yyval.expr)->exprList = (yyvsp[-1].expr_vec);
		}
#line 2834 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 354 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-2].sval);
			(yyval.prep_stmt)->query = (yyvsp[0].sval);
		}
#line 2844 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 364 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[0].sval);
		}
#line 2853 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 368 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[-3].sval);
			(yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
		}
#line 2863 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 380 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.import_stmt) = new ImportStatement((ImportType) (yyvsp[-4].uval));
			(yyval.import_stmt)->filePath = (yyvsp[-2].sval);
			(yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
		}
#line 2874 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 389 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kImportCSV; }
#line 2880 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 393 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = _strdup((yyvsp[0].expr)->name); delete (yyvsp[0].expr); }
#line 2886 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 403 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.show_stmt) = new ShowStatement(kShowTables);
		}
#line 2894 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 406 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.show_stmt) = new ShowStatement(kShowColumns);
			(yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.show_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 2904 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 411 "bison_parser.y" /* yacc.c:1646  */
    {
		(yyval.show_stmt) = new ShowStatement(kShowSchemas);
	}
#line 2912 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 422 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.use_stmt)=new UseStatement();
			(yyval.use_stmt)->schema=(yyvsp[0].table_name).name;
		}
#line 2921 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 433 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateTableFromTbl);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-5].bval);
			(yyval.create_stmt)->schema = (yyvsp[-4].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-4].table_name).name;
			(yyval.create_stmt)->filePath = (yyvsp[0].sval);
		}
#line 2933 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 440 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateTable);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->columns = (yyvsp[-1].column_vec);
		}
#line 2945 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 447 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateView);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
			(yyval.create_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 2958 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 455 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt)=new CreateStatement(kCreateSchema);
			(yyval.create_stmt)->schema =(yyvsp[0].table_name).name;
		}
#line 2967 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 459 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt)=new CreateStatement(kCreateIndex);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->onWhich =(yyvsp[-1].table_name).name;
		}
#line 2978 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 468 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 2984 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 469 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 2990 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 473 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_vec) = new std::vector<ColumnDefinition*>(); (yyval.column_vec)->push_back((yyvsp[0].column_t)); }
#line 2996 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 474 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].column_vec)->push_back((yyvsp[0].column_t)); (yyval.column_vec) = (yyvsp[-2].column_vec); }
#line 3002 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 478 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].bval));
		}
#line 3010 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 484 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3016 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 485 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 3022 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 486 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 3028 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 487 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 3034 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 488 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3040 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 489 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3046 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 490 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3052 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 491 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3058 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 495 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 3064 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 496 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 3070 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 497 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 3076 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 507 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropTable);
			(yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
			(yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 3087 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 513 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropView);
			(yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
			(yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 3098 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 519 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
			(yyval.drop_stmt)->ifExists = false;
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 3108 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 527 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 3114 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 528 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 3120 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 537 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
			(yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
			(yyval.delete_stmt)->expr = (yyvsp[0].expr);
		}
#line 3131 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 546 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
		}
#line 3141 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 559 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.insert_stmt) = new InsertStatement(kInsertValues);
			(yyval.insert_stmt)->schema = (yyvsp[-5].table_name).schema;
			(yyval.insert_stmt)->tableName = (yyvsp[-5].table_name).name;
			(yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
			(yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
		}
#line 3153 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 566 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.insert_stmt) = new InsertStatement(kInsertSelect);
			(yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
			(yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
			(yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
			(yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 3165 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 577 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 3171 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 578 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = nullptr; }
#line 3177 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 588 "bison_parser.y" /* yacc.c:1646  */
    {
		(yyval.update_stmt) = new UpdateStatement();
		(yyval.update_stmt)->table = (yyvsp[-3].table);
		(yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
		(yyval.update_stmt)->where = (yyvsp[0].expr);
	}
#line 3188 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 597 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.update_vec) = new std::vector<UpdateClause*>(); (yyval.update_vec)->push_back((yyvsp[0].update_t)); }
#line 3194 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 598 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t)); (yyval.update_vec) = (yyvsp[-2].update_vec); }
#line 3200 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 602 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.update_t) = new UpdateClause();
			(yyval.update_t)->column = (yyvsp[-2].sval);
			(yyval.update_t)->value = (yyvsp[0].expr);
		}
#line 3210 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 616 "bison_parser.y" /* yacc.c:1646  */
    {
			// TODO: allow multiple unions (through linked list)
			// TODO: capture type of set_operator
			// TODO: might overwrite order and limit of first select here
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->unionSelect = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != nullptr) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 3229 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 633 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3235 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 634 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3241 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 643 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != nullptr) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 3256 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 653 "bison_parser.y" /* yacc.c:1646  */
    {
			// TODO: allow multiple unions (through linked list)
			// TODO: capture type of set_operator
			// TODO: might overwrite order and limit of first select here
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->unionSelect = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != nullptr) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 3275 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 685 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = new SelectStatement();
			(yyval.select_stmt)->limit = (yyvsp[-5].limit);
			(yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
			(yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
			(yyval.select_stmt)->fromTable = (yyvsp[-2].table);
			(yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
			(yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
		}
#line 3289 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 697 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 3295 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 698 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 3301 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 706 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table) = (yyvsp[0].table); }
#line 3307 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 707 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table) = nullptr; }
#line 3313 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 710 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table) = (yyvsp[0].table); }
#line 3319 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 715 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3325 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 716 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = nullptr; }
#line 3331 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 720 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.group_t) = new GroupByDescription();
			(yyval.group_t)->columns = (yyvsp[-1].expr_vec);
			(yyval.group_t)->having = (yyvsp[0].expr);
		}
#line 3341 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 725 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.group_t) = nullptr; }
#line 3347 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 729 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3353 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 730 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = nullptr; }
#line 3359 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 733 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 3365 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 734 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = nullptr; }
#line 3371 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 738 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = new std::vector<OrderDescription*>(); (yyval.order_vec)->push_back((yyvsp[0].order)); }
#line 3377 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 739 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].order_vec)->push_back((yyvsp[0].order)); (yyval.order_vec) = (yyvsp[-2].order_vec); }
#line 3383 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 743 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 3389 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 747 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderAsc; }
#line 3395 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 748 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderDesc; }
#line 3401 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 749 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderAsc; }
#line 3407 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 755 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 3413 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 756 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = nullptr; }
#line 3419 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 760 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 3425 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 761 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[-2].expr)->ival, (yyvsp[0].expr)->ival); delete (yyvsp[-2].expr); delete (yyvsp[0].expr); }
#line 3431 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 762 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3437 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 763 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = nullptr; }
#line 3443 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 764 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = nullptr;  }
#line 3449 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 765 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3455 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 766 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3461 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 767 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = nullptr; }
#line 3467 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 774 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3473 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 775 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3479 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 779 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3485 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 780 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3491 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 784 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = (yyvsp[-1].expr);
			if ((yyvsp[0].alias_t)) {
				(yyval.expr)->alias = _strdup((yyvsp[0].alias_t)->name);
				delete (yyvsp[0].alias_t);
			}
		}
#line 3503 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 802 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 3509 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 811 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt)); }
#line 3515 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 820 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 3521 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 821 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 3527 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 822 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 3533 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 823 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 3539 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 824 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 3545 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 829 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 3551 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 830 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 3557 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 831 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 3563 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 832 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 3569 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 833 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 3575 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 834 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 3581 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 835 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 3587 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 836 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 3593 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 837 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 3599 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 838 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 3605 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 842 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 3611 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 843 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 3617 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 847 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 3623 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 848 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 3629 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 849 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 3635 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 850 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 3641 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 856 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 3647 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 857 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3653 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 858 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 3659 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 859 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3665 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 863 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 3671 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 864 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 3677 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 868 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 3683 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 869 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 3689 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 873 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 3695 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 874 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 3701 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 875 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 3707 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 876 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 3713 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 877 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 3719 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 878 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 3725 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 879 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 3731 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 883 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 3737 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 884 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 3743 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 888 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 3749 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 892 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeSecond; }
#line 3755 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 893 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeMinute; }
#line 3761 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 894 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeHour; }
#line 3767 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 895 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeDay; }
#line 3773 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 896 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeMonth; }
#line 3779 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 897 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeYear; }
#line 3785 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 900 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 3791 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 904 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 3797 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 908 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3803 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 912 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 3809 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 913 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 3815 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 914 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeStar(); }
#line 3821 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 915 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 3827 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 927 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 3833 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 931 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral(true); }
#line 3839 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 932 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral(false); }
#line 3845 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 936 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 3851 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 941 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 3857 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 945 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 3863 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 949 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = Expr::makeParameter(yylloc.total_column);
			(yyval.expr)->ival2 = yyloc.param_list.size();
			yyloc.param_list.push_back((yyval.expr));
		}
#line 3873 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 962 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
			auto tbl = new TableRef(kTableCrossProduct);
			tbl->list = (yyvsp[-2].table_vec);
			(yyval.table) = tbl;
		}
#line 3884 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 978 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].alias_t);
			(yyval.table) = tbl;
		}
#line 3895 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 987 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table_vec) = new std::vector<TableRef*>(); (yyval.table_vec)->push_back((yyvsp[0].table)); }
#line 3901 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 988 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].table_vec)->push_back((yyvsp[0].table)); (yyval.table_vec) = (yyvsp[-2].table_vec); }
#line 3907 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 993 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableName);
			tbl->schema = (yyvsp[-1].table_name).schema;
			tbl->name = (yyvsp[-1].table_name).name;
			tbl->alias = (yyvsp[0].alias_t);
			(yyval.table) = tbl;
		}
#line 3919 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1004 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableName);
			(yyval.table)->schema = (yyvsp[0].table_name).schema;
			(yyval.table)->name = (yyvsp[0].table_name).name;
		}
#line 3929 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1013 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table_name).schema = nullptr; (yyval.table_name).name = (yyvsp[0].sval);}
#line 3935 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1014 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table_name).schema = (yyvsp[-2].sval); (yyval.table_name).name = (yyvsp[0].sval); }
#line 3941 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1020 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 3947 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1026 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = nullptr; }
#line 3953 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1030 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 3959 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1031 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 3965 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1037 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = nullptr; }
#line 3971 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1046 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = kJoinNatural;
			(yyval.table)->join->left = (yyvsp[-3].table);
			(yyval.table)->join->right = (yyvsp[0].table);
		}
#line 3983 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1054 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-4].uval);
			(yyval.table)->join->left = (yyvsp[-5].table);
			(yyval.table)->join->right = (yyvsp[-2].table);
			(yyval.table)->join->condition = (yyvsp[0].expr);
		}
#line 3996 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1064 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-6].uval);
			(yyval.table)->join->left = (yyvsp[-7].table);
			(yyval.table)->join->right = (yyvsp[-4].table);
			auto left_col = Expr::makeColumnRef(_strdup((yyvsp[-1].expr)->name));
			if ((yyvsp[-1].expr)->alias != nullptr) left_col->alias = _strdup((yyvsp[-1].expr)->alias);
			if ((yyvsp[-7].table)->getName() != nullptr) left_col->table = _strdup((yyvsp[-7].table)->getName());
			auto right_col = Expr::makeColumnRef(_strdup((yyvsp[-1].expr)->name));
			if ((yyvsp[-1].expr)->alias != nullptr) right_col->alias = _strdup((yyvsp[-1].expr)->alias);
			if ((yyvsp[-4].table)->getName() != nullptr) right_col->table = _strdup((yyvsp[-4].table)->getName());
			(yyval.table)->join->condition = Expr::makeOpBinary(left_col, kOpEquals, right_col);
			delete (yyvsp[-1].expr);
		}
#line 4016 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1082 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinInner; }
#line 4022 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1083 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinLeft; }
#line 4028 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1084 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinLeft; }
#line 4034 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1085 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinRight; }
#line 4040 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1086 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinRight; }
#line 4046 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1087 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinFull; }
#line 4052 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1088 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinFull; }
#line 4058 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1089 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinFull; }
#line 4064 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1090 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinCross; }
#line 4070 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1091 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinInner; }
#line 4076 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1111 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = new std::vector<char*>(); (yyval.str_vec)->push_back((yyvsp[0].sval)); }
#line 4082 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1112 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval)); (yyval.str_vec) = (yyvsp[-2].str_vec); }
#line 4088 "bison_parser.tab.c" /* yacc.c:1646  */
    break;


#line 4092 "bison_parser.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
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
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, result, scanner);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, result, scanner);
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
  return yyresult;
}
#line 1115 "bison_parser.y" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */

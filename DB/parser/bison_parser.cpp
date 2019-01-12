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

#line 162 "bison_parser.tab.c" /* yacc.c:355  */

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
    SQL_EQUALS = 394,
    SQL_NOTEQUALS = 395,
    SQL_LESS = 396,
    SQL_GREATER = 397,
    SQL_LESSEQ = 398,
    SQL_GREATEREQ = 399,
    SQL_NOTNULL = 400,
    SQL_UMINUS = 401
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

#line 363 "bison_parser.tab.c" /* yacc.c:355  */
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



/* Copy the second part of user declarations.  */

#line 393 "bison_parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   683

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  239
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  433

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   401

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   153,     2,     2,
     158,   159,   151,   149,   162,   150,   160,   152,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   161,
     142,   139,   143,   163,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   156,     2,   157,   154,     2,     2,     2,     2,     2,
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
     135,   136,   137,   138,   140,   141,   144,   145,   146,   147,
     148,   155
};

#if HSQL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   254,   254,   275,   281,   290,   294,   298,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   322,   323,   328,
     329,   333,   337,   349,   356,   359,   363,   375,   384,   388,
     398,   401,   406,   418,   425,   432,   440,   447,   448,   452,
     453,   457,   463,   464,   465,   466,   467,   468,   469,   470,
     474,   475,   476,   486,   492,   498,   506,   507,   516,   525,
     538,   545,   556,   557,   567,   576,   577,   581,   593,   594,
     595,   612,   613,   617,   618,   622,   632,   649,   653,   654,
     655,   659,   660,   664,   676,   677,   681,   685,   686,   689,
     694,   695,   699,   704,   708,   709,   712,   713,   717,   718,
     722,   726,   727,   728,   734,   735,   739,   740,   741,   742,
     743,   744,   745,   746,   753,   754,   758,   759,   763,   773,
     774,   775,   776,   777,   781,   782,   783,   784,   785,   786,
     787,   788,   789,   790,   794,   795,   799,   800,   801,   802,
     803,   807,   808,   809,   810,   811,   812,   813,   814,   815,
     816,   817,   821,   822,   826,   827,   828,   829,   835,   836,
     837,   838,   842,   843,   847,   848,   852,   853,   854,   855,
     856,   857,   858,   862,   863,   867,   871,   872,   873,   874,
     875,   876,   879,   883,   887,   891,   892,   893,   894,   898,
     899,   900,   901,   902,   906,   910,   911,   915,   916,   920,
     924,   928,   940,   941,   951,   952,   956,   957,   966,   967,
     972,   983,   992,   993,   998,   999,  1004,  1005,  1009,  1010,
    1015,  1016,  1024,  1032,  1042,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1075,  1084,  1085,  1090,  1091
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
  "FALSE", "DATABASES", "'='", "EQUALS", "NOTEQUALS", "'<'", "'>'", "LESS",
  "GREATER", "LESSEQ", "GREATEREQ", "NOTNULL", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'^'", "UMINUS", "'['", "']'", "'('", "')'", "'.'", "';'", "','",
  "'?'", "$accept", "input", "statement_list", "statement",
  "preparable_statement", "opt_hints", "hint_list", "hint",
  "prepare_statement", "prepare_target_query", "execute_statement",
  "import_statement", "import_file_type", "file_path", "show_statement",
  "create_statement", "opt_not_exists", "column_def_commalist",
  "column_def", "column_type", "opt_column_nullable", "drop_statement",
  "opt_exists", "delete_statement", "truncate_statement",
  "insert_statement", "opt_column_list", "update_statement",
  "update_clause_commalist", "update_clause", "select_statement",
  "select_with_paren", "select_paren_or_clause", "select_no_paren",
  "set_operator", "set_type", "opt_all", "select_clause", "opt_distinct",
  "select_list", "opt_from_clause", "from_clause", "opt_where",
  "opt_group", "opt_having", "opt_order", "order_list", "order_desc",
  "opt_order_type", "opt_top", "opt_limit", "expr_list", "literal_list",
  "expr_alias", "expr", "operand", "scalar_expr", "unary_expr",
  "binary_expr", "logic_expr", "in_expr", "case_expr", "case_list",
  "exists_expr", "comp_expr", "function_expr", "extract_expr",
  "datetime_field", "array_expr", "array_index", "between_expr",
  "column_name", "literal", "string_literal", "bool_literal",
  "num_literal", "int_literal", "null_literal", "param_expr", "table_ref",
  "table_ref_atomic", "nonjoin_table_ref_atomic", "table_ref_commalist",
  "table_ref_name", "table_ref_name_no_alias", "table_name", "table_alias",
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
     385,   386,   387,   388,   389,   390,   391,   392,   393,    61,
     394,   395,    60,    62,   396,   397,   398,   399,   400,    43,
      45,    42,    47,    37,    94,   401,    91,    93,    40,    41,
      46,    59,    44,    63
};
# endif

#define YYPACT_NINF -335

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-335)))

#define YYTABLE_NINF -235

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-235)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     296,    -5,    44,    45,    52,    -7,   -29,     7,    32,   -27,
      44,     8,     1,   -40,   104,   -26,  -335,    68,    68,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,    17,
    -335,    23,   169,    26,  -335,    24,   110,    44,    92,    92,
      44,   112,    44,   215,   221,   137,  -335,   136,   136,    44,
    -335,  -335,   149,   150,  -335,   296,  -335,   174,  -335,  -335,
    -335,  -335,  -335,   -40,   175,   163,   -40,   -14,  -335,   288,
      25,   291,  -335,   212,    44,    44,   257,  -335,   250,   177,
    -335,  -335,  -335,   127,   333,   299,    44,    44,  -335,  -335,
    -335,  -335,   187,  -335,   278,  -335,  -335,  -335,   127,   278,
     215,     6,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
      21,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
     308,   -76,   177,   127,  -335,   346,   351,   122,    85,   199,
     200,   123,   226,   203,   295,  -335,   193,   275,   202,  -335,
      75,   321,  -335,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,  -335,  -335,  -335,  -335,  -335,  -335,   222,   -63,  -335,
    -335,  -335,  -335,   362,   -14,   204,  -335,   103,   -14,  -335,
     319,   322,   323,  -335,    25,  -335,   253,   369,   256,   101,
     286,  -335,  -335,   107,   223,  -335,    11,    15,   328,   182,
     127,   121,    13,   224,   295,   405,   127,    63,   227,   -92,
       5,   257,  -335,   127,  -335,   127,   380,   127,  -335,  -335,
     295,  -335,   295,   -68,   229,    30,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   215,   127,   333,  -335,   230,   113,  -335,  -335,   127,
    -335,  -335,  -335,  -335,   215,   215,   215,  -335,   310,   572,
     117,  -335,   -40,    44,  -335,   393,    25,  -335,   127,  -335,
    -335,   238,  -335,  -335,  -335,  -335,  -335,  -335,   313,    86,
      36,   127,   127,  -335,   328,   307,   -57,  -335,  -335,   -40,
    -335,   -21,  -335,   239,  -335,    18,  -335,   337,  -335,  -335,
    -335,   297,   363,   440,   295,   244,   193,  -335,   309,   249,
     440,   440,   440,   440,   473,   473,   473,   473,    63,    63,
     -83,   -83,   -83,   -49,   252,   101,  -335,    25,  -335,   362,
    -335,  -335,  -335,  -335,   346,  -335,   254,  -335,  -335,   258,
    -335,  -335,  -335,   142,  -335,   369,  -335,  -335,  -335,   125,
     130,  -335,   127,   127,   127,  -335,   132,    88,   248,  -335,
     255,   325,  -335,  -335,  -335,   347,   348,   349,   327,     5,
     418,  -335,  -335,  -335,   304,  -335,   295,   440,   193,   265,
     135,  -335,  -335,   143,  -335,  -335,   419,   420,  -335,   332,
    -335,  -335,  -335,  -335,   -79,   101,   133,  -335,   127,  -335,
      18,     5,  -335,  -335,  -335,     5,    12,   270,   127,   405,
     271,   148,  -335,  -335,  -335,   274,   276,  -335,  -335,  -335,
     101,  -335,  -335,   320,   351,   -28,  -335,  -335,  -335,  -335,
     279,   127,   160,   127,  -335,    16,   101,  -335,  -335,   101,
     269,   277,  -335
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,   237,     3,    18,    18,    16,
       9,     7,    10,    15,    12,    13,    11,    14,     8,    68,
      69,    97,     0,   212,    59,    25,     0,     0,    38,    38,
       0,     0,     0,     0,    85,     0,   211,    57,    57,     0,
      30,    32,     0,     0,     1,   236,     2,     0,     6,     5,
      79,    80,    78,     0,    82,     0,     0,   113,    55,     0,
       0,     0,    36,     0,     0,     0,    91,    28,     0,    63,
     199,   104,    84,     0,     0,     0,     0,     0,    31,    72,
      71,     4,     0,    73,    97,    74,    81,    77,     0,    97,
       0,     0,    75,   213,   194,   197,   200,   195,   196,   201,
       0,   116,   189,   190,   191,   198,   192,   193,    24,    23,
       0,     0,    63,     0,    58,     0,     0,     0,   185,     0,
       0,     0,     0,     0,     0,   187,     0,    88,    86,   114,
     221,   119,   126,   127,   128,   121,   123,   129,   122,   141,
     130,   131,   132,   125,   120,   134,   135,     0,    91,    65,
      56,    53,    54,     0,   113,    96,    98,   103,   113,   108,
     110,   109,   106,    26,     0,    37,     0,     0,     0,    90,
       0,    29,   238,     0,     0,    61,    85,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,   136,     0,     0,
       0,    91,    87,     0,   219,     0,     0,     0,   220,   118,
       0,   138,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,    21,     0,    19,    70,     0,
     102,   101,   100,    76,     0,     0,     0,   117,     0,     0,
       0,    39,     0,     0,    62,     0,     0,   173,     0,   186,
     188,     0,   176,   177,   178,   179,   180,   181,     0,     0,
       0,     0,     0,   160,     0,     0,     0,   133,   124,     0,
      89,   202,   204,     0,   206,   217,   205,    93,   115,   152,
     218,   153,     0,   148,     0,     0,     0,   139,     0,   151,
     150,   166,   167,   168,   169,   170,   171,   172,   143,   142,
     145,   144,   146,   147,     0,    67,    66,     0,    17,     0,
      99,   112,   111,   107,     0,    43,     0,    46,    45,     0,
      44,    49,    42,    52,    34,     0,    35,    27,   239,     0,
       0,   164,     0,     0,     0,   158,     0,     0,     0,   182,
       0,     0,   233,   225,   231,   229,   232,   227,     0,     0,
       0,   216,   210,   214,     0,    83,     0,   149,     0,     0,
       0,   140,   183,     0,    20,    33,     0,     0,    50,     0,
      41,    40,    60,   174,     0,   162,     0,   161,     0,   165,
     217,     0,   228,   230,   226,     0,   203,   218,     0,   184,
       0,     0,   156,   154,    22,     0,     0,    51,   175,   159,
     163,   207,   222,   234,     0,    95,   157,   155,    47,    48,
       0,     0,     0,     0,    92,     0,   235,   223,   215,    94,
     185,     0,   224
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -335,  -335,  -335,   383,  -335,   421,  -335,   128,  -335,  -335,
    -335,  -335,  -335,   116,  -335,  -335,   402,  -335,   124,  -335,
    -335,  -335,   400,  -335,  -335,  -335,   329,  -335,  -335,   232,
    -163,    22,   390,   -13,   426,  -335,  -335,   261,   280,  -335,
    -335,  -335,  -141,  -335,  -335,   171,  -335,   240,  -335,  -335,
     -51,  -190,  -241,   281,   -95,   -70,  -335,  -335,  -335,  -335,
    -335,  -335,   287,  -335,  -335,  -335,  -335,  -335,  -335,  -335,
    -335,    55,   -66,  -118,  -335,  -335,   -42,  -335,  -335,  -335,
    -334,    90,  -335,  -335,  -335,     0,  -335,    93,   342,  -335,
    -335,  -335,  -335,  -335,    72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    58,   236,   237,    18,   119,
      19,    20,    78,   180,    21,    22,    74,   250,   251,   333,
     380,    23,    86,    24,    25,    26,   127,    27,   158,   159,
      28,    29,    94,    30,    63,    64,    97,    31,    83,   137,
     201,   202,   124,   365,   424,    67,   165,   166,   242,    44,
     102,   138,   110,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   192,   148,   149,   150,   151,   268,   152,   153,
     154,   155,   156,   112,   113,   114,   115,   116,   117,   280,
     281,   282,   283,   284,    45,   285,   361,   362,   363,   209,
     286,   358,   427,    56,   183
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    81,    34,   167,   111,   351,   276,   181,    33,   176,
      46,     9,    80,   123,   205,   339,   423,   234,   259,   430,
      49,   204,    32,    82,   294,   396,    60,   205,   179,   104,
     105,    80,    60,   207,   100,    52,   191,    72,   351,   352,
      76,   199,    79,    37,   353,   216,   207,    33,    35,    88,
     354,   355,   101,   295,    50,    36,    40,    61,   169,   172,
     287,   413,   195,    61,   197,   356,    38,   278,   340,  -234,
     357,   230,   352,   231,   121,   122,   373,   353,   204,   216,
     408,    47,   177,   354,   355,    93,   161,   162,    93,   336,
      43,    62,    41,    65,    39,   269,   271,    62,   356,   233,
     349,   170,  -234,   357,    54,   203,   370,   231,   247,    48,
     289,   171,   291,   238,   185,   272,   350,   243,    13,   344,
     106,    42,   273,   198,   195,   297,   128,   104,   105,    80,
     128,   104,   105,    80,   203,    55,   360,   315,   272,    51,
     292,  -208,   293,   298,   167,   345,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   107,   108,   279,   129,   130,   260,   135,   129,   130,
     257,    57,    68,     9,  -209,   261,   346,   347,   401,   184,
     173,   205,    70,   174,   240,   343,    69,   388,   109,   314,
     111,   216,   205,   206,   205,    71,   128,   104,   105,    80,
     207,   131,   321,   322,   323,   131,   181,   205,   415,   205,
     241,   207,    73,   207,   227,   228,   229,   230,   106,   231,
      77,    80,   106,   190,   367,   190,   207,   205,   207,   128,
     104,   105,    80,    82,   129,   130,   132,   378,   205,   205,
     132,   387,   409,   186,     9,   187,   207,   384,   385,   386,
     133,   111,    84,   337,   133,   379,    85,   207,   207,   107,
     108,   348,    92,   107,   108,   164,   254,   193,   130,   255,
     168,   131,   318,   134,   135,   319,   334,   134,   135,   335,
      96,   136,    98,   369,   382,   136,   109,   174,   106,   383,
     109,   103,   203,   410,   403,   118,   399,   203,   128,   104,
     105,    80,   404,     1,   131,   174,   132,   417,    89,    90,
     203,     2,   262,   263,   264,   265,   266,   267,     3,   428,
     133,   106,   255,     4,    95,   120,   426,    95,   429,   107,
     108,     5,     6,   123,   125,   126,   157,   130,   210,   194,
     160,     7,     8,   134,   135,   163,   351,     9,    65,   175,
     104,   136,    10,   133,   182,   400,   109,   188,   189,   196,
     200,   232,   107,   108,   203,   235,   239,   244,   211,   248,
     245,   246,   249,   131,   252,   253,   134,   135,    11,     9,
     352,   256,   274,   290,   136,   353,   277,   296,   317,   109,
     106,   354,   355,    12,   324,   420,   338,   341,   342,   294,
     364,   359,   368,   205,   371,   231,   356,   389,   194,   372,
     211,   357,   376,   212,   390,   391,   377,   395,   392,   393,
     394,   397,   133,   398,   402,   405,   406,   407,   414,   187,
     416,   107,   108,   418,   213,   419,   432,   425,    91,    59,
     375,    75,   214,   215,   421,   134,   135,   374,    87,   216,
     217,   178,   211,   136,    13,   212,    99,    66,   109,   381,
     218,   219,   220,   221,   222,   316,   258,   223,   224,   366,
     225,   226,   227,   228,   229,   230,   275,   231,   270,   320,
     431,   412,   208,   411,   288,   215,   422,   211,     0,     0,
       0,   216,   217,     0,     0,     0,     0,   212,     0,     0,
       0,     0,   218,   219,   220,   221,   222,     0,     0,   223,
     224,     0,   225,   226,   227,   228,   229,   230,   275,   231,
     211,     0,     0,     0,     0,     0,     0,   215,     0,     0,
       0,     0,  -235,   216,   217,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,   219,   220,   221,   222,     0,
       0,   223,   224,     0,   225,   226,   227,   228,   229,   230,
       0,   231,   215,     0,     0,     0,     0,     0,   216,  -235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -235,
    -235,  -235,   221,   222,     0,     0,   223,   224,     0,   225,
     226,   227,   228,   229,   230,   215,   231,   325,     0,     0,
       0,   216,     0,   326,     0,     0,     0,     0,     0,     0,
     327,     0,     0,     0,     0,  -235,  -235,     0,     0,  -235,
    -235,     0,   225,   226,   227,   228,   229,   230,     0,   231,
       0,     0,     0,     0,   328,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   329,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   330,     0,     0,     0,
     331,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   332
};

static const yytype_int16 yycheck[] =
{
      13,    43,     2,    98,    70,    26,   196,   125,     3,    85,
      10,    51,     6,    76,   106,   256,    44,   158,     3,     3,
      19,     3,    27,    12,    92,   359,     9,   106,   123,     4,
       5,     6,     9,   125,    48,    13,   131,    37,    26,    60,
      40,   136,    42,    50,    65,   128,   125,     3,     3,    49,
      71,    72,    66,   121,    53,     3,    85,    40,   100,   101,
     201,   395,   132,    40,   134,    86,    73,   159,   258,    90,
      91,   154,    60,   156,    74,    75,   317,    65,     3,   128,
     159,    73,   158,    71,    72,    63,    86,    87,    66,   252,
     117,    74,    85,    70,   101,   190,    83,    74,    86,   162,
     157,    95,    90,    91,     0,   162,   296,   156,   174,   101,
     205,   105,   207,   164,   127,   102,   279,   168,   158,    83,
      95,    89,   109,   136,   194,    95,     3,     4,     5,     6,
       3,     4,     5,     6,   162,   161,   118,   232,   102,   138,
     210,   162,   212,   113,   239,   109,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   136,   137,   158,    41,    42,   151,   151,    41,    42,
     159,   103,     3,    51,   162,   188,   271,   272,   368,    57,
     159,   106,   158,   162,    81,    99,   160,    99,   163,   231,
     256,   128,   106,   118,   106,    85,     3,     4,     5,     6,
     125,    78,   244,   245,   246,    78,   324,   106,   398,   106,
     107,   125,   120,   125,   151,   152,   153,   154,    95,   156,
     108,     6,    95,   102,   294,   102,   125,   106,   125,     3,
       4,     5,     6,    12,    41,    42,   113,    95,   106,   106,
     113,   109,   109,   158,    51,   160,   125,   342,   343,   344,
     127,   317,   115,   253,   127,   113,   120,   125,   125,   136,
     137,   274,    88,   136,   137,    94,   159,    41,    42,   162,
      99,    78,   159,   150,   151,   162,   159,   150,   151,   162,
     105,   158,   119,   296,   159,   158,   163,   162,    95,   159,
     163,     3,   162,   388,   159,     4,   366,   162,     3,     4,
       5,     6,   159,     7,    78,   162,   113,   159,   159,   159,
     162,    15,   130,   131,   132,   133,   134,   135,    22,   159,
     127,    95,   162,    27,    63,   113,   421,    66,   423,   136,
     137,    35,    36,    76,    84,   158,     3,    42,    17,   113,
      41,    45,    46,   150,   151,   158,    26,    51,    70,    41,
       4,   158,    56,   127,     3,   368,   163,   158,   158,   156,
      85,   139,   136,   137,   162,     3,   162,    48,    47,   116,
      48,    48,     3,    78,   118,    89,   150,   151,    82,    51,
      60,   158,   158,     3,   158,    65,   159,   158,   158,   163,
      95,    71,    72,    97,    84,    75,     3,   159,    85,    92,
      63,   162,   158,   106,    95,   156,    86,   159,   113,   157,
      47,    91,   158,    92,   159,    90,   158,    90,    71,    71,
      71,     3,   127,   119,   159,     6,     6,    95,   158,   160,
     159,   136,   137,   159,   113,   159,   159,   158,    55,    18,
     324,    39,   121,   122,   124,   150,   151,   319,    48,   128,
     129,   122,    47,   158,   158,    92,    66,    31,   163,   335,
     139,   140,   141,   142,   143,   233,   186,   146,   147,   106,
     149,   150,   151,   152,   153,   154,   113,   156,   191,   239,
     425,   391,   140,   390,   203,   122,   414,    47,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,   139,   140,   141,   142,   143,    -1,    -1,   146,
     147,    -1,   149,   150,   151,   152,   153,   154,   113,   156,
      47,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,    -1,    92,   128,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,    -1,
      -1,   146,   147,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   122,    -1,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,    -1,    -1,   146,   147,    -1,   149,
     150,   151,   152,   153,   154,   122,   156,    25,    -1,    -1,
      -1,   128,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,   142,   143,    -1,    -1,   146,
     147,    -1,   149,   150,   151,   152,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     7,    15,    22,    27,    35,    36,    45,    46,    51,
      56,    82,    97,   158,   165,   166,   167,   168,   172,   174,
     175,   178,   179,   185,   187,   188,   189,   191,   194,   195,
     197,   201,    27,     3,   249,     3,     3,    50,    73,   101,
      85,    85,    89,   117,   213,   248,   249,    73,   101,    19,
      53,   138,   195,   197,     0,   161,   257,   103,   169,   169,
       9,    40,    74,   198,   199,    70,   198,   209,     3,   160,
     158,    85,   249,   120,   180,   180,   249,   108,   176,   249,
       6,   240,    12,   202,   115,   120,   186,   186,   249,   159,
     159,   167,    88,   195,   196,   201,   105,   200,   119,   196,
      48,    66,   214,     3,     4,     5,    95,   136,   137,   163,
     216,   236,   237,   238,   239,   240,   241,   242,     4,   173,
     113,   249,   249,    76,   206,    84,   158,   190,     3,    41,
      42,    78,   113,   127,   150,   151,   158,   203,   215,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   227,   228,
     229,   230,   232,   233,   234,   235,   236,     3,   192,   193,
      41,   249,   249,   158,   209,   210,   211,   218,   209,   240,
      95,   105,   240,   159,   162,    41,    85,   158,   190,   218,
     177,   237,     3,   258,    57,   197,   158,   160,   158,   158,
     102,   218,   226,    41,   113,   219,   156,   219,   197,   218,
      85,   204,   205,   162,     3,   106,   118,   125,   252,   253,
      17,    47,    92,   113,   121,   122,   128,   129,   139,   140,
     141,   142,   143,   146,   147,   149,   150,   151,   152,   153,
     154,   156,   139,   162,   206,     3,   170,   171,   214,   162,
      81,   107,   212,   214,    48,    48,    48,   236,   116,     3,
     181,   182,   118,    89,   159,   162,   158,   159,   202,     3,
     151,   197,   130,   131,   132,   133,   134,   135,   231,   218,
     226,    83,   102,   109,   158,   113,   215,   159,   159,   158,
     243,   244,   245,   246,   247,   249,   254,   206,   217,   218,
       3,   218,   219,   219,    92,   121,   158,    95,   113,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   240,   218,   193,   158,   159,   162,
     211,   240,   240,   240,    84,    25,    31,    38,    62,    79,
      94,    98,   111,   183,   159,   162,   194,   249,     3,   216,
     215,   159,    85,    99,    83,   109,   218,   218,   197,   157,
     194,    26,    60,    65,    71,    72,    86,    91,   255,   162,
     118,   250,   251,   252,    63,   207,   106,   219,   158,   197,
     215,    95,   157,   216,   171,   177,   158,   158,    95,   113,
     184,   182,   159,   159,   218,   218,   218,   109,    99,   159,
     159,    90,    71,    71,    71,    90,   244,     3,   119,   219,
     197,   215,   159,   159,   159,     6,     6,    95,   159,   109,
     218,   251,   245,   244,   158,   215,   159,   159,   159,   159,
      75,   124,   258,    44,   208,   158,   218,   256,   159,   218,
       3,   235,   159
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   164,   165,   166,   166,   167,   167,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   173,   174,   174,   175,   176,   177,
     178,   178,   178,   179,   179,   179,   179,   180,   180,   181,
     181,   182,   183,   183,   183,   183,   183,   183,   183,   183,
     184,   184,   184,   185,   185,   185,   186,   186,   187,   188,
     189,   189,   190,   190,   191,   192,   192,   193,   194,   194,
     194,   195,   195,   196,   196,   197,   197,   198,   199,   199,
     199,   200,   200,   201,   202,   202,   203,   204,   204,   205,
     206,   206,   207,   207,   208,   208,   209,   209,   210,   210,
     211,   212,   212,   212,   213,   213,   214,   214,   214,   214,
     214,   214,   214,   214,   215,   215,   216,   216,   217,   218,
     218,   218,   218,   218,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   220,   220,   221,   221,   221,   221,
     221,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   223,   223,   224,   224,   224,   224,   225,   225,
     225,   225,   226,   226,   227,   227,   228,   228,   228,   228,
     228,   228,   228,   229,   229,   230,   231,   231,   231,   231,
     231,   231,   232,   233,   234,   235,   235,   235,   235,   236,
     236,   236,   236,   236,   237,   238,   238,   239,   239,   240,
     241,   242,   243,   243,   244,   244,   245,   245,   246,   246,
     247,   248,   249,   249,   250,   250,   251,   251,   252,   252,
     253,   253,   254,   254,   254,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   256,   257,   257,   258,   258
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     0,     1,
       3,     1,     4,     4,     1,     2,     5,     7,     1,     1,
       2,     3,     2,     8,     7,     7,     3,     3,     0,     1,
       3,     3,     1,     1,     1,     1,     1,     4,     4,     1,
       1,     2,     0,     4,     4,     3,     2,     0,     4,     2,
       8,     5,     3,     0,     5,     1,     3,     3,     1,     1,
       5,     3,     3,     1,     1,     3,     5,     2,     1,     1,
       1,     1,     0,     7,     1,     0,     1,     1,     0,     2,
       2,     0,     4,     0,     2,     0,     3,     0,     1,     3,
       2,     1,     1,     0,     2,     0,     2,     4,     2,     2,
       2,     4,     4,     0,     1,     3,     1,     3,     2,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     2,     2,     3,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     3,     5,     6,     5,     6,     4,     6,
       3,     5,     4,     5,     4,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     6,     1,     1,     1,     1,
       1,     1,     4,     4,     5,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     4,     1,     3,
       2,     1,     1,     3,     1,     5,     1,     0,     2,     1,
       1,     0,     4,     6,     8,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     0,     1,     1,     0,     1,     3
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
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1706 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 4: /* STRING  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1712 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 5: /* FLOATVAL  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1718 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 6: /* INTVAL  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1724 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 166: /* statement_list  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).stmt_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).stmt_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).stmt_vec));
}
#line 1737 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 167: /* statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).statement)); }
#line 1743 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 168: /* preparable_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).statement)); }
#line 1749 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 169: /* opt_hints  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1762 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 170: /* hint_list  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1775 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 171: /* hint  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 1781 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 172: /* prepare_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).prep_stmt)); }
#line 1787 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 173: /* prepare_target_query  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1793 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 174: /* execute_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).exec_stmt)); }
#line 1799 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 175: /* import_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).import_stmt)); }
#line 1805 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 176: /* import_file_type  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1811 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 177: /* file_path  */
#line 143 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).sval)) ); }
#line 1817 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 178: /* show_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).show_stmt)); }
#line 1823 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 179: /* create_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).create_stmt)); }
#line 1829 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 180: /* opt_not_exists  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1835 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 181: /* column_def_commalist  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).column_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).column_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).column_vec));
}
#line 1848 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 182: /* column_def  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).column_t)); }
#line 1854 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 183: /* column_type  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1860 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 184: /* opt_column_nullable  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1866 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 185: /* drop_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).drop_stmt)); }
#line 1872 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 186: /* opt_exists  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1878 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 187: /* delete_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1884 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 188: /* truncate_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).delete_stmt)); }
#line 1890 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 189: /* insert_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).insert_stmt)); }
#line 1896 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 190: /* opt_column_list  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 1909 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 191: /* update_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).update_stmt)); }
#line 1915 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 192: /* update_clause_commalist  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).update_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).update_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).update_vec));
}
#line 1928 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 193: /* update_clause  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).update_t)); }
#line 1934 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 194: /* select_statement  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1940 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 195: /* select_with_paren  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1946 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 196: /* select_paren_or_clause  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1952 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 197: /* select_no_paren  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1958 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 201: /* select_clause  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).select_stmt)); }
#line 1964 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 202: /* opt_distinct  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 1970 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 203: /* select_list  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 1983 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 204: /* opt_from_clause  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 1989 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 205: /* from_clause  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 1995 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 206: /* opt_where  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2001 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 207: /* opt_group  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).group_t)); }
#line 2007 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 208: /* opt_having  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2013 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 209: /* opt_order  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).order_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 2026 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 210: /* order_list  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).order_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).order_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).order_vec));
}
#line 2039 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 211: /* order_desc  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).order)); }
#line 2045 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 212: /* opt_order_type  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 2051 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 213: /* opt_top  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).limit)); }
#line 2057 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 214: /* opt_limit  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).limit)); }
#line 2063 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 215: /* expr_list  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2076 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 216: /* literal_list  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).expr_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).expr_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).expr_vec));
}
#line 2089 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 217: /* expr_alias  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2095 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 218: /* expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2101 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 219: /* operand  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2107 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 220: /* scalar_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2113 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 221: /* unary_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2119 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 222: /* binary_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2125 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 223: /* logic_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2131 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 224: /* in_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2137 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 225: /* case_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2143 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 226: /* case_list  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2149 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 227: /* exists_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2155 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 228: /* comp_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2161 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 229: /* function_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2167 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 230: /* extract_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2173 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 231: /* datetime_field  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 2179 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 232: /* array_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2185 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 233: /* array_index  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2191 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 234: /* between_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2197 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 235: /* column_name  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2203 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 236: /* literal  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2209 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 237: /* string_literal  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2215 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 238: /* bool_literal  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2221 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 239: /* num_literal  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2227 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 240: /* int_literal  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2233 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 241: /* null_literal  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2239 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 242: /* param_expr  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2245 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 243: /* table_ref  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2251 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 244: /* table_ref_atomic  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2257 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 245: /* nonjoin_table_ref_atomic  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2263 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 246: /* table_ref_commalist  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).table_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).table_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).table_vec));
}
#line 2276 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 247: /* table_ref_name  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2282 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 248: /* table_ref_name_no_alias  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2288 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 249: /* table_name  */
#line 142 "bison_parser.y" /* yacc.c:1257  */
      { free( (((*yyvaluep).table_name).name) ); free( (((*yyvaluep).table_name).schema) ); }
#line 2294 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 250: /* table_alias  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).alias_t)); }
#line 2300 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 251: /* opt_table_alias  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).alias_t)); }
#line 2306 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 252: /* alias  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).alias_t)); }
#line 2312 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 253: /* opt_alias  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).alias_t)); }
#line 2318 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 254: /* join_clause  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).table)); }
#line 2324 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 255: /* opt_join_type  */
#line 141 "bison_parser.y" /* yacc.c:1257  */
      { }
#line 2330 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 256: /* join_condition  */
#line 152 "bison_parser.y" /* yacc.c:1257  */
      { delete (((*yyvaluep).expr)); }
#line 2336 "bison_parser.tab.c" /* yacc.c:1257  */
        break;

    case 258: /* ident_commalist  */
#line 144 "bison_parser.y" /* yacc.c:1257  */
      {
	if ((((*yyvaluep).str_vec)) != nullptr) {
		for (auto ptr : *(((*yyvaluep).str_vec))) {
			delete ptr;
		}
	}
	delete (((*yyvaluep).str_vec));
}
#line 2349 "bison_parser.tab.c" /* yacc.c:1257  */
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

#line 2468 "bison_parser.tab.c" /* yacc.c:1429  */
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
#line 254 "bison_parser.y" /* yacc.c:1646  */
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
#line 2673 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 275 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[0].statement)->stringLength = yylloc.string_length;
			yylloc.string_length = 0;
			(yyval.stmt_vec) = new std::vector<SQLStatement*>();
			(yyval.stmt_vec)->push_back((yyvsp[0].statement));
		}
#line 2684 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 281 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[0].statement)->stringLength = yylloc.string_length;
			yylloc.string_length = 0;
			(yyvsp[-2].stmt_vec)->push_back((yyvsp[0].statement));
			(yyval.stmt_vec) = (yyvsp[-2].stmt_vec);
		}
#line 2695 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 290 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.statement) = (yyvsp[-1].prep_stmt);
			(yyval.statement)->hints = (yyvsp[0].expr_vec);
		}
#line 2704 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 294 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.statement) = (yyvsp[-1].statement);
			(yyval.statement)->hints = (yyvsp[0].expr_vec);
		}
#line 2713 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 298 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.statement) = (yyvsp[0].show_stmt);
		}
#line 2721 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 305 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 2727 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 306 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 2733 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 307 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 2739 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 308 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 2745 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 309 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2751 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 310 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 2757 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 311 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 2763 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 312 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 2769 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 313 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 2775 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 322 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = (yyvsp[-1].expr_vec); }
#line 2781 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 323 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = nullptr; }
#line 2787 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 328 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 2793 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 329 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 2799 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 333 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = Expr::make(kExprHint);
			(yyval.expr)->name = (yyvsp[0].sval);
		}
#line 2808 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 337 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = Expr::make(kExprHint);
			(yyval.expr)->name = (yyvsp[-3].sval);
			(yyval.expr)->exprList = (yyvsp[-1].expr_vec);
		}
#line 2818 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 349 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-2].sval);
			(yyval.prep_stmt)->query = (yyvsp[0].sval);
		}
#line 2828 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 359 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[0].sval);
		}
#line 2837 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 363 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[-3].sval);
			(yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
		}
#line 2847 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 375 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.import_stmt) = new ImportStatement((ImportType) (yyvsp[-4].uval));
			(yyval.import_stmt)->filePath = (yyvsp[-2].sval);
			(yyval.import_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.import_stmt)->tableName = (yyvsp[0].table_name).name;
		}
#line 2858 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 384 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kImportCSV; }
#line 2864 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 388 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = _strdup((yyvsp[0].expr)->name); delete (yyvsp[0].expr); }
#line 2870 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 398 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.show_stmt) = new ShowStatement(kShowTables);
		}
#line 2878 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 401 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.show_stmt) = new ShowStatement(kShowColumns);
			(yyval.show_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.show_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 2888 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 406 "bison_parser.y" /* yacc.c:1646  */
    {
		(yyval.show_stmt) = new ShowStatement(kShowSchemas);
	}
#line 2896 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 418 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateTableFromTbl);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-5].bval);
			(yyval.create_stmt)->schema = (yyvsp[-4].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-4].table_name).name;
			(yyval.create_stmt)->filePath = (yyvsp[0].sval);
		}
#line 2908 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 425 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateTable);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->columns = (yyvsp[-1].column_vec);
		}
#line 2920 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 432 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(kCreateView);
			(yyval.create_stmt)->ifNotExists = (yyvsp[-4].bval);
			(yyval.create_stmt)->schema = (yyvsp[-3].table_name).schema;
			(yyval.create_stmt)->tableName = (yyvsp[-3].table_name).name;
			(yyval.create_stmt)->viewColumns = (yyvsp[-2].str_vec);
			(yyval.create_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 2933 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 440 "bison_parser.y" /* yacc.c:1646  */
    {
		(yyval.create_stmt)=new CreateStatement(kCreateSchema);
		(yyval.create_stmt)->schema =(yyvsp[0].table_name).name;
	}
#line 2942 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 447 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 2948 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 448 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 2954 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 452 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_vec) = new std::vector<ColumnDefinition*>(); (yyval.column_vec)->push_back((yyvsp[0].column_t)); }
#line 2960 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 453 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].column_vec)->push_back((yyvsp[0].column_t)); (yyval.column_vec) = (yyvsp[-2].column_vec); }
#line 2966 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 457 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.column_t) = new ColumnDefinition((yyvsp[-2].sval), (yyvsp[-1].column_type_t), (yyvsp[0].bval));
		}
#line 2974 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 463 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 2980 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 464 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::INT}; }
#line 2986 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 465 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::LONG}; }
#line 2992 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 466 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::FLOAT}; }
#line 2998 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 467 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::DOUBLE}; }
#line 3004 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 468 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::VARCHAR, (yyvsp[-1].ival)}; }
#line 3010 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 469 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::CHAR, (yyvsp[-1].ival)}; }
#line 3016 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 470 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_type_t) = ColumnType{DataType::TEXT}; }
#line 3022 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 474 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 3028 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 475 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 3034 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 476 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 3040 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 486 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropTable);
			(yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
			(yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 3051 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 492 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropView);
			(yyval.drop_stmt)->ifExists = (yyvsp[-1].bval);
			(yyval.drop_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.drop_stmt)->name = (yyvsp[0].table_name).name;
		}
#line 3062 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 498 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(kDropPreparedStatement);
			(yyval.drop_stmt)->ifExists = false;
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 3072 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 506 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 3078 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 507 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 3084 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 516 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->schema = (yyvsp[-1].table_name).schema;
			(yyval.delete_stmt)->tableName = (yyvsp[-1].table_name).name;
			(yyval.delete_stmt)->expr = (yyvsp[0].expr);
		}
#line 3095 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 525 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->schema = (yyvsp[0].table_name).schema;
			(yyval.delete_stmt)->tableName = (yyvsp[0].table_name).name;
		}
#line 3105 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 538 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.insert_stmt) = new InsertStatement(kInsertValues);
			(yyval.insert_stmt)->schema = (yyvsp[-5].table_name).schema;
			(yyval.insert_stmt)->tableName = (yyvsp[-5].table_name).name;
			(yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
			(yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
		}
#line 3117 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 545 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.insert_stmt) = new InsertStatement(kInsertSelect);
			(yyval.insert_stmt)->schema = (yyvsp[-2].table_name).schema;
			(yyval.insert_stmt)->tableName = (yyvsp[-2].table_name).name;
			(yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
			(yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 3129 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 556 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 3135 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 557 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = nullptr; }
#line 3141 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 567 "bison_parser.y" /* yacc.c:1646  */
    {
		(yyval.update_stmt) = new UpdateStatement();
		(yyval.update_stmt)->table = (yyvsp[-3].table);
		(yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
		(yyval.update_stmt)->where = (yyvsp[0].expr);
	}
#line 3152 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 576 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.update_vec) = new std::vector<UpdateClause*>(); (yyval.update_vec)->push_back((yyvsp[0].update_t)); }
#line 3158 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 577 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t)); (yyval.update_vec) = (yyvsp[-2].update_vec); }
#line 3164 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 581 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.update_t) = new UpdateClause();
			(yyval.update_t)->column = (yyvsp[-2].sval);
			(yyval.update_t)->value = (yyvsp[0].expr);
		}
#line 3174 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 595 "bison_parser.y" /* yacc.c:1646  */
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
#line 3193 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 612 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3199 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 613 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 3205 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 622 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order_vec);

			// Limit could have been set by TOP.
			if ((yyvsp[0].limit) != nullptr) {
				delete (yyval.select_stmt)->limit;
				(yyval.select_stmt)->limit = (yyvsp[0].limit);
			}
		}
#line 3220 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 632 "bison_parser.y" /* yacc.c:1646  */
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
#line 3239 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 664 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = new SelectStatement();
			(yyval.select_stmt)->limit = (yyvsp[-5].limit);
			(yyval.select_stmt)->selectDistinct = (yyvsp[-4].bval);
			(yyval.select_stmt)->selectList = (yyvsp[-3].expr_vec);
			(yyval.select_stmt)->fromTable = (yyvsp[-2].table);
			(yyval.select_stmt)->whereClause = (yyvsp[-1].expr);
			(yyval.select_stmt)->groupBy = (yyvsp[0].group_t);
		}
#line 3253 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 676 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 3259 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 677 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 3265 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 685 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table) = (yyvsp[0].table); }
#line 3271 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 686 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table) = nullptr; }
#line 3277 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 689 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table) = (yyvsp[0].table); }
#line 3283 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 694 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3289 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 695 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = nullptr; }
#line 3295 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 699 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.group_t) = new GroupByDescription();
			(yyval.group_t)->columns = (yyvsp[-1].expr_vec);
			(yyval.group_t)->having = (yyvsp[0].expr);
		}
#line 3305 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 704 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.group_t) = nullptr; }
#line 3311 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 708 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 3317 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 709 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = nullptr; }
#line 3323 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 712 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = (yyvsp[0].order_vec); }
#line 3329 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 713 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = nullptr; }
#line 3335 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 717 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_vec) = new std::vector<OrderDescription*>(); (yyval.order_vec)->push_back((yyvsp[0].order)); }
#line 3341 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 718 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].order_vec)->push_back((yyvsp[0].order)); (yyval.order_vec) = (yyvsp[-2].order_vec); }
#line 3347 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 722 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 3353 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 726 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderAsc; }
#line 3359 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 727 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderDesc; }
#line 3365 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 728 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderAsc; }
#line 3371 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 734 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 3377 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 735 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = nullptr; }
#line 3383 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 739 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 3389 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 740 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[-2].expr)->ival, (yyvsp[0].expr)->ival); delete (yyvsp[-2].expr); delete (yyvsp[0].expr); }
#line 3395 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 741 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3401 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 742 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = nullptr; }
#line 3407 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 743 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = nullptr;  }
#line 3413 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 744 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3419 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 745 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription(kNoLimit, (yyvsp[0].expr)->ival); delete (yyvsp[0].expr); }
#line 3425 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 746 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = nullptr; }
#line 3431 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 753 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3437 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 754 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3443 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 758 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 3449 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 759 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 3455 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 763 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = (yyvsp[-1].expr);
			if ((yyvsp[0].alias_t)) {
				(yyval.expr)->alias = _strdup((yyvsp[0].alias_t)->name);
				delete (yyvsp[0].alias_t);
			}
		}
#line 3467 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 781 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 3473 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 790 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeSelect((yyvsp[-1].select_stmt)); }
#line 3479 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 799 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpUnaryMinus, (yyvsp[0].expr)); }
#line 3485 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 800 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, (yyvsp[0].expr)); }
#line 3491 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 801 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-1].expr)); }
#line 3497 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 802 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpIsNull, (yyvsp[-2].expr)); }
#line 3503 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 803 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeOpUnary(kOpIsNull, (yyvsp[-3].expr))); }
#line 3509 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 808 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpMinus, (yyvsp[0].expr)); }
#line 3515 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 809 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPlus, (yyvsp[0].expr)); }
#line 3521 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 810 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpSlash, (yyvsp[0].expr)); }
#line 3527 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 811 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAsterisk, (yyvsp[0].expr)); }
#line 3533 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 812 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpPercentage, (yyvsp[0].expr)); }
#line 3539 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 813 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpCaret, (yyvsp[0].expr)); }
#line 3545 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 814 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLike, (yyvsp[0].expr)); }
#line 3551 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 815 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), kOpNotLike, (yyvsp[0].expr)); }
#line 3557 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 816 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpILike, (yyvsp[0].expr)); }
#line 3563 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 817 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpConcat, (yyvsp[0].expr)); }
#line 3569 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 821 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpAnd, (yyvsp[0].expr)); }
#line 3575 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 822 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpOr, (yyvsp[0].expr)); }
#line 3581 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 826 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].expr_vec)); }
#line 3587 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 827 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].expr_vec))); }
#line 3593 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 828 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeInOperator((yyvsp[-4].expr), (yyvsp[-1].select_stmt)); }
#line 3599 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 829 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeInOperator((yyvsp[-5].expr), (yyvsp[-1].select_stmt))); }
#line 3605 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 835 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase((yyvsp[-2].expr), (yyvsp[-1].expr), nullptr); }
#line 3611 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 836 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3617 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 837 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-1].expr), nullptr); }
#line 3623 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 838 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCase(nullptr, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 3629 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 842 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeCaseList(Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 3635 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 843 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::caseListAppend((yyvsp[-4].expr), Expr::makeCaseListElement((yyvsp[-2].expr), (yyvsp[0].expr))); }
#line 3641 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 847 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeExists((yyvsp[-1].select_stmt)); }
#line 3647 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 848 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(kOpNot, Expr::makeExists((yyvsp[-1].select_stmt))); }
#line 3653 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 852 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 3659 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 853 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpEquals, (yyvsp[0].expr)); }
#line 3665 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 854 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpNotEquals, (yyvsp[0].expr)); }
#line 3671 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 855 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLess, (yyvsp[0].expr)); }
#line 3677 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 856 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreater, (yyvsp[0].expr)); }
#line 3683 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 857 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpLessEq, (yyvsp[0].expr)); }
#line 3689 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 858 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), kOpGreaterEq, (yyvsp[0].expr)); }
#line 3695 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 862 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-2].sval), new std::vector<Expr*>(), false); }
#line 3701 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 863 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr_vec), (yyvsp[-2].bval)); }
#line 3707 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 867 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeExtract((yyvsp[-3].datetime_field), (yyvsp[-1].expr)); }
#line 3713 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 871 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeSecond; }
#line 3719 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 872 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeMinute; }
#line 3725 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 873 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeHour; }
#line 3731 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 874 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeDay; }
#line 3737 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 875 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeMonth; }
#line 3743 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 876 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.datetime_field) = kDatetimeYear; }
#line 3749 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 879 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeArray((yyvsp[-1].expr_vec)); }
#line 3755 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 883 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeArrayIndex((yyvsp[-3].expr), (yyvsp[-1].expr)->ival); }
#line 3761 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 887 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeBetween((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3767 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 891 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 3773 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 892 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 3779 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 893 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeStar(); }
#line 3785 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 894 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeStar((yyvsp[-2].sval)); }
#line 3791 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 906 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 3797 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 910 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral(true); }
#line 3803 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 911 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral(false); }
#line 3809 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 915 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 3815 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 920 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 3821 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 924 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeNullLiteral(); }
#line 3827 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 928 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = Expr::makeParameter(yylloc.total_column);
			(yyval.expr)->ival2 = yyloc.param_list.size();
			yyloc.param_list.push_back((yyval.expr));
		}
#line 3837 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 941 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[-2].table_vec)->push_back((yyvsp[0].table));
			auto tbl = new TableRef(kTableCrossProduct);
			tbl->list = (yyvsp[-2].table_vec);
			(yyval.table) = tbl;
		}
#line 3848 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 957 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].alias_t);
			(yyval.table) = tbl;
		}
#line 3859 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 966 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table_vec) = new std::vector<TableRef*>(); (yyval.table_vec)->push_back((yyvsp[0].table)); }
#line 3865 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 967 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].table_vec)->push_back((yyvsp[0].table)); (yyval.table_vec) = (yyvsp[-2].table_vec); }
#line 3871 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 972 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableName);
			tbl->schema = (yyvsp[-1].table_name).schema;
			tbl->name = (yyvsp[-1].table_name).name;
			tbl->alias = (yyvsp[0].alias_t);
			(yyval.table) = tbl;
		}
#line 3883 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 983 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableName);
			(yyval.table)->schema = (yyvsp[0].table_name).schema;
			(yyval.table)->name = (yyvsp[0].table_name).name;
		}
#line 3893 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 992 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table_name).schema = nullptr; (yyval.table_name).name = (yyvsp[0].sval);}
#line 3899 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 993 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table_name).schema = (yyvsp[-2].sval); (yyval.table_name).name = (yyvsp[0].sval); }
#line 3905 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 999 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = new Alias((yyvsp[-3].sval), (yyvsp[-1].str_vec)); }
#line 3911 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1005 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = nullptr; }
#line 3917 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1009 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 3923 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1010 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = new Alias((yyvsp[0].sval)); }
#line 3929 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1016 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.alias_t) = nullptr; }
#line 3935 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1025 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = kJoinNatural;
			(yyval.table)->join->left = (yyvsp[-3].table);
			(yyval.table)->join->right = (yyvsp[0].table);
		}
#line 3947 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1033 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-4].uval);
			(yyval.table)->join->left = (yyvsp[-5].table);
			(yyval.table)->join->right = (yyvsp[-2].table);
			(yyval.table)->join->condition = (yyvsp[0].expr);
		}
#line 3960 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1043 "bison_parser.y" /* yacc.c:1646  */
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
#line 3980 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1061 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinInner; }
#line 3986 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1062 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinLeft; }
#line 3992 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1063 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinLeft; }
#line 3998 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1064 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinRight; }
#line 4004 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1065 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinRight; }
#line 4010 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1066 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinFull; }
#line 4016 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1067 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinFull; }
#line 4022 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1068 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinFull; }
#line 4028 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1069 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinCross; }
#line 4034 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1070 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinInner; }
#line 4040 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1090 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = new std::vector<char*>(); (yyval.str_vec)->push_back((yyvsp[0].sval)); }
#line 4046 "bison_parser.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1091 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval)); (yyval.str_vec) = (yyvsp[-2].str_vec); }
#line 4052 "bison_parser.tab.c" /* yacc.c:1646  */
    break;


#line 4056 "bison_parser.tab.c" /* yacc.c:1646  */
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
#line 1094 "bison_parser.y" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */

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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "SyntaxAnalyser.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <string.h>
    #include "external.h"
    #include <errno.h>
    #include <stdlib.h>

    extern FILE* yyin;
    extern int yylineno;

    int numberOfVariables = 0;
    struct variable* allVars[1000];

    int hasMain = 0;

    void printVariableVector(struct variable**, int);
    void assignVarTypes(struct variable**, int , char*,char*);
    void assignVarTypesAddress(struct variable**, int,char*,char*, int);
    void addToAllVariables(struct variable** ,int);
    void printAllVariables();
    int variableExists(struct variable*, char*);
    void eval(struct value*);
    struct value* getVar(char*, char*);


    int lengthOfVariableVector;
    struct variable** createVariableVector(struct variable**, struct variable*, int);

#line 95 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NR = 258,
    NRF = 259,
    STRING = 260,
    ID = 261,
    VARTYPE = 262,
    THISOBJ = 263,
    GET = 264,
    SHOW = 265,
    EVAL = 266,
    MAIN = 267,
    FUNCTION = 268,
    AS = 269,
    PUBLIC = 270,
    PRIVATE = 271,
    CLASS = 272,
    RETURN = 273,
    POINTER = 274,
    DEREFERENCE = 275,
    ASSIGN = 276,
    INC = 277,
    DEC = 278,
    GREQ = 279,
    LEEQ = 280,
    NEQ = 281,
    EQ = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    XOR = 286,
    IF = 287,
    THEN = 288,
    ELSE = 289,
    ENDIF = 290,
    WHILE = 291,
    DO = 292,
    ENDWHILE = 293,
    FOR = 294,
    ENDFOR = 295
  };
#endif
/* Tokens.  */
#define NR 258
#define NRF 259
#define STRING 260
#define ID 261
#define VARTYPE 262
#define THISOBJ 263
#define GET 264
#define SHOW 265
#define EVAL 266
#define MAIN 267
#define FUNCTION 268
#define AS 269
#define PUBLIC 270
#define PRIVATE 271
#define CLASS 272
#define RETURN 273
#define POINTER 274
#define DEREFERENCE 275
#define ASSIGN 276
#define INC 277
#define DEC 278
#define GREQ 279
#define LEEQ 280
#define NEQ 281
#define EQ 282
#define AND 283
#define OR 284
#define NOT 285
#define XOR 286
#define IF 287
#define THEN 288
#define ELSE 289
#define ENDIF 290
#define WHILE 291
#define DO 292
#define ENDWHILE 293
#define FOR 294
#define ENDFOR 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "SyntaxAnalyser.y" /* yacc.c:355  */

    int intVal;
    float floatVal;
    char* stringVal;
    struct variable* var;
    struct variable** vars;
    struct value* val;

#line 224 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 241 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   668

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
       2,     2,    43,    41,    51,    42,    57,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    49,
      47,     2,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,    56,    55,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    79,    80,    84,    85,    89,    90,    91,
      95,   101,   110,   120,   136,   142,   169,   178,   184,   190,
     199,   200,   204,   205,   209,   210,   211,   212,   216,   218,
     220,   222,   225,   227,   229,   231,   233,   238,   239,   243,
     244,   245,   249,   250,   254,   258,   262,   263,   267,   268,
     269,   273,   274,   278,   281,   283,   286,   291,   292,   296,
     297,   298,   299,   303,   304,   305,   309,   313,   321,   327,
     333,   334,   373,   411,   449,   486,   526,   527,   562,   597,
     632,   667,   702,   737,   738,   739,   740,   741,   751,   752,
     753,   757,   758,   761,   762,   763,   766,   767,   768,   769,
     773,   774,   778,   779,   783,   784,   785,   789,   790
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NR", "NRF", "STRING", "ID", "VARTYPE",
  "THISOBJ", "GET", "SHOW", "EVAL", "MAIN", "FUNCTION", "AS", "PUBLIC",
  "PRIVATE", "CLASS", "RETURN", "POINTER", "DEREFERENCE", "ASSIGN", "INC",
  "DEC", "GREQ", "LEEQ", "NEQ", "EQ", "AND", "OR", "NOT", "XOR", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "FOR", "ENDFOR",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'<'", "'>'", "';'", "':'",
  "','", "'{'", "'}'", "'['", "']'", "'\\\\'", "'.'", "$accept", "start",
  "instructionBlocks", "instructionBlock", "declarationSet",
  "variableDeclarationSet", "variableDeclarations", "variableDeclaration",
  "value", "spanSet", "addressSet", "functionDeclaration",
  "functionDefinition", "functionInstructions", "functionInstruction",
  "functionParameterDeclarations", "functionParameterDeclaration",
  "classDeclaration", "classObjectsDeclarationSet",
  "classObjectsDeclaration", "accessLevel", "functionDefinitionClass",
  "instructions", "instruction", "controlBlock", "ifBlock", "whileBlock",
  "forBlock", "expression", "variable", "object", "refList", "spanSetVars",
  "functionCall", "predefinedFunctionCall", "parameterList", YY_NULLPTR
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
     295,    43,    45,    42,    47,    37,    94,    60,    62,    59,
      58,    44,   123,   125,    91,    93,    92,    46
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -96

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   -14,     0,    13,    51,    66,    21,  -120,  -120,   101,
     109,  -120,  -120,  -120,    46,     6,   128,   120,   139,  -120,
    -120,  -120,  -120,    40,    89,   184,   149,  -120,  -120,   200,
      -5,   160,   196,   138,   214,   166,   167,   174,   200,   149,
     176,   171,    49,  -120,    35,   224,  -120,  -120,  -120,  -120,
    -120,    78,    -4,   178,   218,  -120,   228,   182,   236,   188,
      14,   241,   238,   239,    16,  -120,   249,   201,   251,  -120,
     208,    55,   209,   261,  -120,   477,  -120,   215,    52,   216,
     199,   199,   229,  -120,   199,    30,  -120,   219,   221,   222,
     226,    -7,   227,   231,   234,   246,   247,   248,   334,  -120,
    -120,  -120,  -120,  -120,   255,   260,   477,   277,    32,  -120,
    -120,   262,   263,  -120,  -120,   254,   106,   446,   258,   446,
      33,   148,    12,   148,   148,   148,   148,   148,   289,   272,
    -120,  -120,  -120,   343,   264,   265,   114,  -120,  -120,   266,
     268,   190,   153,  -120,  -120,   446,   193,   271,   115,    83,
    -120,  -120,  -120,  -120,   576,  -120,   273,    88,  -120,  -120,
     620,   122,   123,   124,   476,   501,   526,   307,  -120,   288,
      36,   279,   286,   477,   291,   299,   301,   311,  -120,   230,
     312,   295,   303,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,  -120,
     351,   313,  -120,  -120,   148,  -120,  -120,  -120,  -120,   335,
     332,   148,  -120,   315,   133,   446,   318,   352,   477,  -120,
    -120,  -120,   333,  -120,   446,   320,   620,   154,   448,   448,
     448,   448,   448,   448,   448,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,   148,   620,   446,   446,   585,   324,
     325,   240,   446,   339,   383,  -120,   250,   446,   148,  -120,
     159,   399,   430,   148,   446,   329,   342,   281,  -120,   346,
     353,   287,   620,  -120,   446,  -120,  -120,   611,   297,   446,
    -120,   357,  -120,  -120,   358,   440,   397,   360,   328,  -120,
    -120,  -120,   385,  -120,   367,   148,  -120,   551,   375,   446,
     389,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     2,     4,     5,     0,
       0,     6,     9,    23,     0,     0,     0,     0,     0,     1,
       3,     7,     8,    14,     0,     0,    11,    13,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,    27,     0,    43,     0,     0,    17,    18,    19,    15,
      21,     0,     0,     0,     0,    12,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    47,     0,     0,     0,    16,
      26,     0,     0,     0,    44,     0,    42,     0,     0,     0,
       0,     0,     0,    46,     0,     0,    20,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      61,    63,    64,    65,     0,     0,     0,     0,     0,    52,
      51,     0,     0,    45,    50,     0,     0,     0,     0,     0,
       0,    93,    93,    93,    93,    93,    93,    93,     0,     0,
      57,    59,    60,     0,     0,    27,     0,    48,    49,     0,
       0,     0,     0,    38,    39,     0,     0,     0,     0,    90,
      94,    99,    97,    86,     0,    87,     0,     0,    70,   103,
     108,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    62,
       0,    88,    98,    96,    93,   102,   104,   105,   106,     0,
       0,    93,    31,    26,     0,     0,     0,     0,     0,    40,
      41,    32,     0,    36,     0,     0,   101,     0,    79,    80,
      78,    77,    83,    84,    85,    71,    72,    73,    74,    75,
      76,    82,    81,    92,    93,   107,     0,     0,     0,     0,
      24,     0,     0,     0,     0,    28,     0,     0,    93,    91,
       0,     0,     0,    93,     0,     0,     0,     0,    34,     0,
       0,     0,   100,    89,     0,    66,    68,     0,     0,     0,
      56,     0,    30,    33,     0,     0,     0,     0,     0,    54,
      29,    67,     0,    55,     0,    93,    53,     0,     0,     0,
       0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,   407,  -120,   -23,   387,   376,   -32,  -120,
    -120,   -20,  -120,  -119,   -43,   -22,   362,  -120,  -120,   354,
     117,  -120,   -84,   -71,  -120,  -120,  -120,  -120,   -72,  -120,
    -120,  -120,   179,  -114,  -120,   -78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    26,    27,   153,    51,
      15,    10,    11,   142,   143,    42,    43,    12,    64,    65,
     111,    66,    98,   144,   100,   101,   102,   103,   160,   155,
     156,   157,   227,   104,   105,   161
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     146,    49,    40,    40,    99,    13,    16,   158,   158,   158,
     158,   158,   158,   158,   121,    46,    47,    48,   149,    17,
     150,    62,   133,    60,    63,    28,   179,   130,     1,    61,
      71,   151,   152,    13,     2,    99,    14,    40,     3,    40,
      40,    62,    60,    40,    63,   162,   163,   122,    61,   154,
      41,    70,    23,   164,   165,   166,    29,    18,    23,    24,
      82,    33,   130,   116,    78,   107,    19,   159,     4,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   115,   136,   135,   147,   217,
     158,   213,    34,    25,   201,    35,   251,   158,   148,   178,
      58,    36,    99,   178,    59,   256,    58,   202,   203,   176,
      88,   226,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   261,   262,    68,
     158,    69,   245,   267,   254,   183,   178,   122,   271,   248,
     -95,    46,    47,    48,   158,   278,   130,    99,   214,   158,
      21,    46,    47,    48,   149,   285,   150,    58,    22,    91,
     288,   140,    92,    93,    94,    58,    58,   151,   152,   172,
     182,   141,   226,   204,   204,   204,    31,   205,   206,   207,
     300,   158,    30,   130,    58,    95,   272,    32,   250,    96,
      37,   277,    97,    46,    47,    48,   175,   177,   112,    91,
      38,   114,    92,    93,    94,   258,    23,   259,   178,    45,
     258,   141,   273,   178,   109,   110,    44,    50,   178,   178,
      52,    53,    54,   297,   178,    95,    56,    57,   178,    96,
      67,    73,    97,    72,    74,   178,    91,   180,    75,    92,
      93,    94,   178,    40,    77,   178,    91,    79,   141,    92,
      93,    94,    80,    81,    86,    85,    91,   178,   141,    92,
      93,    94,    95,    84,    87,    89,    96,    90,   141,    97,
     108,   106,    95,   113,   222,   117,    96,   118,   119,    97,
     120,   123,    95,   134,   266,   124,    96,    91,   125,    97,
      92,    93,    94,    91,   270,   167,    92,    93,    94,   141,
     126,   127,   128,    91,   131,   141,    92,    93,    94,   132,
     139,   137,   138,    95,   145,   141,   168,    96,   170,    95,
      97,   171,   173,    96,   174,   281,    97,   181,   211,    95,
     200,   284,   212,    96,    91,   215,    97,    92,    93,    94,
      91,   287,   216,    92,    93,    94,   141,   218,   219,    91,
     220,   224,    92,    93,    94,   221,   223,   243,    91,   225,
      95,    92,    93,    94,    96,   244,    95,    97,   246,   247,
      96,   249,   294,    97,   252,    95,   257,   255,   129,    96,
     264,   265,    97,   268,    95,   279,   280,   169,    96,    91,
     282,    97,    92,    93,    94,    91,   253,   283,    92,    93,
      94,   289,   290,   292,   293,    91,   295,   141,    92,    93,
      94,   296,   299,    20,    55,    95,    39,   141,    83,    96,
      76,    95,    97,   260,     0,    96,     0,   269,    97,   301,
       0,    95,     0,   274,   275,    96,    91,     0,    97,    92,
      93,    94,     0,     0,     0,     0,    91,     0,   141,    92,
      93,    94,    91,     0,     0,    92,    93,    94,   141,     0,
       0,     0,    95,     0,   141,     0,    96,     0,   276,    97,
       0,     0,    95,     0,     0,   291,    96,     0,    95,    97,
       0,     0,    96,    91,     0,    97,    92,    93,    94,   191,
     192,   193,   194,   195,   196,   197,   198,     0,     0,     0,
     184,   185,   186,   187,   188,   189,     0,   190,     0,    95,
       0,     0,     0,    96,     0,     0,    97,   191,   192,   193,
     194,   195,   196,   197,   198,   184,   185,   186,   187,   188,
     189,   208,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     184,   185,   186,   187,   188,   189,   209,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,   192,   193,
     194,   195,   196,   197,   198,   184,   185,   186,   187,   188,
     189,   210,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     184,   185,   186,   187,   188,   189,   298,   190,     0,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   191,   192,   193,   194,
     195,   196,   197,   198,   263,   184,   185,   186,   187,   188,
     189,     0,   190,     0,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     286,   191,   192,   193,   194,   195,   196,   197,   198
};

static const yytype_int16 yycheck[] =
{
     119,    33,     7,     7,    75,    19,     6,   121,   122,   123,
     124,   125,   126,   127,    21,     3,     4,     5,     6,     6,
       8,    44,   106,     7,    44,    19,   145,    98,     7,    13,
      52,    19,    20,    19,    13,   106,    50,     7,    17,     7,
       7,    64,     7,     7,    64,   123,   124,    54,    13,   121,
      55,    55,     6,   125,   126,   127,    50,     6,     6,    13,
      44,    21,   133,    85,    50,    13,     0,    55,    47,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,    55,   108,    55,    55,   173,
     204,    55,    52,    47,     6,     6,   215,   211,   120,   142,
      51,    12,   173,   146,    55,   224,    51,    19,    20,   141,
      55,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   246,   247,    51,
     244,    53,   204,   252,   218,    52,   179,    54,   257,   211,
      57,     3,     4,     5,   258,   264,   217,   218,   170,   263,
      49,     3,     4,     5,     6,   274,     8,    51,    49,     6,
     279,    55,     9,    10,    11,    51,    51,    19,    20,    55,
      55,    18,   244,    51,    51,    51,    56,    55,    55,    55,
     299,   295,    54,   254,    51,    32,   258,    48,    55,    36,
       6,   263,    39,     3,     4,     5,     6,    44,    81,     6,
      51,    84,     9,    10,    11,    51,     6,    53,   251,    13,
      51,    18,    53,   256,    15,    16,    56,     3,   261,   262,
      54,    54,    48,   295,   267,    32,    50,    56,   271,    36,
       6,    13,    39,    55,     6,   278,     6,    44,    56,     9,
      10,    11,   285,     7,    56,   288,     6,     6,    18,     9,
      10,    11,    14,    14,     3,    54,     6,   300,    18,     9,
      10,    11,    32,    14,    56,    56,    36,     6,    18,    39,
      54,    56,    32,    44,    44,    56,    36,    56,    56,    39,
      54,    54,    32,     6,    44,    54,    36,     6,    54,    39,
       9,    10,    11,     6,    44,     6,     9,    10,    11,    18,
      54,    54,    54,     6,    49,    18,     9,    10,    11,    49,
      56,    49,    49,    32,    56,    18,    44,    36,    54,    32,
      39,    56,    56,    36,    56,    44,    39,    56,    21,    32,
      57,    44,    44,    36,     6,    56,    39,     9,    10,    11,
       6,    44,    56,     9,    10,    11,    18,    56,    49,     6,
      49,    56,     9,    10,    11,    44,    44,     6,     6,    56,
      32,     9,    10,    11,    36,    52,    32,    39,    33,    37,
      36,    56,    44,    39,    56,    32,    56,    44,    44,    36,
      56,    56,    39,    44,    32,    56,    44,    44,    36,     6,
      44,    39,     9,    10,    11,     6,    44,    44,     9,    10,
      11,    44,    44,     6,    44,     6,    21,    18,     9,    10,
      11,    44,    37,     6,    38,    32,    29,    18,    64,    36,
      58,    32,    39,   244,    -1,    36,    -1,    44,    39,    40,
      -1,    32,    -1,    34,    35,    36,     6,    -1,    39,     9,
      10,    11,    -1,    -1,    -1,    -1,     6,    -1,    18,     9,
      10,    11,     6,    -1,    -1,     9,    10,    11,    18,    -1,
      -1,    -1,    32,    -1,    18,    -1,    36,    -1,    38,    39,
      -1,    -1,    32,    -1,    -1,    35,    36,    -1,    32,    39,
      -1,    -1,    36,     6,    -1,    39,     9,    10,    11,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    -1,    31,    -1,    32,
      -1,    -1,    -1,    36,    -1,    -1,    39,    41,    42,    43,
      44,    45,    46,    47,    48,    24,    25,    26,    27,    28,
      29,    55,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      24,    25,    26,    27,    28,    29,    55,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    24,    25,    26,    27,    28,
      29,    55,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      24,    25,    26,    27,    28,    29,    55,    31,    -1,    24,
      25,    26,    27,    28,    29,    -1,    31,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    24,    25,    26,    27,    28,
      29,    -1,    31,    -1,    24,    25,    26,    27,    28,    29,
      -1,    31,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    41,    42,    43,    44,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    13,    17,    47,    59,    60,    61,    62,    63,
      69,    70,    75,    19,    50,    68,     6,     6,     6,     0,
      61,    49,    49,     6,    13,    47,    64,    65,    19,    50,
      54,    56,    48,    21,    52,     6,    12,     6,    51,    64,
       7,    55,    73,    74,    56,    13,     3,     4,     5,    66,
       3,    67,    54,    54,    48,    65,    50,    56,    51,    55,
       7,    13,    63,    69,    76,    77,    79,     6,    51,    53,
      55,    73,    55,    13,     6,    56,    74,    56,    50,     6,
      14,    14,    44,    77,    14,    54,     3,    56,    55,    56,
       6,     6,     9,    10,    11,    32,    36,    39,    80,    81,
      82,    83,    84,    85,    91,    92,    56,    13,    54,    15,
      16,    78,    78,    44,    78,    55,    73,    56,    56,    56,
      54,    21,    54,    54,    54,    54,    54,    54,    54,    44,
      81,    49,    49,    80,     6,    55,    73,    49,    49,    56,
      55,    18,    71,    72,    81,    56,    71,    55,    73,     6,
       8,    19,    20,    66,    86,    87,    88,    89,    91,    55,
      86,    93,    93,    93,    86,    86,    86,     6,    44,    44,
      54,    56,    55,    56,    56,     6,    66,    44,    72,    71,
      44,    56,    55,    52,    24,    25,    26,    27,    28,    29,
      31,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      57,     6,    19,    20,    51,    55,    55,    55,    55,    55,
      55,    21,    44,    55,    73,    56,    56,    80,    56,    49,
      49,    44,    44,    44,    56,    56,    86,    90,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,     6,    52,    86,    33,    37,    86,    56,
      55,    71,    56,    44,    80,    44,    71,    56,    51,    53,
      90,    71,    71,    49,    56,    56,    44,    71,    44,    44,
      44,    71,    86,    53,    34,    35,    38,    86,    71,    56,
      44,    44,    44,    44,    44,    71,    49,    44,    71,    44,
      44,    35,     6,    44,    44,    21,    44,    86,    55,    37,
      71,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    74,    75,    76,    76,    77,    77,
      77,    78,    78,    79,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    82,    82,    82,    83,    83,    84,    85,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
      87,    87,    87,    88,    88,    88,    89,    89,    89,    89,
      90,    90,    91,    91,    92,    92,    92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     2,     1,
       4,     3,     3,     1,     1,     3,     4,     1,     1,     1,
       3,     1,     2,     1,     7,     5,     6,     4,    12,    15,
      13,    10,    11,    14,    12,     9,    11,     2,     1,     1,
       3,     3,     3,     1,     3,     7,     2,     1,     4,     4,
       3,     1,     1,    12,    10,    11,     9,     2,     1,     2,
       2,     1,     4,     1,     1,     1,     7,     9,     7,    15,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     2,     5,
       1,     4,     3,     0,     1,     1,     2,     1,     2,     1,
       3,     1,     4,     3,     4,     4,     4,     3,     1
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 73 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
            printf("Syntax analysis complete!\n");
        }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 96 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { 
            assignVarTypesAddress((yyvsp[0].vars), lengthOfVariableVector, "global", (yyvsp[-3].stringVal), (yyvsp[-2].intVal));
            //printVariableVector($4, lengthOfVariableVector);
            addToAllVariables((yyvsp[0].vars), lengthOfVariableVector);
        }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { 
            assignVarTypes((yyvsp[0].vars), lengthOfVariableVector,"global",  (yyvsp[-2].stringVal)); 
            //printVariableVector($3, lengthOfVariableVector);
            addToAllVariables((yyvsp[0].vars), lengthOfVariableVector);
        }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 111 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
            if( variableExists ( (yyvsp[0].var) , "global" ) == 0 )
                (yyval.vars) = createVariableVector((yyvsp[-2].vars), (yyvsp[0].var), lengthOfVariableVector++);
            else
            {
                yyerror("Variable already exists");
                (yyval.vars) = (yyvsp[-2].vars);
            }
        }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { 
            lengthOfVariableVector = 0;
            if( variableExists( (yyvsp[0].var), "global") == 1 )
            {
                yyerror("Variable already declared");
            }
            else 
            {
                /*printf("%s %d, %d %f %s\n", $1->name, $1->type, $1->intVal, $1->floatVal, $1->stringVal); */
                (yyval.vars) = createVariableVector(NULL, (yyvsp[0].var), lengthOfVariableVector++);
            }
        }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 137 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {  
            (yyval.var) = (struct variable*)malloc(sizeof(struct variable));
            strcpy((yyval.var)->name, (yyvsp[0].stringVal));
            (yyval.var)->depth = 0;
        }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
            if((yyvsp[0].val)->type == Int)
            {
                (yyval.var) = (struct variable*)malloc(sizeof(struct variable));
                (yyval.var)->type = Int;
                (yyval.var)->intVal = (yyvsp[0].val)->intVal;
                strcpy((yyval.var)->name, (yyvsp[-2].stringVal));
                (yyval.var)->depth = 0;
            }
            if((yyvsp[0].val)->type == Float)
            {
                (yyval.var) = (struct variable*)malloc(sizeof(struct variable));
                (yyval.var)->type = Float;
                (yyval.var)->floatVal = (yyvsp[0].val)->floatVal;
                strcpy((yyval.var)->name, (yyvsp[-2].stringVal));
                (yyval.var)->depth = 0;
            }
            if((yyvsp[0].val)->type == String)
            {
                (yyval.var) = (struct variable*)malloc(sizeof(struct variable));
                (yyval.var)->type = String;
                strcpy((yyval.var)->stringVal, (yyvsp[0].val)->stringVal);
                strcpy((yyval.var)->name, (yyvsp[-2].stringVal));
                (yyval.var)->depth = 0;
            }
        }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
            (yyval.var) = (struct variable*)malloc(sizeof(struct variable));
            (yyval.var)->depth = (yyvsp[-1].intVal);
            strcpy((yyval.var)->name, (yyvsp[-3].stringVal));
        }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 179 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { 
            (yyval.val) = (struct value*)malloc(sizeof(struct value));
            (yyval.val)->type = Int;
            (yyval.val)->intVal = (yyvsp[0].intVal);
        }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 185 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { 
            (yyval.val) =  (struct value*)malloc(sizeof(struct value));
            (yyval.val)->type = Float;
            (yyval.val)->floatVal = (yyvsp[0].floatVal);
        }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 191 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
            (yyval.val) =  (struct value*)malloc(sizeof(struct value));
            (yyval.val)->type = String;
            strcpy((yyval.val)->stringVal, (yyvsp[0].stringVal));
        }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 199 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {(yyval.intVal) = (yyvsp[-2].intVal) + 1;}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {(yyval.intVal) = 1;}
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 204 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {(yyval.intVal) = (yyvsp[-1].intVal) + 1;}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 205 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {(yyval.intVal) = 1;}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 333 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 335 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String && ((yyvsp[0].val)->type == Float || (yyvsp[0].val)->type == Int)
            || (yyvsp[0].val)->type == String && ((yyvsp[-2].val)->type == Float || (yyvsp[0].val)->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            if((yyvsp[-2].val)->type >= (yyvsp[0].val)->type)
                (yyval.val)->type= (yyvsp[-2].val)->type;
            else
                (yyval.val)->type = (yyvsp[0].val)->type;

            if((yyval.val)->type == Int)
            {
                (yyval.val)->intVal = (yyvsp[-2].val)->intVal + (yyvsp[0].val)->intVal;
            }
            if((yyval.val)->type == Float)
            {
                if((yyvsp[-2].val)->type == Int)
                    (yyval.val)->floatVal = (yyvsp[-2].val)->intVal + (yyvsp[0].val)->floatVal;
                else if((yyvsp[0].val)->type == Int)
                    (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal + (yyvsp[0].val)->intVal;
                else
                    (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal + (yyvsp[0].val)->floatVal;
            }
            if((yyval.val)->type == String)
            {
                strcpy((yyval.val)->stringVal, strcat((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal));
            }
        }
    }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 374 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String || (yyvsp[0].val)->type == String)
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            if((yyvsp[-2].val)->type >= (yyvsp[0].val)->type)
                (yyval.val)->type= (yyvsp[-2].val)->type;
            else
                (yyval.val)->type = (yyvsp[0].val)->type;

            if((yyval.val)->type == Int)
            {
                (yyval.val)->intVal = (yyvsp[-2].val)->intVal - (yyvsp[0].val)->intVal;
            }
            if((yyval.val)->type == Float)
            {
                if((yyvsp[-2].val)->type == Int)
                    (yyval.val)->floatVal = (yyvsp[-2].val)->intVal - (yyvsp[0].val)->floatVal;
                else if((yyvsp[0].val)->type == Int)
                    (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal - (yyvsp[0].val)->intVal;
                else
                    (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal - (yyvsp[0].val)->floatVal;
            }
            if((yyval.val)->type == String)
            {
                strcpy((yyval.val)->stringVal, strcat((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal));
            }
        }
    }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 411 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        else{
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String || (yyvsp[0].val)->type == String)
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            if((yyvsp[-2].val)->type >= (yyvsp[0].val)->type)
                (yyval.val)->type= (yyvsp[-2].val)->type;
            else
                (yyval.val)->type = (yyvsp[0].val)->type;

            if((yyval.val)->type == Int)
            {
                (yyval.val)->intVal = (yyvsp[-2].val)->intVal * (yyvsp[0].val)->intVal;
            }
            if((yyval.val)->type == Float)
            {
                if((yyvsp[-2].val)->type == Int)
                    (yyval.val)->floatVal = (yyvsp[-2].val)->intVal * (yyvsp[0].val)->floatVal;
                else if((yyvsp[0].val)->type == Int)
                    (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal * (yyvsp[0].val)->intVal;
                else
                    (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal * (yyvsp[0].val)->floatVal;
            }
            if((yyval.val)->type == String)
            {
                strcpy((yyval.val)->stringVal, strcat((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal));
            }
        }}
    }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 449 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String || (yyvsp[0].val)->type == String)
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            if((yyvsp[-2].val)->type >= (yyvsp[0].val)->type)
                (yyval.val)->type= (yyvsp[-2].val)->type;
            else
                (yyval.val)->type = (yyvsp[0].val)->type;

            if((yyval.val)->type == Int)
            {
                (yyval.val)->intVal = (yyvsp[-2].val)->intVal / (yyvsp[0].val)->intVal;
            }
            if((yyval.val)->type == Float)
            {
                if((yyvsp[-2].val)->type == Int)
                    (yyval.val)->floatVal = (yyvsp[-2].val)->intVal / (yyvsp[0].val)->floatVal;
                else if((yyvsp[0].val)->type == Int)
                    (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal / (yyvsp[0].val)->intVal;
                else
                    (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal / (yyvsp[0].val)->floatVal;
            }
            if((yyval.val)->type == String)
            {
                strcpy((yyval.val)->stringVal, strcat((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal));
            }
        }
    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 486 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            (yyval.val) = NULL;
            yyerror("Expression parse error. Failed in syntax check");
        }
        else{
            (yyval.val) = (struct value*)malloc(sizeof(struct value));
            if((yyvsp[-2].val)->type != Int && (yyvsp[0].val)->type != Int)
            {
                yyerror("Expression is syntactically incorrect");
                free((yyval.val));
            }
            else
            {
                if((yyvsp[-2].val)->type >= (yyvsp[0].val)->type)
                    (yyval.val)->type= (yyvsp[-2].val)->type;
                else
                    (yyval.val)->type = (yyvsp[0].val)->type;

                if((yyval.val)->type == Int)
                {
                    (yyval.val)->intVal = (yyvsp[-2].val)->intVal % (yyvsp[0].val)->intVal;
                }
                if((yyval.val)->type == Float)
                {
                    if((yyvsp[-2].val)->type == Int)
                        (yyval.val)->floatVal = (yyvsp[-2].val)->intVal - (yyvsp[0].val)->floatVal;
                    else if((yyvsp[0].val)->type == Int)
                        (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal - (yyvsp[0].val)->intVal;
                    else
                        (yyval.val)->floatVal = (yyvsp[-2].val)->floatVal - (yyvsp[0].val)->floatVal;
                }
                if((yyval.val)->type == String)
                {
                    strcpy((yyval.val)->stringVal, strcat((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal));
                }
            }
        }
    }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 526 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 527 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String && ((yyvsp[0].val)->type == Float || (yyvsp[0].val)->type == Int)
            || (yyvsp[0].val)->type == String && ((yyvsp[-2].val)->type == Float || (yyvsp[0].val)->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            (yyval.val)->type = Int;

            if((yyval.val)->type == Int)
            {
                if((yyvsp[-2].val)->type !=String && (yyvsp[0].val)->type != String)
                {
                    if ((yyvsp[-2].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[-2].val)->floatVal == (yyvsp[0].val)->intVal;
                    else if ((yyvsp[0].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[0].val)->floatVal == (yyvsp[-2].val)->intVal;
                    else
                        (yyval.val)->intVal = (yyvsp[-2].val)->intVal == (yyvsp[0].val)->intVal;
                }
                else
                    if(!strcmp((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal))
                    (yyval.val)->intVal = 1;
                    else
                    (yyval.val)->intVal = 0;
            }
        }
    }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 562 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String && ((yyvsp[0].val)->type == Float || (yyvsp[0].val)->type == Int)
            || (yyvsp[0].val)->type == String && ((yyvsp[-2].val)->type == Float || (yyvsp[0].val)->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            (yyval.val)->type = Int;

            if((yyval.val)->type == Int)
            {
                if((yyvsp[-2].val)->type !=String && (yyvsp[0].val)->type != String)
                {
                    if ((yyvsp[-2].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[-2].val)->floatVal != (yyvsp[0].val)->intVal;
                    else if ((yyvsp[0].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[0].val)->floatVal != (yyvsp[-2].val)->intVal;
                    else
                        (yyval.val)->intVal = (yyvsp[-2].val)->intVal != (yyvsp[0].val)->intVal;
                }
                else
                    if(!strcmp((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal))
                    (yyval.val)->intVal = 0;
                    else
                    (yyval.val)->intVal = 1;
            }
        }
    }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 597 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String && ((yyvsp[0].val)->type == Float || (yyvsp[0].val)->type == Int)
            || (yyvsp[0].val)->type == String && ((yyvsp[-2].val)->type == Float || (yyvsp[0].val)->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            (yyval.val)->type = Int;

            if((yyval.val)->type == Int)
            {
                if((yyvsp[-2].val)->type !=String && (yyvsp[0].val)->type != String)
                {
                    if ((yyvsp[-2].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[-2].val)->floatVal >= (yyvsp[0].val)->intVal;
                    else if ((yyvsp[0].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[0].val)->floatVal <= (yyvsp[-2].val)->intVal;
                    else
                        (yyval.val)->intVal = (yyvsp[-2].val)->intVal >= (yyvsp[0].val)->intVal;
                }
                else
                    if(strcmp((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal) >= 0)
                    (yyval.val)->intVal = 1;
                    else
                    (yyval.val)->intVal = 0;
            }
        }
    }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 632 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String && ((yyvsp[0].val)->type == Float || (yyvsp[0].val)->type == Int)
            || (yyvsp[0].val)->type == String && ((yyvsp[-2].val)->type == Float || (yyvsp[0].val)->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            (yyval.val)->type = Int;

            if((yyval.val)->type == Int)
            {
                if((yyvsp[-2].val)->type !=String && (yyvsp[0].val)->type != String)
                {
                    if ((yyvsp[-2].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[-2].val)->floatVal <= (yyvsp[0].val)->intVal;
                    else if ((yyvsp[0].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[0].val)->floatVal >= (yyvsp[-2].val)->intVal;
                    else
                        (yyval.val)->intVal = (yyvsp[-2].val)->intVal <= (yyvsp[0].val)->intVal;
                }
                else
                    if(strcmp((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal) <= 0)
                    (yyval.val)->intVal = 1;
                    else
                    (yyval.val)->intVal = 0;
            }
        }
    }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 667 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String && ((yyvsp[0].val)->type == Float || (yyvsp[0].val)->type == Int)
            || (yyvsp[0].val)->type == String && ((yyvsp[-2].val)->type == Float || (yyvsp[0].val)->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            (yyval.val)->type = Int;

            if((yyval.val)->type == Int)
            {
                if((yyvsp[-2].val)->type !=String && (yyvsp[0].val)->type != String)
                {
                    if ((yyvsp[-2].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[-2].val)->floatVal > (yyvsp[0].val)->intVal;
                    else if ((yyvsp[0].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[0].val)->floatVal < (yyvsp[-2].val)->intVal;
                    else
                        (yyval.val)->intVal = (yyvsp[-2].val)->intVal > (yyvsp[0].val)->intVal;
                }
                else
                    if(strcmp((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal) > 0)
                    (yyval.val)->intVal = 1;
                    else
                    (yyval.val)->intVal = 0;
            }
        }
    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 702 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].val) == NULL || (yyvsp[0].val) == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        (yyval.val) = (struct value*)malloc(sizeof(struct value));
        if((yyvsp[-2].val)->type == String && ((yyvsp[0].val)->type == Float || (yyvsp[0].val)->type == Int)
            || (yyvsp[0].val)->type == String && ((yyvsp[-2].val)->type == Float || (yyvsp[0].val)->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free((yyval.val));
        }
        else
        {
            (yyval.val)->type = Int;

            if((yyval.val)->type == Int)
            {
                if((yyvsp[-2].val)->type !=String && (yyvsp[0].val)->type != String)
                {
                    if ((yyvsp[-2].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[-2].val)->floatVal <(yyvsp[0].val)->intVal;
                    else if ((yyvsp[0].val)->type == Float)
                        (yyval.val)->intVal = (yyvsp[0].val)->floatVal >(yyvsp[-2].val)->intVal;
                    else
                        (yyval.val)->intVal = (yyvsp[-2].val)->intVal < (yyvsp[0].val)->intVal;
                }
                else
                    if(strcmp((yyvsp[-2].val)->stringVal, (yyvsp[0].val)->stringVal) < 0)
                    (yyval.val)->intVal = 1;
                    else
                    (yyval.val)->intVal = 0;
            }
        }
    }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 737 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 738 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 739 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 740 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { (yyval.val) = (yyvsp[0].val); }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 742 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { 
            if((yyvsp[0].val) != NULL)
                (yyval.val) = (yyvsp[0].val);
            
        }
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 751 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 752 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 754 "SyntaxAnalyser.y" /* yacc.c:1646  */
    {
        (yyval.val) = getVar((yyvsp[0].stringVal), "global");
    }
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 757 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 758 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { }
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 785 "SyntaxAnalyser.y" /* yacc.c:1646  */
    { printf("Expression result:\n"); eval((yyvsp[-1].val)); }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2289 "y.tab.c" /* yacc.c:1646  */
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 793 "SyntaxAnalyser.y" /* yacc.c:1906  */


struct variable** createVariableVector(struct variable** oldVector, struct variable* newVariable, int oldVectorSize)
{
    struct variable** newVector = (struct variable**)malloc(sizeof(size_t) * (oldVectorSize+1) );
    for( int i = 0; i < oldVectorSize; i++)
    {
        newVector[i] = oldVector[i];
    }
    newVector[oldVectorSize] = newVariable;
    if(oldVector != NULL)
        free(oldVector);
    return newVector;
}

void printVariableVector(struct variable** vector, int length)
{
    for(int i = 0; i< length; i++)
    {
        if(vector[i]->type == Int)
        printf("Variable : %s\n\tType Int\n\tDepth : %d\n\tScope : %s\n\tValue: %d\n",
            vector[i]->name,vector[i]->depth, vector[i]->scope, vector[i]->intVal);
        if(vector[i]->type == Float)
        printf("Variable : %s\n\tType Float\n\tDepth : %d\n\tScope : %s\n\tValue: %f\n",
            vector[i]->name,vector[i]->depth, vector[i]->scope, vector[i]->floatVal);
        if(vector[i]->type == String)
        printf("Variable : %s\n\tType String\n\tDepth : %d\n\tScope : %s\n\tValue: %s\n",
            vector[i]->name,vector[i]->depth, vector[i]->scope, vector[i]->stringVal);
    }
}

void assignVarTypes(struct variable** vector, int length, char* scope,char* type)
{
    int typeForm = 0;
    if( !strcmp( type, "integer" ) )
        typeForm = Int;
    if( !strcmp( type, "float" ) )
        typeForm = Float;
    if( !strcmp( type, "string" ) )
        typeForm = String;
    for(int i = 0; i < length; i++)
    {
        if(vector[i]->type != typeForm && vector[i]->type > 0 &&
            ! (vector[i]->type == Int && typeForm == Float) )
        {
            yyerror("Cannot assign this value to this variable");
        }
        if( vector[i]->type == Int && typeForm == Float )
            vector[i]->floatVal = vector[i]->intVal; 
        vector[i]->type = typeForm;
        strcpy(vector[i]->scope, scope);
    }
}


void assignVarTypesAddress(struct variable** vector, int length,char* scope, char* type, int depth)
{
    int typeForm = 0;
    if( !strcmp( type, "integer" ) )
        typeForm = Int;
    if( !strcmp( type, "float" ) )
        typeForm = Float;
    if( !strcmp( type, "string" ) )
        typeForm = String;
    for(int i = 0; i < length; i++)
    {
        if(vector[i]->type != typeForm && vector[i]->type > 0 &&
            ! (vector[i]->type == Int && typeForm == Float) )
        {
            yyerror("Cannot assign this value to this variable");
        }
        vector[i]->type = typeForm;
        vector[i]->depth += depth;
        strcpy(vector[i]->scope, scope);
    }
}

void addToAllVariables(struct variable** vector, int length)
{
    for(int i = 0; i< length; i++)
    {
        allVars[numberOfVariables++] = vector[i];
    }
    free(vector);
}

void printAllVariables()
{
    for(int i = 0; i< numberOfVariables; i++)
    {
        if(allVars[i]->type == Int)
        printf("Variable : %s\n\tType Int\n\tDepth : %d\n\tScope : %s\n\tValue: %d\n",
            allVars[i]->name,allVars[i]->depth, allVars[i]->scope, allVars[i]->intVal);
        if(allVars[i]->type == Float)
        printf("Variable : %s\n\tType Float\n\tDepth : %d\n\tScope : %s\n\tValue: %f\n",
            allVars[i]->name,allVars[i]->depth, allVars[i]->scope, allVars[i]->floatVal);
        if(allVars[i]->type == String)
        printf("Variable : %s\n\tType String\n\tDepth : %d\n\tScope : %s\n\tValue: %s\n",
            allVars[i]->name,allVars[i]->depth, allVars[i]->scope, allVars[i]->stringVal);
    }
}

int variableExists(struct variable* var, char* scope)
{
    for( int i = 0; i < numberOfVariables; i++)
    {
        if( !strcmp(scope, allVars[i]->scope))
        {
            if( !strcmp( var->name, allVars[i]->name))
                return 1;
        } 
    }
    return 0;
}

void eval(struct value* val)
{
    if( val->type == Int)
        printf("%d\n", val->intVal);
    if( val->type == Float)
        printf("%f\n", val->floatVal);
    if( val->type == String)
        printf("%s\n", val->stringVal);
}

int yyerror(char * s)
{
	printf("\nEroare la linia: %d '%s'. \n",yylineno,s);
}


struct value* getVar(char* name, char* scope)
{
    struct value* res = (struct value*)malloc(sizeof(struct value));
    for(int i = 0 ;i < numberOfVariables; i++)
    {
        if( ! strcmp(allVars[i]->scope, scope))
        {
            if(!strcmp(allVars[i]->name, name))
            {
                res->type = allVars[i]->type;
                if(allVars[i]->type == Int)
                    res->intVal = allVars[i]->intVal;
                else if(allVars[i]->type == Float)
                    res->floatVal = allVars[i]->floatVal;
                else if(allVars[i]->type == String)
                    strcpy(res->stringVal ,allVars[i]->stringVal);
                return res;
            }
        }
    }
    yyerror("Var not declared");
    return NULL;
}

int main(int argc, char** argv){
	yyin=fopen(argv[1],"r");
	yyparse();
   // printAllVariables();
}

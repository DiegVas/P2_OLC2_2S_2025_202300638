/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "src/parser/parser.y"

#include <stdio.h>
#include <string.h>
#include "../structures/parser.h"

int yylex();
int yyerror(const char *s);

	extern InstruccionList *list_tokens;
    extern ErrorList *list_errors;


#line 84 "build/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STR = 3,                        /* STR  */
  YYSYMBOL_CHR = 4,                        /* CHR  */
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_OTHER = 7,                      /* OTHER  */
  YYSYMBOL_NUM = 8,                        /* NUM  */
  YYSYMBOL_DEC = 9,                        /* DEC  */
  YYSYMBOL_DECF = 10,                      /* DECF  */
  YYSYMBOL_BREAK_LINE = 11,                /* BREAK_LINE  */
  YYSYMBOL_INT = 12,                       /* INT  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_FLOAT = 15,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 16,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 17,                      /* BOOL  */
  YYSYMBOL_FINAL = 18,                     /* FINAL  */
  YYSYMBOL_PRINTLN = 19,                   /* PRINTLN  */
  YYSYMBOL_NULL_EXP = 20,                  /* NULL_EXP  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_SWITCH = 23,                    /* SWITCH  */
  YYSYMBOL_CASE = 24,                      /* CASE  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 26,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 27,                  /* CONTINUE  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_FOR = 29,                       /* FOR  */
  YYSYMBOL_EQUALS_OP = 30,                 /* EQUALS_OP  */
  YYSYMBOL_NEW = 31,                       /* NEW  */
  YYSYMBOL_INTEGER_OBJ = 32,               /* INTEGER_OBJ  */
  YYSYMBOL_PARSEINT = 33,                  /* PARSEINT  */
  YYSYMBOL_DOUBLE_OBJ = 34,                /* DOUBLE_OBJ  */
  YYSYMBOL_PARSEDOUBLE = 35,               /* PARSEDOUBLE  */
  YYSYMBOL_FLOAT_OBJ = 36,                 /* FLOAT_OBJ  */
  YYSYMBOL_PARSEFLOAT = 37,                /* PARSEFLOAT  */
  YYSYMBOL_VALUEOF = 38,                   /* VALUEOF  */
  YYSYMBOL_JOIN = 39,                      /* JOIN  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_VOID = 41,                      /* VOID  */
  YYSYMBOL_PUBLIC = 42,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 43,                    /* STATIC  */
  YYSYMBOL_MAIN = 44,                      /* MAIN  */
  YYSYMBOL_LEFT_SHIFT = 45,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 46,               /* RIGHT_SHIFT  */
  YYSYMBOL_PLUS_ASSIGN = 47,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 48,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 49,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 50,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 51,                /* MOD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 52,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 53,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 54,                /* XOR_ASSIGN  */
  YYSYMBOL_LEFT_SHIFT_ASSIGN = 55,         /* LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGN = 56,        /* RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_EQUALS = 57,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 58,                /* NOT_EQUALS  */
  YYSYMBOL_AND = 59,                       /* AND  */
  YYSYMBOL_OR = 60,                        /* OR  */
  YYSYMBOL_NOT = 61,                       /* NOT  */
  YYSYMBOL_GREATER_EQUALS = 62,            /* GREATER_EQUALS  */
  YYSYMBOL_LESS_EQUALS = 63,               /* LESS_EQUALS  */
  YYSYMBOL_INCREMENT = 64,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 65,                 /* DECREMENT  */
  YYSYMBOL_ARRAYS = 66,                    /* ARRAYS  */
  YYSYMBOL_INDEXOF = 67,                   /* INDEXOF  */
  YYSYMBOL_LENGTH = 68,                    /* LENGTH  */
  YYSYMBOL_ADD = 69,                       /* ADD  */
  YYSYMBOL_70_ = 70,                       /* '='  */
  YYSYMBOL_71_ = 71,                       /* '|'  */
  YYSYMBOL_72_ = 72,                       /* '^'  */
  YYSYMBOL_73_ = 73,                       /* '&'  */
  YYSYMBOL_74_ = 74,                       /* '<'  */
  YYSYMBOL_75_ = 75,                       /* '>'  */
  YYSYMBOL_76_ = 76,                       /* '+'  */
  YYSYMBOL_77_ = 77,                       /* '-'  */
  YYSYMBOL_78_ = 78,                       /* '*'  */
  YYSYMBOL_79_ = 79,                       /* '/'  */
  YYSYMBOL_80_ = 80,                       /* '%'  */
  YYSYMBOL_UMINUS = 81,                    /* UMINUS  */
  YYSYMBOL_82_ = 82,                       /* '['  */
  YYSYMBOL_83_ = 83,                       /* ']'  */
  YYSYMBOL_84_ = 84,                       /* '('  */
  YYSYMBOL_85_ = 85,                       /* ')'  */
  YYSYMBOL_86_ = 86,                       /* '{'  */
  YYSYMBOL_87_ = 87,                       /* '}'  */
  YYSYMBOL_88_ = 88,                       /* ';'  */
  YYSYMBOL_89_ = 89,                       /* '.'  */
  YYSYMBOL_90_ = 90,                       /* ','  */
  YYSYMBOL_91_ = 91,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 92,                  /* $accept  */
  YYSYMBOL_program = 93,                   /* program  */
  YYSYMBOL_sentences = 94,                 /* sentences  */
  YYSYMBOL_sentence = 95,                  /* sentence  */
  YYSYMBOL_separator = 96,                 /* separator  */
  YYSYMBOL_instruction = 97,               /* instruction  */
  YYSYMBOL_assignment = 98,                /* assignment  */
  YYSYMBOL_assignment_expression = 99,     /* assignment_expression  */
  YYSYMBOL_declaration = 100,              /* declaration  */
  YYSYMBOL_primitive_types = 101,          /* primitive_types  */
  YYSYMBOL_primitive_values = 102,         /* primitive_values  */
  YYSYMBOL_expression = 103,               /* expression  */
  YYSYMBOL_exprList = 104,                 /* exprList  */
  YYSYMBOL_IF_STATEMENT = 105,             /* IF_STATEMENT  */
  YYSYMBOL_IF_LIST = 106,                  /* IF_LIST  */
  YYSYMBOL_ELSE_STATEMENT = 107,           /* ELSE_STATEMENT  */
  YYSYMBOL_SWITCH_STATEMENT = 108,         /* SWITCH_STATEMENT  */
  YYSYMBOL_CASES = 109,                    /* CASES  */
  YYSYMBOL_DEFAULT_CASE = 110,             /* DEFAULT_CASE  */
  YYSYMBOL_WHILE_STATEMENT = 111,          /* WHILE_STATEMENT  */
  YYSYMBOL_FOR_STATEMENT = 112,            /* FOR_STATEMENT  */
  YYSYMBOL_FOREACH_STATEMENT = 113,        /* FOREACH_STATEMENT  */
  YYSYMBOL_dimensions = 114,               /* dimensions  */
  YYSYMBOL_dimensions_value_list = 115,    /* dimensions_value_list  */
  YYSYMBOL_dimensions_expressions = 116,   /* dimensions_expressions  */
  YYSYMBOL_vectorList = 117,               /* vectorList  */
  YYSYMBOL_matrixList = 118,               /* matrixList  */
  YYSYMBOL_dimension_expression = 119,     /* dimension_expression  */
  YYSYMBOL_dimension_values_list = 120,    /* dimension_values_list  */
  YYSYMBOL_dimension_value = 121,          /* dimension_value  */
  YYSYMBOL_optional_newlines = 122,        /* optional_newlines  */
  YYSYMBOL_paramsList = 123                /* paramsList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1599

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    80,    73,     2,
      84,    85,    78,    76,    90,    77,    89,    79,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    88,
      74,    70,    75,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    72,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,    71,    87,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    81
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   162,   187,   197,   202,   205,   208,   215,
     216,   220,   228,   237,   242,   249,   259,   264,   272,   280,
     285,   290,   295,   302,   309,   323,   330,   349,   355,   361,
     367,   373,   379,   385,   391,   397,   403,   409,   416,   425,
     436,   461,   473,   487,   496,   505,   520,   534,   544,   563,
     574,   583,   593,   615,   616,   617,   618,   619,   620,   625,
     631,   637,   643,   649,   655,   660,   670,   671,   677,   683,
     690,   697,   704,   711,   718,   719,   726,   733,   740,   748,
     757,   765,   775,   783,   791,   799,   807,   815,   823,   831,
     839,   846,   853,   860,   867,   874,   881,   888,   894,   901,
     922,   931,   935,   940,   950,   960,   961,   970,   971,   975,
     986,   987,   997,   998,  1006,  1018,  1033,  1046,  1047,  1050,
    1057,  1065,  1070,  1077,  1081,  1086,  1094,  1098,  1103,  1109,
    1112,  1113,  1118,  1121,  1124,  1131,  1132,  1139,  1140,  1145,
    1153,  1157
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STR", "CHR",
  "BOOLEAN", "ID", "OTHER", "NUM", "DEC", "DECF", "BREAK_LINE", "INT",
  "STRING", "CHAR", "FLOAT", "DOUBLE", "BOOL", "FINAL", "PRINTLN",
  "NULL_EXP", "IF", "ELSE", "SWITCH", "CASE", "BREAK", "DEFAULT",
  "CONTINUE", "WHILE", "FOR", "EQUALS_OP", "NEW", "INTEGER_OBJ",
  "PARSEINT", "DOUBLE_OBJ", "PARSEDOUBLE", "FLOAT_OBJ", "PARSEFLOAT",
  "VALUEOF", "JOIN", "RETURN", "VOID", "PUBLIC", "STATIC", "MAIN",
  "LEFT_SHIFT", "RIGHT_SHIFT", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "AND_ASSIGN", "OR_ASSIGN",
  "XOR_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN", "EQUALS",
  "NOT_EQUALS", "AND", "OR", "NOT", "GREATER_EQUALS", "LESS_EQUALS",
  "INCREMENT", "DECREMENT", "ARRAYS", "INDEXOF", "LENGTH", "ADD", "'='",
  "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "'.'", "','",
  "':'", "$accept", "program", "sentences", "sentence", "separator",
  "instruction", "assignment", "assignment_expression", "declaration",
  "primitive_types", "primitive_values", "expression", "exprList",
  "IF_STATEMENT", "IF_LIST", "ELSE_STATEMENT", "SWITCH_STATEMENT", "CASES",
  "DEFAULT_CASE", "WHILE_STATEMENT", "FOR_STATEMENT", "FOREACH_STATEMENT",
  "dimensions", "dimensions_value_list", "dimensions_expressions",
  "vectorList", "matrixList", "dimension_expression",
  "dimension_values_list", "dimension_value", "optional_newlines",
  "paramsList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-330)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-122)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -330,    40,   242,  -330,   -10,   -33,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,   170,   -80,   -36,   -18,  -330,  -330,   -17,
      -9,   909,    70,    28,  -330,  -330,  -330,  -330,   -10,  -330,
     340,  -330,    -3,  -330,  -330,  -330,  -330,  -330,  -330,   909,
     909,    46,   -48,    81,   815,   909,    84,   909,   100,  -330,
    -330,  -330,    38,  -330,  -330,  -330,    55,  -330,    57,    67,
      68,   909,    79,   909,   874,  -330,  1423,    39,   131,   148,
    -330,   909,   909,   909,   909,   909,   909,   909,   909,   909,
     909,  -330,  -330,    56,    87,  1423,  1315,  -330,   909,   909,
     104,  -330,  1003,  1027,    93,  1051,    91,     0,   121,   909,
     909,   -45,   136,    -6,   184,   191,   190,  -330,   161,   145,
      55,   144,  1075,   909,   909,   909,   909,   909,   909,   909,
     909,   909,   909,   909,   909,   909,   909,   909,   909,   909,
     909,   147,   186,  -330,  1423,  1423,  1423,  1423,  1423,  1423,
    1423,  1423,  1423,  1423,   909,   170,   -39,     1,    -5,  1423,
    1351,   909,  -330,   151,   152,   153,   909,   -55,   909,  1387,
    1423,    62,  -330,   149,   156,   157,   165,   167,   168,   178,
     909,  -330,   123,   123,  1495,  1495,  1471,  1447,   135,   135,
     904,   235,  1519,   135,   135,   145,   145,  -330,  -330,  -330,
     159,   180,  1423,     4,    63,   -14,   183,   198,   189,  -330,
    1423,   262,   263,   264,   967,   270,  1099,  -330,  -330,   909,
     909,   909,   909,   909,   909,   909,   271,  1423,   267,   194,
    -330,   202,   201,   170,   170,  -330,  -330,  -330,    -1,   282,
    -330,  -330,  -330,   982,   205,  -330,  1423,  1123,  1147,    65,
    1171,  1195,  1219,   204,  -330,   209,   285,   288,     6,   214,
     780,   211,   170,   909,   232,   326,    15,   357,   220,   230,
    -330,  -330,  -330,  -330,  -330,  -330,   909,   409,  -330,  -330,
    -330,  -330,   234,   311,   238,  -330,  1423,  -330,   231,  -330,
     253,   241,  1423,   -40,   -12,  -330,   125,   233,   239,  -330,
     245,   314,  1243,  -330,   440,   492,   328,   252,   338,  -330,
       2,   325,   268,   348,  -330,   909,   170,  -330,   335,   257,
     349,  -330,   350,  -330,  -330,  -330,  -330,  -330,  -330,   276,
     780,  -330,   909,   279,  1423,   283,     5,   -13,  -330,   353,
    -330,  -330,   523,  -330,  -330,  1267,  -330,   369,   909,    34,
     295,   370,  -330,   575,   606,  -330,   325,  -330,   300,   117,
    -330,  -330,   909,  -330,   741,  -330,   317,  -330,     7,  1291,
     658,   312,   393,   325,   909,   316,  -330,   392,   323,   129,
     396,  -330,  -330,  -330,  -330,   325,   689,  -330
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     0,    39,     9,    53,    54,    58,
      56,    55,    57,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     5,    10,     4,     7,     0,    16,
       0,    13,     0,    17,    18,    19,    21,    20,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      64,    63,    67,    59,    61,    62,     0,    65,     0,     0,
       0,     0,     0,     0,     0,    66,    24,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    42,     0,    25,     0,    12,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,    99,     0,     0,     0,     0,    90,     0,    68,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     0,   137,     0,     0,    40,    26,
       0,     0,    14,     0,     0,     0,     0,    42,     0,     0,
     102,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    79,    80,    82,    83,    88,    89,    86,    87,
      77,    78,    76,    85,    84,    69,    70,    71,    72,    73,
       0,     0,    41,     0,     0,     0,     0,     0,     0,   122,
      43,     0,     0,     0,     0,     0,     0,   121,   100,     0,
       0,     0,   101,     0,     0,     0,     0,    75,     0,     0,
     138,     0,     0,     0,     0,   135,    51,   118,     0,     0,
       5,   110,     5,     0,     0,    81,   103,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
     130,     0,     0,   123,     0,     0,   112,     0,     0,     0,
      98,    94,    95,    91,    92,    93,     0,     0,     5,   139,
       5,   140,     0,     0,    52,   136,   133,   134,   135,   135,
       0,     0,   124,     0,     0,   105,     0,     0,     0,   114,
       0,     0,     0,    50,     0,     0,     0,     0,     0,   135,
       0,   131,     0,     0,    44,     0,     0,   135,   107,     0,
       0,   109,     0,     5,    96,     3,    49,   141,   119,     0,
       0,   129,     0,     0,   125,     0,   126,     0,   104,     0,
       5,     5,     0,   120,   135,     0,    45,     0,   123,     0,
       0,     0,     5,     0,     0,   116,   132,    46,     0,     0,
      47,   135,     0,     5,     0,   115,     0,   135,     0,     0,
       0,    22,     0,   127,   123,     0,   108,     0,     0,     0,
       0,   111,    48,   135,     5,   128,     0,   106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -330,  -330,   -24,  -330,    10,   175,  -330,  -330,   361,    -2,
     130,   -19,   199,  -330,  -330,  -330,  -330,  -330,  -330,  -330,
    -330,  -330,  -330,  -330,   365,  -329,  -330,   223,  -330,    99,
    -215,  -330
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    26,    27,    28,    29,    30,    31,    32,
      65,   282,   161,    33,   308,   328,    34,   256,   288,    35,
      36,    37,   146,   274,    42,   283,   339,   277,   278,   279,
     250,   194
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,     6,    66,    83,    44,   251,   157,   197,   340,   349,
     220,    43,   271,   275,    38,   144,   275,   224,   275,   306,
      85,    86,    88,   162,   163,    92,    93,  -117,    95,   145,
     252,   195,   164,   165,    89,   369,   205,    39,    70,   286,
       3,   287,   107,   196,   109,   112,    97,   304,    45,    40,
     305,    41,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   111,   300,   301,  -121,    46,    47,    98,   149,
     150,    68,   225,   341,   307,    48,    67,  -121,    25,    84,
     159,   160,    84,   198,   320,   253,   221,    90,   272,   321,
      94,   338,   326,   364,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     7,     8,     9,    10,    11,    12,    13,   346,
      99,   350,   100,   131,   351,   192,   144,   101,    49,    50,
      51,    87,   200,    53,    54,    55,   358,   204,  -117,   206,
     145,    22,   363,   193,   103,    57,   104,   208,   222,     4,
     262,   217,   209,   223,     5,   209,   105,   106,   375,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   108,    15,
     147,    16,   132,    17,   151,    18,    19,    20,   154,   156,
     113,   114,     7,     8,     9,    10,    11,    12,    21,    22,
     236,   237,   238,   160,   240,   241,   242,  -122,  -122,   126,
     127,   128,   129,   130,   357,   158,   255,   305,   257,  -122,
    -122,   126,   127,   128,   129,   130,   373,   166,    89,   305,
     267,   248,   249,   128,   129,   130,   167,   168,   169,   170,
     191,   276,   190,   210,    24,   133,    25,   201,   202,   203,
     211,   212,    -2,     4,   294,   218,   295,   292,     5,   213,
     281,   214,   215,     6,     7,     8,     9,    10,    11,    12,
      13,    14,   216,    15,   219,    16,   227,    17,   228,    18,
      19,    20,   229,   230,   231,   232,   234,   243,   244,   245,
     113,   114,    21,    22,    23,   246,   324,   247,   254,   332,
     259,   269,   115,   116,   266,   268,   273,   119,   120,   270,
     280,   276,   284,   335,   325,   290,   343,   344,   123,   124,
     125,   126,   127,   128,   129,   130,   291,   296,   354,   297,
     298,   299,   302,   303,   310,   313,   311,     4,    24,   360,
      25,   312,     5,   359,   317,   318,   275,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   319,    15,   329,    16,
     376,    17,   322,    18,    19,    20,   323,   327,     4,   333,
     330,   331,   336,     5,   342,   337,    21,    22,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   348,    15,   352,
      16,   353,    17,   356,    18,    19,    20,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    21,    22,   362,
     367,   368,   370,   371,    81,    82,   372,   374,   258,    96,
       4,   239,    24,   285,    25,     5,   309,   102,   226,   334,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
      15,     0,    16,     0,    17,     0,    18,    19,    20,     0,
       0,     4,     0,    24,   289,    25,     5,     0,     0,    21,
      22,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,    15,     0,    16,     0,    17,     0,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,    24,   293,    25,     5,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,    15,     0,    16,     0,    17,     0,    18,
      19,    20,     0,     0,     4,     0,    24,   315,    25,     5,
       0,     0,    21,    22,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,    15,     0,    16,     0,    17,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,    24,   316,
      25,     5,     0,     0,     0,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,    15,     0,    16,     0,
      17,     0,    18,    19,    20,     0,     0,     4,     0,    24,
     345,    25,     5,     0,     0,    21,    22,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,    15,     0,    16,
       0,    17,     0,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,    24,  -113,    25,     5,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,    15,
       0,    16,     0,    17,     0,    18,    19,    20,     0,     0,
       4,     0,    24,   355,    25,     5,     0,     0,    21,    22,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
      15,     0,    16,     0,    17,     0,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,    24,   366,    25,     5,     0,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,    15,     0,    16,     0,   361,     0,    18,    19,
      20,     0,     0,     0,     0,    24,   377,    25,     0,     0,
       0,    21,    22,    49,    50,    51,    52,     0,    53,    54,
      55,   275,     0,    56,     0,     0,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    59,     0,    60,     0,    49,    50,
      51,    52,     0,    53,    54,    55,     0,    24,    56,    25,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,    62,    58,     0,    59,
       0,    60,     0,     0,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,    64,     0,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    49,    50,    51,
      52,    62,    53,    54,    55,     0,     7,   110,     9,    10,
      11,    12,    63,     0,    57,     0,     0,     0,     0,    64,
      91,     0,     0,     0,     0,     0,    58,     0,    59,     0,
      60,     0,    49,    50,    51,    52,     0,    53,    54,    55,
       0,     0,    56,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
      62,    58,     0,    59,     0,    60,     0,     0,     0,   113,
     114,    63,     0,     0,     0,     0,     0,     0,    64,     0,
       0,   115,   116,     0,     0,     0,   119,   120,     0,     0,
      61,     0,     0,     0,     0,    62,   122,   123,   124,   125,
     126,   127,   128,   129,   130,     0,    63,     0,     5,     0,
       0,     0,     0,    64,     7,     8,     9,    10,    11,    12,
      13,    14,     0,    15,     0,    16,     0,    17,     0,    18,
      19,    20,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    22,   115,   116,   117,   118,     0,   119,
     120,     0,     0,     0,     0,     0,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   113,   114,
       0,     0,     0,     0,     0,   233,     0,     0,     0,     0,
     115,   116,   117,   118,     0,   119,   120,     0,    24,     0,
       0,     0,   113,   114,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   115,   116,   117,   118,   152,   119,
     120,     0,     0,     0,     0,     0,   113,   114,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   115,   116,
     117,   118,   153,   119,   120,     0,     0,     0,     0,     0,
     113,   114,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   115,   116,   117,   118,   155,   119,   120,     0,
       0,     0,     0,     0,   113,   114,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   115,   116,   117,   118,
     171,   119,   120,     0,     0,     0,     0,     0,   113,   114,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     115,   116,   117,   118,   235,   119,   120,     0,     0,     0,
       0,     0,   113,   114,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   115,   116,   117,   118,   260,   119,
     120,     0,     0,     0,     0,     0,   113,   114,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   115,   116,
     117,   118,   261,   119,   120,     0,     0,     0,     0,     0,
     113,   114,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   115,   116,   117,   118,   263,   119,   120,     0,
       0,     0,     0,     0,   113,   114,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   115,   116,   117,   118,
     264,   119,   120,     0,     0,     0,     0,     0,   113,   114,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     115,   116,   117,   118,   265,   119,   120,     0,     0,     0,
       0,     0,   113,   114,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   115,   116,   117,   118,   314,   119,
     120,     0,     0,     0,     0,     0,   113,   114,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   115,   116,
     117,   118,   347,   119,   120,     0,     0,     0,     0,     0,
     113,   114,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   115,   116,   117,   118,   365,   119,   120,     0,
       0,     0,     0,     0,     0,     0,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   113,   114,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,   118,     0,   119,   120,     0,     0,     0,     0,     0,
       0,     0,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   113,   114,   199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   116,   117,   118,     0,   119,
     120,     0,     0,     0,     0,     0,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   113,   114,
     207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   118,     0,   119,   120,     0,     0,     0,
       0,     0,   113,   114,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   115,   116,   117,     0,     0,   119,
     120,     0,     0,     0,     0,     0,   113,   114,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   115,   116,
       0,     0,     0,   119,   120,     0,     0,     0,     0,     0,
     113,   114,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,  -122,  -122,     0,     0,     0,   119,   120,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,   115,   116,     0,     0,
       0,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   130
};

static const yytype_int16 yycheck[] =
{
      24,    11,    21,     6,    84,     6,     6,     6,    21,   338,
       6,    13,     6,    11,     4,    70,    11,    31,    11,    31,
      39,    40,    70,    68,    69,    44,    45,    82,    47,    84,
      31,    70,    38,    39,    82,   364,    91,    70,    28,    24,
       0,    26,    61,    82,    63,    64,    48,    87,    84,    82,
      90,    84,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    64,   278,   279,    70,    84,    84,    30,    88,
      89,    43,    86,    86,    86,    84,     6,    82,    88,    82,
      99,   100,    82,    82,   299,    86,    82,     6,    82,    87,
       6,    86,   307,    86,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    12,    13,    14,    15,    16,    17,    18,   334,
      82,    87,    84,    84,    90,   144,    70,    89,     3,     4,
       5,    85,   151,     8,     9,    10,   351,   156,    82,   158,
      84,    41,   357,   145,    89,    20,    89,    85,    85,     1,
      85,   170,    90,    90,     6,    90,    89,    89,   373,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    89,    21,
      83,    23,    41,    25,    70,    27,    28,    29,    85,    88,
      45,    46,    12,    13,    14,    15,    16,    17,    40,    41,
     209,   210,   211,   212,   213,   214,   215,    62,    63,    76,
      77,    78,    79,    80,    87,    84,   230,    90,   232,    74,
      75,    76,    77,    78,    79,    80,    87,    33,    82,    90,
     244,   223,   224,    78,    79,    80,    35,    37,    67,    85,
      44,   250,    85,    84,    86,    87,    88,    86,    86,    86,
      84,    84,     0,     1,   268,    86,   270,   266,     6,    84,
     252,    84,    84,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    84,    21,    84,    23,    83,    25,    70,    27,
      28,    29,    83,    11,    11,    11,     6,     6,    11,    85,
      45,    46,    40,    41,    42,    83,   305,    86,     6,   313,
      85,     6,    57,    58,    90,    86,    82,    62,    63,    11,
      89,   320,    70,   322,   306,    85,   330,   331,    73,    74,
      75,    76,    77,    78,    79,    80,    86,    83,   342,     8,
      82,    90,    69,    82,    91,    11,    87,     1,    86,   353,
      88,    86,     6,   352,     6,    83,    11,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     8,    21,    91,    23,
     374,    25,    84,    27,    28,    29,     8,    22,     1,    83,
      11,    11,    83,     6,    11,    82,    40,    41,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     8,    21,    84,
      23,    11,    25,    83,    27,    28,    29,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    40,    41,    82,
      88,     8,    86,    11,    64,    65,    83,    11,   233,    48,
       1,   212,    86,    87,    88,     6,   286,    52,   195,   320,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    -1,    23,    -1,    25,    -1,    27,    28,    29,    -1,
      -1,     1,    -1,    86,    87,    88,     6,    -1,    -1,    40,
      41,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    -1,    23,    -1,    25,    -1,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    86,    87,    88,     6,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    -1,    23,    -1,    25,    -1,    27,
      28,    29,    -1,    -1,     1,    -1,    86,    87,    88,     6,
      -1,    -1,    40,    41,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    -1,    23,    -1,    25,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    86,    87,
      88,     6,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    -1,    23,    -1,
      25,    -1,    27,    28,    29,    -1,    -1,     1,    -1,    86,
      87,    88,     6,    -1,    -1,    40,    41,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    -1,    23,
      -1,    25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    86,    87,    88,     6,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    23,    -1,    25,    -1,    27,    28,    29,    -1,    -1,
       1,    -1,    86,    87,    88,     6,    -1,    -1,    40,    41,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    -1,    23,    -1,    25,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    86,    87,    88,     6,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    -1,    23,    -1,    25,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,
      -1,    40,    41,     3,     4,     5,     6,    -1,     8,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    -1,    36,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    -1,    86,    13,    88,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    66,    32,    -1,    34,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,     3,     4,     5,
       6,    66,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    77,    -1,    20,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,
      36,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,    -1,
      66,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,    45,
      46,    77,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    57,    58,    -1,    -1,    -1,    62,    63,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    66,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    77,    -1,     6,    -1,
      -1,    -1,    -1,    84,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    -1,    23,    -1,    25,    -1,    27,
      28,    29,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    57,    58,    59,    60,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    45,    46,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    62,    63,    -1,    86,    -1,
      -1,    -1,    45,    46,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    57,    58,    59,    60,    85,    62,
      63,    -1,    -1,    -1,    -1,    -1,    45,    46,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    57,    58,
      59,    60,    85,    62,    63,    -1,    -1,    -1,    -1,    -1,
      45,    46,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    57,    58,    59,    60,    85,    62,    63,    -1,
      -1,    -1,    -1,    -1,    45,    46,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    57,    58,    59,    60,
      85,    62,    63,    -1,    -1,    -1,    -1,    -1,    45,    46,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      57,    58,    59,    60,    85,    62,    63,    -1,    -1,    -1,
      -1,    -1,    45,    46,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    57,    58,    59,    60,    85,    62,
      63,    -1,    -1,    -1,    -1,    -1,    45,    46,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    57,    58,
      59,    60,    85,    62,    63,    -1,    -1,    -1,    -1,    -1,
      45,    46,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    57,    58,    59,    60,    85,    62,    63,    -1,
      -1,    -1,    -1,    -1,    45,    46,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    57,    58,    59,    60,
      85,    62,    63,    -1,    -1,    -1,    -1,    -1,    45,    46,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      57,    58,    59,    60,    85,    62,    63,    -1,    -1,    -1,
      -1,    -1,    45,    46,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    57,    58,    59,    60,    85,    62,
      63,    -1,    -1,    -1,    -1,    -1,    45,    46,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    57,    58,
      59,    60,    85,    62,    63,    -1,    -1,    -1,    -1,    -1,
      45,    46,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    57,    58,    59,    60,    85,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    45,    46,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    45,    46,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    45,    46,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    45,    46,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    57,    58,    59,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    45,    46,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    57,    58,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      45,    46,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    57,    58,    -1,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    57,    58,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    93,    94,     0,     1,     6,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    21,    23,    25,    27,    28,
      29,    40,    41,    42,    86,    88,    95,    96,    97,    98,
      99,   100,   101,   105,   108,   111,   112,   113,    96,    70,
      82,    84,   116,   101,    84,    84,    84,    84,    84,     3,
       4,     5,     6,     8,     9,    10,    13,    20,    32,    34,
      36,    61,    66,    77,    84,   102,   103,     6,    43,    94,
      96,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    64,    65,     6,    82,   103,   103,    85,    70,    82,
       6,    85,   103,   103,     6,   103,   100,   101,    30,    82,
      84,    89,   116,    89,    89,    89,    89,   103,    89,   103,
      13,   101,   103,    45,    46,    57,    58,    59,    60,    62,
      63,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    84,    41,    87,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,    70,    84,   114,    83,    83,   103,
     103,    70,    85,    85,    85,    85,    88,     6,    84,   103,
     103,   104,    68,    69,    38,    39,    33,    35,    37,    67,
      85,    85,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
      85,    44,   103,   101,   123,    70,    82,     6,    82,    83,
     103,    86,    86,    86,   103,    91,   103,    83,    85,    90,
      84,    84,    84,    84,    84,    84,    84,   103,    86,    84,
       6,    82,    85,    90,    31,    86,   119,    83,    70,    83,
      11,    11,    11,    88,     6,    85,   103,   103,   103,   104,
     103,   103,   103,     6,    11,    85,    83,    86,   101,   101,
     122,     6,    31,    86,     6,    94,   109,    94,    97,    85,
      85,    85,    85,    85,    85,    85,    90,    94,    86,     6,
      11,     6,    82,    82,   115,    11,   103,   119,   120,   121,
      89,   101,   103,   117,    70,    87,    24,    26,   110,    87,
      85,    86,   103,    87,    94,    94,    83,     8,    82,    90,
     122,   122,    69,    82,    87,    90,    31,    86,   106,   102,
      91,    87,    86,    11,    85,    87,    87,     6,    83,     8,
     122,    87,    84,     8,   103,   101,   122,    22,   107,    91,
      11,    11,    94,    83,   121,   103,    83,    82,    86,   118,
      21,    86,    11,    94,    94,    87,   122,    85,     8,   117,
      87,    90,    84,    11,    94,    87,    83,    87,   122,   103,
      94,    25,    82,   122,    86,    85,    87,    88,     8,   117,
      86,    11,    83,    87,    11,   122,    94,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    92,    93,    93,    94,    94,    95,    95,    95,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   101,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   105,   106,   106,   107,   107,   108,
     109,   109,   110,   110,   111,   112,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   118,   118,   118,   119,
     120,   120,   120,   121,   121,   122,   122,   123,   123,   123,
     123,   123
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,    10,     2,     0,     2,     1,     2,     1,
       1,     3,     3,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       4,     4,     2,     5,     8,    10,    11,    11,    15,     9,
       8,     5,     7,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     4,     3,     3,     3,     3,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     6,     6,     6,     6,     6,     8,     3,     6,     2,
       4,     0,     1,     3,    10,     0,    10,     0,     5,     9,
       0,     9,     0,     4,     8,    12,    11,     0,     3,     3,
       4,     3,     4,     0,     1,     3,     0,     4,     7,     5,
       0,     2,     5,     1,     1,     0,     2,     0,     2,     4,
       4,     6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: sentences  */
#line 150 "src/parser/parser.y"
                { 
        printf("Programa completo\n");
        // Copiar todas las instrucciones a la lista global
        if ((yyvsp[0].instrList) && (yyvsp[0].instrList)->head) {
            InstruccionNode *curr = (yyvsp[0].instrList)->head;
            while (curr) {
                InstruccionList_insert(list_tokens, curr->instr);
                curr = curr->next;
            }
        }
        (yyval.instrList) = (yyvsp[0].instrList);
     }
#line 2083 "build/parser.tab.c"
    break;

  case 3: /* program: sentences PUBLIC STATIC VOID MAIN '(' ')' '{' sentences '}'  */
#line 162 "src/parser/parser.y"
                                                                  {
        // Código antes del main + main
        // $1 son las instrucciones antes del main
        // $9 son las instrucciones dentro del main
        printf("Programa con main y código previo\n");
        
        // Combinar ambas listas de instrucciones
        if ((yyvsp[-9].instrList) && (yyvsp[-9].instrList)->head) {
            InstruccionNode *curr = (yyvsp[-9].instrList)->head;
            while (curr) {
                InstruccionList_insert(list_tokens, curr->instr);
                curr = curr->next;
            }
        }
        if ((yyvsp[-1].instrList) && (yyvsp[-1].instrList)->head) {
            InstruccionNode *curr = (yyvsp[-1].instrList)->head;
            while (curr) {
                InstruccionList_insert(list_tokens, curr->instr);
                curr = curr->next;
            }
        }
        (yyval.instrList) = (yyvsp[-9].instrList);
    }
#line 2111 "build/parser.tab.c"
    break;

  case 4: /* sentences: sentences sentence  */
#line 188 "src/parser/parser.y"
        { 
            if ((yyvsp[0].instr) != NULL) {
                InstruccionList_insert((yyvsp[-1].instrList), (yyvsp[0].instr));
                (yyval.instrList) = (yyvsp[-1].instrList);
            } else {
                (yyval.instrList) = (yyvsp[-1].instrList);
            }
        }
#line 2124 "build/parser.tab.c"
    break;

  case 5: /* sentences: %empty  */
#line 197 "src/parser/parser.y"
        { 
            (yyval.instrList) = InstruccionList_create();
        }
#line 2132 "build/parser.tab.c"
    break;

  case 6: /* sentence: instruction separator  */
#line 202 "src/parser/parser.y"
                           {
        (yyval.instr) = (yyvsp[-1].instr);
    }
#line 2140 "build/parser.tab.c"
    break;

  case 7: /* sentence: separator  */
#line 205 "src/parser/parser.y"
                {
        (yyval.instr) = NULL;
    }
#line 2148 "build/parser.tab.c"
    break;

  case 8: /* sentence: error separator  */
#line 208 "src/parser/parser.y"
                      {
        // Recuperación de error: saltar hasta el siguiente separador
        yyerrok;
        (yyval.instr) = NULL;
    }
#line 2158 "build/parser.tab.c"
    break;

  case 9: /* separator: BREAK_LINE  */
#line 215 "src/parser/parser.y"
                 {}
#line 2164 "build/parser.tab.c"
    break;

  case 10: /* separator: ';'  */
#line 216 "src/parser/parser.y"
          { /* skip */ }
#line 2170 "build/parser.tab.c"
    break;

  case 11: /* instruction: '{' sentences '}'  */
#line 220 "src/parser/parser.y"
                      {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "BLOCK";
        instP->id = "BLOCK";
        instP->body = (yyvsp[-1].instrList);
        instP->line = (yylsp[-2]).first_line;
        instP->column = (yylsp[-2]).first_column;
        (yyval.instr) = instP; }
#line 2183 "build/parser.tab.c"
    break;

  case 12: /* instruction: ID '(' ')'  */
#line 228 "src/parser/parser.y"
                 {
        fprintf(stderr, "Función void llamada: %s\n", (yyvsp[-2].sval));
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "VOID_CALL";
        instP->id = (yyvsp[-2].sval);
        instP->line = (yylsp[-2]).first_line;
        instP->column = (yylsp[-2]).first_column;
        (yyval.instr) = instP;
    }
#line 2197 "build/parser.tab.c"
    break;

  case 13: /* instruction: declaration  */
#line 237 "src/parser/parser.y"
                  {
        (yyvsp[0].instr)->InstType = "DECLARATION";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr);
    }
#line 2207 "build/parser.tab.c"
    break;

  case 14: /* instruction: PRINTLN '(' expression ')'  */
#line 242 "src/parser/parser.y"
                                 {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "PRINTLN";
        instP->value = (yyvsp[-1].expr);
        instP->line = (yylsp[-3]).first_line;
        (yyval.instr) = instP;
    }
#line 2219 "build/parser.tab.c"
    break;

  case 15: /* instruction: PRINTLN '(' ')'  */
#line 249 "src/parser/parser.y"
                      {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "PRINTLN";
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("CHARACTER");
        exp->value = strdup("\n");
        instP->value = exp;
        instP->line = (yylsp[-2]).first_line;
        (yyval.instr) = instP;
    }
#line 2234 "build/parser.tab.c"
    break;

  case 16: /* instruction: assignment  */
#line 259 "src/parser/parser.y"
                 {
        (yyvsp[0].instr)->InstType = "ASSIGNMENT";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr);
    }
#line 2244 "build/parser.tab.c"
    break;

  case 17: /* instruction: IF_STATEMENT  */
#line 264 "src/parser/parser.y"
                   {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "IF_STATEMENT";
        instP->ifData = (yyvsp[0].ifdata);
        instP->line = (yylsp[0]).first_line;
        instP->column = (yylsp[0]).first_column;
        (yyval.instr) = instP;
    }
#line 2257 "build/parser.tab.c"
    break;

  case 18: /* instruction: SWITCH_STATEMENT  */
#line 272 "src/parser/parser.y"
                       {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "SWITCH_STATEMENT";
        instP->switchData = (yyvsp[0].switchdata);
        instP->line = (yylsp[0]).first_line;
        instP->column = (yylsp[0]).first_column;
        (yyval.instr) = instP;
    }
#line 2270 "build/parser.tab.c"
    break;

  case 19: /* instruction: WHILE_STATEMENT  */
#line 280 "src/parser/parser.y"
                      {
        (yyvsp[0].instr)->InstType = "WHILE_STATEMENT";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr); 
    }
#line 2280 "build/parser.tab.c"
    break;

  case 20: /* instruction: FOREACH_STATEMENT  */
#line 285 "src/parser/parser.y"
                       {
        (yyvsp[0].instr)->InstType = "FOREACH_STATEMENT";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr);
    }
#line 2290 "build/parser.tab.c"
    break;

  case 21: /* instruction: FOR_STATEMENT  */
#line 290 "src/parser/parser.y"
                    {
        (yyvsp[0].instr)->InstType = "FOR_STATEMENT";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr); 
    }
#line 2300 "build/parser.tab.c"
    break;

  case 22: /* instruction: BREAK  */
#line 295 "src/parser/parser.y"
            {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "BREAK";
        instP->line = (yylsp[0]).first_line;
        instP->column = (yylsp[0]).first_column;
        (yyval.instr) = instP;
    }
#line 2312 "build/parser.tab.c"
    break;

  case 23: /* instruction: CONTINUE  */
#line 302 "src/parser/parser.y"
               {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "CONTINUE";
        instP->line = (yylsp[0]).first_line;
        instP->column = (yylsp[0]).first_column;
        (yyval.instr) = instP;
    }
#line 2324 "build/parser.tab.c"
    break;

  case 24: /* instruction: RETURN expression  */
#line 309 "src/parser/parser.y"
                        {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->InstType = "RETURN";
        instP->value = (yyvsp[0].expr);
        instP->line = (yylsp[-1]).first_line;
        instP->column = (yylsp[-1]).first_column;
        (yyval.instr) = instP;
    }
#line 2337 "build/parser.tab.c"
    break;

  case 25: /* assignment: ID '=' expression  */
#line 323 "src/parser/parser.y"
                      {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-2].sval);
        instP->value = (yyvsp[0].expr);
        instP->column = (yylsp[-2]).first_column;
        (yyval.instr) = instP; }
#line 2348 "build/parser.tab.c"
    break;

  case 26: /* assignment: ID dimensions_expressions '=' expression  */
#line 330 "src/parser/parser.y"
                                               {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-3].sval);
        instP->column = (yylsp[-3]).first_column;
        instP->value = (yyvsp[0].expr);
        
        // Manejar según el número de dimensiones
        int size = ExpressionList_size((yyvsp[-2].exprList));
        if (size == 1) {
            instP->IndexVector = ExpressionList_get((yyvsp[-2].exprList), 0);
        } else if (size == 2) {
            instP->IndexVector = ExpressionList_get((yyvsp[-2].exprList), 1); // Segunda dimensión
            instP->IndexMatrix = ExpressionList_get((yyvsp[-2].exprList), 0); // Primera dimensión
        } else {
            instP->indexList = (yyvsp[-2].exprList); // Múltiples dimensiones
        }
        
        (yyval.instr) = instP; }
#line 2371 "build/parser.tab.c"
    break;

  case 27: /* assignment: assignment_expression PLUS_ASSIGN expression  */
#line 349 "src/parser/parser.y"
                                                   {
        (yyvsp[-2].instr)->value->type = "SUM";
        (yyvsp[-2].instr)->value->value = strdup("+");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2381 "build/parser.tab.c"
    break;

  case 28: /* assignment: assignment_expression MINUS_ASSIGN expression  */
#line 355 "src/parser/parser.y"
                                                    {
        (yyvsp[-2].instr)->value->type = "SUBTRACT";
        (yyvsp[-2].instr)->value->value = strdup("-");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2391 "build/parser.tab.c"
    break;

  case 29: /* assignment: assignment_expression MULT_ASSIGN expression  */
#line 361 "src/parser/parser.y"
                                                   {
        (yyvsp[-2].instr)->value->type = "MULTIPLICATION";
        (yyvsp[-2].instr)->value->value = strdup("*");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2401 "build/parser.tab.c"
    break;

  case 30: /* assignment: assignment_expression DIV_ASSIGN expression  */
#line 367 "src/parser/parser.y"
                                                  {
        (yyvsp[-2].instr)->value->type = "DIVIDE";
        (yyvsp[-2].instr)->value->value = strdup("/");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2411 "build/parser.tab.c"
    break;

  case 31: /* assignment: assignment_expression MOD_ASSIGN expression  */
#line 373 "src/parser/parser.y"
                                                  {
        (yyvsp[-2].instr)->value->type = "MODULO";
        (yyvsp[-2].instr)->value->value = strdup("%");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2421 "build/parser.tab.c"
    break;

  case 32: /* assignment: assignment_expression AND_ASSIGN expression  */
#line 379 "src/parser/parser.y"
                                                  {
        (yyvsp[-2].instr)->value->type = "BITWISE_AND";
        (yyvsp[-2].instr)->value->value = strdup("&");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2431 "build/parser.tab.c"
    break;

  case 33: /* assignment: assignment_expression OR_ASSIGN expression  */
#line 385 "src/parser/parser.y"
                                                 {
        (yyvsp[-2].instr)->value->type = "BITWISE_OR";
        (yyvsp[-2].instr)->value->value = strdup("|");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2441 "build/parser.tab.c"
    break;

  case 34: /* assignment: assignment_expression XOR_ASSIGN expression  */
#line 391 "src/parser/parser.y"
                                                  {
        (yyvsp[-2].instr)->value->type = "BITWISE_XOR";
        (yyvsp[-2].instr)->value->value = strdup("^");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2451 "build/parser.tab.c"
    break;

  case 35: /* assignment: assignment_expression LEFT_SHIFT_ASSIGN expression  */
#line 397 "src/parser/parser.y"
                                                         {
        (yyvsp[-2].instr)->value->type = "BITWISE_LEFT_SHIFT";
        (yyvsp[-2].instr)->value->value = strdup("<<");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2461 "build/parser.tab.c"
    break;

  case 36: /* assignment: assignment_expression RIGHT_SHIFT_ASSIGN expression  */
#line 403 "src/parser/parser.y"
                                                          {
        (yyvsp[-2].instr)->value->type = "BITWISE_RIGHT_SHIFT";
        (yyvsp[-2].instr)->value->value = strdup(">>");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2471 "build/parser.tab.c"
    break;

  case 37: /* assignment: assignment_expression INCREMENT  */
#line 409 "src/parser/parser.y"
                                      {
        (yyvsp[-1].instr)->value->type = "SUM";
        (yyvsp[-1].instr)->value->value = strdup("+");
        (yyvsp[-1].instr)->value->right = (Expression*)calloc(1, sizeof(Expression));
        (yyvsp[-1].instr)->value->right->type = "INTEGER";
        (yyvsp[-1].instr)->value->right->value = strdup("1");
        (yyval.instr) = (yyvsp[-1].instr); }
#line 2483 "build/parser.tab.c"
    break;

  case 38: /* assignment: assignment_expression DECREMENT  */
#line 416 "src/parser/parser.y"
                                      {
        (yyvsp[-1].instr)->value->type = "SUBTRACT";
        (yyvsp[-1].instr)->value->value = strdup("-");
        (yyvsp[-1].instr)->value->right = (Expression*)calloc(1, sizeof(Expression));
        (yyvsp[-1].instr)->value->right->type = "INTEGER";
        (yyvsp[-1].instr)->value->right->value = strdup("1");
        (yyval.instr) = (yyvsp[-1].instr); }
#line 2495 "build/parser.tab.c"
    break;

  case 39: /* assignment_expression: ID  */
#line 425 "src/parser/parser.y"
       {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[0].sval);
        instP->column = (yylsp[0]).first_column;

        instP->value = (Expression*)calloc(1, sizeof(Expression));
        instP->value->left = (Expression*)calloc(1, sizeof(Expression));
        instP->value->left->type = "ID";
        instP->value->left->value = strdup((yyvsp[0].sval));
        (yyval.instr) = instP;
        }
#line 2511 "build/parser.tab.c"
    break;

  case 40: /* assignment_expression: ID '[' expression ']'  */
#line 436 "src/parser/parser.y"
                            {
        
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-3].sval);
        instP->IndexVector = (yyvsp[-1].expr);
        instP->column = (yylsp[-3]).first_column;

        
        instP->value = (Expression*)calloc(1, sizeof(Expression));
        instP->value->left = (Expression*)calloc(1, sizeof(Expression));
        instP->value->left->type = "VECTOR_ACCESS";
        instP->value->left->value = strdup((yyvsp[-3].sval));
        instP->value->left->left = (yyvsp[-1].expr);

    

        (yyval.instr) = instP;
        }
#line 2534 "build/parser.tab.c"
    break;

  case 41: /* declaration: primitive_types ID '=' expression  */
#line 461 "src/parser/parser.y"
                                      {

        // ? Crear instrucción

        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-2].sval);
        instP->type = (yyvsp[-3].sval);
        instP->column = (yylsp[-2]).first_column;
        instP->symbolType = "VARIABLE";
        instP->value = (yyvsp[0].expr);
        (yyval.instr) = instP; }
#line 2550 "build/parser.tab.c"
    break;

  case 42: /* declaration: primitive_types ID  */
#line 473 "src/parser/parser.y"
                         {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[0].sval);
        instP->type = (yyvsp[-1].sval);
        instP->column = (yylsp[0]).first_column;
        instP->symbolType = "VARIABLE";

        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = (yyvsp[-1].sval);
        exp->value = strdup("UNDEFINED");

        instP->value = exp;
        (yyval.instr) = instP; }
#line 2568 "build/parser.tab.c"
    break;

  case 43: /* declaration: FINAL primitive_types ID '=' expression  */
#line 487 "src/parser/parser.y"
                                              {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-2].sval);
        instP->type = (yyvsp[-3].sval);
        instP->column = (yylsp[-2]).first_column;
        instP->symbolType = "CONSTANT";
        instP->value = (yyvsp[0].expr);
        (yyval.instr) = instP; }
#line 2581 "build/parser.tab.c"
    break;

  case 44: /* declaration: primitive_types '[' ']' ID '=' '{' vectorList '}'  */
#line 496 "src/parser/parser.y"
                                                        {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-4].sval);
        instP->type = (yyvsp[-7].sval);
        instP->column = (yylsp[-5]).first_column;
        instP->symbolType = "VECTOR";
        instP->vectorValues = (yyvsp[-1].VList);
        (yyval.instr) = instP; }
#line 2594 "build/parser.tab.c"
    break;

  case 45: /* declaration: primitive_types '[' ']' ID '=' NEW primitive_types '[' NUM ']'  */
#line 505 "src/parser/parser.y"
                                                                     {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-6].sval);
        instP->type = (yyvsp[-9].sval);
        instP->column = (yylsp[-7]).first_column;
        instP->symbolType = "VECTOR";
        instP->vectorValues = (VectorList*)calloc(1, sizeof(VectorList));
        for (int i = 0; i < atoi((yyvsp[-1].sval)); i++) {
            Expression* exp = (Expression*)calloc(1, sizeof(Expression));
            exp->type = (yyvsp[-3].sval);
            exp->value = strdup("UNDEFINED");
            VectorList_addExp(instP->vectorValues, exp);
        }
        (yyval.instr) = instP; }
#line 2613 "build/parser.tab.c"
    break;

  case 46: /* declaration: primitive_types '[' ']' ID '=' ID '.' ADD '(' expression ')'  */
#line 520 "src/parser/parser.y"
                                                                   {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-7].sval);
        instP->type = (yyvsp[-10].sval);
        instP->column = (yylsp[-8]).first_column;
        instP->symbolType = "VECTOR";
        instP->vectorValues = (VectorList*)calloc(1, sizeof(VectorList));
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "ADD";
        exp->value = strdup((yyvsp[-5].sval));
        exp->left = (yyvsp[-1].expr);
        VectorList_addExp(instP->vectorValues, exp);
        (yyval.instr) = instP; }
#line 2631 "build/parser.tab.c"
    break;

  case 47: /* declaration: primitive_types '[' ']' '[' ']' ID '=' '{' optional_newlines matrixList '}'  */
#line 534 "src/parser/parser.y"
                                                                               {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-5].sval);
        instP->type = (yyvsp[-10].sval);
        instP->column = (yylsp[-6]).first_column;
        instP->symbolType = "MATRIX";
        instP->matrixValues = (yyvsp[-1].MList);
        (yyval.instr) = instP;
    }
#line 2645 "build/parser.tab.c"
    break;

  case 48: /* declaration: primitive_types '[' ']' '[' ']' ID '=' NEW primitive_types '[' NUM ']' '[' NUM ']'  */
#line 544 "src/parser/parser.y"
                                                                                       {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-9].sval);
        instP->type = (yyvsp[-14].sval);
        instP->column = (yylsp[-10]).first_column;
        instP->symbolType = "MATRIX";
        instP->matrixValues = (MatrixList*)calloc(1, sizeof(MatrixList));
        for (int i = 0; i < atoi((yyvsp[-4].sval)); i++) {
            VectorList* vecList = (VectorList*)calloc(1, sizeof(VectorList));
            for (int j = 0; j < atoi((yyvsp[-1].sval)); j++) {
                Expression* exp = (Expression*)calloc(1, sizeof(Expression));
                exp->type = (yyvsp[-6].sval);
                exp->value = strdup("UNDEFINED");
                VectorList_addExp(vecList, exp);
            }
            MatrixList_add(instP->matrixValues, vecList);
            }
        (yyval.instr) = instP; }
#line 2668 "build/parser.tab.c"
    break;

  case 49: /* declaration: primitive_types ID '(' paramsList ')' '{' BREAK_LINE sentences '}'  */
#line 563 "src/parser/parser.y"
                                                                         {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-7].sval);
        instP->type = (yyvsp[-8].sval);
        instP->column = (yylsp[-7]).first_column;
        instP->symbolType = "FUNCTION";
        instP->functionData = (Function*)calloc(1, sizeof(Function));
        instP->functionData->parameters = (yyvsp[-5].paramlist);
        instP->functionData->body = (yyvsp[-1].instrList);
        (yyval.instr) = instP; }
#line 2683 "build/parser.tab.c"
    break;

  case 50: /* declaration: VOID ID '(' ')' '{' BREAK_LINE sentences '}'  */
#line 574 "src/parser/parser.y"
                                                   {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-6].sval);
        instP->column = (yylsp[-6]).first_column;
        instP->symbolType = "VOID";
        instP->functionData = (Function*)calloc(1, sizeof(Function));
        instP->functionData->body = (yyvsp[-1].instrList);
        (yyval.instr) = instP; }
#line 2696 "build/parser.tab.c"
    break;

  case 51: /* declaration: primitive_types ID dimensions '=' dimension_expression  */
#line 583 "src/parser/parser.y"
                                                             {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-3].sval);
        instP->type = (yyvsp[-4].sval);
        instP->arrayValues = (SymbolList*)calloc(1, sizeof(SymbolList));
        instP->arrayValues->dimension = (yyvsp[-2].ival);
        instP->arrayValues->values = (yyvsp[0].list);
        instP->column = (yylsp[-2]).first_column;
        instP->symbolType = "LIST";
        (yyval.instr) = instP; }
#line 2711 "build/parser.tab.c"
    break;

  case 52: /* declaration: primitive_types ID dimensions '=' NEW primitive_types dimensions_value_list  */
#line 593 "src/parser/parser.y"
                                                                                  {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-5].sval);
        instP->type = (yyvsp[-6].sval);
        instP->arrayValues = (SymbolList*)calloc(1, sizeof(SymbolList));
        instP->arrayValues->dimension = (yyvsp[-4].ival);
        
        // Usar la función multidimensional para crear la estructura
        instP->arrayValues->values = create_multidimensional_array((yyvsp[0].dimlist)->dimensions, (yyvsp[0].dimlist)->count, (yyvsp[-1].sval));
        
        // Liberar la estructura temporal
        free((yyvsp[0].dimlist)->dimensions);
        free((yyvsp[0].dimlist));
        
        instP->column = (yylsp[-4]).first_column;
        instP->symbolType = "LIST";
        (yyval.instr) = instP; 
    }
#line 2734 "build/parser.tab.c"
    break;

  case 53: /* primitive_types: INT  */
#line 615 "src/parser/parser.y"
        { (yyval.sval) = strdup("INTEGER"); }
#line 2740 "build/parser.tab.c"
    break;

  case 54: /* primitive_types: STRING  */
#line 616 "src/parser/parser.y"
             { (yyval.sval) = strdup("STRING"); }
#line 2746 "build/parser.tab.c"
    break;

  case 55: /* primitive_types: DOUBLE  */
#line 617 "src/parser/parser.y"
             { (yyval.sval) = strdup("DOUBLE"); }
#line 2752 "build/parser.tab.c"
    break;

  case 56: /* primitive_types: FLOAT  */
#line 618 "src/parser/parser.y"
            { (yyval.sval) = strdup("FLOAT"); }
#line 2758 "build/parser.tab.c"
    break;

  case 57: /* primitive_types: BOOL  */
#line 619 "src/parser/parser.y"
           { (yyval.sval) = strdup("BOOLEAN"); }
#line 2764 "build/parser.tab.c"
    break;

  case 58: /* primitive_types: CHAR  */
#line 620 "src/parser/parser.y"
           { (yyval.sval) = strdup("CHARACTER"); }
#line 2770 "build/parser.tab.c"
    break;

  case 59: /* primitive_values: NUM  */
#line 625 "src/parser/parser.y"
        { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("INTEGER");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2781 "build/parser.tab.c"
    break;

  case 60: /* primitive_values: STR  */
#line 631 "src/parser/parser.y"
          { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("STRING");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2792 "build/parser.tab.c"
    break;

  case 61: /* primitive_values: DEC  */
#line 637 "src/parser/parser.y"
          { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("DOUBLE");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2803 "build/parser.tab.c"
    break;

  case 62: /* primitive_values: DECF  */
#line 643 "src/parser/parser.y"
           { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("FLOAT");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2814 "build/parser.tab.c"
    break;

  case 63: /* primitive_values: BOOLEAN  */
#line 649 "src/parser/parser.y"
              { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("BOOLEAN");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2825 "build/parser.tab.c"
    break;

  case 64: /* primitive_values: CHR  */
#line 655 "src/parser/parser.y"
          { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("CHARACTER");
        exp->value = strdup((yyvsp[0].sval));
        (yyval.expr) = exp; }
#line 2835 "build/parser.tab.c"
    break;

  case 65: /* primitive_values: NULL_EXP  */
#line 660 "src/parser/parser.y"
               { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("NULL");
        exp->value = strdup("null");
        (yyval.expr) = exp; }
#line 2845 "build/parser.tab.c"
    break;

  case 66: /* expression: primitive_values  */
#line 670 "src/parser/parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 2851 "build/parser.tab.c"
    break;

  case 67: /* expression: ID  */
#line 671 "src/parser/parser.y"
         {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "ID";
        exp->value = strdup((yyvsp[0].sval));
        (yyval.expr) = exp;
        }
#line 2862 "build/parser.tab.c"
    break;

  case 68: /* expression: '-' expression  */
#line 677 "src/parser/parser.y"
                               {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "NEGATIVE";
        exp->value = strdup("-");
        exp->left = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2873 "build/parser.tab.c"
    break;

  case 69: /* expression: expression '+' expression  */
#line 683 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "SUM";
        exp->value = strdup("+");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2885 "build/parser.tab.c"
    break;

  case 70: /* expression: expression '-' expression  */
#line 690 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "SUBTRACT";
        exp->value = strdup("-");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2897 "build/parser.tab.c"
    break;

  case 71: /* expression: expression '*' expression  */
#line 697 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "MULTIPLICATION";
        exp->value = strdup("*");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2909 "build/parser.tab.c"
    break;

  case 72: /* expression: expression '/' expression  */
#line 704 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "DIVIDE";
        exp->value = strdup("/");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2921 "build/parser.tab.c"
    break;

  case 73: /* expression: expression '%' expression  */
#line 711 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "MODULO";
        exp->value = strdup("%");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2933 "build/parser.tab.c"
    break;

  case 74: /* expression: '(' expression ')'  */
#line 718 "src/parser/parser.y"
                         { (yyval.expr) = (yyvsp[-1].expr); }
#line 2939 "build/parser.tab.c"
    break;

  case 75: /* expression: '(' primitive_types ')' expression  */
#line 719 "src/parser/parser.y"
                                         {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "CASTING";
        exp->value = (yyvsp[-2].sval);
        exp->left = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2950 "build/parser.tab.c"
    break;

  case 76: /* expression: expression '&' expression  */
#line 726 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_AND";
        exp->value = strdup("&");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2962 "build/parser.tab.c"
    break;

  case 77: /* expression: expression '|' expression  */
#line 733 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_OR";
        exp->value = strdup("|");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2974 "build/parser.tab.c"
    break;

  case 78: /* expression: expression '^' expression  */
#line 740 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_XOR";
        exp->value = strdup("^");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2986 "build/parser.tab.c"
    break;

  case 79: /* expression: expression LEFT_SHIFT expression  */
#line 748 "src/parser/parser.y"
                                       {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_LEFT_SHIFT";
        exp->value = strdup("<<");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2998 "build/parser.tab.c"
    break;

  case 80: /* expression: expression RIGHT_SHIFT expression  */
#line 757 "src/parser/parser.y"
                                        {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_RIGHT_SHIFT";
        exp->value = strdup(">>");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3010 "build/parser.tab.c"
    break;

  case 81: /* expression: ID EQUALS_OP '(' expression ')'  */
#line 765 "src/parser/parser.y"
                                      {
        Expression *exp = (Expression*)calloc(1, sizeof(Expression));   
        exp->type = "EQUALS_OP";
        exp->value = strdup(".equals");
        exp->left = (Expression*)calloc(1, sizeof(Expression));
        exp->left->type = "ID";
        exp->left->value = strdup((yyvsp[-4].sval));
        exp->right = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3024 "build/parser.tab.c"
    break;

  case 82: /* expression: expression EQUALS expression  */
#line 775 "src/parser/parser.y"
                                   {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "EQUALS";
        exp->value = strdup("==");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3036 "build/parser.tab.c"
    break;

  case 83: /* expression: expression NOT_EQUALS expression  */
#line 783 "src/parser/parser.y"
                                       {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "NOT_EQUALS";
        exp->value = strdup("!=");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3048 "build/parser.tab.c"
    break;

  case 84: /* expression: expression '>' expression  */
#line 791 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "GREATER";
        exp->value = strdup(">");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3060 "build/parser.tab.c"
    break;

  case 85: /* expression: expression '<' expression  */
#line 799 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LESS";
        exp->value = strdup("<");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3072 "build/parser.tab.c"
    break;

  case 86: /* expression: expression GREATER_EQUALS expression  */
#line 807 "src/parser/parser.y"
                                           {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "GREATER_EQUALS";
        exp->value = strdup(">=");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3084 "build/parser.tab.c"
    break;

  case 87: /* expression: expression LESS_EQUALS expression  */
#line 815 "src/parser/parser.y"
                                        {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LESS_EQUALS";
        exp->value = strdup("<=");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3096 "build/parser.tab.c"
    break;

  case 88: /* expression: expression AND expression  */
#line 823 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_AND";
        exp->value = strdup("&&");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3108 "build/parser.tab.c"
    break;

  case 89: /* expression: expression OR expression  */
#line 831 "src/parser/parser.y"
                               {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_OR";
        exp->value = strdup("||");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3120 "build/parser.tab.c"
    break;

  case 90: /* expression: NOT expression  */
#line 839 "src/parser/parser.y"
                     {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_NOT";
        exp->value = strdup("!");
        exp->left = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3131 "build/parser.tab.c"
    break;

  case 91: /* expression: INTEGER_OBJ '.' PARSEINT '(' expression ')'  */
#line 846 "src/parser/parser.y"
                                                  {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEINT";
        exp->value = strdup("Integer.parseInt");
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3142 "build/parser.tab.c"
    break;

  case 92: /* expression: DOUBLE_OBJ '.' PARSEDOUBLE '(' expression ')'  */
#line 853 "src/parser/parser.y"
                                                    {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEDOUBLE";
        exp->value = strdup("Double.parseDouble");
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3153 "build/parser.tab.c"
    break;

  case 93: /* expression: FLOAT_OBJ '.' PARSEFLOAT '(' expression ')'  */
#line 860 "src/parser/parser.y"
                                                  {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEFLOAT";
        exp->value = strdup("Float.parseFloat");
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3164 "build/parser.tab.c"
    break;

  case 94: /* expression: STRING '.' VALUEOF '(' expression ')'  */
#line 867 "src/parser/parser.y"
                                            {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "VALUEOF";
        exp->value = strdup("String.valueOf");
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3175 "build/parser.tab.c"
    break;

  case 95: /* expression: STRING '.' JOIN '(' exprList ')'  */
#line 874 "src/parser/parser.y"
                                       {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "JOIN";
        exp->value = strdup("String.join");
        exp->list = (yyvsp[-1].exprList);
        (yyval.expr) = exp; }
#line 3186 "build/parser.tab.c"
    break;

  case 96: /* expression: ARRAYS '.' INDEXOF '(' ID ',' expression ')'  */
#line 881 "src/parser/parser.y"
                                                   {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "INDEXOF";
        exp->value = (yyvsp[-3].sval);
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3197 "build/parser.tab.c"
    break;

  case 97: /* expression: ID '.' LENGTH  */
#line 888 "src/parser/parser.y"
                    {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LENGTH";
        exp->value = strdup((yyvsp[-2].sval));
        (yyval.expr) = exp; }
#line 3207 "build/parser.tab.c"
    break;

  case 98: /* expression: ID '.' ADD '(' expression ')'  */
#line 894 "src/parser/parser.y"
                                    {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "ADD";
        exp->value = strdup((yyvsp[-5].sval));
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3218 "build/parser.tab.c"
    break;

  case 99: /* expression: ID dimensions_expressions  */
#line 901 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        
        // Determinar el tipo según el número de dimensiones
        int size = ExpressionList_size((yyvsp[0].exprList));
        if (size == 1) {
            exp->type = "VECTOR_ACCESS";
            exp->left = ExpressionList_get((yyvsp[0].exprList), 0); // Primera dimensión
        } else if (size == 2) {
            exp->type = "MATRIX_ACCESS";
            exp->left = ExpressionList_get((yyvsp[0].exprList), 0);  // Primera dimensión
            exp->right = ExpressionList_get((yyvsp[0].exprList), 1); // Segunda dimensión
        } else {
            exp->type = "ARRAY_ACCESS";
            exp->list = (yyvsp[0].exprList); // Múltiples dimensiones
        }
        
        exp->value = (yyvsp[-1].sval);
        (yyval.expr) = exp;
    }
#line 3243 "build/parser.tab.c"
    break;

  case 100: /* expression: ID '(' exprList ')'  */
#line 922 "src/parser/parser.y"
                          {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "FUNCTION_CALL";
        exp->value = strdup((yyvsp[-3].sval));
        exp->list = (yyvsp[-1].exprList);
        (yyval.expr) = exp;
    }
#line 3255 "build/parser.tab.c"
    break;

  case 101: /* exprList: %empty  */
#line 931 "src/parser/parser.y"
                { 
        ExpressionList* exprList = create_expression_list();
        (yyval.exprList) = exprList;
    }
#line 3264 "build/parser.tab.c"
    break;

  case 102: /* exprList: expression  */
#line 935 "src/parser/parser.y"
                 {
        ExpressionList* exprList = create_expression_list();
        ExpressionList_add(exprList, (yyvsp[0].expr));
        (yyval.exprList) = exprList;
     }
#line 3274 "build/parser.tab.c"
    break;

  case 103: /* exprList: exprList ',' expression  */
#line 940 "src/parser/parser.y"
                              {
        ExpressionList_add((yyvsp[-2].exprList), (yyvsp[0].expr));
        (yyval.exprList) = (yyvsp[-2].exprList);
     }
#line 3283 "build/parser.tab.c"
    break;

  case 104: /* IF_STATEMENT: IF '(' expression ')' '{' BREAK_LINE sentences '}' IF_LIST ELSE_STATEMENT  */
#line 950 "src/parser/parser.y"
                                                                                 {
        IfData* ifdata = (IfData*)calloc(1, sizeof(IfData));
        ifdata->condition = (yyvsp[-7].expr);
        ifdata->block = (yyvsp[-3].instrList);
        ifdata->elseIfs = (yyvsp[-1].ifnodelist);
        ifdata->elseBlock = (yyvsp[0].instrList);
        (yyval.ifdata) = ifdata;
    }
#line 3296 "build/parser.tab.c"
    break;

  case 105: /* IF_LIST: %empty  */
#line 960 "src/parser/parser.y"
                { (yyval.ifnodelist) = createIfNodeList(); }
#line 3302 "build/parser.tab.c"
    break;

  case 106: /* IF_LIST: IF_LIST ELSE IF '(' expression ')' '{' BREAK_LINE sentences '}'  */
#line 961 "src/parser/parser.y"
                                                                        {
        IfData* elseIfNode = (IfData*)malloc(sizeof(IfData));
        elseIfNode->condition = (yyvsp[-5].expr);
        elseIfNode->block = (yyvsp[-1].instrList);
        insertIfNode((yyvsp[-9].ifnodelist), elseIfNode);
        (yyval.ifnodelist) = (yyvsp[-9].ifnodelist);
    }
#line 3314 "build/parser.tab.c"
    break;

  case 107: /* ELSE_STATEMENT: %empty  */
#line 970 "src/parser/parser.y"
                { (yyval.instrList) = NULL; }
#line 3320 "build/parser.tab.c"
    break;

  case 108: /* ELSE_STATEMENT: ELSE '{' BREAK_LINE sentences '}'  */
#line 971 "src/parser/parser.y"
                                        { (yyval.instrList) = (yyvsp[-1].instrList); }
#line 3326 "build/parser.tab.c"
    break;

  case 109: /* SWITCH_STATEMENT: SWITCH '(' ID ')' '{' BREAK_LINE CASES DEFAULT_CASE '}'  */
#line 975 "src/parser/parser.y"
                                                            {
        SwitchData* switchdata = (SwitchData*)malloc(sizeof(SwitchData));
        switchdata->condition = strdup((yyvsp[-6].sval));
        switchdata->cases = (yyvsp[-2].casenodelist);
        switchdata->defaultCase = (yyvsp[-1].instrList);
        (yyval.switchdata) = switchdata;
    }
#line 3338 "build/parser.tab.c"
    break;

  case 110: /* CASES: %empty  */
#line 986 "src/parser/parser.y"
                { (yyval.casenodelist) = CaseNodeList_create(); }
#line 3344 "build/parser.tab.c"
    break;

  case 111: /* CASES: CASES CASE primitive_values ':' BREAK_LINE sentences BREAK ';' BREAK_LINE  */
#line 987 "src/parser/parser.y"
                                                                                {
        CaseData* new_case = (CaseData*)malloc(sizeof(CaseData));
        new_case->condition = (yyvsp[-6].expr);
        new_case->block = (yyvsp[-3].instrList);
        CaseNodeList_add((yyvsp[-8].casenodelist), new_case);
        (yyval.casenodelist) = (yyvsp[-8].casenodelist);
    }
#line 3356 "build/parser.tab.c"
    break;

  case 112: /* DEFAULT_CASE: %empty  */
#line 997 "src/parser/parser.y"
                { (yyval.instrList) = NULL; }
#line 3362 "build/parser.tab.c"
    break;

  case 113: /* DEFAULT_CASE: DEFAULT ':' BREAK_LINE sentences  */
#line 998 "src/parser/parser.y"
                                       { (yyval.instrList) = (yyvsp[0].instrList); }
#line 3368 "build/parser.tab.c"
    break;

  case 114: /* WHILE_STATEMENT: WHILE '(' expression ')' '{' BREAK_LINE sentences '}'  */
#line 1006 "src/parser/parser.y"
                                                          {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->whileData = (WhileData*)malloc(sizeof(WhileData));
        instP->whileData->condition = (yyvsp[-5].expr);
        instP->whileData->block = (yyvsp[-1].instrList);
        instP->column = (yylsp[-7]).first_column;
        (yyval.instr) = instP;
    }
#line 3381 "build/parser.tab.c"
    break;

  case 115: /* FOR_STATEMENT: FOR '(' declaration ';' expression ';' instruction ')' '{' BREAK_LINE sentences '}'  */
#line 1018 "src/parser/parser.y"
                                                                                        {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->forData = (ForData*)malloc(sizeof(ForData));
        instP->forData->init = (yyvsp[-9].instr);
        instP->forData->init->InstType = "DECLARATION";
        instP->forData->init->line = (yylsp[-11]).first_line;
        instP->forData->condition = (yyvsp[-7].expr);

        instP->forData->update = (yyvsp[-5].instr);
        instP->forData->block = (yyvsp[-1].instrList);
        instP->column = (yylsp[-11]).first_column;
        (yyval.instr) = instP;
    }
#line 3399 "build/parser.tab.c"
    break;

  case 116: /* FOREACH_STATEMENT: FOR '(' primitive_types ID ':' ID ')' '{' BREAK_LINE sentences '}'  */
#line 1033 "src/parser/parser.y"
                                                                       {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->forEachData = (ForEachData*)malloc(sizeof(ForEachData));
        instP->forEachData->type = (yyvsp[-8].sval);
        instP->forEachData->item = (yyvsp[-7].sval);
        instP->forEachData->array = (yyvsp[-5].sval);
        instP->forEachData->block = (yyvsp[-1].instrList);
        instP->column = (yylsp[-10]).first_column;
        (yyval.instr) = instP;
    }
#line 3414 "build/parser.tab.c"
    break;

  case 117: /* dimensions: %empty  */
#line 1046 "src/parser/parser.y"
                  { (yyval.ival) = 0; }
#line 3420 "build/parser.tab.c"
    break;

  case 118: /* dimensions: dimensions '[' ']'  */
#line 1047 "src/parser/parser.y"
                         { (yyval.ival) = (yyvsp[-2].ival) + 1; }
#line 3426 "build/parser.tab.c"
    break;

  case 119: /* dimensions_value_list: '[' NUM ']'  */
#line 1050 "src/parser/parser.y"
                  { 
        DimensionsList* dimList = (DimensionsList*)malloc(sizeof(DimensionsList));
        dimList->dimensions = (int*)malloc(sizeof(int));
        dimList->dimensions[0] = atoi((yyvsp[-1].sval));
        dimList->count = 1;
        (yyval.dimlist) = dimList;
    }
#line 3438 "build/parser.tab.c"
    break;

  case 120: /* dimensions_value_list: dimensions_value_list '[' NUM ']'  */
#line 1057 "src/parser/parser.y"
                                        { 
        (yyvsp[-3].dimlist)->dimensions = (int*)realloc((yyvsp[-3].dimlist)->dimensions, sizeof(int) * ((yyvsp[-3].dimlist)->count + 1));
        (yyvsp[-3].dimlist)->dimensions[(yyvsp[-3].dimlist)->count] = atoi((yyvsp[-1].sval));
        (yyvsp[-3].dimlist)->count += 1;
        (yyval.dimlist) = (yyvsp[-3].dimlist);
    }
#line 3449 "build/parser.tab.c"
    break;

  case 121: /* dimensions_expressions: '[' expression ']'  */
#line 1065 "src/parser/parser.y"
                       { 
        ExpressionList* exprList = create_expression_list();
        ExpressionList_add(exprList, (yyvsp[-1].expr));
        (yyval.exprList) = exprList;
    }
#line 3459 "build/parser.tab.c"
    break;

  case 122: /* dimensions_expressions: dimensions_expressions '[' expression ']'  */
#line 1070 "src/parser/parser.y"
                                                {
        ExpressionList_add((yyvsp[-3].exprList), (yyvsp[-1].expr));
        (yyval.exprList) = (yyvsp[-3].exprList);
     }
#line 3468 "build/parser.tab.c"
    break;

  case 123: /* vectorList: %empty  */
#line 1077 "src/parser/parser.y"
                  { 
        VectorList* vecList = VectorList_create();
        (yyval.VList) = vecList;
    }
#line 3477 "build/parser.tab.c"
    break;

  case 124: /* vectorList: expression  */
#line 1081 "src/parser/parser.y"
                 {
        VectorList* vecList = VectorList_create();
        VectorList_addExp(vecList, (yyvsp[0].expr));
        (yyval.VList) = vecList;
     }
#line 3487 "build/parser.tab.c"
    break;

  case 125: /* vectorList: vectorList ',' expression  */
#line 1086 "src/parser/parser.y"
                                {
        VectorList_addExp((yyvsp[-2].VList), (yyvsp[0].expr));
        (yyval.VList) = (yyvsp[-2].VList);
     }
#line 3496 "build/parser.tab.c"
    break;

  case 126: /* matrixList: %empty  */
#line 1094 "src/parser/parser.y"
                  { 
        MatrixList* matList = MatrixList_create();
        (yyval.MList) = matList;
    }
#line 3505 "build/parser.tab.c"
    break;

  case 127: /* matrixList: '{' vectorList '}' optional_newlines  */
#line 1098 "src/parser/parser.y"
                                          {
        MatrixList* matList = MatrixList_create();
        MatrixList_add(matList, (yyvsp[-2].VList));
        (yyval.MList) = matList;
     }
#line 3515 "build/parser.tab.c"
    break;

  case 128: /* matrixList: matrixList ',' optional_newlines '{' vectorList '}' optional_newlines  */
#line 1103 "src/parser/parser.y"
                                                                             {
        MatrixList_add((yyvsp[-6].MList), (yyvsp[-2].VList));
        (yyval.MList) = (yyvsp[-6].MList);
     }
#line 3524 "build/parser.tab.c"
    break;

  case 129: /* dimension_expression: '{' optional_newlines dimension_values_list optional_newlines '}'  */
#line 1109 "src/parser/parser.y"
                                                                      {(yyval.list) = (yyvsp[-2].list); }
#line 3530 "build/parser.tab.c"
    break;

  case 130: /* dimension_values_list: %empty  */
#line 1112 "src/parser/parser.y"
                  {  (yyval.list) = List_create(); }
#line 3536 "build/parser.tab.c"
    break;

  case 131: /* dimension_values_list: dimension_value optional_newlines  */
#line 1113 "src/parser/parser.y"
                                        { 
        List* list = List_create(); 
        List_add(list, (yyvsp[-1].listdata)); 
        (yyval.list) = list; 
    }
#line 3546 "build/parser.tab.c"
    break;

  case 132: /* dimension_values_list: dimension_values_list ',' optional_newlines dimension_value optional_newlines  */
#line 1118 "src/parser/parser.y"
                                                                                    {List_add((yyvsp[-4].list), (yyvsp[-1].listdata)); (yyval.list) = (yyvsp[-4].list);}
#line 3552 "build/parser.tab.c"
    break;

  case 133: /* dimension_value: expression  */
#line 1121 "src/parser/parser.y"
               { ListData* data = (ListData*)calloc(1, sizeof(ListData));
                  data->exprData = (yyvsp[0].expr);
                  (yyval.listdata) = data; }
#line 3560 "build/parser.tab.c"
    break;

  case 134: /* dimension_value: dimension_expression  */
#line 1124 "src/parser/parser.y"
                           {
        ListData* data = (ListData*)calloc(1, sizeof(ListData));
        data->listData = (yyvsp[0].list);
        (yyval.listdata) = data;
    }
#line 3570 "build/parser.tab.c"
    break;

  case 137: /* paramsList: %empty  */
#line 1139 "src/parser/parser.y"
                { (yyval.paramlist) = createParamsList(); }
#line 3576 "build/parser.tab.c"
    break;

  case 138: /* paramsList: primitive_types ID  */
#line 1140 "src/parser/parser.y"
                         {
        paramsList* paramList = createParamsList();
        addParam(paramList, (yyvsp[-1].sval), (yyvsp[0].sval));
        (yyval.paramlist) = paramList;
     }
#line 3586 "build/parser.tab.c"
    break;

  case 139: /* paramsList: primitive_types '[' ']' ID  */
#line 1145 "src/parser/parser.y"
                                 {
        paramsList* paramList = createParamsList();
        // Puedes usar un tipo especial, por ejemplo: "VECTOR_INTEGER"
        char* vectorType = (char*)malloc(strlen((yyvsp[-3].sval)) + 8);
        sprintf(vectorType, "VECTOR_%s", (yyvsp[-3].sval));
        addParam(paramList, vectorType, (yyvsp[0].sval));
        (yyval.paramlist) = paramList;
     }
#line 3599 "build/parser.tab.c"
    break;

  case 140: /* paramsList: paramsList ',' primitive_types ID  */
#line 1153 "src/parser/parser.y"
                                        {
        addParam((yyvsp[-3].paramlist), (yyvsp[-1].sval), (yyvsp[0].sval));
        (yyval.paramlist) = (yyvsp[-3].paramlist);
     }
#line 3608 "build/parser.tab.c"
    break;

  case 141: /* paramsList: paramsList ',' primitive_types '[' ']' ID  */
#line 1157 "src/parser/parser.y"
                                                {
        char* vectorType = (char*)malloc(strlen((yyvsp[-3].sval)) + 8);
        sprintf(vectorType, "VECTOR_%s", (yyvsp[-3].sval));
        addParam((yyvsp[-5].paramlist), vectorType, (yyvsp[0].sval));
        (yyval.paramlist) = (yyvsp[-5].paramlist);
     }
#line 3619 "build/parser.tab.c"
    break;


#line 3623 "build/parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1164 "src/parser/parser.y"


// Función para reinicializar el estado del parser
void reset_parser_state() {
    // Reinicializar solo las variables básicas del lexer
    extern int yylineno;
    extern int yycolumn; 
    yylineno = 1;
    yycolumn = 1;
}

int yyerror(const char *s)
{
    extern YYLTYPE yylloc;
    
    // Crear mensaje de error más detallado
    char detailed_message[512];
    snprintf(detailed_message, sizeof(detailed_message), 
             "%s en línea %d, columna %d", s, yylloc.first_line, yylloc.first_column);
    
    printf("Syntax Error: %s\n", detailed_message);
    
    // Verificar que list_errors esté inicializada
    if (list_errors == NULL) {
        list_errors = createErrorList();
    }
    
    Error *error = malloc(sizeof(Error));
    error->type = strdup("Sintáctico");
    error->environment = strdup("Global");
    error->message = strdup(detailed_message);
    error->line = yylloc.first_line;
    error->column = yylloc.first_column;
    
    insertError(list_errors, error);
    
    // Limpiar el estado del parser para mejor recuperación
    extern int yychar;
    yychar = YYEMPTY;
    
    // Continuar con el análisis (no abortar)
    return 0;
}

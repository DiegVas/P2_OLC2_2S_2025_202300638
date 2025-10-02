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
  YYSYMBOL_ARRAYS = 65,                    /* ARRAYS  */
  YYSYMBOL_INDEXOF = 66,                   /* INDEXOF  */
  YYSYMBOL_LENGTH = 67,                    /* LENGTH  */
  YYSYMBOL_ADD = 68,                       /* ADD  */
  YYSYMBOL_69_ = 69,                       /* '='  */
  YYSYMBOL_70_ = 70,                       /* '|'  */
  YYSYMBOL_71_ = 71,                       /* '^'  */
  YYSYMBOL_72_ = 72,                       /* '&'  */
  YYSYMBOL_73_ = 73,                       /* '<'  */
  YYSYMBOL_74_ = 74,                       /* '>'  */
  YYSYMBOL_75_ = 75,                       /* '+'  */
  YYSYMBOL_76_ = 76,                       /* '-'  */
  YYSYMBOL_77_ = 77,                       /* '*'  */
  YYSYMBOL_78_ = 78,                       /* '/'  */
  YYSYMBOL_79_ = 79,                       /* '%'  */
  YYSYMBOL_UMINUS = 80,                    /* UMINUS  */
  YYSYMBOL_81_ = 81,                       /* '['  */
  YYSYMBOL_82_ = 82,                       /* ']'  */
  YYSYMBOL_83_ = 83,                       /* '('  */
  YYSYMBOL_84_ = 84,                       /* ')'  */
  YYSYMBOL_85_ = 85,                       /* '{'  */
  YYSYMBOL_86_ = 86,                       /* '}'  */
  YYSYMBOL_87_ = 87,                       /* ';'  */
  YYSYMBOL_88_ = 88,                       /* '.'  */
  YYSYMBOL_89_ = 89,                       /* ','  */
  YYSYMBOL_90_ = 90,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_program = 92,                   /* program  */
  YYSYMBOL_sentences = 93,                 /* sentences  */
  YYSYMBOL_sentence = 94,                  /* sentence  */
  YYSYMBOL_separator = 95,                 /* separator  */
  YYSYMBOL_instruction = 96,               /* instruction  */
  YYSYMBOL_assignment = 97,                /* assignment  */
  YYSYMBOL_assignment_expression = 98,     /* assignment_expression  */
  YYSYMBOL_declaration = 99,               /* declaration  */
  YYSYMBOL_primitive_types = 100,          /* primitive_types  */
  YYSYMBOL_primitive_values = 101,         /* primitive_values  */
  YYSYMBOL_expression = 102,               /* expression  */
  YYSYMBOL_exprList = 103,                 /* exprList  */
  YYSYMBOL_IF_STATEMENT = 104,             /* IF_STATEMENT  */
  YYSYMBOL_IF_LIST = 105,                  /* IF_LIST  */
  YYSYMBOL_ELSE_STATEMENT = 106,           /* ELSE_STATEMENT  */
  YYSYMBOL_SWITCH_STATEMENT = 107,         /* SWITCH_STATEMENT  */
  YYSYMBOL_CASES = 108,                    /* CASES  */
  YYSYMBOL_DEFAULT_CASE = 109,             /* DEFAULT_CASE  */
  YYSYMBOL_WHILE_STATEMENT = 110,          /* WHILE_STATEMENT  */
  YYSYMBOL_FOR_STATEMENT = 111,            /* FOR_STATEMENT  */
  YYSYMBOL_FOREACH_STATEMENT = 112,        /* FOREACH_STATEMENT  */
  YYSYMBOL_dimensions = 113,               /* dimensions  */
  YYSYMBOL_dimensions_value_list = 114,    /* dimensions_value_list  */
  YYSYMBOL_dimensions_expressions = 115,   /* dimensions_expressions  */
  YYSYMBOL_vectorList = 116,               /* vectorList  */
  YYSYMBOL_matrixList = 117,               /* matrixList  */
  YYSYMBOL_dimension_expression = 118,     /* dimension_expression  */
  YYSYMBOL_dimension_values_list = 119,    /* dimension_values_list  */
  YYSYMBOL_dimension_value = 120,          /* dimension_value  */
  YYSYMBOL_optional_newlines = 121,        /* optional_newlines  */
  YYSYMBOL_paramsList = 122                /* paramsList  */
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
#define YYLAST   1510

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  378

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
       2,     2,     2,     2,     2,     2,     2,    79,    72,     2,
      83,    84,    77,    75,    89,    76,    88,    78,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    90,    87,
      73,    69,    74,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    82,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,    70,    86,     2,     2,     2,     2,
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
      65,    66,    67,    68,    80
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   162,   187,   197,   202,   205,   208,   215,
     216,   220,   228,   237,   242,   249,   259,   264,   272,   280,
     285,   290,   295,   302,   309,   323,   330,   349,   355,   361,
     367,   373,   379,   385,   391,   397,   403,   409,   418,   429,
     454,   466,   480,   489,   498,   513,   527,   537,   556,   567,
     576,   586,   608,   609,   610,   611,   612,   613,   618,   624,
     630,   636,   642,   648,   653,   663,   664,   670,   676,   683,
     690,   697,   704,   711,   712,   719,   726,   733,   741,   750,
     758,   768,   776,   784,   792,   800,   808,   816,   824,   832,
     839,   846,   853,   860,   867,   874,   881,   887,   894,   915,
     924,   928,   933,   943,   953,   954,   963,   964,   968,   979,
     980,   990,   991,   999,  1011,  1039,  1052,  1053,  1056,  1063,
    1071,  1076,  1083,  1087,  1092,  1100,  1104,  1109,  1115,  1118,
    1119,  1124,  1127,  1130,  1137,  1138,  1145,  1146,  1151,  1159,
    1163
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
  "INCREMENT", "ARRAYS", "INDEXOF", "LENGTH", "ADD", "'='", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "'['",
  "']'", "'('", "')'", "'{'", "'}'", "';'", "'.'", "','", "':'", "$accept",
  "program", "sentences", "sentence", "separator", "instruction",
  "assignment", "assignment_expression", "declaration", "primitive_types",
  "primitive_values", "expression", "exprList", "IF_STATEMENT", "IF_LIST",
  "ELSE_STATEMENT", "SWITCH_STATEMENT", "CASES", "DEFAULT_CASE",
  "WHILE_STATEMENT", "FOR_STATEMENT", "FOREACH_STATEMENT", "dimensions",
  "dimensions_value_list", "dimensions_expressions", "vectorList",
  "matrixList", "dimension_expression", "dimension_values_list",
  "dimension_value", "optional_newlines", "paramsList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-334)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -334,    16,   250,  -334,   -10,   -34,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,   160,   -60,   -33,    31,  -334,  -334,    35,
      50,   867,   117,    92,  -334,  -334,  -334,  -334,   -10,  -334,
     424,  -334,    -3,  -334,  -334,  -334,  -334,  -334,  -334,   867,
     867,    63,   -30,   133,   798,   867,   143,   867,   377,  -334,
    -334,  -334,   -18,  -334,  -334,  -334,    67,  -334,    72,    74,
      78,   867,    79,   867,   832,  -334,  1293,    95,   138,   328,
    -334,   867,   867,   867,   867,   867,   867,   867,   867,   867,
     867,  -334,     5,    99,  1293,  1188,  -334,   867,   867,   114,
    -334,   889,   912,   101,   935,   109,     0,   123,   867,   867,
     -27,   116,   126,   175,   176,   173,  -334,   146,   -45,    67,
     130,   958,   867,   867,   867,   867,   867,   867,   867,   867,
     867,   867,   867,   867,   867,   867,   867,   867,   867,   867,
     131,   172,  -334,  1293,  1293,  1293,  1293,  1293,  1293,  1293,
    1293,  1293,  1293,   867,   160,     6,     1,    44,  1293,  1223,
     867,  -334,   132,   137,   140,   867,   -54,   867,  1258,  1293,
     -65,  -334,   135,   144,   145,   149,   151,   152,   153,   867,
    -334,    51,    51,  1408,  1408,  1339,  1316,   125,   125,  1362,
    1385,  1431,   125,   125,   -45,   -45,  -334,  -334,  -334,   141,
     154,  1293,     2,   -41,   -14,   147,   169,   157,  -334,  1293,
     212,   229,   230,   236,   238,   981,  -334,  -334,   867,   867,
     867,   867,   867,   867,   867,   241,  1293,   231,   164,  -334,
     170,   168,   160,   160,  -334,  -334,  -334,    -1,   248,  -334,
    -334,  -334,   249,   174,  -334,  1293,  1004,  1027,   -17,  1050,
    1073,  1096,   171,  -334,   185,   251,   261,     4,   178,   148,
     186,   160,   867,   207,   359,    40,   410,   216,   198,  -334,
    -334,  -334,  -334,  -334,  -334,   867,   441,  -334,  -334,  -334,
    -334,   202,   278,   206,  -334,  1293,  -334,   200,  -334,   233,
     223,  1293,    48,    -9,  -334,   112,   226,   211,  -334,   234,
     309,  1119,  -334,   492,   523,   315,   240,   316,  -334,     3,
     314,   243,   319,  -334,   867,   160,  -334,   308,   246,   320,
    -334,   253,  -334,  -334,  -334,  -334,  -334,  -334,   266,   148,
    -334,   867,   270,  1293,   252,     7,   -12,  -334,   343,  -334,
     347,   574,  -334,  -334,  1142,  -334,   351,   867,    54,   279,
     350,  -334,   605,  -334,  -334,   314,  -334,   281,    55,  -334,
    -334,   867,  -334,   769,   656,   283,  -334,    27,  1165,   687,
     280,  -334,   358,   314,   867,   294,  -334,   370,   301,    59,
     374,  -334,  -334,  -334,  -334,   314,   738,  -334
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     0,    38,     9,    52,    53,    57,
      55,    54,    56,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,     0,     5,    10,     4,     7,     0,    16,
       0,    13,     0,    17,    18,    19,    21,    20,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    59,
      63,    62,    66,    58,    60,    61,     0,    64,     0,     0,
       0,     0,     0,     0,     0,    65,    24,     0,     0,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    41,     0,    25,     0,    12,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,   100,
       0,    98,     0,     0,     0,     0,    89,     0,    67,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     0,   136,     0,     0,    39,    26,     0,
       0,    14,     0,     0,     0,     0,    41,     0,     0,   101,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    78,    79,    81,    82,    87,    88,    85,    86,    76,
      77,    75,    84,    83,    68,    69,    70,    71,    72,     0,
       0,    40,     0,     0,     0,     0,     0,     0,   121,    42,
       0,     0,     0,     0,     0,     0,   120,    99,     0,     0,
       0,   100,     0,     0,     0,     0,    74,     0,     0,   137,
       0,     0,     0,     0,   134,    50,   117,     0,     0,     5,
     109,     5,     0,     0,    80,   102,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,   129,
       0,     0,   122,     0,     0,   111,     0,     0,     0,    97,
      93,    94,    90,    91,    92,     0,     0,     5,   138,     5,
     139,     0,     0,    51,   135,   132,   133,   134,   134,     0,
       0,   123,     0,     0,   104,     0,     0,     0,   113,     0,
       0,     0,    49,     0,     0,     0,     0,     0,   134,     0,
     130,     0,     0,    43,     0,     0,   134,   106,     0,     0,
     108,     0,     5,    95,     3,    48,   140,   118,     0,     0,
     128,     0,     0,   124,     0,   125,     0,   103,     0,     5,
       0,     0,   119,   134,     0,    44,     0,   122,     0,     0,
       0,     5,     0,     5,   115,   131,    45,     0,     0,    46,
     134,     0,     5,     0,     0,     0,   134,     0,     0,     0,
      22,   114,     0,   126,   122,     0,   107,     0,     0,     0,
       0,   110,    47,   134,     5,   127,     0,   105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -334,  -334,   -24,  -334,     9,  -334,  -334,  -334,   348,    -2,
     113,   -19,   190,  -334,  -334,  -334,  -334,  -334,  -334,  -334,
    -334,  -334,  -334,  -334,   345,  -333,  -334,   208,  -334,    84,
    -187,  -334
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    26,    27,    28,    29,    30,    31,    32,
      65,   281,   160,    33,   307,   327,    34,   255,   287,    35,
      36,    37,   145,   273,    42,   282,   338,   276,   277,   278,
     249,   193
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,     6,    66,    82,   348,   250,   156,   196,   219,   339,
     270,    43,    97,    38,   274,   143,     3,   223,   274,   207,
      84,    85,   305,    44,   208,    91,    92,  -116,    94,   144,
     251,   369,   127,   128,   129,    39,   204,    70,   274,    87,
     161,   162,   106,   221,   108,   111,    96,    40,   222,    41,
      45,    88,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   110,    98,   285,    99,   286,   261,   148,   149,
     100,   224,   208,   340,   143,   194,   306,    25,    83,   158,
     159,    83,   197,   220,   252,   271,  -116,   195,   144,   320,
     299,   300,   337,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   319,   364,  -120,    46,    49,    50,    51,    47,   325,
      53,    54,    55,    67,   191,  -120,   125,   126,   127,   128,
     129,   199,    57,    48,   303,    68,   203,   304,   205,    89,
     349,   356,   192,   350,   304,   373,   345,    86,   304,    93,
     216,    49,    50,    51,    52,   102,    53,    54,    55,   274,
     103,    56,   104,   357,   163,   164,   105,   107,    57,   363,
     112,   113,     7,     8,     9,    10,    11,    12,   130,   131,
      58,   146,    59,   150,    60,   153,   375,  -121,  -121,   235,
     236,   237,   159,   239,   240,   241,   155,    88,  -121,  -121,
     125,   126,   127,   128,   129,   254,   157,   256,   165,    61,
     167,   166,   168,    62,   169,   189,   190,   200,   209,   266,
     247,   248,   201,   229,    63,   202,   217,   210,   211,   226,
     275,    64,   212,   224,   213,   214,   215,   218,   227,   228,
     230,   231,   243,   293,   233,   294,   291,   242,   244,   280,
      -2,     4,   245,   246,   253,   257,     5,   268,   258,   272,
     265,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     267,    15,   269,    16,   279,    17,   283,    18,    19,    20,
     289,   112,   113,   290,   295,   323,   296,   297,   331,   298,
      21,    22,    23,   114,   115,   116,   117,   310,   118,   119,
     275,   301,   334,   324,   302,   342,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   309,   353,   311,   354,
     312,   316,   317,   232,   318,   274,   321,   322,   359,     4,
     326,   329,   358,   336,     5,    24,   328,    25,   330,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   332,    15,
     376,    16,   335,    17,   341,    18,    19,    20,   343,   347,
       4,   352,   351,   355,   362,     5,   368,   367,    21,    22,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   370,
      15,   371,    16,   372,    17,   374,    18,    19,    20,     7,
       8,     9,    10,    11,    12,    13,    95,   101,   308,    21,
      22,   238,   225,   333,     0,     0,     0,     0,     0,     0,
       0,     4,     0,    24,   132,    25,     5,     0,    22,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
       0,    15,     0,    16,     0,    17,     0,    18,    19,    20,
       0,     0,     4,     0,    24,   284,    25,     5,     0,     0,
      21,    22,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,    15,     0,    16,     0,    17,     0,    18,    19,
      20,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    21,    22,     0,     0,     0,     0,     0,    81,     0,
       0,     0,     0,     4,     0,    24,   288,    25,     5,     0,
       0,     0,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,    15,     0,    16,     0,    17,     0,    18,
      19,    20,     0,     0,     4,     0,    24,   292,    25,     5,
       0,     0,    21,    22,     6,     7,     8,     9,    10,    11,
      12,    13,    14,     0,    15,     0,    16,     0,    17,     0,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,    24,   314,    25,
       5,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     0,    15,     0,    16,     0,    17,
       0,    18,    19,    20,     0,     0,     4,     0,    24,   315,
      25,     5,     0,     0,    21,    22,     6,     7,     8,     9,
      10,    11,    12,    13,    14,     0,    15,     0,    16,     0,
      17,     0,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,    24,
     344,    25,     5,     0,     0,     0,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,    15,     0,    16,
       0,    17,     0,    18,    19,    20,     0,     0,     4,     0,
      24,  -112,    25,     5,     0,     0,    21,    22,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     0,    15,     0,
      16,     0,    17,     0,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       0,    24,   361,    25,     5,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,    15,
       0,    16,     0,    17,     0,    18,    19,    20,     0,     0,
       4,     0,    24,   366,    25,     5,     0,     0,    21,    22,
       6,     7,     8,     9,    10,    11,    12,    13,    14,     0,
      15,     0,    16,     0,   360,     0,    18,    19,    20,     0,
       0,    49,    50,    51,    52,     0,    53,    54,    55,    21,
      22,    56,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,    24,   377,    25,     0,     0,     0,     0,
      58,     0,    59,     0,    60,    49,    50,    51,    52,     0,
      53,    54,    55,     0,     7,   109,     9,    10,    11,    12,
       0,     0,    57,     0,    24,     0,    25,     0,     0,    61,
       0,     0,     0,    62,    58,     0,    59,     0,    60,     0,
      49,    50,    51,    52,    63,    53,    54,    55,     0,     0,
      56,    64,    90,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,    61,     0,     0,     0,    62,     0,    58,
       0,    59,     0,    60,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     0,
       0,     0,    62,     0,   112,   113,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,   114,   115,   116,   117,
      64,   118,   119,     0,     0,     0,     0,   112,   113,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   114,
     115,   116,   117,   151,   118,   119,     0,     0,     0,     0,
     112,   113,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   114,   115,   116,   117,   152,   118,   119,     0,
       0,     0,     0,   112,   113,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   114,   115,   116,   117,   154,
     118,   119,     0,     0,     0,     0,   112,   113,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   114,   115,
     116,   117,   170,   118,   119,     0,     0,     0,     0,   112,
     113,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   114,   115,   116,   117,   234,   118,   119,     0,     0,
       0,     0,   112,   113,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   114,   115,   116,   117,   259,   118,
     119,     0,     0,     0,     0,   112,   113,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   114,   115,   116,
     117,   260,   118,   119,     0,     0,     0,     0,   112,   113,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     114,   115,   116,   117,   262,   118,   119,     0,     0,     0,
       0,   112,   113,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   114,   115,   116,   117,   263,   118,   119,
       0,     0,     0,     0,   112,   113,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   114,   115,   116,   117,
     264,   118,   119,     0,     0,     0,     0,   112,   113,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   114,
     115,   116,   117,   313,   118,   119,     0,     0,     0,     0,
     112,   113,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   114,   115,   116,   117,   346,   118,   119,     0,
       0,     0,     0,   112,   113,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   114,   115,   116,   117,   365,
     118,   119,     0,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   112,   113,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,     0,   118,   119,     0,     0,     0,
       0,     0,     0,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   112,   113,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,     0,
     118,   119,     0,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   112,   113,
     206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,     0,   118,   119,     0,     0,     0,
       0,   112,   113,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   114,   115,   116,     0,     0,   118,   119,
       0,     0,     0,     0,   112,   113,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   114,   115,     0,     0,
       0,   118,   119,     0,     0,     0,     0,   112,   113,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   114,
     115,     0,     0,     0,   118,   119,     0,     0,     0,     0,
     112,   113,     0,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   114,   115,     0,     0,     0,   118,   119,     0,
       0,     0,     0,   112,   113,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   129,  -121,  -121,     0,     0,     0,
     118,   119,     0,     0,     0,     0,   112,   113,     0,     0,
       0,   123,   124,   125,   126,   127,   128,   129,   114,   115,
       0,     0,     0,   118,   119,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,   126,   127,   128,
     129
};

static const yytype_int16 yycheck[] =
{
      24,    11,    21,     6,   337,     6,     6,     6,     6,    21,
       6,    13,    30,     4,    11,    69,     0,    31,    11,    84,
      39,    40,    31,    83,    89,    44,    45,    81,    47,    83,
      31,   364,    77,    78,    79,    69,    90,    28,    11,    69,
      67,    68,    61,    84,    63,    64,    48,    81,    89,    83,
      83,    81,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    64,    81,    24,    83,    26,    84,    87,    88,
      88,    85,    89,    85,    69,    69,    85,    87,    81,    98,
      99,    81,    81,    81,    85,    81,    81,    81,    83,    86,
     277,   278,    85,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   298,    85,    69,    83,     3,     4,     5,    83,   306,
       8,     9,    10,     6,   143,    81,    75,    76,    77,    78,
      79,   150,    20,    83,    86,    43,   155,    89,   157,     6,
      86,    86,   144,    89,    89,    86,   333,    84,    89,     6,
     169,     3,     4,     5,     6,    88,     8,     9,    10,    11,
      88,    13,    88,   350,    38,    39,    88,    88,    20,   356,
      45,    46,    12,    13,    14,    15,    16,    17,    83,    41,
      32,    82,    34,    69,    36,    84,   373,    62,    63,   208,
     209,   210,   211,   212,   213,   214,    87,    81,    73,    74,
      75,    76,    77,    78,    79,   229,    83,   231,    33,    61,
      37,    35,    66,    65,    84,    84,    44,    85,    83,   243,
     222,   223,    85,    11,    76,    85,    85,    83,    83,    82,
     249,    83,    83,    85,    83,    83,    83,    83,    69,    82,
      11,    11,    11,   267,     6,   269,   265,     6,    84,   251,
       0,     1,    82,    85,     6,     6,     6,     6,    84,    81,
      89,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      85,    21,    11,    23,    88,    25,    69,    27,    28,    29,
      64,    45,    46,    85,    82,   304,     8,    81,   312,    89,
      40,    41,    42,    57,    58,    59,    60,    86,    62,    63,
     319,    68,   321,   305,    81,   329,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    90,   341,    84,   343,
      11,     6,    82,    87,     8,    11,    83,     8,   352,     1,
      22,    11,   351,    81,     6,    85,    90,    87,    85,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    82,    21,
     374,    23,    82,    25,    11,    27,    28,    29,    11,     8,
       1,    11,    83,    82,    81,     6,     8,    87,    40,    41,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    85,
      21,    11,    23,    82,    25,    11,    27,    28,    29,    12,
      13,    14,    15,    16,    17,    18,    48,    52,   285,    40,
      41,   211,   194,   319,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    85,    86,    87,     6,    -1,    41,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    -1,    23,    -1,    25,    -1,    27,    28,    29,
      -1,    -1,     1,    -1,    85,    86,    87,     6,    -1,    -1,
      40,    41,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    -1,    23,    -1,    25,    -1,    27,    28,
      29,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    40,    41,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,     1,    -1,    85,    86,    87,     6,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    -1,    23,    -1,    25,    -1,    27,
      28,    29,    -1,    -1,     1,    -1,    85,    86,    87,     6,
      -1,    -1,    40,    41,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    -1,    23,    -1,    25,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    85,    86,    87,
       6,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    -1,    23,    -1,    25,
      -1,    27,    28,    29,    -1,    -1,     1,    -1,    85,    86,
      87,     6,    -1,    -1,    40,    41,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    -1,    23,    -1,
      25,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    85,
      86,    87,     6,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    21,    -1,    23,
      -1,    25,    -1,    27,    28,    29,    -1,    -1,     1,    -1,
      85,    86,    87,     6,    -1,    -1,    40,    41,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    -1,
      23,    -1,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    85,    86,    87,     6,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    21,
      -1,    23,    -1,    25,    -1,    27,    28,    29,    -1,    -1,
       1,    -1,    85,    86,    87,     6,    -1,    -1,    40,    41,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    -1,    23,    -1,    25,    -1,    27,    28,    29,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    10,    40,
      41,    13,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    85,    86,    87,    -1,    -1,    -1,    -1,
      32,    -1,    34,    -1,    36,     3,     4,     5,     6,    -1,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      -1,    -1,    20,    -1,    85,    -1,    87,    -1,    -1,    61,
      -1,    -1,    -1,    65,    32,    -1,    34,    -1,    36,    -1,
       3,     4,     5,     6,    76,     8,     9,    10,    -1,    -1,
      13,    83,    84,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    -1,    32,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    65,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    -1,    -1,    57,    58,    59,    60,
      83,    62,    63,    -1,    -1,    -1,    -1,    45,    46,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    57,
      58,    59,    60,    84,    62,    63,    -1,    -1,    -1,    -1,
      45,    46,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    57,    58,    59,    60,    84,    62,    63,    -1,
      -1,    -1,    -1,    45,    46,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    57,    58,    59,    60,    84,
      62,    63,    -1,    -1,    -1,    -1,    45,    46,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    57,    58,
      59,    60,    84,    62,    63,    -1,    -1,    -1,    -1,    45,
      46,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    57,    58,    59,    60,    84,    62,    63,    -1,    -1,
      -1,    -1,    45,    46,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    57,    58,    59,    60,    84,    62,
      63,    -1,    -1,    -1,    -1,    45,    46,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    57,    58,    59,
      60,    84,    62,    63,    -1,    -1,    -1,    -1,    45,    46,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      57,    58,    59,    60,    84,    62,    63,    -1,    -1,    -1,
      -1,    45,    46,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    57,    58,    59,    60,    84,    62,    63,
      -1,    -1,    -1,    -1,    45,    46,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    57,    58,    59,    60,
      84,    62,    63,    -1,    -1,    -1,    -1,    45,    46,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    57,
      58,    59,    60,    84,    62,    63,    -1,    -1,    -1,    -1,
      45,    46,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    57,    58,    59,    60,    84,    62,    63,    -1,
      -1,    -1,    -1,    45,    46,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    57,    58,    59,    60,    84,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    45,    46,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    45,    46,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    45,    46,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    62,    63,    -1,    -1,    -1,
      -1,    45,    46,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    57,    58,    59,    -1,    -1,    62,    63,
      -1,    -1,    -1,    -1,    45,    46,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    57,    58,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    45,    46,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    57,
      58,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      45,    46,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    57,    58,    -1,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    72,    73,    74,
      75,    76,    77,    78,    79,    57,    58,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    57,    58,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,    78,
      79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    92,    93,     0,     1,     6,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    21,    23,    25,    27,    28,
      29,    40,    41,    42,    85,    87,    94,    95,    96,    97,
      98,    99,   100,   104,   107,   110,   111,   112,    95,    69,
      81,    83,   115,   100,    83,    83,    83,    83,    83,     3,
       4,     5,     6,     8,     9,    10,    13,    20,    32,    34,
      36,    61,    65,    76,    83,   101,   102,     6,    43,    93,
      95,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    64,     6,    81,   102,   102,    84,    69,    81,     6,
      84,   102,   102,     6,   102,    99,   100,    30,    81,    83,
      88,   115,    88,    88,    88,    88,   102,    88,   102,    13,
     100,   102,    45,    46,    57,    58,    59,    60,    62,    63,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      83,    41,    86,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,    69,    83,   113,    82,    82,   102,   102,
      69,    84,    84,    84,    84,    87,     6,    83,   102,   102,
     103,    67,    68,    38,    39,    33,    35,    37,    66,    84,
      84,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,    84,
      44,   102,   100,   122,    69,    81,     6,    81,    82,   102,
      85,    85,    85,   102,    90,   102,    82,    84,    89,    83,
      83,    83,    83,    83,    83,    83,   102,    85,    83,     6,
      81,    84,    89,    31,    85,   118,    82,    69,    82,    11,
      11,    11,    87,     6,    84,   102,   102,   102,   103,   102,
     102,   102,     6,    11,    84,    82,    85,   100,   100,   121,
       6,    31,    85,     6,    93,   108,    93,     6,    84,    84,
      84,    84,    84,    84,    84,    89,    93,    85,     6,    11,
       6,    81,    81,   114,    11,   102,   118,   119,   120,    88,
     100,   102,   116,    69,    86,    24,    26,   109,    86,    64,
      85,   102,    86,    93,    93,    82,     8,    81,    89,   121,
     121,    68,    81,    86,    89,    31,    85,   105,   101,    90,
      86,    84,    11,    84,    86,    86,     6,    82,     8,   121,
      86,    83,     8,   102,   100,   121,    22,   106,    90,    11,
      85,    93,    82,   120,   102,    82,    81,    85,   117,    21,
      85,    11,    93,    11,    86,   121,    84,     8,   116,    86,
      89,    83,    11,    93,    93,    82,    86,   121,   102,    93,
      25,    86,    81,   121,    85,    84,    86,    87,     8,   116,
      85,    11,    82,    86,    11,   121,    93,    86
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    94,    94,    94,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   104,   105,   105,   106,   106,   107,   108,
     108,   109,   109,   110,   111,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   117,   117,   117,   118,   119,
     119,   119,   120,   120,   121,   121,   122,   122,   122,   122,
     122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,    10,     2,     0,     2,     1,     2,     1,
       1,     3,     3,     1,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     4,
       4,     2,     5,     8,    10,    11,    11,    15,     9,     8,
       5,     7,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     4,     3,     3,     3,     3,     3,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       6,     6,     6,     6,     6,     8,     3,     6,     2,     4,
       0,     1,     3,    10,     0,    10,     0,     5,     9,     0,
       9,     0,     4,     8,    13,    11,     0,     3,     3,     4,
       3,     4,     0,     1,     3,     0,     4,     7,     5,     0,
       2,     5,     1,     1,     0,     2,     0,     2,     4,     4,
       6
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
#line 2065 "build/parser.tab.c"
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
#line 2093 "build/parser.tab.c"
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
#line 2106 "build/parser.tab.c"
    break;

  case 5: /* sentences: %empty  */
#line 197 "src/parser/parser.y"
        { 
            (yyval.instrList) = InstruccionList_create();
        }
#line 2114 "build/parser.tab.c"
    break;

  case 6: /* sentence: instruction separator  */
#line 202 "src/parser/parser.y"
                           {
        (yyval.instr) = (yyvsp[-1].instr);
    }
#line 2122 "build/parser.tab.c"
    break;

  case 7: /* sentence: separator  */
#line 205 "src/parser/parser.y"
                {
        (yyval.instr) = NULL;
    }
#line 2130 "build/parser.tab.c"
    break;

  case 8: /* sentence: error separator  */
#line 208 "src/parser/parser.y"
                      {
        // Recuperación de error: saltar hasta el siguiente separador
        yyerrok;
        (yyval.instr) = NULL;
    }
#line 2140 "build/parser.tab.c"
    break;

  case 9: /* separator: BREAK_LINE  */
#line 215 "src/parser/parser.y"
                 {}
#line 2146 "build/parser.tab.c"
    break;

  case 10: /* separator: ';'  */
#line 216 "src/parser/parser.y"
          { /* skip */ }
#line 2152 "build/parser.tab.c"
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
#line 2165 "build/parser.tab.c"
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
#line 2179 "build/parser.tab.c"
    break;

  case 13: /* instruction: declaration  */
#line 237 "src/parser/parser.y"
                  {
        (yyvsp[0].instr)->InstType = "DECLARATION";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr);
    }
#line 2189 "build/parser.tab.c"
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
#line 2201 "build/parser.tab.c"
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
#line 2216 "build/parser.tab.c"
    break;

  case 16: /* instruction: assignment  */
#line 259 "src/parser/parser.y"
                 {
        (yyvsp[0].instr)->InstType = "ASSIGNMENT";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr);
    }
#line 2226 "build/parser.tab.c"
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
#line 2239 "build/parser.tab.c"
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
#line 2252 "build/parser.tab.c"
    break;

  case 19: /* instruction: WHILE_STATEMENT  */
#line 280 "src/parser/parser.y"
                      {
        (yyvsp[0].instr)->InstType = "WHILE_STATEMENT";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr); 
    }
#line 2262 "build/parser.tab.c"
    break;

  case 20: /* instruction: FOREACH_STATEMENT  */
#line 285 "src/parser/parser.y"
                       {
        (yyvsp[0].instr)->InstType = "FOREACH_STATEMENT";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr);
    }
#line 2272 "build/parser.tab.c"
    break;

  case 21: /* instruction: FOR_STATEMENT  */
#line 290 "src/parser/parser.y"
                    {
        (yyvsp[0].instr)->InstType = "FOR_STATEMENT";
        (yyvsp[0].instr)->line = (yylsp[0]).first_line;
        (yyval.instr) = (yyvsp[0].instr); 
    }
#line 2282 "build/parser.tab.c"
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
#line 2294 "build/parser.tab.c"
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
#line 2306 "build/parser.tab.c"
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
#line 2319 "build/parser.tab.c"
    break;

  case 25: /* assignment: ID '=' expression  */
#line 323 "src/parser/parser.y"
                      {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-2].sval);
        instP->value = (yyvsp[0].expr);
        instP->column = (yylsp[-2]).first_column;
        (yyval.instr) = instP; }
#line 2330 "build/parser.tab.c"
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
#line 2353 "build/parser.tab.c"
    break;

  case 27: /* assignment: assignment_expression PLUS_ASSIGN expression  */
#line 349 "src/parser/parser.y"
                                                   {
        (yyvsp[-2].instr)->value->type = "SUM";
        (yyvsp[-2].instr)->value->value = strdup("+");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2363 "build/parser.tab.c"
    break;

  case 28: /* assignment: assignment_expression MINUS_ASSIGN expression  */
#line 355 "src/parser/parser.y"
                                                    {
        (yyvsp[-2].instr)->value->type = "SUBTRACT";
        (yyvsp[-2].instr)->value->value = strdup("-");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2373 "build/parser.tab.c"
    break;

  case 29: /* assignment: assignment_expression MULT_ASSIGN expression  */
#line 361 "src/parser/parser.y"
                                                   {
        (yyvsp[-2].instr)->value->type = "MULTIPLICATION";
        (yyvsp[-2].instr)->value->value = strdup("*");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2383 "build/parser.tab.c"
    break;

  case 30: /* assignment: assignment_expression DIV_ASSIGN expression  */
#line 367 "src/parser/parser.y"
                                                  {
        (yyvsp[-2].instr)->value->type = "DIVIDE";
        (yyvsp[-2].instr)->value->value = strdup("/");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2393 "build/parser.tab.c"
    break;

  case 31: /* assignment: assignment_expression MOD_ASSIGN expression  */
#line 373 "src/parser/parser.y"
                                                  {
        (yyvsp[-2].instr)->value->type = "MODULO";
        (yyvsp[-2].instr)->value->value = strdup("%");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2403 "build/parser.tab.c"
    break;

  case 32: /* assignment: assignment_expression AND_ASSIGN expression  */
#line 379 "src/parser/parser.y"
                                                  {
        (yyvsp[-2].instr)->value->type = "BITWISE_AND";
        (yyvsp[-2].instr)->value->value = strdup("&");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2413 "build/parser.tab.c"
    break;

  case 33: /* assignment: assignment_expression OR_ASSIGN expression  */
#line 385 "src/parser/parser.y"
                                                 {
        (yyvsp[-2].instr)->value->type = "BITWISE_OR";
        (yyvsp[-2].instr)->value->value = strdup("|");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2423 "build/parser.tab.c"
    break;

  case 34: /* assignment: assignment_expression XOR_ASSIGN expression  */
#line 391 "src/parser/parser.y"
                                                  {
        (yyvsp[-2].instr)->value->type = "BITWISE_XOR";
        (yyvsp[-2].instr)->value->value = strdup("^");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2433 "build/parser.tab.c"
    break;

  case 35: /* assignment: assignment_expression LEFT_SHIFT_ASSIGN expression  */
#line 397 "src/parser/parser.y"
                                                         {
        (yyvsp[-2].instr)->value->type = "BITWISE_LEFT_SHIFT";
        (yyvsp[-2].instr)->value->value = strdup("<<");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2443 "build/parser.tab.c"
    break;

  case 36: /* assignment: assignment_expression RIGHT_SHIFT_ASSIGN expression  */
#line 403 "src/parser/parser.y"
                                                          {
        (yyvsp[-2].instr)->value->type = "BITWISE_RIGHT_SHIFT";
        (yyvsp[-2].instr)->value->value = strdup(">>");
        (yyvsp[-2].instr)->value->right = (yyvsp[0].expr);
        (yyval.instr) = (yyvsp[-2].instr); }
#line 2453 "build/parser.tab.c"
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
#line 2465 "build/parser.tab.c"
    break;

  case 38: /* assignment_expression: ID  */
#line 418 "src/parser/parser.y"
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
#line 2481 "build/parser.tab.c"
    break;

  case 39: /* assignment_expression: ID '[' expression ']'  */
#line 429 "src/parser/parser.y"
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
#line 2504 "build/parser.tab.c"
    break;

  case 40: /* declaration: primitive_types ID '=' expression  */
#line 454 "src/parser/parser.y"
                                      {

        // ? Crear instrucción

        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-2].sval);
        instP->type = (yyvsp[-3].sval);
        instP->column = (yylsp[-2]).first_column;
        instP->symbolType = "VARIABLE";
        instP->value = (yyvsp[0].expr);
        (yyval.instr) = instP; }
#line 2520 "build/parser.tab.c"
    break;

  case 41: /* declaration: primitive_types ID  */
#line 466 "src/parser/parser.y"
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
#line 2538 "build/parser.tab.c"
    break;

  case 42: /* declaration: FINAL primitive_types ID '=' expression  */
#line 480 "src/parser/parser.y"
                                              {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-2].sval);
        instP->type = (yyvsp[-3].sval);
        instP->column = (yylsp[-2]).first_column;
        instP->symbolType = "CONSTANT";
        instP->value = (yyvsp[0].expr);
        (yyval.instr) = instP; }
#line 2551 "build/parser.tab.c"
    break;

  case 43: /* declaration: primitive_types '[' ']' ID '=' '{' vectorList '}'  */
#line 489 "src/parser/parser.y"
                                                        {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-4].sval);
        instP->type = (yyvsp[-7].sval);
        instP->column = (yylsp[-5]).first_column;
        instP->symbolType = "VECTOR";
        instP->vectorValues = (yyvsp[-1].VList);
        (yyval.instr) = instP; }
#line 2564 "build/parser.tab.c"
    break;

  case 44: /* declaration: primitive_types '[' ']' ID '=' NEW primitive_types '[' NUM ']'  */
#line 498 "src/parser/parser.y"
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
#line 2583 "build/parser.tab.c"
    break;

  case 45: /* declaration: primitive_types '[' ']' ID '=' ID '.' ADD '(' expression ')'  */
#line 513 "src/parser/parser.y"
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
#line 2601 "build/parser.tab.c"
    break;

  case 46: /* declaration: primitive_types '[' ']' '[' ']' ID '=' '{' optional_newlines matrixList '}'  */
#line 527 "src/parser/parser.y"
                                                                               {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-5].sval);
        instP->type = (yyvsp[-10].sval);
        instP->column = (yylsp[-6]).first_column;
        instP->symbolType = "MATRIX";
        instP->matrixValues = (yyvsp[-1].MList);
        (yyval.instr) = instP;
    }
#line 2615 "build/parser.tab.c"
    break;

  case 47: /* declaration: primitive_types '[' ']' '[' ']' ID '=' NEW primitive_types '[' NUM ']' '[' NUM ']'  */
#line 537 "src/parser/parser.y"
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
#line 2638 "build/parser.tab.c"
    break;

  case 48: /* declaration: primitive_types ID '(' paramsList ')' '{' BREAK_LINE sentences '}'  */
#line 556 "src/parser/parser.y"
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
#line 2653 "build/parser.tab.c"
    break;

  case 49: /* declaration: VOID ID '(' ')' '{' BREAK_LINE sentences '}'  */
#line 567 "src/parser/parser.y"
                                                   {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->id = (yyvsp[-6].sval);
        instP->column = (yylsp[-6]).first_column;
        instP->symbolType = "VOID";
        instP->functionData = (Function*)calloc(1, sizeof(Function));
        instP->functionData->body = (yyvsp[-1].instrList);
        (yyval.instr) = instP; }
#line 2666 "build/parser.tab.c"
    break;

  case 50: /* declaration: primitive_types ID dimensions '=' dimension_expression  */
#line 576 "src/parser/parser.y"
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
#line 2681 "build/parser.tab.c"
    break;

  case 51: /* declaration: primitive_types ID dimensions '=' NEW primitive_types dimensions_value_list  */
#line 586 "src/parser/parser.y"
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
#line 2704 "build/parser.tab.c"
    break;

  case 52: /* primitive_types: INT  */
#line 608 "src/parser/parser.y"
        { (yyval.sval) = strdup("INTEGER"); }
#line 2710 "build/parser.tab.c"
    break;

  case 53: /* primitive_types: STRING  */
#line 609 "src/parser/parser.y"
             { (yyval.sval) = strdup("STRING"); }
#line 2716 "build/parser.tab.c"
    break;

  case 54: /* primitive_types: DOUBLE  */
#line 610 "src/parser/parser.y"
             { (yyval.sval) = strdup("DOUBLE"); }
#line 2722 "build/parser.tab.c"
    break;

  case 55: /* primitive_types: FLOAT  */
#line 611 "src/parser/parser.y"
            { (yyval.sval) = strdup("FLOAT"); }
#line 2728 "build/parser.tab.c"
    break;

  case 56: /* primitive_types: BOOL  */
#line 612 "src/parser/parser.y"
           { (yyval.sval) = strdup("BOOLEAN"); }
#line 2734 "build/parser.tab.c"
    break;

  case 57: /* primitive_types: CHAR  */
#line 613 "src/parser/parser.y"
           { (yyval.sval) = strdup("CHARACTER"); }
#line 2740 "build/parser.tab.c"
    break;

  case 58: /* primitive_values: NUM  */
#line 618 "src/parser/parser.y"
        { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("INTEGER");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2751 "build/parser.tab.c"
    break;

  case 59: /* primitive_values: STR  */
#line 624 "src/parser/parser.y"
          { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("STRING");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2762 "build/parser.tab.c"
    break;

  case 60: /* primitive_values: DEC  */
#line 630 "src/parser/parser.y"
          { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("DOUBLE");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2773 "build/parser.tab.c"
    break;

  case 61: /* primitive_values: DECF  */
#line 636 "src/parser/parser.y"
           { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("FLOAT");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2784 "build/parser.tab.c"
    break;

  case 62: /* primitive_values: BOOLEAN  */
#line 642 "src/parser/parser.y"
              { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("BOOLEAN");
        exp->value = strdup((yyvsp[0].sval));

        (yyval.expr) = exp; }
#line 2795 "build/parser.tab.c"
    break;

  case 63: /* primitive_values: CHR  */
#line 648 "src/parser/parser.y"
          { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("CHARACTER");
        exp->value = strdup((yyvsp[0].sval));
        (yyval.expr) = exp; }
#line 2805 "build/parser.tab.c"
    break;

  case 64: /* primitive_values: NULL_EXP  */
#line 653 "src/parser/parser.y"
               { 
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = strdup("NULL");
        exp->value = strdup("null");
        (yyval.expr) = exp; }
#line 2815 "build/parser.tab.c"
    break;

  case 65: /* expression: primitive_values  */
#line 663 "src/parser/parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 2821 "build/parser.tab.c"
    break;

  case 66: /* expression: ID  */
#line 664 "src/parser/parser.y"
         {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "ID";
        exp->value = strdup((yyvsp[0].sval));
        (yyval.expr) = exp;
        }
#line 2832 "build/parser.tab.c"
    break;

  case 67: /* expression: '-' expression  */
#line 670 "src/parser/parser.y"
                               {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "NEGATIVE";
        exp->value = strdup("-");
        exp->left = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2843 "build/parser.tab.c"
    break;

  case 68: /* expression: expression '+' expression  */
#line 676 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "SUM";
        exp->value = strdup("+");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2855 "build/parser.tab.c"
    break;

  case 69: /* expression: expression '-' expression  */
#line 683 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "SUBTRACT";
        exp->value = strdup("-");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2867 "build/parser.tab.c"
    break;

  case 70: /* expression: expression '*' expression  */
#line 690 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "MULTIPLICATION";
        exp->value = strdup("*");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2879 "build/parser.tab.c"
    break;

  case 71: /* expression: expression '/' expression  */
#line 697 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "DIVIDE";
        exp->value = strdup("/");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2891 "build/parser.tab.c"
    break;

  case 72: /* expression: expression '%' expression  */
#line 704 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "MODULO";
        exp->value = strdup("%");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2903 "build/parser.tab.c"
    break;

  case 73: /* expression: '(' expression ')'  */
#line 711 "src/parser/parser.y"
                         { (yyval.expr) = (yyvsp[-1].expr); }
#line 2909 "build/parser.tab.c"
    break;

  case 74: /* expression: '(' primitive_types ')' expression  */
#line 712 "src/parser/parser.y"
                                         {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "CASTING";
        exp->value = (yyvsp[-2].sval);
        exp->left = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2920 "build/parser.tab.c"
    break;

  case 75: /* expression: expression '&' expression  */
#line 719 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_AND";
        exp->value = strdup("&");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2932 "build/parser.tab.c"
    break;

  case 76: /* expression: expression '|' expression  */
#line 726 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_OR";
        exp->value = strdup("|");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2944 "build/parser.tab.c"
    break;

  case 77: /* expression: expression '^' expression  */
#line 733 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_XOR";
        exp->value = strdup("^");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2956 "build/parser.tab.c"
    break;

  case 78: /* expression: expression LEFT_SHIFT expression  */
#line 741 "src/parser/parser.y"
                                       {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_LEFT_SHIFT";
        exp->value = strdup("<<");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2968 "build/parser.tab.c"
    break;

  case 79: /* expression: expression RIGHT_SHIFT expression  */
#line 750 "src/parser/parser.y"
                                        {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "BITWISE_RIGHT_SHIFT";
        exp->value = strdup(">>");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 2980 "build/parser.tab.c"
    break;

  case 80: /* expression: ID EQUALS_OP '(' expression ')'  */
#line 758 "src/parser/parser.y"
                                      {
        Expression *exp = (Expression*)calloc(1, sizeof(Expression));   
        exp->type = "EQUALS_OP";
        exp->value = strdup(".equals");
        exp->left = (Expression*)calloc(1, sizeof(Expression));
        exp->left->type = "ID";
        exp->left->value = strdup((yyvsp[-4].sval));
        exp->right = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 2994 "build/parser.tab.c"
    break;

  case 81: /* expression: expression EQUALS expression  */
#line 768 "src/parser/parser.y"
                                   {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "EQUALS";
        exp->value = strdup("==");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3006 "build/parser.tab.c"
    break;

  case 82: /* expression: expression NOT_EQUALS expression  */
#line 776 "src/parser/parser.y"
                                       {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "NOT_EQUALS";
        exp->value = strdup("!=");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3018 "build/parser.tab.c"
    break;

  case 83: /* expression: expression '>' expression  */
#line 784 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "GREATER";
        exp->value = strdup(">");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3030 "build/parser.tab.c"
    break;

  case 84: /* expression: expression '<' expression  */
#line 792 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LESS";
        exp->value = strdup("<");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3042 "build/parser.tab.c"
    break;

  case 85: /* expression: expression GREATER_EQUALS expression  */
#line 800 "src/parser/parser.y"
                                           {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "GREATER_EQUALS";
        exp->value = strdup(">=");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3054 "build/parser.tab.c"
    break;

  case 86: /* expression: expression LESS_EQUALS expression  */
#line 808 "src/parser/parser.y"
                                        {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LESS_EQUALS";
        exp->value = strdup("<=");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3066 "build/parser.tab.c"
    break;

  case 87: /* expression: expression AND expression  */
#line 816 "src/parser/parser.y"
                                {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_AND";
        exp->value = strdup("&&");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3078 "build/parser.tab.c"
    break;

  case 88: /* expression: expression OR expression  */
#line 824 "src/parser/parser.y"
                               {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_OR";
        exp->value = strdup("||");
        exp->left = (yyvsp[-2].expr);
        exp->right = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3090 "build/parser.tab.c"
    break;

  case 89: /* expression: NOT expression  */
#line 832 "src/parser/parser.y"
                     {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LOGICAL_NOT";
        exp->value = strdup("!");
        exp->left = (yyvsp[0].expr);
        (yyval.expr) = exp; }
#line 3101 "build/parser.tab.c"
    break;

  case 90: /* expression: INTEGER_OBJ '.' PARSEINT '(' expression ')'  */
#line 839 "src/parser/parser.y"
                                                  {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEINT";
        exp->value = strdup("Integer.parseInt");
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3112 "build/parser.tab.c"
    break;

  case 91: /* expression: DOUBLE_OBJ '.' PARSEDOUBLE '(' expression ')'  */
#line 846 "src/parser/parser.y"
                                                    {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEDOUBLE";
        exp->value = strdup("Double.parseDouble");
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3123 "build/parser.tab.c"
    break;

  case 92: /* expression: FLOAT_OBJ '.' PARSEFLOAT '(' expression ')'  */
#line 853 "src/parser/parser.y"
                                                  {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "PARSEFLOAT";
        exp->value = strdup("Float.parseFloat");
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3134 "build/parser.tab.c"
    break;

  case 93: /* expression: STRING '.' VALUEOF '(' expression ')'  */
#line 860 "src/parser/parser.y"
                                            {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "VALUEOF";
        exp->value = strdup("String.valueOf");
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3145 "build/parser.tab.c"
    break;

  case 94: /* expression: STRING '.' JOIN '(' exprList ')'  */
#line 867 "src/parser/parser.y"
                                       {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "JOIN";
        exp->value = strdup("String.join");
        exp->list = (yyvsp[-1].exprList);
        (yyval.expr) = exp; }
#line 3156 "build/parser.tab.c"
    break;

  case 95: /* expression: ARRAYS '.' INDEXOF '(' ID ',' expression ')'  */
#line 874 "src/parser/parser.y"
                                                   {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "INDEXOF";
        exp->value = (yyvsp[-3].sval);
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3167 "build/parser.tab.c"
    break;

  case 96: /* expression: ID '.' LENGTH  */
#line 881 "src/parser/parser.y"
                    {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "LENGTH";
        exp->value = strdup((yyvsp[-2].sval));
        (yyval.expr) = exp; }
#line 3177 "build/parser.tab.c"
    break;

  case 97: /* expression: ID '.' ADD '(' expression ')'  */
#line 887 "src/parser/parser.y"
                                    {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "ADD";
        exp->value = strdup((yyvsp[-5].sval));
        exp->left = (yyvsp[-1].expr);
        (yyval.expr) = exp; }
#line 3188 "build/parser.tab.c"
    break;

  case 98: /* expression: ID dimensions_expressions  */
#line 894 "src/parser/parser.y"
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
#line 3213 "build/parser.tab.c"
    break;

  case 99: /* expression: ID '(' exprList ')'  */
#line 915 "src/parser/parser.y"
                          {
        Expression* exp = (Expression*)calloc(1, sizeof(Expression));
        exp->type = "FUNCTION_CALL";
        exp->value = strdup((yyvsp[-3].sval));
        exp->list = (yyvsp[-1].exprList);
        (yyval.expr) = exp;
    }
#line 3225 "build/parser.tab.c"
    break;

  case 100: /* exprList: %empty  */
#line 924 "src/parser/parser.y"
                { 
        ExpressionList* exprList = create_expression_list();
        (yyval.exprList) = exprList;
    }
#line 3234 "build/parser.tab.c"
    break;

  case 101: /* exprList: expression  */
#line 928 "src/parser/parser.y"
                 {
        ExpressionList* exprList = create_expression_list();
        ExpressionList_add(exprList, (yyvsp[0].expr));
        (yyval.exprList) = exprList;
     }
#line 3244 "build/parser.tab.c"
    break;

  case 102: /* exprList: exprList ',' expression  */
#line 933 "src/parser/parser.y"
                              {
        ExpressionList_add((yyvsp[-2].exprList), (yyvsp[0].expr));
        (yyval.exprList) = (yyvsp[-2].exprList);
     }
#line 3253 "build/parser.tab.c"
    break;

  case 103: /* IF_STATEMENT: IF '(' expression ')' '{' BREAK_LINE sentences '}' IF_LIST ELSE_STATEMENT  */
#line 943 "src/parser/parser.y"
                                                                                 {
        IfData* ifdata = (IfData*)calloc(1, sizeof(IfData));
        ifdata->condition = (yyvsp[-7].expr);
        ifdata->block = (yyvsp[-3].instrList);
        ifdata->elseIfs = (yyvsp[-1].ifnodelist);
        ifdata->elseBlock = (yyvsp[0].instrList);
        (yyval.ifdata) = ifdata;
    }
#line 3266 "build/parser.tab.c"
    break;

  case 104: /* IF_LIST: %empty  */
#line 953 "src/parser/parser.y"
                { (yyval.ifnodelist) = createIfNodeList(); }
#line 3272 "build/parser.tab.c"
    break;

  case 105: /* IF_LIST: IF_LIST ELSE IF '(' expression ')' '{' BREAK_LINE sentences '}'  */
#line 954 "src/parser/parser.y"
                                                                        {
        IfData* elseIfNode = (IfData*)malloc(sizeof(IfData));
        elseIfNode->condition = (yyvsp[-5].expr);
        elseIfNode->block = (yyvsp[-1].instrList);
        insertIfNode((yyvsp[-9].ifnodelist), elseIfNode);
        (yyval.ifnodelist) = (yyvsp[-9].ifnodelist);
    }
#line 3284 "build/parser.tab.c"
    break;

  case 106: /* ELSE_STATEMENT: %empty  */
#line 963 "src/parser/parser.y"
                { (yyval.instrList) = NULL; }
#line 3290 "build/parser.tab.c"
    break;

  case 107: /* ELSE_STATEMENT: ELSE '{' BREAK_LINE sentences '}'  */
#line 964 "src/parser/parser.y"
                                        { (yyval.instrList) = (yyvsp[-1].instrList); }
#line 3296 "build/parser.tab.c"
    break;

  case 108: /* SWITCH_STATEMENT: SWITCH '(' ID ')' '{' BREAK_LINE CASES DEFAULT_CASE '}'  */
#line 968 "src/parser/parser.y"
                                                            {
        SwitchData* switchdata = (SwitchData*)malloc(sizeof(SwitchData));
        switchdata->condition = strdup((yyvsp[-6].sval));
        switchdata->cases = (yyvsp[-2].casenodelist);
        switchdata->defaultCase = (yyvsp[-1].instrList);
        (yyval.switchdata) = switchdata;
    }
#line 3308 "build/parser.tab.c"
    break;

  case 109: /* CASES: %empty  */
#line 979 "src/parser/parser.y"
                { (yyval.casenodelist) = CaseNodeList_create(); }
#line 3314 "build/parser.tab.c"
    break;

  case 110: /* CASES: CASES CASE primitive_values ':' BREAK_LINE sentences BREAK ';' BREAK_LINE  */
#line 980 "src/parser/parser.y"
                                                                                {
        CaseData* new_case = (CaseData*)malloc(sizeof(CaseData));
        new_case->condition = (yyvsp[-6].expr);
        new_case->block = (yyvsp[-3].instrList);
        CaseNodeList_add((yyvsp[-8].casenodelist), new_case);
        (yyval.casenodelist) = (yyvsp[-8].casenodelist);
    }
#line 3326 "build/parser.tab.c"
    break;

  case 111: /* DEFAULT_CASE: %empty  */
#line 990 "src/parser/parser.y"
                { (yyval.instrList) = NULL; }
#line 3332 "build/parser.tab.c"
    break;

  case 112: /* DEFAULT_CASE: DEFAULT ':' BREAK_LINE sentences  */
#line 991 "src/parser/parser.y"
                                       { (yyval.instrList) = (yyvsp[0].instrList); }
#line 3338 "build/parser.tab.c"
    break;

  case 113: /* WHILE_STATEMENT: WHILE '(' expression ')' '{' BREAK_LINE sentences '}'  */
#line 999 "src/parser/parser.y"
                                                          {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->whileData = (WhileData*)malloc(sizeof(WhileData));
        instP->whileData->condition = (yyvsp[-5].expr);
        instP->whileData->block = (yyvsp[-1].instrList);
        instP->column = (yylsp[-7]).first_column;
        (yyval.instr) = instP;
    }
#line 3351 "build/parser.tab.c"
    break;

  case 114: /* FOR_STATEMENT: FOR '(' declaration ';' expression ';' ID INCREMENT ')' '{' BREAK_LINE sentences '}'  */
#line 1011 "src/parser/parser.y"
                                                                                         {
        Instruccion* instP = (Instruccion*)malloc(sizeof(Instruccion));
        instP->forData = (ForData*)malloc(sizeof(ForData));
        instP->forData->init = (yyvsp[-10].instr);
        instP->forData->init->InstType = "DECLARATION";
        instP->forData->init->line = (yylsp[-12]).first_line;
        instP->forData->condition = (yyvsp[-8].expr);

        Instruccion* updateInst = (Instruccion*)malloc(sizeof(Instruccion));
        updateInst->id = (yyvsp[-6].sval);
        updateInst->InstType = "ASSIGNMENT";
        updateInst->value = (Expression*)calloc(1, sizeof(Expression));
        updateInst->value->left = (Expression*)calloc(1, sizeof(Expression));
        updateInst->value->left->type = "ID";
        updateInst->value->left->value = strdup((yyvsp[-6].sval));
        updateInst->value->type = "SUM";
        updateInst->value->value = strdup("+");
        updateInst->value->right = (Expression*)calloc(1, sizeof(Expression));
        updateInst->value->right->type = "INTEGER";
        updateInst->value->right->value = strdup("1");

        instP->forData->update = updateInst;
        instP->forData->block = (yyvsp[-1].instrList);
        instP->column = (yylsp[-12]).first_column;
        (yyval.instr) = instP;
    }
#line 3382 "build/parser.tab.c"
    break;

  case 115: /* FOREACH_STATEMENT: FOR '(' primitive_types ID ':' ID ')' '{' BREAK_LINE sentences '}'  */
#line 1039 "src/parser/parser.y"
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
#line 3397 "build/parser.tab.c"
    break;

  case 116: /* dimensions: %empty  */
#line 1052 "src/parser/parser.y"
                  { (yyval.ival) = 0; }
#line 3403 "build/parser.tab.c"
    break;

  case 117: /* dimensions: dimensions '[' ']'  */
#line 1053 "src/parser/parser.y"
                         { (yyval.ival) = (yyvsp[-2].ival) + 1; }
#line 3409 "build/parser.tab.c"
    break;

  case 118: /* dimensions_value_list: '[' NUM ']'  */
#line 1056 "src/parser/parser.y"
                  { 
        DimensionsList* dimList = (DimensionsList*)malloc(sizeof(DimensionsList));
        dimList->dimensions = (int*)malloc(sizeof(int));
        dimList->dimensions[0] = atoi((yyvsp[-1].sval));
        dimList->count = 1;
        (yyval.dimlist) = dimList;
    }
#line 3421 "build/parser.tab.c"
    break;

  case 119: /* dimensions_value_list: dimensions_value_list '[' NUM ']'  */
#line 1063 "src/parser/parser.y"
                                        { 
        (yyvsp[-3].dimlist)->dimensions = (int*)realloc((yyvsp[-3].dimlist)->dimensions, sizeof(int) * ((yyvsp[-3].dimlist)->count + 1));
        (yyvsp[-3].dimlist)->dimensions[(yyvsp[-3].dimlist)->count] = atoi((yyvsp[-1].sval));
        (yyvsp[-3].dimlist)->count += 1;
        (yyval.dimlist) = (yyvsp[-3].dimlist);
    }
#line 3432 "build/parser.tab.c"
    break;

  case 120: /* dimensions_expressions: '[' expression ']'  */
#line 1071 "src/parser/parser.y"
                       { 
        ExpressionList* exprList = create_expression_list();
        ExpressionList_add(exprList, (yyvsp[-1].expr));
        (yyval.exprList) = exprList;
    }
#line 3442 "build/parser.tab.c"
    break;

  case 121: /* dimensions_expressions: dimensions_expressions '[' expression ']'  */
#line 1076 "src/parser/parser.y"
                                                {
        ExpressionList_add((yyvsp[-3].exprList), (yyvsp[-1].expr));
        (yyval.exprList) = (yyvsp[-3].exprList);
     }
#line 3451 "build/parser.tab.c"
    break;

  case 122: /* vectorList: %empty  */
#line 1083 "src/parser/parser.y"
                  { 
        VectorList* vecList = VectorList_create();
        (yyval.VList) = vecList;
    }
#line 3460 "build/parser.tab.c"
    break;

  case 123: /* vectorList: expression  */
#line 1087 "src/parser/parser.y"
                 {
        VectorList* vecList = VectorList_create();
        VectorList_addExp(vecList, (yyvsp[0].expr));
        (yyval.VList) = vecList;
     }
#line 3470 "build/parser.tab.c"
    break;

  case 124: /* vectorList: vectorList ',' expression  */
#line 1092 "src/parser/parser.y"
                                {
        VectorList_addExp((yyvsp[-2].VList), (yyvsp[0].expr));
        (yyval.VList) = (yyvsp[-2].VList);
     }
#line 3479 "build/parser.tab.c"
    break;

  case 125: /* matrixList: %empty  */
#line 1100 "src/parser/parser.y"
                  { 
        MatrixList* matList = MatrixList_create();
        (yyval.MList) = matList;
    }
#line 3488 "build/parser.tab.c"
    break;

  case 126: /* matrixList: '{' vectorList '}' optional_newlines  */
#line 1104 "src/parser/parser.y"
                                          {
        MatrixList* matList = MatrixList_create();
        MatrixList_add(matList, (yyvsp[-2].VList));
        (yyval.MList) = matList;
     }
#line 3498 "build/parser.tab.c"
    break;

  case 127: /* matrixList: matrixList ',' optional_newlines '{' vectorList '}' optional_newlines  */
#line 1109 "src/parser/parser.y"
                                                                             {
        MatrixList_add((yyvsp[-6].MList), (yyvsp[-2].VList));
        (yyval.MList) = (yyvsp[-6].MList);
     }
#line 3507 "build/parser.tab.c"
    break;

  case 128: /* dimension_expression: '{' optional_newlines dimension_values_list optional_newlines '}'  */
#line 1115 "src/parser/parser.y"
                                                                      {(yyval.list) = (yyvsp[-2].list); }
#line 3513 "build/parser.tab.c"
    break;

  case 129: /* dimension_values_list: %empty  */
#line 1118 "src/parser/parser.y"
                  {  (yyval.list) = List_create(); }
#line 3519 "build/parser.tab.c"
    break;

  case 130: /* dimension_values_list: dimension_value optional_newlines  */
#line 1119 "src/parser/parser.y"
                                        { 
        List* list = List_create(); 
        List_add(list, (yyvsp[-1].listdata)); 
        (yyval.list) = list; 
    }
#line 3529 "build/parser.tab.c"
    break;

  case 131: /* dimension_values_list: dimension_values_list ',' optional_newlines dimension_value optional_newlines  */
#line 1124 "src/parser/parser.y"
                                                                                    {List_add((yyvsp[-4].list), (yyvsp[-1].listdata)); (yyval.list) = (yyvsp[-4].list);}
#line 3535 "build/parser.tab.c"
    break;

  case 132: /* dimension_value: expression  */
#line 1127 "src/parser/parser.y"
               { ListData* data = (ListData*)calloc(1, sizeof(ListData));
                  data->exprData = (yyvsp[0].expr);
                  (yyval.listdata) = data; }
#line 3543 "build/parser.tab.c"
    break;

  case 133: /* dimension_value: dimension_expression  */
#line 1130 "src/parser/parser.y"
                           {
        ListData* data = (ListData*)calloc(1, sizeof(ListData));
        data->listData = (yyvsp[0].list);
        (yyval.listdata) = data;
    }
#line 3553 "build/parser.tab.c"
    break;

  case 136: /* paramsList: %empty  */
#line 1145 "src/parser/parser.y"
                { (yyval.paramlist) = createParamsList(); }
#line 3559 "build/parser.tab.c"
    break;

  case 137: /* paramsList: primitive_types ID  */
#line 1146 "src/parser/parser.y"
                         {
        paramsList* paramList = createParamsList();
        addParam(paramList, (yyvsp[-1].sval), (yyvsp[0].sval));
        (yyval.paramlist) = paramList;
     }
#line 3569 "build/parser.tab.c"
    break;

  case 138: /* paramsList: primitive_types '[' ']' ID  */
#line 1151 "src/parser/parser.y"
                                 {
        paramsList* paramList = createParamsList();
        // Puedes usar un tipo especial, por ejemplo: "VECTOR_INTEGER"
        char* vectorType = (char*)malloc(strlen((yyvsp[-3].sval)) + 8);
        sprintf(vectorType, "VECTOR_%s", (yyvsp[-3].sval));
        addParam(paramList, vectorType, (yyvsp[0].sval));
        (yyval.paramlist) = paramList;
     }
#line 3582 "build/parser.tab.c"
    break;

  case 139: /* paramsList: paramsList ',' primitive_types ID  */
#line 1159 "src/parser/parser.y"
                                        {
        addParam((yyvsp[-3].paramlist), (yyvsp[-1].sval), (yyvsp[0].sval));
        (yyval.paramlist) = (yyvsp[-3].paramlist);
     }
#line 3591 "build/parser.tab.c"
    break;

  case 140: /* paramsList: paramsList ',' primitive_types '[' ']' ID  */
#line 1163 "src/parser/parser.y"
                                                {
        char* vectorType = (char*)malloc(strlen((yyvsp[-3].sval)) + 8);
        sprintf(vectorType, "VECTOR_%s", (yyvsp[-3].sval));
        addParam((yyvsp[-5].paramlist), vectorType, (yyvsp[0].sval));
        (yyval.paramlist) = (yyvsp[-5].paramlist);
     }
#line 3602 "build/parser.tab.c"
    break;


#line 3606 "build/parser.tab.c"

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

#line 1170 "src/parser/parser.y"


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

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
#line 14 "A_sintactico2.y"

//Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//FUNCIÓN OBTENERSIGUIENTENUMERO
int obtenerSiguienteLBL(){
	static int siguienteNumero = 0;
	return siguienteNumero++;
}
	

//Variables de bison
int yylex (void);

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}







#line 98 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WHILE = 258,                   /* WHILE  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    PRINT = 261,                   /* PRINT  */
    READ = 262,                    /* READ  */
    DO = 263,                      /* DO  */
    FOR = 264,                     /* FOR  */
    FROM = 265,                    /* FROM  */
    TO = 266,                      /* TO  */
    BY = 267,                      /* BY  */
    ASIG = 268,                    /* ASIG  */
    ADD_ASIG = 269,                /* ADD_ASIG  */
    SUB_ASIG = 270,                /* SUB_ASIG  */
    MUL_ASIG = 271,                /* MUL_ASIG  */
    DIV_ASIG = 272,                /* DIV_ASIG  */
    ADD = 273,                     /* ADD  */
    SUB = 274,                     /* SUB  */
    MUL = 275,                     /* MUL  */
    DIV = 276,                     /* DIV  */
    IPAREN = 277,                  /* IPAREN  */
    DPAREN = 278,                  /* DPAREN  */
    PUNTO_COMA = 279,              /* PUNTO_COMA  */
    ICOR = 280,                    /* ICOR  */
    DCOR = 281,                    /* DCOR  */
    NUM = 282,                     /* NUM  */
    ID = 283                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define WHILE 258
#define IF 259
#define ELSE 260
#define PRINT 261
#define READ 262
#define DO 263
#define FOR 264
#define FROM 265
#define TO 266
#define BY 267
#define ASIG 268
#define ADD_ASIG 269
#define SUB_ASIG 270
#define MUL_ASIG 271
#define DIV_ASIG 272
#define ADD 273
#define SUB 274
#define MUL 275
#define DIV 276
#define IPAREN 277
#define DPAREN 278
#define PUNTO_COMA 279
#define ICOR 280
#define DCOR 281
#define NUM 282
#define ID 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 41 "A_sintactico2.y"

    int num; // Para números
    char* str; // Para cadenas/identificadores
    int lbl;

#line 213 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_WHILE = 3,                      /* WHILE  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_PRINT = 6,                      /* PRINT  */
  YYSYMBOL_READ = 7,                       /* READ  */
  YYSYMBOL_DO = 8,                         /* DO  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_FROM = 10,                      /* FROM  */
  YYSYMBOL_TO = 11,                        /* TO  */
  YYSYMBOL_BY = 12,                        /* BY  */
  YYSYMBOL_ASIG = 13,                      /* ASIG  */
  YYSYMBOL_ADD_ASIG = 14,                  /* ADD_ASIG  */
  YYSYMBOL_SUB_ASIG = 15,                  /* SUB_ASIG  */
  YYSYMBOL_MUL_ASIG = 16,                  /* MUL_ASIG  */
  YYSYMBOL_DIV_ASIG = 17,                  /* DIV_ASIG  */
  YYSYMBOL_ADD = 18,                       /* ADD  */
  YYSYMBOL_SUB = 19,                       /* SUB  */
  YYSYMBOL_MUL = 20,                       /* MUL  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_IPAREN = 22,                    /* IPAREN  */
  YYSYMBOL_DPAREN = 23,                    /* DPAREN  */
  YYSYMBOL_PUNTO_COMA = 24,                /* PUNTO_COMA  */
  YYSYMBOL_ICOR = 25,                      /* ICOR  */
  YYSYMBOL_DCOR = 26,                      /* DCOR  */
  YYSYMBOL_NUM = 27,                       /* NUM  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_stmts = 30,                     /* stmts  */
  YYSYMBOL_stmt = 31,                      /* stmt  */
  YYSYMBOL_loop = 32,                      /* loop  */
  YYSYMBOL_33_1 = 33,                      /* @1  */
  YYSYMBOL_34_2 = 34,                      /* @2  */
  YYSYMBOL_35_3 = 35,                      /* $@3  */
  YYSYMBOL_36_4 = 36,                      /* @4  */
  YYSYMBOL_37_5 = 37,                      /* @5  */
  YYSYMBOL_38_6 = 38,                      /* $@6  */
  YYSYMBOL_for2 = 39,                      /* for2  */
  YYSYMBOL_cond = 40,                      /* cond  */
  YYSYMBOL_41_7 = 41,                      /* @7  */
  YYSYMBOL_42_8 = 42,                      /* @8  */
  YYSYMBOL_43_9 = 43,                      /* $@9  */
  YYSYMBOL_cond2 = 44,                     /* cond2  */
  YYSYMBOL_45_10 = 45,                     /* $@10  */
  YYSYMBOL_46_11 = 46,                     /* $@11  */
  YYSYMBOL_47_12 = 47,                     /* $@12  */
  YYSYMBOL_io = 48,                        /* io  */
  YYSYMBOL_assig = 49,                     /* assig  */
  YYSYMBOL_50_13 = 50,                     /* $@13  */
  YYSYMBOL_51_14 = 51,                     /* $@14  */
  YYSYMBOL_52_15 = 52,                     /* $@15  */
  YYSYMBOL_53_16 = 53,                     /* $@16  */
  YYSYMBOL_54_17 = 54,                     /* $@17  */
  YYSYMBOL_expr = 55,                      /* expr  */
  YYSYMBOL_expr1 = 56,                     /* expr1  */
  YYSYMBOL_57_18 = 57,                     /* $@18  */
  YYSYMBOL_58_19 = 58,                     /* $@19  */
  YYSYMBOL_mult = 59,                      /* mult  */
  YYSYMBOL_mult1 = 60,                     /* mult1  */
  YYSYMBOL_61_20 = 61,                     /* $@20  */
  YYSYMBOL_62_21 = 62,                     /* $@21  */
  YYSYMBOL_val = 63                        /* val  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   70

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    64,    70,    71,    72,    73,    83,    84,
      82,    88,    90,    91,    92,    87,   102,   105,   118,   119,
     121,   117,   131,   134,   135,   137,   133,   147,   148,   157,
     157,   158,   158,   159,   159,   160,   160,   161,   161,   171,
     179,   179,   180,   180,   181,   190,   200,   200,   201,   201,
     202,   212,   213,   214
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "WHILE", "IF", "ELSE",
  "PRINT", "READ", "DO", "FOR", "FROM", "TO", "BY", "ASIG", "ADD_ASIG",
  "SUB_ASIG", "MUL_ASIG", "DIV_ASIG", "ADD", "SUB", "MUL", "DIV", "IPAREN",
  "DPAREN", "PUNTO_COMA", "ICOR", "DCOR", "NUM", "ID", "$accept", "stmts",
  "stmt", "loop", "@1", "@2", "$@3", "@4", "@5", "$@6", "for2", "cond",
  "@7", "@8", "$@9", "cond2", "$@10", "$@11", "$@12", "io", "assig",
  "$@13", "$@14", "$@15", "$@16", "$@17", "expr", "expr1", "$@18", "$@19",
  "mult", "mult1", "$@20", "$@21", "val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -14,   -12,   -15,   -37,    10,     4,    34,    15,   -37,
     -37,   -37,   -37,   -37,   -12,   -37,   -37,   -37,    -7,     2,
     -37,   -37,    14,   -37,   -37,   -37,   -37,   -37,   -37,    -2,
     -37,    20,   -12,   -12,   -37,   -12,   -12,   -37,    -2,    35,
     -12,   -12,   -12,   -12,   -12,   -37,   -12,   -37,   -37,   -37,
     -37,   -37,    41,   -37,   -37,   -37,   -37,   -37,   -37,    23,
      -7,    -7,     2,     2,    26,   -12,   -37,   -37,   -37,   -37,
     -37,   -12,    38,    25,    28,    27,    -2,   -37,   -37,    29,
     -37,    48,   -37,    31,   -37,    -9,   -37,    30,    36,   -37,
     -37,    37,    -2,    -2,    40,    33,   -37,    -2,   -37,    43,
      44,   -37,   -37
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     8,     0,     0,     0,     3,     4,
       5,     7,     6,    18,     0,    51,    52,    27,    44,    50,
      28,     9,     0,    29,    31,    33,    35,    37,     1,     0,
      19,     0,     0,     0,    39,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     2,     0,    53,    40,    42,
      46,    48,     0,    11,    30,    32,    34,    36,    38,     0,
      44,    44,    50,    50,     0,     0,    20,    41,    43,    47,
      49,     0,     0,     0,     0,     0,     0,    10,    12,     0,
      13,    22,    14,     0,    21,     0,    23,     0,     0,    15,
      24,     0,     0,     0,     0,     0,    25,     0,    16,     0,
       0,    26,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -29,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -13,   -36,   -37,   -37,
       3,   -25,   -37,   -37,     5
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    21,    38,    65,    80,    82,    85,
      89,    10,    30,    46,    73,    84,    90,    93,    99,    11,
      12,    40,    41,    42,    43,    44,    17,    34,    60,    61,
      18,    37,    62,    63,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,    31,     1,    87,     2,     3,     4,     5,    13,    52,
      14,    32,    33,    20,    88,    15,    16,    23,    24,    25,
      26,    27,    35,    36,    67,    68,     6,    54,    55,    56,
      57,    58,    22,    59,    28,    48,    49,    69,    70,    29,
      50,    51,    39,    47,    64,    53,    66,    79,    71,    75,
      76,    77,    72,    83,    78,    81,    86,    91,    74,    98,
      94,    92,     0,    95,    96,    97,     0,     0,   100,   101,
     102
};

static const yytype_int8 yycheck[] =
{
      29,    14,     4,    12,     6,     7,     8,     9,    22,    38,
      22,    18,    19,    28,    23,    27,    28,    13,    14,    15,
      16,    17,    20,    21,    60,    61,    28,    40,    41,    42,
      43,    44,    22,    46,     0,    32,    33,    62,    63,    24,
      35,    36,    28,    23,     3,    10,    23,    76,    22,    11,
      25,    23,    65,     5,    27,    26,    25,    27,    71,    26,
      23,    25,    -1,    92,    93,    25,    -1,    -1,    97,    26,
      26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     6,     7,     8,     9,    28,    30,    31,    32,
      40,    48,    49,    22,    22,    27,    28,    55,    59,    63,
      28,    33,    22,    13,    14,    15,    16,    17,     0,    24,
      41,    55,    18,    19,    56,    20,    21,    60,    34,    28,
      50,    51,    52,    53,    54,    30,    42,    23,    59,    59,
      63,    63,    30,    10,    55,    55,    55,    55,    55,    55,
      57,    58,    61,    62,     3,    35,    23,    56,    56,    60,
      60,    22,    55,    43,    55,    11,    25,    23,    27,    30,
      36,    26,    37,     5,    44,    38,    25,    12,    23,    39,
      45,    27,    25,    46,    23,    30,    30,    25,    26,    47,
      30,    26,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    31,    31,    33,    34,
      32,    35,    36,    37,    38,    32,    39,    39,    41,    42,
      43,    40,    44,    45,    46,    47,    44,    48,    48,    50,
      49,    51,    49,    52,    49,    53,    49,    54,    49,    55,
      57,    56,    58,    56,    56,    59,    61,    60,    62,    60,
      60,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     1,     1,     1,     1,     0,     0,
       8,     0,     0,     0,     0,    12,     4,     6,     0,     0,
       0,    11,     0,     0,     0,     0,     7,     2,     2,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     2,
       0,     4,     0,     4,     0,     2,     0,     4,     0,     4,
       0,     1,     1,     3
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* @1: %empty  */
#line 83 "A_sintactico2.y"
    { (yyval.lbl) = obtenerSiguienteLBL();  printf("LBL%d:\n", (yyval.lbl)); }
#line 1315 "y.tab.c"
    break;

  case 9: /* @2: %empty  */
#line 84 "A_sintactico2.y"
    { (yyval.lbl) = obtenerSiguienteLBL(); }
#line 1321 "y.tab.c"
    break;

  case 10: /* loop: DO @1 @2 stmts WHILE IPAREN expr DPAREN  */
#line 86 "A_sintactico2.y"
    { printf("\tsifalsovea LBL%d\n", (yyvsp[-5].lbl)); printf("\tvea LBL%d\n", (yyvsp[-6].lbl)); printf("LBL%d:\n", (yyvsp[-5].lbl)); }
#line 1327 "y.tab.c"
    break;

  case 11: /* $@3: %empty  */
#line 88 "A_sintactico2.y"
    {printf("\tvalori %s\n", (yyvsp[-1].str));}
#line 1333 "y.tab.c"
    break;

  case 12: /* @4: %empty  */
#line 90 "A_sintactico2.y"
    { (yyval.lbl) = obtenerSiguienteLBL(); }
#line 1339 "y.tab.c"
    break;

  case 13: /* @5: %empty  */
#line 91 "A_sintactico2.y"
    { (yyval.lbl) = obtenerSiguienteLBL();}
#line 1345 "y.tab.c"
    break;

  case 14: /* $@6: %empty  */
#line 92 "A_sintactico2.y"
    { printf("\tasigna\nLBL%d:\n", (yyvsp[-1].lbl)); }
#line 1351 "y.tab.c"
    break;

  case 16: /* for2: DPAREN ICOR stmts DCOR  */
#line 103 "A_sintactico2.y"
    { printf("\tvalorid %s\n\tvalord %s\n\tmete 1\n\tadd\n\tasigna\n\tmete %d\n\tvalord %s\n\tsub\n\tsifalsovea LBL%d\n\tvea LBL%d\nLBL%d:\n", (yyvsp[(-8) - (4)].str),(yyvsp[(-8) - (4)].str),(yyvsp[(-3) - (4)].num),(yyvsp[(-8) - (4)].str),(yyvsp[(-1) - (4)].lbl), (yyvsp[(-2) - (4)].lbl),(yyvsp[(-1) - (4)].lbl)); }
#line 1357 "y.tab.c"
    break;

  case 17: /* for2: BY NUM DPAREN ICOR stmts DCOR  */
#line 106 "A_sintactico2.y"
        { printf("\tvalori %s\n\tvalord %s\n\tmete %d\n\tadd\n\tasigna\n\tmete %d\n\tvalord %s\n\tsub\n\tsifalsovea LBL%d\n\tvea LBL%d\nLBL%d:\n", (yyvsp[(-8) - (6)].str),(yyvsp[(-8) - (6)].str),(yyvsp[-4].num),(yyvsp[(-3) - (6)].num),(yyvsp[(-8) - (6)].str),(yyvsp[(-1) - (6)].lbl), (yyvsp[(-2) - (6)].lbl),(yyvsp[(-1) - (6)].lbl)); }
#line 1363 "y.tab.c"
    break;

  case 18: /* @7: %empty  */
#line 118 "A_sintactico2.y"
    { (yyval.lbl) = obtenerSiguienteLBL(); }
#line 1369 "y.tab.c"
    break;

  case 19: /* @8: %empty  */
#line 119 "A_sintactico2.y"
    { (yyval.lbl) = obtenerSiguienteLBL(); }
#line 1375 "y.tab.c"
    break;

  case 20: /* $@9: %empty  */
#line 121 "A_sintactico2.y"
    { printf("\tsifalsovea LBL%d\n", (yyvsp[-3].lbl)); }
#line 1381 "y.tab.c"
    break;

  case 22: /* cond2: %empty  */
#line 131 "A_sintactico2.y"
    { printf("LBL%d:\n", (yyvsp[(-7) - (0)].lbl)); }
#line 1387 "y.tab.c"
    break;

  case 23: /* $@10: %empty  */
#line 134 "A_sintactico2.y"
    { printf("\tvea LBL%d\n",(yyvsp[(-6) - (2)].lbl)); }
#line 1393 "y.tab.c"
    break;

  case 24: /* $@11: %empty  */
#line 135 "A_sintactico2.y"
    { printf("LBL%d:\n", (yyvsp[(-7) - (3)].lbl)); }
#line 1399 "y.tab.c"
    break;

  case 25: /* $@12: %empty  */
#line 137 "A_sintactico2.y"
    { printf("LBL%d:\n", (yyvsp[(-6) - (5)].lbl)); }
#line 1405 "y.tab.c"
    break;

  case 27: /* io: PRINT expr  */
#line 147 "A_sintactico2.y"
               {printf("\tprint\n");}
#line 1411 "y.tab.c"
    break;

  case 28: /* io: READ ID  */
#line 148 "A_sintactico2.y"
              {printf("\tread %s\n", (yyvsp[0].str));}
#line 1417 "y.tab.c"
    break;

  case 29: /* $@13: %empty  */
#line 157 "A_sintactico2.y"
            { printf("\tvalori %s\n", (yyvsp[-1].str)); }
#line 1423 "y.tab.c"
    break;

  case 30: /* assig: ID ASIG $@13 expr  */
#line 157 "A_sintactico2.y"
                                                  { printf("\tasigna\n"); }
#line 1429 "y.tab.c"
    break;

  case 31: /* $@14: %empty  */
#line 158 "A_sintactico2.y"
                  { printf("\tvalori %s\n\tvalord %s\n", (yyvsp[-1].str), (yyvsp[-1].str)); }
#line 1435 "y.tab.c"
    break;

  case 32: /* assig: ID ADD_ASIG $@14 expr  */
#line 158 "A_sintactico2.y"
                                                                         { printf("\tadd\n\tasigna\n"); }
#line 1441 "y.tab.c"
    break;

  case 33: /* $@15: %empty  */
#line 159 "A_sintactico2.y"
                  { printf("\tvalori %s\n\tvalord %s\n", (yyvsp[-1].str), (yyvsp[-1].str)); }
#line 1447 "y.tab.c"
    break;

  case 34: /* assig: ID SUB_ASIG $@15 expr  */
#line 159 "A_sintactico2.y"
                                                                         { printf("\tsub\n\tasigna\n"); }
#line 1453 "y.tab.c"
    break;

  case 35: /* $@16: %empty  */
#line 160 "A_sintactico2.y"
                  { printf("\tvalori %s\n\tvalord %s\n", (yyvsp[-1].str), (yyvsp[-1].str)); }
#line 1459 "y.tab.c"
    break;

  case 36: /* assig: ID MUL_ASIG $@16 expr  */
#line 160 "A_sintactico2.y"
                                                                         { printf("\tmul\n\tasigna\n"); }
#line 1465 "y.tab.c"
    break;

  case 37: /* $@17: %empty  */
#line 161 "A_sintactico2.y"
                  { printf("\tvalori %s\n\tvalord %s\n", (yyvsp[-1].str), (yyvsp[-1].str)); }
#line 1471 "y.tab.c"
    break;

  case 38: /* assig: ID DIV_ASIG $@17 expr  */
#line 161 "A_sintactico2.y"
                                                                         { printf("\tdiv\n\tasigna\n"); }
#line 1477 "y.tab.c"
    break;

  case 40: /* $@18: %empty  */
#line 179 "A_sintactico2.y"
             { printf("\tadd\n"); }
#line 1483 "y.tab.c"
    break;

  case 42: /* $@19: %empty  */
#line 180 "A_sintactico2.y"
               { printf("\tsub\n"); }
#line 1489 "y.tab.c"
    break;

  case 46: /* $@20: %empty  */
#line 200 "A_sintactico2.y"
             { printf("\tmul\n"); }
#line 1495 "y.tab.c"
    break;

  case 48: /* $@21: %empty  */
#line 201 "A_sintactico2.y"
               { printf("\tdiv\n"); }
#line 1501 "y.tab.c"
    break;

  case 51: /* val: NUM  */
#line 212 "A_sintactico2.y"
                {printf("\tmete %d\n", (yyvsp[0].num));}
#line 1507 "y.tab.c"
    break;

  case 52: /* val: ID  */
#line 213 "A_sintactico2.y"
                {printf("\tvalord %s\n", (yyvsp[0].str));}
#line 1513 "y.tab.c"
    break;


#line 1517 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 217 "A_sintactico2.y"


/* Separador de sección */

/* FUNCIÓN MAIN
 * Descripción: Punto de entrada principal del programa.
 * Comportamiento: Evalúa si se abre un fichero o se lee desde el terminal.
 *                Si hay un fichero, lo abre y lo procesa; de lo contrario, lee desde el terminal.
 */
int main( int argc, char *argv[] ){
        
	if (argc > 1){ //Condición if que evalua si se abre un fichero o por el terminal
		extern FILE *yyin;
		++argv;
		yyin = fopen( argv[0], "r" ); //Abre el fichero en modo lectura
		if(!yyin) { //Condición if que evalua si se abre correctamente el fichero
			fprintf(stderr, "Ha ocurrido un error al intentar abrir el fichero. %s\n", argv[1]);
			exit(1);
		}
		yyparse();
		printf("\n");
	}else{
	        yyparse ();
	        printf("\n");
	        return 0;
        }
}



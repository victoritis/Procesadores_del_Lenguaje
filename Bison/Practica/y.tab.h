/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 9 "A_sintactico.y"

    int num; // Para números
    char* str; // Para cadenas/identificadores

#line 128 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

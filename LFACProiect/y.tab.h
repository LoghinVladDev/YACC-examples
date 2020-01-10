/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 31 "SyntaxAnalyser.y" /* yacc.c:1909  */

    int intVal;
    float floatVal;
    char* stringVal;
    struct variable* var;
    struct variable** vars;
    struct value* val;

#line 143 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

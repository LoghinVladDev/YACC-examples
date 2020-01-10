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
    ID = 258,
    STRING = 259,
    VARIABLE = 260,
    STRVAL = 261,
    NR = 262,
    MAIN = 263,
    ENDMAIN = 264,
    IF = 265,
    THEN = 266,
    ENDIF = 267,
    ELSE = 268,
    WHILE = 269,
    ENDWHILE = 270,
    FOR = 271,
    ENDFOR = 272,
    EVAL = 273,
    GEQ = 274,
    EQ = 275,
    LEQ = 276,
    NEQ = 277
  };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define VARIABLE 260
#define STRVAL 261
#define NR 262
#define MAIN 263
#define ENDMAIN 264
#define IF 265
#define THEN 266
#define ENDIF 267
#define ELSE 268
#define WHILE 269
#define ENDWHILE 270
#define FOR 271
#define ENDFOR 272
#define EVAL 273
#define GEQ 274
#define EQ 275
#define LEQ 276
#define NEQ 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

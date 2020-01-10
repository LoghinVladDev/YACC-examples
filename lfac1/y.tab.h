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
    STRING = 258,
    VARIABLE = 259,
    MAIN = 260,
    ENDMAIN = 261,
    IF = 262,
    THEN = 263,
    ENDIF = 264,
    ELSE = 265,
    WHILE = 266,
    ENDWHILE = 267,
    FOR = 268,
    ENDFOR = 269,
    EVAL = 270,
    GEQ = 271,
    EQ = 272,
    LEQ = 273,
    FUNCTION = 274,
    RETURN = 275,
    NR = 276,
    NRF = 277,
    ID = 278,
    STRVAL = 279,
    NEQ = 280
  };
#endif
/* Tokens.  */
#define STRING 258
#define VARIABLE 259
#define MAIN 260
#define ENDMAIN 261
#define IF 262
#define THEN 263
#define ENDIF 264
#define ELSE 265
#define WHILE 266
#define ENDWHILE 267
#define FOR 268
#define ENDFOR 269
#define EVAL 270
#define GEQ 271
#define EQ 272
#define LEQ 273
#define FUNCTION 274
#define RETURN 275
#define NR 276
#define NRF 277
#define ID 278
#define STRVAL 279
#define NEQ 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "ex1.y" /* yacc.c:1909  */

	int value;
	float floatValue;
	struct variable* var;
	struct variable** vars;
	struct rez_expresie* expr;
	char *varString;

#line 113 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

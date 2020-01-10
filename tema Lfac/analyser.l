%{
    #include <stdio.h>
    #include "y.tab.h"
    #include "defHeader.h"
%}
%option noyywrap
%%
"/*"(.|\n)+"*/" ;
"start" {return MAIN;}
"int"|"float"|"char"|"bool" { yylval.typeString = strdup(yytext); return VARTYPE;}
[a-zA-Z]+[A-Za-z0-9]* { yylval.varString = strdup(yytext); return ID; }
0|[1-9][0-9]* {return NR;}
[ \t] ;
[\n] {yylineno++;}
. {return yytext[0];}
%%
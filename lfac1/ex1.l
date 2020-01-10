%{
#include <stdio.h>
#include "y.tab.h"
#include<string.h>
%}
%option noyywrap

%option yylineno
%%

main {return MAIN;}
endmain {return ENDMAIN;}
var {return VARIABLE;}
function {return FUNCTION;}
string {return STRING;}
send { return RETURN; }
Eval {return EVAL;}
then {return THEN;}

if {return IF;}
else {return ELSE;}
endif {return ENDIF;}

while {return WHILE;}
endwhile {return ENDWHILE;}

for {return FOR;}
endfor {return ENDFOR;}

[a-zA-Z][a-zA-Z]*  { yylval.varString = strdup(yytext);  return ID;}
"-"?[0-9]+"."[0-9]+ { yylval.floatValue = atof(yytext); return NRF; }
"-"?[0-9]+ { yylval.value = atoi(yytext);return NR; }
'[a-zA-Z][a-zA-Z0-9]*'  { yylval.varString = strdup(yytext); return STRVAL;}
[ \t\f]+ ;
"\r\n"|"\n" {}


">=" { return GEQ; }
"==" { return EQ; }
"<=" { return LEQ; }
"!=" { return NEQ; }

. {return yytext[0];}

%%

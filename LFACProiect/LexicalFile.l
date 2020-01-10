%{
    #include <stdio.h>
    #include "y.tab.h"
    #include <string.h>
%}
%option yylineno
%option noyywrap
%%
thisItem {return THISOBJ; }
main { return MAIN; }
method { return FUNCTION; }
"integer"|"float"|"bool"|"char"|"string"|"double" { yylval.stringVal = strdup(yytext); return VARTYPE; }
as { return AS; }
public { return PUBLIC; }
private { return PRIVATE; }
item { return CLASS; }
result {return RETURN;}
eval {return EVAL;}

if {return IF;}
then {return THEN;}
else {return ELSE;}
endif {return ENDIF;}

while {return WHILE;}
do { return DO;}
endwhile {return ENDWHILE;}

for {return FOR;}
endfor {return ENDFOR;}

get {return GET;}
show {return SHOW;}

"@" { return POINTER; }
"#" { return DEREFERENCE; }

"<-" { return ASSIGN; }

">=" { return GREQ; }
"<=" { return LEEQ;}
"=" { return EQ; }
"!=" { return NEQ; }

"&&" { return AND; }
"||" { return OR; }
"!"  { return NOT; }
"^^" { return XOR; }

"++" { return INC; }
"--" { return DEC; }

[a-zA-Z0-9]*[a-zA-Z][a-zA-Z0-9]* { yylval.stringVal = strdup(yytext); return ID; }
"0"|[1-9][0-9]*"."[0-9]+ {  yylval.floatVal = atof(yytext); return NRF;}
"0"|[1-9][0-9]* {yylval.intVal = atoi(yytext);  return NR;} 
'[a-zA-Z0-9]+' {yylval.stringVal = strdup(yytext); return STRING;}

[ \t\f] ;
"\r\n"|"\n" ;

. {return yytext[0];}

%%
yacc SyntaxAnalyser.y -d
flex LexicalFile.l
cc lex.yy.c y.tab.c -ll

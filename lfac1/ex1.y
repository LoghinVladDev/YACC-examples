%{
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include <errno.h>
extern FILE* yyin;
extern int yylineno;

struct variable v[1000];
int vLength = 0;

int varsVectorLength = 0;
int existsVariable(char *, char*);
void addToVariables(char *variableName, int varType, char*stringVal, float varVal , char* varScope);
struct variable getFunctionVar(char*, int, int, float, char*);
struct variable** getNewVarsVector(struct variable**, int, struct variable*);
void addVectorToVariables(struct variable** , int , char*);
struct variable getVariable(char *name);

void printVarsVect(struct variable**);

%}

%union
{
	int value;
	float floatValue;
	struct variable* var;
	struct variable** vars;
	struct rez_expresie* expr;
	char *varString;
}

%token STRING VARIABLE MAIN ENDMAIN IF THEN ENDIF ELSE WHILE ENDWHILE FOR ENDFOR EVAL
%token GEQ EQ LEQ FUNCTION RETURN

%token <value> NR
%token <floatValue> NRF
%token <varString> ID
%token <varString> STRVAL

%type <expr> expresieEval

%type <var> variableFunction
%type <vars> variablesFunction	
%type <expr> valoare

%left '+'
%left '-'
%left '*'
%left '/'
%left '^'
%left '>'
%left '<'

%left GEQ
%left LEQ
%left EQ
%left NEQ

%start start


%%

start: declarari main  
		{ 
			printf("Gata\n");
		}
	  ;

declarari: declarari declarare 
	| 		declarare 

declarare: VARIABLE variables ';'
	|       STRING stringVariables ';'
	|		VARIABLE functionDeclaration
	|		STRING functionDeclarationString
	;

functionDeclaration: FUNCTION ID '(' variablesFunction ')' '{' instructiuniFunctie '}' 
		{ 
			//printVarsVect($4);
			addVectorToVariables($4, varsVectorLength, $2);
			if(existsVariable($2,"global"))
				yyerror("Function/Variable previously declared");
			addToVariables($2, FunctionVar, NULL, 0, "global");
		}

functionDeclarationString: FUNCTION ID '(' variablesFunction ')' '{' instructiuniFunctie '}'
		{
			//printVarsVect($4);
			addVectorToVariables($4, varsVectorLength, $2);
			if(existsVariable($2, "global"))
				yyerror("Function/Variable previously declared");
			addToVariables($2, FunctionString, NULL, 0, "global");
		}

variablesFunction: variablesFunction ',' variableFunction { $$ = getNewVarsVector($1,varsVectorLength, $3);  varsVectorLength++;}
	|				variableFunction { varsVectorLength = 0; $$ = getNewVarsVector(NULL,varsVectorLength, $1); varsVectorLength++; 
					}
	;

variableFunction: VARIABLE ID  { $$ = (struct variable*)malloc(sizeof(struct variable));
								*$$ = getFunctionVar($2, Int, 0, 0, NULL); 
								}
	|			   VARIABLE ID '=' NR  { 
								 $$ = (struct variable*)malloc(sizeof(struct variable));
								*$$ = getFunctionVar($2, Int, $4,0 ,NULL); }
	|			   VARIABLE ID '=' NRF {
								 $$ = (struct variable*)malloc(sizeof(struct variable));
								*$$ = getFunctionVar($2, Float, 0, $4, NULL); }
	|			   STRING ID {    $$ = (struct variable*)malloc(sizeof(struct variable));
								*$$ = getFunctionVar($2, String, 0, 0, NULL); }
	|			   STRING ID '=' STRVAL {
								$$ = (struct variable*)malloc(sizeof(struct variable)); 
								*$$ = getFunctionVar($2, String, 0, 0, $4); }
	;

variables: variables ',' variable
	|  		variable 
	;

variable: ID '=' NR
			{
				if(existsVariable($1,"global") == 0)
					 	addToVariables($1, Int, NULL, $3, "global");
			}
	|	 ID '=' NRF
	     	{
				if(existsVariable($1, "global") == 0)
					addToVariables($1, Float, NULL, $3, "global");
			}
	|	   ID 
			{
				if(existsVariable($1, "global") == 0)
					 	addToVariables($1, Int, NULL, 0, "global");
			}
	;

stringVariables: stringVariables ',' stringVariable
	| 		stringVariable
	;

stringVariable: ID '=' STRVAL  
				 { 
					 if(existsVariable($1, "global") == 0)
					 	addToVariables($1, String, $3, 0, "global");
 				 }
	| 			 ID 
				 { 
					 if(existsVariable($1, "global") == 0)
						addToVariables($1,String, NULL, 0, "global");
				 }
	;

main: MAIN '{' instructiuni '}' ENDMAIN
	;

instructiuni: instructiuni instructiune 
	| 		   instructiune 
	;

instructiune: ID '=' expresie ';'
	|		   apelFunctie ';'
	|		   IF '(' expresie ')' instructiuni	ENDIF
	|		   IF '(' expresie ')' instructiuni ELSE instructiuni ENDIF
	|		   WHILE '(' expresie ')' THEN  instructiuni ENDWHILE
	|		   FOR '(' setValoriFor ')' THEN instructiuni ENDFOR
	|		   EVAL '(' expresieEval ')' ';' { if($3->tip == Int)
												printf("Eval result : %d\n", $3->intVal);
											   if($3->tip == Float)
											   	printf("Eval result : %f\n", $3->floatVal); 
												if($3->tip == String)
												printf("Eval result : %s\n", $3->stringVal); }
	;

instructiuniFunctie: instructiuniFunctie instructiuneFunctie
	|		  		  instructiuneFunctie

instructiuneFunctie: ID '=' expresie ';'
	|		   apelFunctie ';'
	|		   IF '(' expresie ')' instructiuni	ENDIF
	|		   IF '(' expresie ')' instructiuni ELSE instructiuni ENDIF
	|		   WHILE '(' expresie ')' THEN  instructiuni ENDWHILE
	|		   FOR '(' setValoriFor ')' THEN instructiuni ENDFOR
	|		   EVAL '(' expresieEval ')' ';' { }
	|		   RETURN ID ';'
	;

expresieEval : expresieEval '+' expresieEval { //if ( $1->tip != $3->tip ) 
													//yyerror("Cannot assign type left to type right"); 
												 if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal + $3->intVal;}
												else if ( $1->tip == Float) {$$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Float;
																			$$->floatVal = $1->floatVal + $3->floatVal;}
												else if ( $1->tip == String) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																			$$->tip = String;
																			strcpy($$->stringVal, strcat($1->stringVal, $3->stringVal));}} 
	|		   expresieEval '-' expresieEval {  if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal - $3->intVal;}
												else if ( $1->tip == Float) {$$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Float;
																			$$->floatVal = $1->floatVal - $3->floatVal;}
												else if ( $1->tip == String) yyerror("Undefined Operation for String type");  }
	| 		   expresieEval '*' expresieEval {  if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal * $3->intVal;}
												else if ( $1->tip == Float) { $$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Float;
																			$$->floatVal = $1->floatVal * $3->floatVal;}
												else if ( $1->tip == String) yyerror("Undefined Operation for String type");  }
	| 	   	   expresieEval '/' expresieEval {  if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal / $3->intVal;}
												else if ( $1->tip == Float) { $$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Float;
																			$$->floatVal = $1->floatVal / $3->floatVal;}
												else if ( $1->tip == String) yyerror("Undefined Operation for String type");  }
	|	       expresieEval '^' expresieEval {  if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = 1;
																		  for( int i = 0; i< $3->intVal; i++)
																		  		$$->intVal *= $1->intVal; }
												else if ( $1->tip == Float) yyerror("Cannot assign power to float"); 
												else if ( $1->tip == String){$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																			$$->tip = String;
																			strcpy($$->stringVal, strcat($1->stringVal, $3->stringVal));  }}
	|	       expresieEval '<' expresieEval { if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal < $3->intVal;}
												else if ( $1->tip == Float) { $$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			$$->intVal = $1->floatVal < $3->floatVal;}
												else if ( $1->tip == String) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			if(strcmp($1->stringVal, $3->stringVal) < 0)
																				$$->intVal = 1;
																				else $$->intVal = 0;  }}
	|	       expresieEval '>' expresieEval {  if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal > $3->intVal;}
												else if ( $1->tip == Float) { $$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			$$->intVal = $1->floatVal > $3->floatVal;}
												else if ( $1->tip == String) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			if(strcmp($1->stringVal, $3->stringVal) > 0)
																				$$->intVal = 1;
																				else $$->intVal = 0;  }}
	|	       expresieEval LEQ expresieEval { if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal <= $3->intVal;}
												else if ( $1->tip == Float) { $$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			$$->intVal = $1->floatVal <= $3->floatVal;}
												else if ( $1->tip == String) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			if(strcmp($1->stringVal, $3->stringVal) <= 0)
																				$$->intVal = 1;
																				else $$->intVal = 0; } }
	| 	       expresieEval EQ expresieEval { if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal == $3->intVal;}
												else if ( $1->tip == Float) { $$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			$$->intVal = $1->floatVal == $3->floatVal;}
												else if ( $1->tip == String) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			if(strcmp($1->stringVal, $3->stringVal) == 0)
																				$$->intVal = 1;
																				else $$->intVal = 0;  }}
	|	       expresieEval GEQ expresieEval {  if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right"); 
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal >= $3->intVal;}
												else if ( $1->tip == Float) { $$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			$$->intVal = $1->floatVal >= $3->floatVal;}
												else if ( $1->tip == String) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			if(strcmp($1->stringVal, $3->stringVal) >= 0)
																				$$->intVal = 1;
																				else $$->intVal = 0; } }
	|	       expresieEval NEQ expresieEval { if ( $1->tip != $3->tip ) yyerror("Cannot assign type left to type right");
												else if ( $1->tip == Int) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																		  $$->tip = Int;
																		  $$->intVal = $1->intVal != $3->intVal;}
												else if ( $1->tip == Float) { $$ = (struct rez_expresie*) malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			$$->intVal = $1->floatVal != $3->floatVal;}
												else if ( $1->tip == String) {$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
																			$$->tip = Int;
																			if(strcmp($1->stringVal, $3->stringVal))
																				$$->intVal = 1;
																				else $$->intVal = 0; } }
	|	       valoare  { $$ = $1; }
	;

setValoriFor: instructiuneFor ',' expresie ',' instructiuneFor
	;

instructiuneFor: ID '=' expresie 
	;

expresie: expresie '+' expresie { }
	|      expresie '-' expresie { }
	|	   expresie '*' expresie { }
	| 	   expresie '/' expresie { }
	|	   expresie '^' expresie { }
	|	   expresie '<' expresie { }
	|	   expresie '>' expresie { }
	|	   expresie LEQ expresie { }
	| 	   expresie EQ expresie { }
	|	   expresie GEQ expresie { }
	|	   expresie NEQ expresie { }
	|	   valoare  { }
	;

apelFunctie: ID '(' parametriiApel ')'
	;

parametriiApel: parametriiApel ',' expresie 
	|		     expresie
	;

valoare: ID { $$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
				struct variable currentVar = getVariable($1);
				$$->tip = currentVar.tip;
				if(currentVar.tip == Int) $$->intVal = currentVar.intValue;
				if(currentVar.tip == Float) $$->floatVal = currentVar.floatValue;
				if(currentVar.tip == String) strcpy($$->stringVal, currentVar.stringValue);
			 }
	|     NR { 
			$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
			$$->tip = Int;
			$$->intVal = $1;
	 } 
	|	  NRF { 
			$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
			$$->tip = Float;
			$$->floatVal = $1;
	}
	|	  STRVAL { 
			$$ = (struct rez_expresie*)malloc(sizeof(struct rez_expresie));
			$$->tip = String;
			strcpy($$->stringVal, $1);
	}
 	|	  apelFunctie { /*nu inca*/ }
	;

%%

struct variable getVariable(char *name)
{
	for( int i = 0; i < vLength; i++)
		if ( ! strcmp( v[i].nume, name ) == 0)
			return v[i];
}

void printVarsVect(struct variable** v)
{
	for(int i = 0; i < varsVectorLength; i++)
		printf("%s %d\n", " aaa ", v[i]->tip);
}

struct variable** getNewVarsVector(struct variable** oldVector, int oldSize, struct variable* addedVar)
{
	struct variable** newVector = (struct variable**) malloc(sizeof(size_t) * (oldSize+1));

	for(int i = 0; i < oldSize; i++)
	{	
		newVector[i] = (struct variable*)malloc(sizeof(struct variable));
		*newVector[i] = *oldVector[i];
	}
	

	newVector[oldSize] = (struct variable*)malloc(sizeof(struct variable));
	*newVector[oldSize++] = *addedVar;
	

	if(oldVector) 
		free(oldVector);
	return newVector;	
}

struct variable getFunctionVar(char* name, int type, int intVal, float floatVal, char* stringVal)
{
	struct variable ret;


	strcpy(ret.nume, name);
	ret.tip = type;
	ret.intValue = intVal;
	ret.floatValue = floatVal;
	if(stringVal)
		strcpy(ret.stringValue, stringVal);


	return ret;
}

int existsVariable(char * variableString, char* scope)
{
	fflush(stdout);
	for(int i = 0; i < vLength; i++)
		if( !strcmp(v[i].nume, variableString) && !strcmp(v[i].scope, scope) )
			{
				return 1;
			}
	return 0;
}

void addVectorToVariables(struct variable** vars, int varsVectorLength, char *varsScope)
{
	for(int i = 0; i <varsVectorLength; i++)
		if( existsVariable (vars[i]->nume, varsScope ) ==0 )
			if( vars[i]->tip == Float ) {
				addToVariables( vars[i]->nume, vars[i]->tip, vars[i]->stringValue,
				vars[i]->floatValue, varsScope ); }
			else 
				{
				addToVariables( vars[i]->nume, vars[i]->tip, vars[i]->stringValue,
				vars[i]->intValue, varsScope );
				}
}

void addToVariables(char *variableName, int varType, char*stringVal, float varVal, char* scope)
{
	if( varType == Int )
	{
		if(varVal != (int)varVal )
			varType = Float;
	}
	strcpy ( v[vLength].nume , variableName );
	v[vLength].tip = varType;
	strcpy ( v[vLength].scope, scope );
	if( varType == String )
	if(stringVal)
		strcpy( v[vLength].stringValue, stringVal );

	if( varType == Int )
		v[vLength].intValue = varVal;
	
	if( varType == Float )
		v[vLength].floatValue = varVal;
	vLength++;
 }

void printValues()
{

	for ( int i = 0; i < vLength; i++ )
	{
		if(v[i].tip == String)
			printf("Variable %s is %s and has a value of %s, declared in scope %s\n", v[i].nume, "string", v[i].stringValue, v[i].scope);
		if(v[i].tip == Float)
			printf("Variable %s is %s and has a value of %f, declared in scope %s\n", v[i].nume, "float", v[i].floatValue,v[i].scope);
		if(v[i].tip == Int)
			printf("Variable %s is %s and has a value of %d, declared in scope %s\n", v[i].nume, "int", v[i].intValue, v[i].scope);	
	}
}


int yyerror(char * s){
	printf("\n Eroare la linia: %d '%s'. \n",yylineno,s);
}

int main(int argc, char** argv){
	yyin=fopen(argv[1],"r");
	yyparse();
	printValues();
}

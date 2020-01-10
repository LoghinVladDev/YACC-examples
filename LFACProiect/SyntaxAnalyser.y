%{
    #include <stdio.h>
    #include <string.h>
    #include "external.h"
    #include <errno.h>
    #include <stdlib.h>

    extern FILE* yyin;
    extern int yylineno;

    int numberOfVariables = 0;
    struct variable* allVars[1000];

    int hasMain = 0;

    void printVariableVector(struct variable**, int);
    void assignVarTypes(struct variable**, int , char*,char*);
    void assignVarTypesAddress(struct variable**, int,char*,char*, int);
    void addToAllVariables(struct variable** ,int);
    void printAllVariables();
    int variableExists(struct variable*, char*);
    void eval(struct value*);
    struct value* getVar(char*, char*);


    int lengthOfVariableVector;
    struct variable** createVariableVector(struct variable**, struct variable*, int);
%}

%union
{
    int intVal;
    float floatVal;
    char* stringVal;
    struct variable* var;
    struct variable** vars;
    struct value* val;
}

%token <intVal> NR
%token <floatVal> NRF
%token <stringVal> STRING
%token <stringVal> ID
%token <stringVal> VARTYPE

%token THISOBJ
%token GET SHOW EVAL
%token MAIN FUNCTION AS PUBLIC PRIVATE CLASS RETURN
%token POINTER DEREFERENCE
%token ASSIGN INC DEC
%token GREQ LEEQ NEQ EQ AND OR NOT XOR

%token IF THEN ELSE ENDIF WHILE DO ENDWHILE FOR ENDFOR

%left GREQ LEEQ NEQ EQ AND OR XOR
%left '+' '-' '*' '/' '%' '^' '<' '>'

%right ASSIGN

%type <var> variableDeclaration
%type <vars> variableDeclarations
%type <intVal> spanSet
%type <val> value
%type <intVal> addressSet
%type <val> expression
%type <val> variable

%start start
%%

start: 
        instructionBlocks
        {
            printf("Syntax analysis complete!\n");
        }
        ;

instructionBlocks: 
        instructionBlocks instructionBlock
    |   instructionBlock
    ;

instructionBlock:
        declarationSet
    |   functionDefinition
    ;

declarationSet:
        variableDeclarationSet ';'
    |   functionDeclaration ';'
    |   classDeclaration 
    ; 

variableDeclarationSet:
        VARTYPE  addressSet ':' variableDeclarations
        { 
            assignVarTypesAddress($4, lengthOfVariableVector, "global", $1, $2);
            //printVariableVector($4, lengthOfVariableVector);
            addToAllVariables($4, lengthOfVariableVector);
        }
    |   VARTYPE ':' variableDeclarations 
        { 
            assignVarTypes($3, lengthOfVariableVector,"global",  $1); 
            //printVariableVector($3, lengthOfVariableVector);
            addToAllVariables($3, lengthOfVariableVector);
        }
    ;

variableDeclarations: 
        variableDeclarations ',' variableDeclaration
        {
            if( variableExists ( $3 , "global" ) == 0 )
                $$ = createVariableVector($1, $3, lengthOfVariableVector++);
            else
            {
                yyerror("Variable already exists");
                $$ = $1;
            }
        }
    |   variableDeclaration
        { 
            lengthOfVariableVector = 0;
            if( variableExists( $1, "global") == 1 )
            {
                yyerror("Variable already declared");
            }
            else 
            {
                /*printf("%s %d, %d %f %s\n", $1->name, $1->type, $1->intVal, $1->floatVal, $1->stringVal); */
                $$ = createVariableVector(NULL, $1, lengthOfVariableVector++);
            }
        }
    ;

variableDeclaration:
        ID
        {  
            $$ = (struct variable*)malloc(sizeof(struct variable));
            strcpy($$->name, $1);
            $$->depth = 0;
        }
    |   ID ASSIGN value 
        {
            if($3->type == Int)
            {
                $$ = (struct variable*)malloc(sizeof(struct variable));
                $$->type = Int;
                $$->intVal = $3->intVal;
                strcpy($$->name, $1);
                $$->depth = 0;
            }
            if($3->type == Float)
            {
                $$ = (struct variable*)malloc(sizeof(struct variable));
                $$->type = Float;
                $$->floatVal = $3->floatVal;
                strcpy($$->name, $1);
                $$->depth = 0;
            }
            if($3->type == String)
            {
                $$ = (struct variable*)malloc(sizeof(struct variable));
                $$->type = String;
                strcpy($$->stringVal, $3->stringVal);
                strcpy($$->name, $1);
                $$->depth = 0;
            }
        }
    |   ID '{' spanSet '}'
        {
            $$ = (struct variable*)malloc(sizeof(struct variable));
            $$->depth = $3;
            strcpy($$->name, $1);
        }
    ;

value:
        NR 
        { 
            $$ = (struct value*)malloc(sizeof(struct value));
            $$->type = Int;
            $$->intVal = $1;
        }
    |   NRF 
        { 
            $$ =  (struct value*)malloc(sizeof(struct value));
            $$->type = Float;
            $$->floatVal = $1;
        }
    |   STRING  
        {
            $$ =  (struct value*)malloc(sizeof(struct value));
            $$->type = String;
            strcpy($$->stringVal, $1);
        }
    ;

spanSet: 
        spanSet ',' NR {$$ = $1 + 1;}
    |   NR {$$ = 1;}
    ;

addressSet:
        addressSet POINTER {$$ = $1 + 1;}
    |   POINTER {$$ = 1;}
    ;

functionDeclaration:
        VARTYPE ':' FUNCTION ID '[' functionParameterDeclarations ']'
    |   FUNCTION ID '[' functionParameterDeclarations ']' 
    |   VARTYPE ':' FUNCTION ID '['  ']'
    |   FUNCTION ID '['  ']' 
    ;

functionDefinition:
        VARTYPE ':' FUNCTION ID '[' functionParameterDeclarations ']'
        '\\' '\\' functionInstructions '/' '/'
    |   VARTYPE ':' '<' ID '>' FUNCTION ID '[' functionParameterDeclarations ']'
        '\\' '\\' functionInstructions '/' '/'
    |   '<' ID '>' FUNCTION ID '[' functionParameterDeclarations ']'
        '\\' '\\' instructions '/' '/'
    |   FUNCTION ID '[' functionParameterDeclarations ']'
        '\\' '\\' instructions '/' '/'
    |
        VARTYPE ':' FUNCTION ID '['  ']'
        '\\' '\\' functionInstructions '/' '/'
    |   VARTYPE ':' '<' ID '>' FUNCTION ID '['  ']'
        '\\' '\\' functionInstructions '/' '/'
    |   '<' ID '>' FUNCTION ID '['  ']'
        '\\' '\\' instructions '/' '/'
    |   FUNCTION ID '['  ']'
        '\\' '\\' instructions '/' '/'
    |   VARTYPE ':' FUNCTION MAIN '[' ']'
        '\\' '\\' functionInstructions '/' '/'
    ;

functionInstructions:
        functionInstructions functionInstruction
    |   functionInstruction
    ;

functionInstruction:
        instruction
    |   RETURN ID ';'
    |   RETURN value ';'
    ;

functionParameterDeclarations:
        functionParameterDeclarations ',' functionParameterDeclaration
    |   functionParameterDeclaration
    ;

functionParameterDeclaration:
        VARTYPE ':' ID
    ;

classDeclaration: 
        CLASS ID '\\' '\\' classObjectsDeclarationSet '/' '/'
    ;

classObjectsDeclarationSet:
        classObjectsDeclarationSet classObjectsDeclaration
    |   classObjectsDeclaration
    ;

classObjectsDeclaration:
        variableDeclarationSet AS accessLevel ';'
    |   functionDeclaration AS accessLevel ';'
    |   functionDefinitionClass AS accessLevel
    ;

accessLevel:
        PRIVATE
    |   PUBLIC
    ;

functionDefinitionClass:
        VARTYPE ':' FUNCTION ID '[' functionParameterDeclarations ']'
        '\\' '\\' functionInstructions '/' '/'
    |   
        FUNCTION ID '[' functionParameterDeclarations ']'
        '\\' '\\' functionInstructions '/' '/'
    |    VARTYPE ':' FUNCTION ID '['  ']'
        '\\' '\\' functionInstructions '/' '/'
    |   
        FUNCTION ID '['  ']'
        '\\' '\\' functionInstructions '/' '/'
    ;

instructions: 
        instructions instruction
    |   instruction
    ;

instruction: 
        functionCall ';'
    |   predefinedFunctionCall ';'
    |   controlBlock
    |   ID ASSIGN expression ';'
    ;

controlBlock:
        ifBlock
    |   whileBlock
    |   forBlock
    ;

ifBlock:
        IF '[' expression ']' THEN
            functionInstructions
        ENDIF
    |
        IF '[' expression ']' THEN
            functionInstructions
        ELSE
            functionInstructions
        ENDIF
    ;

whileBlock:
        WHILE '[' expression ']' DO
            functionInstructions
        ENDWHILE
    ;

forBlock:
        FOR '[' ID ASSIGN expression ';' expression ';' ID ASSIGN expression ']' DO
            functionInstructions
        ENDFOR
    ;  

expression: 
        functionCall    { }
    |   expression '+' expression
    {
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String && ($3->type == Float || $3->type == Int)
            || $3->type == String && ($1->type == Float || $3->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            if($1->type >= $3->type)
                $$->type= $1->type;
            else
                $$->type = $3->type;

            if($$->type == Int)
            {
                $$->intVal = $1->intVal + $3->intVal;
            }
            if($$->type == Float)
            {
                if($1->type == Int)
                    $$->floatVal = $1->intVal + $3->floatVal;
                else if($3->type == Int)
                    $$->floatVal = $1->floatVal + $3->intVal;
                else
                    $$->floatVal = $1->floatVal + $3->floatVal;
            }
            if($$->type == String)
            {
                strcpy($$->stringVal, strcat($1->stringVal, $3->stringVal));
            }
        }
    }
    |   expression '-' expression 
    {
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String || $3->type == String)
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            if($1->type >= $3->type)
                $$->type= $1->type;
            else
                $$->type = $3->type;

            if($$->type == Int)
            {
                $$->intVal = $1->intVal - $3->intVal;
            }
            if($$->type == Float)
            {
                if($1->type == Int)
                    $$->floatVal = $1->intVal - $3->floatVal;
                else if($3->type == Int)
                    $$->floatVal = $1->floatVal - $3->intVal;
                else
                    $$->floatVal = $1->floatVal - $3->floatVal;
            }
            if($$->type == String)
            {
                strcpy($$->stringVal, strcat($1->stringVal, $3->stringVal));
            }
        }
    }
    |   expression '*' expression{
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        else{
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String || $3->type == String)
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            if($1->type >= $3->type)
                $$->type= $1->type;
            else
                $$->type = $3->type;

            if($$->type == Int)
            {
                $$->intVal = $1->intVal * $3->intVal;
            }
            if($$->type == Float)
            {
                if($1->type == Int)
                    $$->floatVal = $1->intVal * $3->floatVal;
                else if($3->type == Int)
                    $$->floatVal = $1->floatVal * $3->intVal;
                else
                    $$->floatVal = $1->floatVal * $3->floatVal;
            }
            if($$->type == String)
            {
                strcpy($$->stringVal, strcat($1->stringVal, $3->stringVal));
            }
        }}
    }
    |   expression '/' expression{
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String || $3->type == String)
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            if($1->type >= $3->type)
                $$->type= $1->type;
            else
                $$->type = $3->type;

            if($$->type == Int)
            {
                $$->intVal = $1->intVal / $3->intVal;
            }
            if($$->type == Float)
            {
                if($1->type == Int)
                    $$->floatVal = $1->intVal / $3->floatVal;
                else if($3->type == Int)
                    $$->floatVal = $1->floatVal / $3->intVal;
                else
                    $$->floatVal = $1->floatVal / $3->floatVal;
            }
            if($$->type == String)
            {
                strcpy($$->stringVal, strcat($1->stringVal, $3->stringVal));
            }
        }
    }
    |   expression '%' expression{
        if($1 == NULL || $3 == NULL)
        {
            $$ = NULL;
            yyerror("Expression parse error. Failed in syntax check");
        }
        else{
            $$ = (struct value*)malloc(sizeof(struct value));
            if($1->type != Int && $3->type != Int)
            {
                yyerror("Expression is syntactically incorrect");
                free($$);
            }
            else
            {
                if($1->type >= $3->type)
                    $$->type= $1->type;
                else
                    $$->type = $3->type;

                if($$->type == Int)
                {
                    $$->intVal = $1->intVal % $3->intVal;
                }
                if($$->type == Float)
                {
                    if($1->type == Int)
                        $$->floatVal = $1->intVal - $3->floatVal;
                    else if($3->type == Int)
                        $$->floatVal = $1->floatVal - $3->intVal;
                    else
                        $$->floatVal = $1->floatVal - $3->floatVal;
                }
                if($$->type == String)
                {
                    strcpy($$->stringVal, strcat($1->stringVal, $3->stringVal));
                }
            }
        }
    }
    |   expression '^' expression { }
    |   expression EQ expression{
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String && ($3->type == Float || $3->type == Int)
            || $3->type == String && ($1->type == Float || $3->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            $$->type = Int;

            if($$->type == Int)
            {
                if($1->type !=String && $3->type != String)
                {
                    if ($1->type == Float)
                        $$->intVal = $1->floatVal == $3->intVal;
                    else if ($3->type == Float)
                        $$->intVal = $3->floatVal == $1->intVal;
                    else
                        $$->intVal = $1->intVal == $3->intVal;
                }
                else
                    if(!strcmp($1->stringVal, $3->stringVal))
                    $$->intVal = 1;
                    else
                    $$->intVal = 0;
            }
        }
    }
    |   expression NEQ expression{
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String && ($3->type == Float || $3->type == Int)
            || $3->type == String && ($1->type == Float || $3->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            $$->type = Int;

            if($$->type == Int)
            {
                if($1->type !=String && $3->type != String)
                {
                    if ($1->type == Float)
                        $$->intVal = $1->floatVal != $3->intVal;
                    else if ($3->type == Float)
                        $$->intVal = $3->floatVal != $1->intVal;
                    else
                        $$->intVal = $1->intVal != $3->intVal;
                }
                else
                    if(!strcmp($1->stringVal, $3->stringVal))
                    $$->intVal = 0;
                    else
                    $$->intVal = 1;
            }
        }
    }
    |   expression GREQ expression {
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String && ($3->type == Float || $3->type == Int)
            || $3->type == String && ($1->type == Float || $3->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            $$->type = Int;

            if($$->type == Int)
            {
                if($1->type !=String && $3->type != String)
                {
                    if ($1->type == Float)
                        $$->intVal = $1->floatVal >= $3->intVal;
                    else if ($3->type == Float)
                        $$->intVal = $3->floatVal <= $1->intVal;
                    else
                        $$->intVal = $1->intVal >= $3->intVal;
                }
                else
                    if(strcmp($1->stringVal, $3->stringVal) >= 0)
                    $$->intVal = 1;
                    else
                    $$->intVal = 0;
            }
        }
    }
    |   expression LEEQ expression {
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String && ($3->type == Float || $3->type == Int)
            || $3->type == String && ($1->type == Float || $3->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            $$->type = Int;

            if($$->type == Int)
            {
                if($1->type !=String && $3->type != String)
                {
                    if ($1->type == Float)
                        $$->intVal = $1->floatVal <= $3->intVal;
                    else if ($3->type == Float)
                        $$->intVal = $3->floatVal >= $1->intVal;
                    else
                        $$->intVal = $1->intVal <= $3->intVal;
                }
                else
                    if(strcmp($1->stringVal, $3->stringVal) <= 0)
                    $$->intVal = 1;
                    else
                    $$->intVal = 0;
            }
        }
    }
    |   expression '>' expression {
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String && ($3->type == Float || $3->type == Int)
            || $3->type == String && ($1->type == Float || $3->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            $$->type = Int;

            if($$->type == Int)
            {
                if($1->type !=String && $3->type != String)
                {
                    if ($1->type == Float)
                        $$->intVal = $1->floatVal > $3->intVal;
                    else if ($3->type == Float)
                        $$->intVal = $3->floatVal < $1->intVal;
                    else
                        $$->intVal = $1->intVal > $3->intVal;
                }
                else
                    if(strcmp($1->stringVal, $3->stringVal) > 0)
                    $$->intVal = 1;
                    else
                    $$->intVal = 0;
            }
        }
    }
    |   expression '<' expression {
        if($1 == NULL || $3 == NULL)
        {
            yyerror("Expression parse error. Failed in syntax check");
        }
        $$ = (struct value*)malloc(sizeof(struct value));
        if($1->type == String && ($3->type == Float || $3->type == Int)
            || $3->type == String && ($1->type == Float || $3->type == Int))
        {
            yyerror("Expression is syntactically incorrect");
            free($$);
        }
        else
        {
            $$->type = Int;

            if($$->type == Int)
            {
                if($1->type !=String && $3->type != String)
                {
                    if ($1->type == Float)
                        $$->intVal = $1->floatVal <$3->intVal;
                    else if ($3->type == Float)
                        $$->intVal = $3->floatVal >$1->intVal;
                    else
                        $$->intVal = $1->intVal < $3->intVal;
                }
                else
                    if(strcmp($1->stringVal, $3->stringVal) < 0)
                    $$->intVal = 1;
                    else
                    $$->intVal = 0;
            }
        }
    }
    |   expression AND expression { }
    |   expression OR expression { }
    |   expression XOR expression { }
    |   value  { $$ = $1; }
    |   variable  
        { 
            if($1 != NULL)
                $$ = $1;
            
        }
    ;    


variable:
        refList ID { }
    |   refList ID '{' spanSetVars '}' { }
    |   ID 
    {
        $$ = getVar($1, "global");
    }
    |   ID '{' spanSetVars '}' { }
    |   object '.' ID { }
    ;

object: 
    |   THISOBJ
    |   ID
    ;

refList: refList DEREFERENCE
    |    DEREFERENCE
    |    refList POINTER
    |    POINTER
    ;

spanSetVars:
        spanSetVars ',' expression
    |   expression
    ;

functionCall:
        ID '[' parameterList ']'
    |   ID '[' ']'
    ;

predefinedFunctionCall:
        GET '[' parameterList ']'
    |   SHOW '[' parameterList ']'
    |   EVAL '[' expression ']' { printf("Expression result:\n"); eval($3); }
    ;

parameterList: 
        parameterList ',' expression
    |   expression
    ;  

%%

struct variable** createVariableVector(struct variable** oldVector, struct variable* newVariable, int oldVectorSize)
{
    struct variable** newVector = (struct variable**)malloc(sizeof(size_t) * (oldVectorSize+1) );
    for( int i = 0; i < oldVectorSize; i++)
    {
        newVector[i] = oldVector[i];
    }
    newVector[oldVectorSize] = newVariable;
    if(oldVector != NULL)
        free(oldVector);
    return newVector;
}

void printVariableVector(struct variable** vector, int length)
{
    for(int i = 0; i< length; i++)
    {
        if(vector[i]->type == Int)
        printf("Variable : %s\n\tType Int\n\tDepth : %d\n\tScope : %s\n\tValue: %d\n",
            vector[i]->name,vector[i]->depth, vector[i]->scope, vector[i]->intVal);
        if(vector[i]->type == Float)
        printf("Variable : %s\n\tType Float\n\tDepth : %d\n\tScope : %s\n\tValue: %f\n",
            vector[i]->name,vector[i]->depth, vector[i]->scope, vector[i]->floatVal);
        if(vector[i]->type == String)
        printf("Variable : %s\n\tType String\n\tDepth : %d\n\tScope : %s\n\tValue: %s\n",
            vector[i]->name,vector[i]->depth, vector[i]->scope, vector[i]->stringVal);
    }
}

void assignVarTypes(struct variable** vector, int length, char* scope,char* type)
{
    int typeForm = 0;
    if( !strcmp( type, "integer" ) )
        typeForm = Int;
    if( !strcmp( type, "float" ) )
        typeForm = Float;
    if( !strcmp( type, "string" ) )
        typeForm = String;
    for(int i = 0; i < length; i++)
    {
        if(vector[i]->type != typeForm && vector[i]->type > 0 &&
            ! (vector[i]->type == Int && typeForm == Float) )
        {
            yyerror("Cannot assign this value to this variable");
        }
        if( vector[i]->type == Int && typeForm == Float )
            vector[i]->floatVal = vector[i]->intVal; 
        vector[i]->type = typeForm;
        strcpy(vector[i]->scope, scope);
    }
}


void assignVarTypesAddress(struct variable** vector, int length,char* scope, char* type, int depth)
{
    int typeForm = 0;
    if( !strcmp( type, "integer" ) )
        typeForm = Int;
    if( !strcmp( type, "float" ) )
        typeForm = Float;
    if( !strcmp( type, "string" ) )
        typeForm = String;
    for(int i = 0; i < length; i++)
    {
        if(vector[i]->type != typeForm && vector[i]->type > 0 &&
            ! (vector[i]->type == Int && typeForm == Float) )
        {
            yyerror("Cannot assign this value to this variable");
        }
        vector[i]->type = typeForm;
        vector[i]->depth += depth;
        strcpy(vector[i]->scope, scope);
    }
}

void addToAllVariables(struct variable** vector, int length)
{
    for(int i = 0; i< length; i++)
    {
        allVars[numberOfVariables++] = vector[i];
    }
    free(vector);
}

void printAllVariables()
{
    for(int i = 0; i< numberOfVariables; i++)
    {
        if(allVars[i]->type == Int)
        printf("Variable : %s\n\tType Int\n\tDepth : %d\n\tScope : %s\n\tValue: %d\n",
            allVars[i]->name,allVars[i]->depth, allVars[i]->scope, allVars[i]->intVal);
        if(allVars[i]->type == Float)
        printf("Variable : %s\n\tType Float\n\tDepth : %d\n\tScope : %s\n\tValue: %f\n",
            allVars[i]->name,allVars[i]->depth, allVars[i]->scope, allVars[i]->floatVal);
        if(allVars[i]->type == String)
        printf("Variable : %s\n\tType String\n\tDepth : %d\n\tScope : %s\n\tValue: %s\n",
            allVars[i]->name,allVars[i]->depth, allVars[i]->scope, allVars[i]->stringVal);
    }
}

int variableExists(struct variable* var, char* scope)
{
    for( int i = 0; i < numberOfVariables; i++)
    {
        if( !strcmp(scope, allVars[i]->scope))
        {
            if( !strcmp( var->name, allVars[i]->name))
                return 1;
        } 
    }
    return 0;
}

void eval(struct value* val)
{
    if( val->type == Int)
        printf("%d\n", val->intVal);
    if( val->type == Float)
        printf("%f\n", val->floatVal);
    if( val->type == String)
        printf("%s\n", val->stringVal);
}

int yyerror(char * s)
{
	printf("\nEroare la linia: %d '%s'. \n",yylineno,s);
}



struct value* getVar(char* name, char* scope)
{
    struct value* res = (struct value*)malloc(sizeof(struct value));
    for(int i = 0 ;i < numberOfVariables; i++)
    {
        if( ! strcmp(allVars[i]->scope, scope))
        {
            if(!strcmp(allVars[i]->name, name))
            {
                res->type = allVars[i]->type;
                if(allVars[i]->type == Int)
                    res->intVal = allVars[i]->intVal;
                else if(allVars[i]->type == Float)
                    res->floatVal = allVars[i]->floatVal;
                else if(allVars[i]->type == String)
                    strcpy(res->stringVal ,allVars[i]->stringVal);
                return res;
            }
        }
    }
    yyerror("Var not declared");
    return NULL;
}

int main(int argc, char** argv){
	yyin=fopen(argv[1],"r");
	yyparse();
   // printAllVariables();
integer : i;

}
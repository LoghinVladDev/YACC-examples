%{
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include "defHeader.h"
    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno;
    variable heap[500];
    int sizeOfHeap = 0;
    int getParent(int);
    int getRight(int);
    int getLeft(int);
    bool isLeaf(int);
    int isInHeap(char* );
    void swap(int, int);
    void printHeap();
    void restoreHeap(int);
    void insertInHeap(char*, char*, char*);
    void addSequenceToHeap(char*, char*, char*);
    char *createVarsString(char*, char*);
    variable* getVar(char*, int);
%}
%name parse
%union{
    char *typeString;
    char *varString;
    char *varsString;
    int addrDepth;
    struct variable *var;
}
%token NR MAIN
%token <typeString> VARTYPE
%token <varString> ID
%type <var> operation
%type <var> operand 
%type <varsString> variable
%type <varsString> variables
%type <addrDepth> addresses
%type <addrDepth> staticAddresses
%start s
%%

s: instructions  {printHeap(); printf("Analysis complete\n");
instructions: instructions instruction
    | instruction
    ;

instruction: declaration 
    | definition
    ;
definition : MAIN '{' operations '}'
    |       MAIN '{'  '}'
    |       ID '{' operations '}' {printf("%s\n", $1);}
    |       ID '{' '}' {printf("%s\n", $1);}
    ;
operations : operations operation {printf("Operation result : %s, %s, %s, %d\n", $2->type, $2->name, $2->scope, $2->depth);}
    |        operation {printf("Operation result : %s, %s, %s, %d\n", $1->type, $1->name, $1->scope, $1->depth);}
    ;
operation :
                operand '=' operation
                {
                    if($1 && $3)
                    {
                        if($1->depth != $3->depth)
                        {
                            char *leftAddr = (char*)calloc(1, 256);
                            char *rightAddr = (char*)calloc(1, 256);
                            memset(leftAddr, '*', $1->depth);
                            memset(rightAddr, '*', $3->depth);
                            printf("Error at line %d, cannot assign %s%s to %s%s\n", yylineno, rightAddr, $3->name, leftAddr, $1->name);
                            free(leftAddr); free(rightAddr);
                        }
                        $$->depth = $1->depth;
                        $$->name = $1->name;
                        $$->type = $1->type;
                        $$->scope = $1->scope;
                    }
                }
    |       operand '=' operand ';'
                {
                    if($1 && $3)
                    {
                        if($1->depth != $3->depth)
                        {
                            char *leftAddr = (char*)calloc(1, 256);
                            char *rightAddr = (char*)calloc(1, 256);
                            memset(leftAddr, '*', $1->depth);
                            memset(rightAddr, '*', $3->depth);
                            printf("Error at line %d, cannot assign %s%s to %s%s\n", yylineno, rightAddr, $3->name, leftAddr, $1->name);
                            free(leftAddr); free(rightAddr);
                        }
                        $$->depth = $1->depth;
                        $$->name = $1->name;
                        $$->type = $1->type;
                        $$->scope = $1->scope;
                    }
                }
    |
            operand '=' NR ';' 
                {
                    if($1)
                    if(strcmp($1->type, "int") && strcmp($1->type, "float"))
                        printf("Error at line %d, cannot assign integer to %s\n",yylineno, $1->type);
                }
    |
            operand
                {
                    if($1)
                        $$ = $1;
                }
    ;

operand: addresses ID staticAddresses { $$ = getVar($2, $1+$3); if($$)$$->depth -= $1+$3;}
    |   addresses ID { $$ = getVar($2, $1);  if($$)$$->depth -=$1;}
    |   ID staticAddresses {$$ = getVar($1, $2);  if($$)$$->depth -=$2;}
    |   ID {$$ = getVar($1, 0);}
    ;

declaration: VARTYPE variables ';' {char* scope = (char*)malloc(256); strcpy(scope, "global");addSequenceToHeap(scope,$1,$2); free($1); free($2);}
    ;
variables: variables ',' variable {$$ = createVarsString($1, $3);} 
    |       variable { $$ = createVarsString($1, NULL);}
    ;
variable: addresses ID staticAddresses {char*addrStr = malloc($1 + strlen($2) + $3 + 1); memset(addrStr, '*', $1 + $3); addrStr[$1+$3]=0; strcat(addrStr, $2); $$=addrStr;}
    |     addresses ID { char*addrStr = malloc($1 + strlen($2) + 1); memset(addrStr, '*',$1); addrStr[$1] = 0; strcat(addrStr, $2); $$ = addrStr;}
    |     ID staticAddresses {char *addrStr = malloc($2 + strlen($1) +1); memset(addrStr, '*', $2); addrStr[$2] = 0; strcat(addrStr, $1); $$ = addrStr;}
    |     ID {$$ = $1;}
    ;
staticAddresses: staticAddresses '[' NR ']' {$$ = $1 + 1;}
    |   '[' NR ']' {$$ = 1;}
    ;
addresses: addresses '*' {$$ = $1 + 1; }
    |    '*' {$$ = 1;}
    ;
%%

variable* getVar(char* varName, int varAddrDepth)
{
    int i = isInHeap(varName);
    if( i == 0)
    {
        return NULL;
        printf("Error at line %d, variable %s was not declared in this scope!\n",  yylineno, varName);
    }
    if( heap[i].depth < varAddrDepth )
    {
        char* requested = (char*)calloc(1,256);
        char* have = (char*)calloc(1,256);
        memset(requested, '*', varAddrDepth);
        memset(have, '*', heap[i].depth);
        printf("Error at line %d, variable %s%s exists, but %s%s was requested\n",yylineno, have, varName, requested, varName);
        free(have); free(requested);
        return NULL;
    }
    variable* returned = (variable*)malloc(sizeof(variable));
    returned->depth = heap[i].depth;
    returned->name = heap[i].name;
    returned->type = heap[i].type;
    returned->scope = heap[i].scope;
    return returned;
}

void printHeap()
{
    for(int i = 1; i <= sizeOfHeap; i++)
        printf("Type: %s, Name: %s, Address Depth: %d, Scope: %s\n", heap[i].type, heap[i].name, heap[i].depth, heap[i].scope);
}

int getParent(int index)
{
    return index/2;
}

int getRight(int index)
{
    return index*2 + 1;
}

int getLeft(int index)
{
    return index*2;
}

bool isLeaf(int index)
{
    if( index >= sizeOfHeap/2 && index <= sizeOfHeap)
        return true;
    return false;
}

int isInHeap(char* variable)
{
    for(int i = 1; i <= sizeOfHeap; i++)
    {
        if(strcmp(heap[i].name, variable) == 0)
            return i;
    }
    return 0;
}

void swap(int index1, int index2)
{
    variable auxilliary;
    auxilliary.name = (char*) malloc(256);
    auxilliary.type = (char*) malloc(256);
    auxilliary.scope = (char*)malloc(256);
    strcpy(auxilliary.name, heap[index1].name);
    strcpy(heap[index1].name, heap[index2].name);
    strcpy(heap[index2].name, auxilliary.name);
    strcpy(auxilliary.type, heap[index1].type);
    strcpy(heap[index1].type, heap[index2].type);
    strcpy(heap[index2].type, auxilliary.type);
    strcpy(auxilliary.scope, heap[index1].scope);
    strcpy(heap[index1].scope, heap[index2].scope);
    strcpy(heap[index2].scope, auxilliary.scope);
    auxilliary.depth = heap[index1].depth;
    heap[index1].depth = heap[index2].depth;
    heap[index2].depth = auxilliary.depth;
    free(auxilliary.scope);
    free(auxilliary.type);
    free(auxilliary.name);
}

void restoreHeap(int index)
{
    if( isLeaf(index) )
        return;
    if( strcmp(heap[index].name, heap[getLeft(index)].name ) < 0 || strcmp(heap[index].name, heap[getRight(index)].name) <0)
    {
        if(strcmp(heap[getLeft(index)].name, heap[getRight(index)].name) >0)
        {
            swap(index, getLeft(index));
            restoreHeap(getLeft(index));
        }
        else
        {
            swap(index, getRight(index));
            restoreHeap(getRight(index));
        }
    }
}

void insertInHeap(char* variableTypeString ,char * variableNameString, char * variableDeclarationScope)
{
    printf("Adding %s to heap\n", variableNameString);
    heap[++sizeOfHeap].name = (char*)malloc(256);
    heap[sizeOfHeap].type = (char*)malloc(256);
    heap[sizeOfHeap].scope = (char*)malloc(256);
    strcpy(heap[sizeOfHeap].type, variableTypeString);
    strcpy(heap[sizeOfHeap].name, variableNameString);
    strcpy(heap[sizeOfHeap].scope, variableDeclarationScope);
    heap[sizeOfHeap].depth = 0;

    while(strchr(heap[sizeOfHeap].name, '*'))
    {
        if(heap[sizeOfHeap].name[0]=='*')
        heap[sizeOfHeap].depth++; 
        heap[sizeOfHeap].name++;
    }

    int index = sizeOfHeap;
    while(strcmp(heap[index].name, heap[getParent(index)].name) > 0)
    {
        swap(index, getParent(index));
        index = getParent(index);
    }
}

void addSequenceToHeap(char* scope, char* type,char *sequence)
{
    int i = 0;
    //printf("Adding %s to heap\n", sequence);
    if(sizeOfHeap == 0)
    {
        heap[0].name=(char*)malloc(256);
        memset(heap[0].name, 'z', 256);
        heap[0].name[255] = 0;
    }
    char *variableString = strtok(sequence," ");
    while(variableString)
    {
        if( (i = isInHeap(variableString))> 0)
        if(strcmp(heap[i].scope, scope)==0)
        {
            printf("Error at line %d. Variable %s already declared\n", yylineno, variableString);
        }
        insertInHeap(type, variableString, scope);
        variableString = strtok(NULL, " ");
    }
}

char* createVarsString(char* varSet1, char* varSet2)
{
    char* returnedVarSet = (char*)malloc( strlen(varSet1) + (varSet2 ? strlen(varSet2) : 0) +1 );
    if(varSet2)
    sprintf(returnedVarSet, "%s %s", varSet1, varSet2);
    else
    strcpy(returnedVarSet, varSet1);
    free(varSet1); free(varSet2);
    return returnedVarSet;
}

int yyerror(char *s)
{
    printf("error %s at line %d\n", s, yylineno);
}

int main(int argc, char **argv)
{
    yyin = fopen(argv[1], "r");
    yyparse();
    return 0;
}
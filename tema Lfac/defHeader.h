
typedef struct node{
    struct node* left;
    struct node* right;
    struct node* parent;
    char* value;
}node;

typedef struct variable
{
    char* name;
    char* type;
    char* scope;
    int depth;
}variable;

typedef struct varDepth
{
    char* name;
    int depth;
}varDepth;

#define varAlreadyExists 1

typedef char* varInfoString;
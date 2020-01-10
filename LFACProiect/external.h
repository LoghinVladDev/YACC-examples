struct variable
{
    int type;
    int depth;
    char name[64];
    char scope[64];
    char stringVal[64];
    int intVal;
    float floatVal;
};

struct value
{
    int type;
    int intVal;
    char stringVal[64];
    float floatVal;
};

#define Int 1
#define Float 2
#define String 3

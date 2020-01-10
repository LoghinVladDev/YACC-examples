struct variable{
	char nume[64];
	char scope[64];
	int depth;
	int intValue;
	float floatValue;
	char stringValue[64];
	int tip;
};

struct rez_expresie{
	int tip;
	int intVal;
	float floatVal;
	char stringVal[64];
};

#define Int 0
#define String 1
#define Float 2
#define FunctionVar 3
#define FunctionString 4

typedef struct variable variable;
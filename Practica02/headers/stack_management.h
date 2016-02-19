#include <stdio.h>
#define MAXSIZE 5

struct stack {
  int stk[MAXSIZE];
  int top;
};

typedef struct stack STACK;
STACK s;
 

void vfnStackInit(void);
unsigned char bfnStackPush(char* cpData, unsigned short wSize);
unsigned char bfnStackPop(char* cpData, unsigned short wSize);
void display(void);



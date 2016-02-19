//#include "../headers/stack_management.h"

/*  Function to add an element to the stack */
unsigned char bfnStackPush(char* cpData, unsigned short wSize) {
  int num;
  if (s.top == (MAXSIZE - 1)) {
    printf ("Stack is Full\n");
    return 0;
  }
  else {
    printf ("Enter the element to be pushed\n");
    scanf ("%d", &num);
    s.top = s.top + 1;
    s.stk[s.top] = num;
  }
  return 0;
}

/*  Function to delete an element from the stack */
unsigned char bfnStackPop(char* cpData, unsigned short wSize) {
  int num;
  if (s.top == - 1) {
    printf ("Stack is Empty\n");
    return (s.top);
  }
  else {
    num = s.stk[s.top];
    printf ("poped element is = %dn", s.stk[s.top]);
    s.top = s.top - 1;
  }
  return(num);
}

/*  Function to display the status of the stack */
void display () {
  int i;
  if (s.top == -1) {
    printf ("Stack is empty\n");
    return;
  }
  else {
    printf ("\n The status of the stack is \n");
    for (i = s.top; i >= 0; i--) {
      printf ("%d\n", s.stk[i]);
    }
  }
  printf ("\n");
}

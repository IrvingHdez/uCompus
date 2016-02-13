#include <stdio.h>

int main () {

  int aInt;
  scanf("%d", &aInt);

  char str[32];
  sprintf(str, "%d", aInt);

  printf("str: %c", str[0]);
  
  
  return 0;
}

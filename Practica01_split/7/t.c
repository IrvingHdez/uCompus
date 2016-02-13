#include <stdio.h>

int main () {
  int a = 7;
  int* pa = &a;

  printf("pa=%p\n", pa);
  printf("a=%d\n", *pa);

  return 0;
}


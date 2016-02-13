#include <stdio.h>
int main () {
  char a = 0;
  char b = 2;
  char c = (a + b + 0x2) & 0x0;
  printf("sum: %d", c);
  return 0;
}

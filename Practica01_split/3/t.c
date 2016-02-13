#include <stdio.h>

char absolute (char v);

int main () {
  unsigned char Source;
  unsigned char x = -2;
  x = absolute(x);
  printf("Source: %d", x);

  return 0;
}

char absolute (char v) {
  // if v > 0 (positive), the equation in the parenthesis gives 1
  // if v < 0 (negative), the equation in the parenthesis gives -1,
  //    hence minus one will multiply a negative number, 
  //    thus making it positve
  return v * ((v>0) - (v<0));
}

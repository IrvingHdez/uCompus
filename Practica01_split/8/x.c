// #include <stdio.h>
// #define sizeof_var( var ) ((size_t)(&(var)+1)-(size_t)(&(var)))

int main (){
  char  c;
  short s;
  int   i;

  int xc = sizeof(c);
  int xs = sizeof(s);
  int xi = sizeof(i);

  /* printf("\n%u",xc); */
  /* printf("\n%u",xs); */
  /* printf("\n%u",xi); */
  
  return 0;
}

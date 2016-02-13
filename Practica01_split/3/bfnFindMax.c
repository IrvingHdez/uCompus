#include <stdio.h>

/* Devuelve el número sin signo mayor encontrado en el bloque de */
/* memoria apuntado por bpDest */
unsigned char bfnFindMax(unsigned char* bpDest,
	                 unsigned short wSize);
int main () {
  /* in order to let arrays be initialized using 'Size' as their length, */
  /* 'Size' must be declared constant */
  const unsigned char Size = 5;
  
  unsigned char Source[Size] = {'5','8','1','3','7'};
  
  printf("Largest number is: %c\n", bfnFindMax(&Source[0], Size));
  return 0;
}


unsigned char bfnFindMax(unsigned char* bpDest,
	                 unsigned short wSize) {
  unsigned char l = 0;
  for(unsigned char i=0; i<wSize; i++){
    if (l < *(bpDest+i)) {
      l = *(bpDest+i);
    }
  }
  return l;
}

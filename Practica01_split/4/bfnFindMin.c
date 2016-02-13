#include <stdio.h>

/* Devuelve el número sin signo menor encontrado en el bloque */
/* de memoria apuntado por bpDes */
unsigned char bfnFindMin(unsigned char* bpDest,
	                 unsigned short wSize);
int main () {
  /* in order to let arrays be initialized using 'Size' as their length, */
  /* 'Size' must be declared constant */
  const unsigned char Size = 5;
  
  unsigned char Source[Size] = {'5','8','1','3','7'};
  
  printf("Smallest number is: %c", bfnFindMin(&Source[0], Size));
  return 0;
}

unsigned char bfnFindMin(unsigned char* bpDest,
	                 unsigned short wSize) {
  unsigned char s = *bpDest;
  for(unsigned char i=1; i<wSize; i++){
    if (s > *(bpDest+i)) {
      s = *(bpDest+i);
    }
  }
  return s;
}

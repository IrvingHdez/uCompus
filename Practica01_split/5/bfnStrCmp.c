#include <stdio.h>

/* Compara las cadenas apuntadas por bpSource y bpDest,  */
/* devolviendo 1 si las cadenas son iguales o 0 si son distintas */
unsigned char bfnStrCmp(unsigned char* bpSource, 
                        unsigned char* bpDest, 
			unsigned short wSize);

int main () {

  const unsigned short Size = 5;
  unsigned char  Source[Size] = {'7','6','1','2','3'};
  unsigned char  Dest[Size]   = {'7','6','1','2','3'};

  printf("\nAre Strings identical: %d\n", bfnStrCmp(&Source[0], &Dest[0], Size));
  return 0;
}

unsigned char bfnStrCmp(unsigned char* bpSource, 
                        unsigned char* bpDest, 
			unsigned short wSize) {
  for(int i=0; i<wSize; i++){
    if (*(bpSource+i) != *(bpDest+i))
      return (0 > 1); // false, returns 0
  }
  return (0 < 1); // true, returns 1
}

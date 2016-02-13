#include <stdio.h>

/* Devuelve el número de 16 bits que representa la cantidad de */
/* veces que se repite el elemento bSymbol en el bloque indicado */
/* por bpSrc de tamaño wSize  */
/* (http://en.wikipedia.org/wiki/Run-length_encoding) */

unsigned short wfnOccurrence(unsigned char  bSymbol, 
			     unsigned char* bpSrc, 
			     unsigned short wSize);

int main () {
  const unsigned short Size      = 8;
  unsigned char        Src[Size] = {'1','9','7','3','4','7','r','b'};
  unsigned char        Symbol   = '7';

  printf("Ocurrences: %d", wfnOccurrence(Symbol, &Src[0], Size));

  return 0;
}

unsigned short wfnOccurrence(unsigned char  bSymbol,
			     unsigned char* bpSrc,
			     unsigned short wSize) {
  unsigned short Occurrence = 0;

  for (unsigned short i=0; i<wSize; i++) {
    if ( *(bpSrc + i) == bSymbol ) {
      Occurrence++;
    }
  }
  return Occurrence;
}

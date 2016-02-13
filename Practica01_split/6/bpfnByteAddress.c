#include <stdio.h>

/* Entrega la dirección donde se encuentra el valor 'bCharToFind' */
/* en la cadena 'bpString'. En caso de no encontrar datos, regresa */
/* un apuntador a NULL. */
unsigned char* bpfnByteAddress(unsigned char* bpString, 
			       unsigned char  bCharToFind, 
			       unsigned short wSize);

int main () {
  const unsigned short Size = 5;

  unsigned char  String[Size] = {'1','g','3','4','5'};
  /* Why initializing to "=1g345" generates this error?: */
  /* initializer-string for array of chars is too long [-fpermissive] */
  
  unsigned char CharToFind = 'g';

  if ( bpfnByteAddress(&String[0], CharToFind, Size) == NULL ) {
    printf("Char not foud");
  } else {
    // the trick is: use %p to print an address
    printf( "Char at Address: %p\n", bpfnByteAddress(&String[0], CharToFind, Size) );    
  }

  return 0;
}


unsigned char* bpfnByteAddress(unsigned char* bpString, 
			       unsigned char  bCharToFind, 
			       unsigned short wSize) {
  for (int i=0; i<wSize; i++){
    if (bCharToFind == *(bpString+i)){
      return bpString+i;
    }
  }
  return NULL;
}

#include <stdio.h>
/* Devuelve el número de 8 bits que resulta de realizar un xor */
/* entre todos los datos contenidos en el espacio de memoria */
/* apuntado por 'bpSrc' con tamaño especificado por wSize */
/* (https://en.wikipedia.org/wiki/Longitudinal_redundancy_check) */

unsigned char bfnLRC(unsigned char* bpSrc, 
		     unsigned short wSize);

int main () {
  const unsigned short Size = 4;
  unsigned char Src[Size] = {'9','2','6','4'};

  printf("Sum is: %d", bfnLRC( &Src[0], Size ));

  return 0;
}

unsigned char bfnLRC(unsigned char* bpSrc,
		     unsigned short wSize) {
  unsigned char LRC = 0;
  for (unsigned short i=0; i<wSize; i++) {
    LRC = (LRC + (*bpSrc + i) & 0xFF);
  }

  return (((LRC ^ 0xFF) + 1) & 0xFF);
  /* Set LRC = 0 */
  /* For each byte b in the buffer */
  /* do */
  /*     Set LRC = (LRC + b) AND 0xFF */
  /* end do */
  /* Set LRC = (((LRC XOR 0xFF) + 1) AND 0xFF) */
}

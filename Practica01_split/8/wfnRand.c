#include <stdio.h>

#define b16M 0x8000
#define b14M 0x2000
#define b13M 0x1000
#define b11M 0x0600

/* Devuelve un numero de 16 bits por medio de un generador de números */
/* pseudo aleatorio basado en la semilla recibida en wSeed.  */
/* Utilice el algoritmo de Fibonacci en registros de corrimiento con  */
/* retroalimentación lineal (LFSR) que muestra la figura */
// b1 = (((b16 ^ b14) ^ b13) ^ b11)
// En g++, al dar 'sizeof()' a una variable 'short' nos da que 
// la variable es de 2 bytes: 16 bits

unsigned short wfnRand(unsigned short wSeed);

int main () {

  // Used seed from example in document:
  unsigned short Seed = 0x8735;

  printf("\nRandom Number: 0x%x\n", wfnRand(Seed));

  return 0;
}


unsigned short wfnRand(unsigned short wSeed) {
  //short lfsrNum = wSeed;
  /* unsigned char b16 = (lfsrNum & b16M > 0); */
  /* unsigned char b14 = (lfsrNum & b14M > 0); */
  /* unsigned char b13 = (lfsrNum & b13M > 0); */
  /* unsigned char b11 = (lfsrNum & b11M > 0); */
  /* unsigned char b01 = ((( b16^b14 ) ^ b13 ) ^ b11); */

  unsigned char b01 = ((( (lfsrNum & b16M > 0)^(lfsrNum & b14M > 0)) ^
  			  (lfsrNum & b13M > 0) ) ^
  		          (lfsrNum & b11M > 0) );

  return (wSeed << 1) + b01;
}

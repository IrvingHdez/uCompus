#include <stdio.h>

#define b16M 0x8000
#define b14M 0x2000
#define b13M 0x1000
#define b11M 0x0600

/* Copia los datos del bloque apuntado por bpSource  */
/* al bloque apuntado por bpDest. */
void vfnMemCpy (unsigned char* bpSource,
		unsigned char* bpDest,
		unsigned short wSize);

/* Rellena el bloque apuntado por bpDest con el dato  */
/* indicado por bByteToFill. */
void vfnMemSet(unsigned char* bpDest, 
	       unsigned char bByteToFill, 
	       unsigned short wSize);

/* Devuelve el número sin signo mayor encontrado en el bloque de */
/* memoria apuntado por bpDest */
unsigned char bfnFindMax(unsigned char* bpDest,
	                 unsigned short wSize);


/* Devuelve el número sin signo menor encontrado en el bloque */
/* de memoria apuntado por bpDes */
unsigned char bfnFindMin(unsigned char* bpDest,
	                 unsigned short wSize);


/* Compara las cadenas apuntadas por bpSource y bpDest,  */
/* devolviendo 1 si las cadenas son iguales o 0 si son distintas */
unsigned char bfnStrCmp(unsigned char* bpSource, 
                        unsigned char* bpDest, 
			unsigned short wSize);


/* Entrega la dirección donde se encuentra el valor 'bCharToFind' */
/* en la cadena 'bpString'. En caso de no encontrar datos, regresa */
/* un apuntador a NULL. */
unsigned char* bpfnByteAddress(unsigned char* bpString, 
			       unsigned char  bCharToFind, 
			       unsigned short wSize);


/* Devuelve el tamaño de la cadena terminada en 0, apuntada por bpString. */
unsigned short wfnStrLen (unsigned char* bpString);


/* Devuelve un numero de 16 bits por medio de un generador de números */
/* pseudo aleatorio basado en la semilla recibida en wSeed.  */
/* Utilice el algoritmo de Fibonacci en registros de corrimiento con  */
/* retroalimentación lineal (LFSR) que muestra la figura */
// b1 = (((b16 ^ b14) ^ b13) ^ b11)
// En g++, al dar 'sizeof()' a una variable 'short' nos da que 
// la variable es de 2 bytes: 16 bits
unsigned short wfnRand(unsigned short wSeed);


/* Devuelve el número de 8 bits que resulta de realizar un xor */
/* entre todos los datos contenidos en el espacio de memoria */
/* apuntado por 'bpSrc' con tamaño especificado por wSize */
/* (https://en.wikipedia.org/wiki/Longitudinal_redundancy_check) */
unsigned char bfnLRC(unsigned char* bpSrc, 
		     unsigned short wSize);


/* Devuelve el número de 16 bits que representa la cantidad de */
/* veces que se repite el elemento bSymbol en el bloque indicado */
/* por bpSrc de tamaño wSize  */
/* (http://en.wikipedia.org/wiki/Run-length_encoding) */
unsigned short wfnOccurrence(unsigned char  bSymbol, 
			     unsigned char* bpSrc, 
			     unsigned short wSize);


/* Ordena de menor a mayor, en el mismo sitio, los datos */
/* contenidos en el buffer apuntado por bpString. */
void vfnSort (unsigned char* bpString, 
	      unsigned short wStringSize);

/* Ordena de menor a mayor, en el mismo sitio, los datos */
/* contenidos en el buffer apuntado por bpString. */
void vfnSort (unsigned char* bpString, 
	      unsigned short wStringSize);



main () {
}  const unsigned char Size = 8;

  unsigned char  Source[Size] = {'5','7','9','1','3','4','8','2'};
  unsigned char  Dest[Size];

  vfnMemCpy(&Source[0], &Dest[0], Size);

  for (unsigned char i=0; i<Size; i++) {
    printf("Source: %x\nDest: %x\n", Source[i], Dest[i]);
  }
  
  return 0;
}


void vfnMemCpy (unsigned char* bpSource,
		unsigned char* bpDest,
		unsigned short wSize) {
  for(unsigned char i = 0; i< wSize; i++) {
    *(bpDest+i) = *(bpSource+i);
  }
}


void vfnMemSet(unsigned char* bpDest, 
	       unsigned char  bByteToFill, 
	       unsigned short wSize) {
  for(unsigned char i=0; i<wSize; i++) {
    *(bpDest+i) = bByteToFill;
  }
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


unsigned char bfnStrCmp(unsigned char* bpSource, 
                        unsigned char* bpDest, 
			unsigned short wSize) {
  for(int i=0; i<wSize; i++){
    if (*(bpSource+i) != *(bpDest+i))
      return (0 > 1); // false, returns 0
  }
  return (0 < 1); // true, returns 1
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


unsigned short wfnStrLen (unsigned char* bpString) {
  short StrSize = 0;

  do {
    if ( *(bpString + StrSize) == '0' ) {
      /* must return StrSize+1, 'StrSize=0' means 'bpString + 0' */
      /* points to a string of length=1 */
      /* If user wants to ignore the '0' char, then 'return StrSize' */
      /* must be used */
      return StrSize+1;
    }
    StrSize++;
  } while ( 1 );

}


unsigned short wfnRand(unsigned short wSeed) {
  unsigned char b01 = ((( (lfsrNum & b16M > 0)^(lfsrNum & b14M > 0)) ^
  			  (lfsrNum & b13M > 0) ) ^
  		          (lfsrNum & b11M > 0) );

  return (wSeed << 1) + b01;
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


void vfnSort (unsigned char* bpString,
	      unsigned short wStringSize) {
   unsigned short i, j;
   unsigned char  tmp;

   for (i = 0 ; i < ( wStringSize - 1 ); i++) {
      for (j = 0 ; j < wStringSize - i - 1; j++) {
	 if (*(bpString + j) > *(bpString + j + 1)) {
	    tmp = *(bpString + j);
	    *(bpString + j)  = *(bpString + j + 1);
	    *(bpString + j + 1) = tmp;
	 }
      }
   }
}



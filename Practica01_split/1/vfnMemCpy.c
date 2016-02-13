#include <stdio.h>

/* Copia los datos del bloque apuntado por bpSource  */
/* al bloque apuntado por bpDest. */
void vfnMemCpy (unsigned char* bpSource,
		unsigned char* bpDest,
		unsigned short wSize);

main () {
  const unsigned char Size = 8;

  unsigned char  Source[Size];
  unsigned char  Dest[Size];

  for(unsigned char i=0; i<Size; i++){
    Source[i]=i+3;
  }

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

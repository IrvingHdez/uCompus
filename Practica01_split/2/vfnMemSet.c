#include <stdio.h>

/* Rellena el bloque apuntado por bpDest con el dato  */
/* indicado por bByteToFill. */
void vfnMemSet(unsigned char* bpDest, 
	       unsigned char bByteToFill, 
	       unsigned short wSize);

int main () {
  const unsigned char Size = 8;
  /* printf("Enter a size for the memory block\n"); */
  /* scanf("%hhu", &Size); */

  unsigned char ByteToFill = 'x';
  /* printf("Enter a ByteToFill\n"); */
  /* scanf("%hhu", &ByteToFill); */

  unsigned char Dest[Size];
  
  vfnMemSet(&Dest[0], ByteToFill, Size);
  printf("Dest: ");
  for(unsigned char i=0; i<Size; i++) {
    printf("%c", Dest[i]);
  }

  return 0;
}


void vfnMemSet(unsigned char* bpDest, 
	       unsigned char  bByteToFill, 
	       unsigned short wSize) {
  for(unsigned char i=0; i<wSize; i++) {
    *(bpDest+i) = bByteToFill;
  }
}

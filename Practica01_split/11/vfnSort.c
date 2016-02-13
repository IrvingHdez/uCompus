#include <stdio.h>

/* Ordena de menor a mayor, en el mismo sitio, los datos */
/* contenidos en el buffer apuntado por bpString. */
void vfnSort (unsigned char* bpString, 
	      unsigned short wStringSize);


int main () {
  const unsigned short Size = 10;
  unsigned char String[Size] = {'1','3','7','9','4','6','2','5','8','0'};

  vfnSort(&String[0], Size);
  for (unsigned short i=0; i<Size; i++) {
    printf("Element: %c\n", String[i]);
  }
  return 0;
}

void vfnSort (unsigned char* bpString,
	      unsigned short wStringSize) {

  while (not_ordered) {
    
  }
}

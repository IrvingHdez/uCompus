#include <stdio.h>

/* Devuelve el tamaño de la cadena terminada en 0, apuntada por bpString. */
unsigned short wfnStrLen (unsigned char* bpString);

int main () {
  unsigned char  String[8] = {'7','9','f','6','1','5','g','0'};

  printf("Lenght of string is: %d\n", wfnStrLen(&String[0]) );
  return 0;
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

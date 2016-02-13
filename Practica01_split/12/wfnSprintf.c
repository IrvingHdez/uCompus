
/* /\* Formatea en la cadena 'string'  los datos siguiendo el formato. *\/ */
/* /\* Devuelve el tamaño de la cadena generada *\/ */
/* /\* %c – imprime el carácter *\/ */
/* /\* %d – imprime en 3 dígitos el número de 8 bits *\/ */
/* /\* %s – imprime como cadena los datos actuales *\/ */
/* /\* %x – imprime en 2 dígitos el número hexadecimal *\/ */
/* /\* %b – imprime 8 dígitos representando el binario de 8 bits *\/ */
/* /\* ** - Las opciones de %d, %d y %b deben soportar la supresión de los *\/ */
/* /\*      ceros precedentes a menos que se utilice %0b, %0d o %0x donde *\/ */
/* /\*      se especifica que se dejaran los ceros iniciales. *\/ */

//#include<stdio.h>
//#include<stdarg.h>
 
void  Myprintf(char *,...); 	   //Our printf function
char* convert(unsigned int, int);  //Convert integer number into octal, hex, etc.

//void putchar(char c);
char putchar(char c);
int puts(const char *string);
   
typedef char*  va_list;

#define INT 32
#define _INTSIZEOF(n)   ((sizeof(n) + sizeof(INT) - 1) & ~(sizeof(INT) - 1)) 
#define va_start(ap,v)  (ap = (va_list)&v + _INTSIZEOF(v))
#define va_arg(ap,t)    (*(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
#define va_end(ap)      (ap = (va_list)0)

/* #ifndef EOF */
/* #define EOF -1 */
/* #endif */

int main() { 
  Myprintf(" WWW.FIRMCODES.COM \n %d", 9); 
	
  return 0;
} 
 
 
void Myprintf(char* format,...)  { 
  char *traverse; 
  unsigned int i; 
  char *s; 
	
  //Module 1: Initializing Myprintf's arguments 
  va_list arg; 
  va_start(arg, format); 
	
  for(traverse = format; *traverse != '\0'; traverse++) { 
    while( *traverse != '%' ) { 
      putchar(*traverse);
      traverse++; 
    } 
		
    traverse++; 
		
    //Module 2: Fetching and executing arguments
    switch(*traverse) {
    case 'c' : i = va_arg(arg,int);		//Fetch char argument
      putchar(i);
      break; 
						
    case 'd' : i = va_arg(arg,int); 		//Fetch Decimal/Integer argument
      if(i<0) {
	i = -i;
	putchar('-'); 
      } 
      puts(convert(i,10));
      break; 
						
    case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
      puts(convert(i,8));
      break; 
						
    case 's': s = va_arg(arg,char *); 		//Fetch string
      puts(s); 
      break; 
						
    case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
      puts(convert(i,16));
      break; 
    }	
  } 
	
  //Module 3: Closing argument list to necessary clean-up
  va_end(arg); 
} 
 
char *convert(unsigned int num, int base) { 
  static char Representation[]= "0123456789ABCDEF";
  static char buffer[50]; 
  char *ptr; 
	
  ptr = &buffer[49]; 
  *ptr = '\0'; 
	
  do { 
    *--ptr = Representation[num%base]; 
    num /= base; 
  }while(num != 0); 
	
  return(ptr); 
}


char putchar(char c) {
  extern long write(int, const char *, unsigned long);
  (void) write(1, &c, 1);
  return c;
}


int puts(const char *string) {
  int i = 0;
  //standard c idiom for looping through a null-terminated string
  while(string[i]) {
    //if we got the EOF value from writing the char
    if( putchar(string[i]) == -1 ) { 
      return -1;
    }
    i++;
  }
  //this will occur right after we quit due to the null terminated character.
  if(putchar('\n') == -1) {
    return -1;
  }
  return 1; //to meet spec.
}

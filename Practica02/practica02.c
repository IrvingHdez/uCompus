#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "headers/memory_management.h"
#include "headers/queue_management.h"
#include "headers/stack_management.h"
#include "headers/general_functions.h"
#include "headers/data_conversion.h"
#include "headers/data_management.h"

/*Data conversion*/

/*Data Management*/

int main() {
  //vpfnMalloc(10);
  //malloc();
  //printf("Result %d", bfnLog2(64));

  unsigned char num_str[] = "2";
  unsigned char size = sizeof(num_str);
  unsigned char c = num_str[2];
  //unsigned char* pc = &c[0];

  printf("Number: %c", c);
  printf("\n: %d", size);
  //dwAToUL(char* cpPtr)


  return 0;
}


#include "functions/memory_management.c" // needs revision
#include "functions/queue_management.c"  // needs revision
#include "functions/stack_management.c"  // needs revision
#include "functions/general_functions.c" 
#include "functions/data_conversion.c"
#include "functions/data_management.c"


/*Data conversion*/

/*Data Management*/


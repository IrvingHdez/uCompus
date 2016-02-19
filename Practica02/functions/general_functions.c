//#include "../headers/general_functions.h"

/*General Functions*/
unsigned char bfnCmdLine(char *cpCmd, char *cpCmdList){
  int pos = 0;
  while(*cpCmdList){
    if(*cpCmdList == *cpCmd)
      return pos;
    
    cpCmdList++;
    pos++;
  }    
  return '\0';
}


unsigned char bfnLog2(unsigned long dwNum){
  unsigned int r;
  unsigned int shift;
    
  r = (dwNum > 0xFFFF) << 4; 
  dwNum >>= r;
  shift = (dwNum > 0xFF) << 3; 
  dwNum >>= shift; 
  r |= shift;
  shift = (dwNum > 0xF) << 2; 
  dwNum >>= shift; 
  r |= shift;
  shift = (dwNum > 0x3) << 1; 
  dwNum >>= shift; 
  r |= shift;
  r |= (dwNum >> 1);
    
  return r++;
}

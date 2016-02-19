struct block_meta{
  size_t wSize;
  struct block_meta *next;
  int free;
};


/*Memory Management*/
void *vpfnMalloc(unsigned short wSize);
void vfnFree(void *vpPtr);
void *realloc(void *vpPtr, unsigned short wSize);
void *calloc(unsigned short wSize);

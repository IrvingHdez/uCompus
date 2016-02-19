/* #include <stdio.h> */
/* #include <assert.h> */
/* #include <string.h> */
/* #include <sys/types.h> */
/* #include <unistd.h> */

/* #include "../headers/memory_management.h" */

/*Memory Management*/
void *vpfnMalloc(unsigned short wSize){
  void *p = sbrk(0);
  void *request = sbrk(wSize);
  if (request == (void*) -1){
    return NULL;//sbrk failed
  }else{
    assert(p == request); //Not thread safe
    return p;
  }
}

struct block_meta *get_block_ptr(void *vpPtr){
  return (struct block_meta*)vpPtr -1;
}

void vfnFree(void *vpPtr){
  if(!vpPtr)
    return;
    
  struct block_meta* block_ptr = get_block_ptr(vpPtr);
  assert(block_ptr->free==0);
  block_ptr->free = 1;
}

void *realloc(void *vpPtr, unsigned short wSize){
  if(!vpPtr)
    return vpfnMalloc(wSize);
    
  struct block_meta* block_ptr = get_block_ptr(vpPtr);
  if(block_ptr->wSize >= wSize)
    return vpPtr;
    
  void *new_ptr;
  new_ptr = vpfnMalloc(wSize);
  if (!new_ptr)
    return NULL;
    
  memcpy(new_ptr,vpPtr, block_ptr->wSize);
  vfnFree(vpPtr);
  return new_ptr;
}

void *calloc(unsigned short wSize){
  void *ptr = vpfnMalloc(wSize);
  memset(ptr, 0, wSize);
  return ptr;
}

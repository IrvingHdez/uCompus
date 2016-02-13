
int main () {

  __asm__ (
	   "section .text\n\t"
	   "global _start\n\t"
	   "_start:\n\t"
	   "mov edx,len\n\t"
	   "mov ecx,msg\n\t"
	   "mov ebx,1\n\t"
	   "mov eax,4\n\t"
	   "int 0x80\n\t"
	   "mov eax,1\n\t"
	   "int 0x80\n\t"
	   "section .data\n\t"
	   "msg db 'Hello, world!',0xa\n\t"
	   "len equ $ - msg\n\t"
	   );
  return 0;
}

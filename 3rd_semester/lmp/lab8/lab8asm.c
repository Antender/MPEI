#include <stdio.h>
#include <stdint.h>

uint32_t __declspec(naked) __cdecl invert(uint32_t x,uint32_t n,uint32_t p) {
	__asm {
push ebx
mov eax, [esp+8]
mov ebx, -1
mov ecx, [esp+12]
mov edx, [esp+16]
lea ecx, [ecx+edx-32]
neg ecx
shr ebx, cl
mov ecx, -1
xchg edx, ecx
shl edx, cl
and ebx, edx
xor eax, ebx
pop ebx
ret
  }
}

int main(void) {
	uint32_t x,n,p;
	scanf("%8x %u %u",&x,&n,&p);
    if ((p<0) || (p>30) || (n<1) || (n>(31-p))) {
		puts("Wrong input parameters");
	} else {
		printf("%08x\n",invert(x,n,p));
	}
	return 0;
}

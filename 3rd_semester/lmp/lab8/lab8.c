#include <stdio.h>
#include <stdint.h>


uint32_t invert(uint32_t x,uint32_t n,uint32_t p) {
	return x^((UINT32_MAX<<p)&(UINT32_MAX>>(32-n-p)));
}

int main(void) {
	uint32_t x,n,p;
	scanf("%8x %u %u",&x,&n,&p);
    if ((p<0) || (p>30) || (n<1) || (n>(31-p))) {
		puts("Wrong input parameters");
	} else {
		printf("%08x %u\n",x, UINT32_MAX);
		printf("%08x\n",invert(x,n,p));
	}
	return 0;
}

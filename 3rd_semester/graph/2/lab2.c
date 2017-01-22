#include <stdio.h>

int main(void) {
  long long int n;
  scanf("%lli",&n);
  if (n>=0) {
    printf("%lli\n",(n+1)*n/2);
  } else {
    printf("-%lli\n",((-n)+1)*(-n)/2-1);
  }
  return 0;
}

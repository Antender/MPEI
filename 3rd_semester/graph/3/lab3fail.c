#include <stdio.h>

const int fac[11] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
int main(void) {
  int n,k;
  scanf("%i %i",&n,&k);
  if (k>n) {
    puts("0");
  } else {
    printf("%li",((long int)fac[n])/((long int)fac[k]*fac[n-k]));
  }
  return 0;
}

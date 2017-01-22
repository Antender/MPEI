#include <stdio.h>

int main(void) {
  long int nom = 1;
  long int den = 1;
  int n;
  int k;
  scanf("%i %i",&n,&k);
  if ((n<=0) || (k<=0)) {
    puts("1\n");
  } else {
    if (n<k) {
      puts("0\n");
    } else {
      while(n>k) {
      nom*=n;
      den*=n-k;
      --n;
      }
      printf("%li\n",nom/den);
    }
  }
  return 0;
}


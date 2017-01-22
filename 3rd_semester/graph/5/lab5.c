#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long int fac[21] = {
1,
1,
2,
6,
24,
120,
720,
5040,
40320,
362880,
3628800,
39916800,
479001600,
6227020800,
87178291200,
1307674368000,
20922789888000,
355687428096000,
6402373705728000,
121645100408832000,
2432902008176640000};

int size;
long long int pos;

int * decode(int * indexes) {
  int * set = (int *) malloc(sizeof(int)*size);
  for (int i=0;i<size;++i) {
    set[i]=i+1;
  }
  for (int i=size-1;i>=0;--i)
  {
    int j = indexes[i];
    indexes[i]=set[j];
    for (;j<size-1;++j) {
      set[j]=set[j+1];
    }
  }
  free(set);
  return indexes;
}

int * findIndexes(void) {
  int * indexes = (int *) malloc(sizeof(int)*size);
  for (int i=size-1;i>0;--i) {
    indexes[i]=(int)(pos/(fac[i]));
    pos=pos%(fac[i]);
  }
  return indexes;
}

int main(void) {
  scanf("%i %lli",&size,&pos);
  --pos;
  int * result = decode(findIndexes());
  for (int i=size-1;i>=0;--i) {
    printf("%i ",result[i]);
  }
  free(result);
  return 0;
}

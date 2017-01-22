#include <stdio.h>
#include <stdlib.h>

int nextPerm (int *a, int n)
{
  int k, t, temp;

  for (k = n - 2; (a[k] >= a[k + 1]) && (k >= 0); k--); 
  if (k == -1) return 0;
  for (t = n - 1; (a[k] >= a[t]) && (t >= k + 1); t--);
  temp = a[k], a[k] = a[t], a[t] = temp;
 
  for (int i = k + 1; i <= (n + k)/2; i++)
  {
    t = n + k - i;
    temp = a[i], a[i] = a[t], a[t] = temp;
  }
  return 1;
}

void outputArray(int *a, int n) {
  for (int i=0; i<n; ++i) {
    printf("%i ",a[i]);
  }
  puts("");
}

int main(void) {
  int n;
  scanf("%i",&n);
  if (n>0) {

    int* array = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; ++i) {
      array[i]=i+1;
    }
    outputArray(array,n);

    while(nextPerm(array,n)) {
      outputArray(array,n);
    }

    free(array);
  }
  return 0;
}

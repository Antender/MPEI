#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* data;
  int size;
} array;

typedef struct {
  int min;
  int max;
} limits;

int countSum (array a,limits l) {
  int sum = 0;
  for (int i=0;i<a.size;i++) {
	  if ((a.data[i]<l.min) && (a.data[i]>l.max)) {
        sum+=a.data[i];
	  }
  }
  return sum;
}

limits getLimits() {
  limits l;
  puts("Enter minimal element:");
  scanf("%d", &(l.min));
  puts("Enter maximal element:");
  scanf("%d", &(l.max));
  if (l.max > l.min) {
    int temp = l.min;
    l.min = l.max;
    l.max = temp;
  }
  return l;
}

void printSum(int sum) {
  printf("Sum is %d\n", sum);
}

array readFile(char * filename) {
  int sum = 0;
  FILE * fid = fopen(filename,"r");
  int *ar;
  int size;
  if (fid==NULL) {
    printf("File %s doesn't exist",filename);
  } else {
	  fscanf(fid, "%d", &size);
	  ar= (int *) malloc(sizeof(int)*size);

    puts("Initial array:");
    for (int counter=0;counter<size;counter++) {
      fscanf(fid, "%d", &(ar[counter]));
      printf("%d",ar[counter]);
    }	
    puts("");
    fclose(fid);
  }
  array a;
  a.data=ar;
  a.size=size;
  return a;
}

int compare(const void * element_p1,const void* element_p2) {
  int el1 = *((int *)element_p1);
  int el2 = *((int *)element_p2);
  if (el2>el1) {
    return -1;
  } else if (el2<el1) {
    return 1;
  } else {
    return 0;
  }
}

int main (int argc,char * argv[]) {
  if (argc<=1) {
    puts("Enter some filenames, please");
  } else {
	  int ARCOUNT = argc-1;
	  int* sum = (int*)malloc(sizeof(int)*ARCOUNT);
	  for(int i=0;i<ARCOUNT;i++) {
	    array a = readFile(argv[i+1]);
    	printSum(sum[i] = countSum(a,getLimits()));
    	free(a.data);
	  }
      qsort((void*)&sum,ARCOUNT,sizeof(int),compare);
	  int i = 0;
	  printf("Minimum sum is %d\n",sum[0]); 
	  while (sum[0]==sum[i]) {
        i++;
	  }
	  printf("Number of same sums is %d\n",i);
	  free(sum);
  }
  return 0;
}
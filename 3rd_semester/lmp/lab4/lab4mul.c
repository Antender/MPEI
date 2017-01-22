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

#define asm_arraydata 8
#define asm_arraysize 12
#define asm_lmin 16
#define asm_lmax 20

_declspec(naked) int __cdecl countproduct (array a,limits l) {
  __asm 
  {
    push ebx
    xor eax,eax
    mov ecx, [esp+asm_arraysize]
    mov edx, [esp+asm_arraydata]
    lea edx, [edx+ecx*4-4]
check_limits:                                     
    mov ebx, [edx]
    cmp ebx, [esp+asm_lmin]
    jl short mul_num
    cmp ebx, [esp+asm_lmax]
    jle short check_loop
mul_num:                            
    imul eax,ebx
check_loop:
    sub edx, 4                             
    loop check_limits
    pop ebx
    ret
  }
}

limits getLimits(void) {
  limits l;
  puts("Enter minimal element:");
  scanf("%d", &(l.min));
  puts("Enter maximal element:");
  scanf("%d", &(l.max));
  if (l.max < l.min) {
    int temp = l.min;
    l.min = l.max;
    l.max = temp;
  }
  return l;
}

void printProduct(int product) {
  printf("Product is %d\n", product);
}

int nop(int i) {
  return i;
}

array readFile(char * filename,int fun(int)) {
  FILE * fid = fopen(filename,"r");
  int *ar = NULL;
  int size;
  size = 0;
  if (fid==NULL) {
    printf("File %s doesn't exist\n",filename);
  } else {
  	fscanf(fid, "%d ", &size);
    ar= (int *) malloc(sizeof(int)*size);
    puts("Initial array:");
    for (int counter=0;counter<size;++counter) {
      fscanf(fid, "%d ", &(ar[counter]));
      ar[counter]=(int)fun(ar[counter]);
      printf("%d ",ar[counter]);
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
  if (el2<el1) {
    return -1;
  } else if (el2>el1) {
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
	  int* product = (int*)malloc(sizeof(int)*ARCOUNT);
	  limits l = getLimits();
	  for(int i=0;i<ARCOUNT;i++) {
	    array a;
	    if (i%2) {
	      a = readFile(argv[i+1],abs);
	    } else {
	      a = readFile(argv[i+1],nop);
	    }
	    if (a.size!=0) {
    	  printProduct(product[i] = countproduct(a,l));
        free(a.data);
	    }
	  }
      qsort((void*)product,ARCOUNT,sizeof(int),compare);
	  int i = 0;
	  printf("Maximum product is %d\n",product[0]); 
	  while (product[0]==product[i]) {
        i++;
	  }
	  printf("Number of same products is %d\n",i);
	  free(product);
  }
  return 0;
}

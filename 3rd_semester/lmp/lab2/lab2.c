#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int * data;
  int xsize;
  int ysize;
} array;

array getMatrix(char * filename) {
  FILE * fid = fopen(filename,"r");
  array a;
  if (fid!=NULL) {
  fscanf(fid,"%d %d",&(a.xsize),&(a.ysize));
  int data[a.xsize][] = (int[a.xsize][a.ysize]) malloc(sizeof(int)*(a.xsize)*(a.ysize));
  for (int i=0;i<a.xsize;++i) {
    for (int j=0;j<a.ysize;++j) {
        fscanf(fid,"%d",&(a.data[i][j]));
    }
  }
  } else {
    printf("File %s doesn't exist\n");
    a.xsize=0;
  }
  return a;
}

bool checkMatrix(array a) {
  bool check = true;
  data = (int[a.xsize][a.ysize])a.data;
  for(int i=0;i<a.xsize;++i) {
    for(int j=0;j<a.ysize;++j) {
      if (data[i][j]==0) {
        check=false;
        goto breakall;
      }
    }
  }
  :breakall
  return check;
}

void computeRow(int[] data,int ysize) {
  int c = 0;
  for (int i=0;i<a.ysize;++i) {
    if (data[i]<0) {
      ++c;
    }
  }
  printf("%d ",c);	
}

int main (int argc,char * argv[]) {
  if (argc!=2) {
    puts("Enter matrix filename, please");
  } else {   
    for(int i=2;i<=argc;i++) {
      array a = getMatrix(argv[i]);
      if (a.xsize!=0) {
        if (checkMatrix(a)) {
          for (int i=0;i<i.xsize;++i) {
            computeRow(a[xsize],ysize);          
          }
          puts("");
        }
        free((void*)a.data);
      }
    }     
  }
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  long int a;
  long int b;
  long int c;
} record;

void convertFile(char * inputfile,char * outputfile) {
  FILE * fid = fopen(inputfile,"r");
  FILE * oid = fopen(outputfile,"wb");
  if (fid==NULL) {
    printf("File %s doesn't exist",inputfile);
  } else {
    record temp;
    while(!feof(fid)) {
      fscanf(fid,"%li %li %li",&(temp.a),&(temp.b),&(temp.c));
      fwrite(&temp,sizeof(temp),1,oid);
    }
    fclose(fid);
  }
}

void readFile(char * filename) {
  FILE * fid = fopen(filename,"rb");
  puts("File contents");
  while (!feof(fid)) {
  	record temp;
  	fread(&temp,sizeof(record),1,fid);
  	printf("%li %li %li",temp.a,temp.b,temp.c);
  }
  fclose(fid);
}

void swapRecords(char * filename,int src,int dst)

int main (int argc,char * argv[]) {
  if ((argc<=1) || (argc%2!=0)) {
    puts("Enter pairs of filenames, please");
  } else {
	  for(int i=1;i<argc;i+=2) {
      convertFile(argv[i],argv[i+1]);
    }
  }
  return 0;
}
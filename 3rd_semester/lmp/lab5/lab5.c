#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <stdio.h>

uint32_t set[8];

void clearSet(void) {
  for (int i=0;i<8;++i) {
    set[i]=0;
  }
}

bool testSet(int i) {
  int bucket = i/32;
  int pos = 1<<(i%32-1);
  if (((set[bucket])&pos)>0) {
    return true;
  } else {
    set[bucket]|=pos;
    return false;
  }
}

bool parsing_word;
bool repeats;
char temp_char;
char* word_start;
char* pos;
char str[80];

int main(void) {
  if (fgets(str,80,stdin)!=NULL) {
    pos=str;
    while (*pos!=0) {
      if (isalnum(*pos)) {
        if (!repeats) {
          if (!parsing_word) {
            parsing_word=true;
            clearSet();
            word_start=pos;
            repeats=false;
          }
          if (testSet(*pos)) {
            repeats=true;
          }
        }	        
      } else {
        if (parsing_word) {
          parsing_word=false;
          if (repeats) {
            temp_char=*pos;
            *pos=0;
            printf("%s ",word_start);
            *pos=temp_char;
            repeats=false;
          }
        }
      }
      pos+=sizeof(char);
    }
    if (parsing_word && repeats) {
      printf("%s\n",word_start);
    } else {
      puts("");
    }
  } else {
    puts("");
  }
  getc(stdin);
  return 0;
}


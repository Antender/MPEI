#include <stdint.h>
#include <stdbool.h>

uint32_t check[8];

char * getNotRepeating() {
  
}

bool setCheck(char input) {
  if ((check[input>>3]&(1<<input))>0) {
    return true;
  }
  check[input>>3]|(1<<input);
  return false;
}

char * __declspec(dllexport) __declspec(naked) __cdecl getWithLength(char * input, char * buffer, int length) {
  __asm {

  }
}

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  int size;
  uint32_t * data;
} BitArray;

BitArray* newBitArray(int size) {
  BitArray* array = (BitArray*) malloc(sizeof(BitArray));
  array->size = size;
  array->data = (uint32_t*) calloc(size/32+1,sizeof(uint32_t));
  return array;
}

void freeBitArray(BitArray * array) {
  free(array->data);
  free(array);
}

void clearBitArray(BitArray * array) {
  memset(array->data,0,((array->size)/32+1)*4);
}

void setBitArray(BitArray * array, int pos) {
  (array->data)[pos/32]=((array->data)[pos/32])|(1<<(pos%32));
}

bool getBitArray(BitArray * array, int pos) {
  return ((array->data)[pos/32])&(1<<(pos%32));
}
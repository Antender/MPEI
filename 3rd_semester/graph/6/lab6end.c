#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

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

typedef struct GraphNode {
  int data;
  struct GraphNode* next;
} GraphNode;

typedef struct {
  int size;
  GraphNode ** data;
} Graph;

Graph * readGraph(FILE* fid) {
  int size;
  fscanf(fid,"%i",&size);
  Graph* graph = (Graph*) malloc(sizeof(Graph));
  graph->size = size;
  GraphNode ** data = malloc(sizeof(GraphNode*)*size);
  int link;
  for (int i=0;i<size;++i) {
    GraphNode* temp;
    fscanf(fid,"%i",&link);
    data[i] = NULL;
    while (link!=0) {
      temp = (GraphNode*)malloc(sizeof(GraphNode));
      temp->data = link;
      temp->next = data[i];
      data[i] = temp;
      fscanf(fid,"%i",&link);
    }
  }
  graph->data = data;
  return graph;
}

void sortedWriteGraph(FILE* fid, Graph* graph) {
  GraphNode** data = graph->data;
  int size = graph->size;
  fprintf(fid,"%i\n",size);
  BitArray* array = newBitArray(size);
  for (int i=0;i<size;++i) {
    clearBitArray(array);
    GraphNode* link = data[i];
    while(link!=NULL) {
      setBitArray(array,(link->data)-1);
      link = link->next;
    }
    for (int j=0;j<size;++j) {
      if (getBitArray(array,j)) {
        fprintf(fid,"%i ",j+1);
      }
    }
    fputs("0\n",fid);
  }
  freeBitArray(array);
}
void freeGraph(Graph * graph) {
  GraphNode ** data = graph->data;
  int size = graph->size;
  for (int i=0;i<size;++i) {
    GraphNode * link = data[i];
    GraphNode * nextlink;
    while (link!=NULL) {
      nextlink = link->next;
      free(link);
      link=nextlink;
    }
  }
  free(data);
  free(graph);
}

Graph * complGraph(Graph * graph) {
  Graph* cgraph = (Graph*)malloc(sizeof(Graph));
  int size = ((cgraph->size) = (graph->size));
  GraphNode ** data = graph->data;
  GraphNode ** cdata = (GraphNode**)malloc(sizeof(GraphNode*)*size);
  BitArray * array = newBitArray(size);
  for (int i=0;i<size;++i) {
    GraphNode * link = data[i];
    while (link!=NULL) {
      setBitArray(array,(link->data)-1);
      link = link->next;
    }
    setBitArray(array,i);
    cdata[i] = NULL;
    GraphNode * temp;
    for (int j=0;j<size;++j) {
      if (!getBitArray(array,j) ) {
        temp = malloc(sizeof(GraphNode));
        temp->next = cdata[i];
        temp->data = j+1;
        cdata[i] = temp;
      }
    }
    clearBitArray(array);
  }
  cgraph->data = cdata;
  return cgraph;
}

int main(void) {
  Graph * input = readGraph(stdin);
  Graph * compl = complGraph(input);
  sortedWriteGraph(stdout,compl);
  getc(stdin);
  freeGraph(input);
  freeGraph(compl);
  return 0;
}
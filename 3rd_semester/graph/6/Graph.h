#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "BitArray.h"

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

void writeGraph(FILE* fid, Graph* graph) {
  GraphNode** data = graph->data;
  int size = graph->size;
  fprintf(fid,"%i\n",size);
  for (int i=0;i<size;++i) {
    GraphNode* link = data[i];
    while(link!=NULL) {
      fprintf(fid,"%i ",link->data);
      link = link->next;
    }
    fputs("0\n",fid);
  }
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
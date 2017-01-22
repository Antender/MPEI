#include <stdio.h>
#include "Graph.h"

int main(void) {
  Graph * input = readGraph(stdin);
  Graph * compl = complGraph(input);
  sortedWriteGraph(stdout,compl);
  getc(stdin);
  freeGraph(input);
  freeGraph(compl);
  return 0;
}
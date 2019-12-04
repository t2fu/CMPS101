/*
 * Assignment: Programming Assignment 4(pa4)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]){
  Graph G = newGraph(6);
  //printf("Size: %d", getSize(G));
  addEdge(G,1,2);
  addEdge(G,1,3);
  addEdge(G,2,4);
  addEdge(G,2,5);
  addEdge(G,2,6);
  addEdge(G,3,4);
  addEdge(G,4,5);
  addEdge(G,5,6);
  BFS(G,1);
  //printf("%d\n", "NIL");
  printf("Order: %d\n", getOrder(G));
  printf("Size: %d\n", getSize(G));
  printf("Source: %d\n", getSource(G));
  printf("Parent: %d\n", getParent(G, 4));
  printf("Distance: %d\n", getDist(G, 4));
  List Path = newList();
  getPath(Path, G, 4);
  printList(stdout, Path);
  printf("\n");
  printGraph(stdout, G);
  makeNull(G);
  printf("Order: %d\n", getOrder(G));
  printf("Size: %d\n", getSize(G));
  freeGraph(&G);

}

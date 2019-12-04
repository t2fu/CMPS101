/*
 * Assignment: Programming Assignment 5(pa5)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]){
  Graph G = newGraph(8);
  //printf("Size: %d", getSize(G));
  addArc(G,1,2);
  addArc(G,2,3);
  addArc(G,2,5);
  addArc(G,2,6);
  addArc(G,3,4);
  addArc(G,3,7);
  addArc(G,4,3);
  addArc(G,4,8);
  addArc(G,5,1);
  addArc(G,5,6);
  addArc(G,6,7);
  addArc(G,7,6);
  addArc(G,7,8);
  addArc(G,8,8);
  List L = newList();
  for(int i=1; i<getOrder(G)+1;i++){
    append(L, i);
  }
  DFS(G,L);
  //printf("%d\n", "NIL");
  printf("Order: %d\n", getOrder(G));
  printf("Size: %d\n", getSize(G));
  printf("Finish: %d\n", getFinish(G, 6));
  printf("Parent: %d\n", getParent(G, 1));
  printf("Discover: %d\n", getDiscover(G, 1));

  List Path = newList();
  //getPath(Path, G, 4);
  //printList(stdout, Path);
  printf("\n");
  printGraph(stdout, G);
  printf("\n");
  Graph newG = transpose(G);
  List newL = newList();
  for(int i=1; i<getOrder(newG)+1;i++){
    append(newL, i);
  }
  DFS(newG, newL);
  printGraph(stdout, newG);
  printf("Finish: %d\n", getFinish(newG, 6));
  makeNull(G);
  printf("Order: %d\n", getOrder(G));
  printf("Size: %d\n", getSize(G));
  freeGraph(&G);
  freeGraph(&newG);
  freeList(&newL);
  freeList(&L);
}

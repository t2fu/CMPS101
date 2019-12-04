/*
 * Assignment: Programming Assignment 5(pa5)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
#define MAX_LEN 160

int main(int argc, char* argv[]){

if (argc == 3){
  char line[MAX_LEN];
  char* inputName = argv[1];
  char* outputName = argv[2];


  FILE* in = fopen(inputName, "r");
  FILE* out = fopen(outputName, "w");

  //fgets(line, MAX_LEN, in);
  int num1;
  fscanf(in, "%d", &num1);
  int n = num1;
  //printf("n: %d\n", n);
  //int* inputs1[10000];
  //int* inputs2[10000];

  //for(int i=0; i < MAX_LEN; i++){
      //inputs1[i] = malloc(sizeof(int));
      //inputs1[i] = 0;
      //inputs2[i] = malloc(sizeof(int));
      //inputs2[i] = 0;
  //}

  int read1;
  int read2;
  int r = 0;
  Graph G = newGraph(n);
  int sw = 0;
  //int count = 0;
  int c = 0;

  while((r = fscanf(in, "%d %d", &read1, &read2)) != EOF && sw == 0){
    if (r == 2){
      if(read1 != 0){
        //printf("%d\n", read2);
        addArc(G, read1, read2);
        //inputs1[c] = malloc(sizeof(int));
        //inputs1[c] = read1;
        //inputs2[c] = malloc(sizeof(int));
        //inputs2[c] = read2;
        //printf("%d %d\n", inputs1[c], inputs2[c]);
        c++;

      }else if(read1 == 0){
        sw = 1;
      }
    }
  }
  fclose(in);
  fprintf(out, "Adjacency list representation of G:");
  fprintf(out, "\n");
  printGraph(out, G);
  fprintf(out, "\n");
  //printf("worked");
  List L = newList();
  int* deleted[MAX_LEN];
  for(int i = 0; i < getOrder(G)+1; i++){
    deleted[i] = malloc(sizeof(int));
    deleted[i] = 0;
  }
  for(int i = 1; i < getOrder(G)+1; i++){
    append(L, i);
  }
  DFS(G, L);
  //printList(stdout,L);
  Graph G1 = transpose(G);
  Graph G2 = transpose(G);
  List queue = newList();
  int count = 1;
  clear(queue);
  int cc = 0;

  while(length(L)>0){
    append(queue,front(L));
    for(int i=2; i < getOrder(G1)+1; i++){
      append(queue, 0);
    }
    DFS(G1, queue);
    //moveFront(queue);
    for(moveFront(queue); index(queue)!=-1;moveNext(queue)){
    if(deleted[get(queue)] == 1){
        delete(queue);
        moveFront(queue);
      }
    }

    moveFront(queue);
    while(length(queue)>0){
      for(moveFront(L);index(L)!=-1;moveNext(L)){
        if(front(queue) == get(L)){
          deleteFront(queue);
          deleted[get(L)] = 1;
          delete(L);
          moveFront(L);
          //printList(stdout,queue);
          //printList(stdout,L);
        }
      }
    }
    //printf(" |quit| ");
    count++;
  }
  /*
  int* found[MAX_LEN];
  List* SCC[MAX_LEN];
  int count = 0;
  for(int i=1;i< getOrder(G)+1;i++){
    SCC[i]=malloc(sizeof(List));
    int a = GetSCC(G, SCC, i);
    if(a != -1){
      found[i]=malloc(sizeof(int));
      found[i]=1;
      count++;
    }

  }*/
  fprintf(out, "G contains %d strongly connected components:\n", count-1);

  clear(L);
  clear(queue);
  for(int i = 1; i < getOrder(G)+1; i++){
    append(L, i);
  }
  for(int i = 0; i < getOrder(G)+1; i++){
    //deleted[i] = malloc(sizeof(int));
    deleted[i] = 0;
  }
  DFS(G, L);
  int count2 = 1;
  //printList(stdout,L);

  while(length(L) > 0){
    append(queue, front(L));
    for(int i = 2; i < getOrder(G2)+1;i++){
      append(queue, 0);
    }
    DFS(G2, queue);
    for(moveFront(queue); index(queue)!=-1;moveNext(queue)){
    if(deleted[get(queue)] == 1){
        delete(queue);
        moveFront(queue);
      }
    }
    fprintf(out, "Component %d: ", count2);
    printList(out, queue);
    fprintf(out, "\n");
    moveFront(queue);
    while(length(queue) > 0){
      for(moveFront(L); index(L) != -1; moveNext(L)){
        if(front(queue) == get(L)){
          deleteFront(queue);
          deleted[get(L)] = 1;
          delete(L);
          moveFront(L);
        }
      }
    }
    count2++;
  }
  /*
  for(int i = 1;i< getOrder(G)+1; i++){
    if(found[i]==1){
    fprintf(out,"Component %d: ",d);
    d++;
    printList(out, SCC[i]);
    fprintf(out,"\n");
    }
  }*/
  for(int q = 0;q < MAX_LEN;q++){
    deleted[q] = 0;
    free(deleted[q]);
    //inputs1[q] = 0;
    //free(inputs1[q]);
    //inputs2[q] = 0;
    //free(inputs2[q]);
    //printf("count:%d ",z);
  }
  freeGraph(&G);
  freeGraph(&G1);
  freeGraph(&G2);
  freeList(&L);
  freeList(&queue);
  fclose(out);
  }else{
    fprintf(stdout, "Input Error\n");
    exit(1);
  }
  return(0);
}

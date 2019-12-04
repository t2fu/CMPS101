/*
 * Assignment: Programming Assignment 4(pa4)
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
  int* inputs1[10000];
  int* inputs2[10000];
  for(int i=0; i < MAX_LEN; i++){

      inputs1[i] = malloc(sizeof(int));
      inputs1[i] = 0;
      inputs2[i] = malloc(sizeof(int));
      inputs2[i] = 0;
  }
  int read1;
  int read2;
  int r = 0;
  Graph G = newGraph(n);
  int sw = 0;
  int count = 0;
  int c = 0;

  while((r = fscanf(in, "%d %d", &read1, &read2)) != EOF){
    if (r == 2 && sw == 0){
      if(read1 != 0){
        //printf("%d\n", read2);
      addEdge(G, read1, read2);
      //inputs1[c] = malloc(sizeof(int));
      inputs1[c] = read1;
      //inputs2[c] = malloc(sizeof(int));
      inputs2[c] = read2;
      //printf("%d %d\n", inputs1[c], inputs2[c]);
      c++;

      }else if(read1 == 0){
        sw = 1;
        printGraph(out, G);
      }
    }else{
      //printf("worked");
      if(read1 != 0){
      BFS(G, read1);
      //printf("source: %d Distance: %d| ", getSource (G), getDist(G,read2));
      if(getDist(G, read2) != INF){
      fprintf(out, "\n");
      fprintf(out, "The distance from %d to %d is %d\n", read1, read2, getDist(G, read2));
      fprintf(out, "A shortest %d-%d path is: ", read1, read2);
      List Path = newList();
      getPath(Path, G, read2);
      printList(out, Path);
      freeList(&Path);
      fprintf(out, "\n");

      //printf("\n");
      count++;
      }else if (read1 != read2){
      fprintf(out, "\n");
      fprintf(out, "The distance from %d to %d is infinity\n", read1, read2);
      fprintf(out, "No %d-%d path exists", read1, read2);
      fprintf(out, "\n");

      //printf("\n");
      count++;
      }else if (read1 == read2){
      fprintf(out, "\n");
      fprintf(out, "The distance from %d to %d is 0\n", read1, read2);
      fprintf(out, "A shortest %d-%d path is: %d", read1, read2, read1);
      fprintf(out, "\n");

      //printf("\n");
      count++;
      }
      makeNull(G);
      G = newGraph(n);
      for(int z=0; z < c; z++){
       addEdge(G, inputs1[z], inputs2[z]);
      }
     }
    }
  }
  fclose(in);
  //printf("count: %d", count);
        //freeList(&indexL);
  for(int q = 0;q<MAX_LEN;q++){
    inputs1[q] = 0;
    free(inputs1[q]);
    inputs2[q] = 0;
    free(inputs2[q]);
    //printf("count:%d ",z);
  }
  freeGraph(&G);
  fclose(out);
  }else{
    fprintf(stdout, "Input Error\n");
    exit(1);
  }
  return(0);
}

/*
 * Assignment: Programming Assignment 2(pa2)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"

#define MAX_LEN 160

int main(int argc, char * argv[]){
  if (argc == 3){
  char line[MAX_LEN];
  char* inputName = argv[1];
  char* outputName = argv[2];


  FILE *in = fopen(inputName, "r");
  FILE *out = fopen(outputName, "w");

  int n = 0;
  while(fgets(line, MAX_LEN, in) != NULL)  {
    n++;
  }
  char* words[n];
  //int count = 0;
  fclose(in);
  in = fopen(inputName, "r");
    for(int z =0; fgets(line, MAX_LEN, in) != NULL && z < n; z++)  {
    //words[z] = calloc(MAX_LEN, sizeof(char));
      words[z] = (char*) malloc(MAX_LEN);
    //char* p = strtok(line, "\n");
    //strcpy(words[z], p);
      //char* p = strtok(line, "\n");
      strcpy(words[z], line);
    //fprintf(stdout, words[z]);
    }

  //for(int z=0;z<5;z++){
    //fprintf(stdout, words[z]);
  //}

  fclose(in);
  List indexL = newList();


        for(int i = 0;i < n; i++){
          char* key = words[i];
          int j = 0;
          int z = 0;
          int change = 0;
          int location = 0;
          if(i != 0){
           j = i-1;
           moveFront(indexL);
         for(z=0; z <= j; z++){
          //words[j + 1] = words[j];
          if(strcmp(words[get(indexL)], key)<0){
           //System.out.println(words[z]+" "+key+z);
           change = 1;
           location = index(indexL);
          }
          if(index(indexL) < j){
           moveNext(indexL);
          }
         }
         }else{
            prepend(indexL, i);
          }
            moveFront(indexL);
          for(int k=0; k < location; k++){
            moveNext(indexL);
          }
          if(i != 0 && change == 1){
            insertAfter(indexL, i);
          }else if(i != 0 && change == 0){
            //System.out.println("a "+i);
            prepend(indexL, i);
          }
       }
       moveFront(indexL);
        for(int z=0; z < n; z++){
          fprintf(out, words[get(indexL)]);
          moveNext(indexL);
        }
        for(int q = 0; q<n; q++){
        free(words[q]);
        }
        freeList(&indexL);
        fclose(out);
  }else{
    fprintf(stdout, "Input Error\n");
    exit(1);
  }
  return(0);
}

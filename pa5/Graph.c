/*
 * Assignment: Programming Assignment 5(pa5)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"
#include"List.h"

#define MAX_LEN 100
//*** Constructors-Destructors ***/
typedef struct GraphObj{
   int n;
   int order;//number of vertices
   int size;//number of the edge
   //int source;
   //int path;
   List* neighbor[MAX_LEN];
   int* color[MAX_LEN];//0 white ,1 grey, 2 black
   int* parent[MAX_LEN];
   //int* distance[MAX_LEN];//distance from the source
   int* discover[MAX_LEN];
   int* finish[MAX_LEN];
} GraphObj;

typedef struct GraphObj* Graph;

Graph newGraph(int n){
  Graph G = malloc(sizeof(GraphObj));
  G->n = n;
  //G->order = malloc(MAX_LEN);
  G->order = n;
  //printf("order: %d",G->order);
  G->size = 0;
  //G->source = 0;
  for(int i=0; i < n+1; i++){
    G->neighbor[i] = malloc(sizeof(List));
    G->neighbor[i] = newList();
    G->discover[i] = malloc(sizeof(int));
    G->discover[i] = -1;
    G->color[i] = malloc(sizeof(int));
    G->color[i] = 0;
    G->parent[i] = malloc(sizeof(int));
    G->parent[i] = 0;
    G->finish[i] = malloc(sizeof(int));
    G->finish[i] = -1;
  }
  return G;
}

void freeGraph(Graph* pG){
   if(pG!=NULL && *pG!=NULL){
      if(*pG != NULL){
        makeNull(*pG);
      }
      free(*pG);
      *pG = NULL;
   }
}

//*** Access functions ***/
int getOrder(Graph G){
  //printf("order: %d",G->order);
  return (G->order);
}

int getSize(Graph G){
  return (G->size);
}

int getParent(Graph G, int u){
  if(1<=u && u <= getOrder(G)){
    return (G->parent[u]);
  }else{
    return 0;
  }
}

int getDiscover(Graph G, int u){
  //int index = 0;
  if(1<=u && u <= getOrder(G)){
    return (G->discover[u]);
  }else{
    return -1;
  }
}

int getFinish(Graph G, int u){
  if(1<=u && u <= getOrder(G)){
    return (G->finish[u]);
  }else{
    return -1;
  }
}

//*** Manipulation procedures ***/
void makeNull(Graph G){
    if(G != NULL){
      //Node current = D->front;
      //Node temp = NULL;
    for(int q = 0; q < G->n+1; q++){
      clear(G->neighbor[q]);
      G->color[q] = 0;
      G->parent[q] = 0;
      G->discover[q] = 0;
      G->finish[q] = 0;
      free(G->color[q]);
      free(G->parent[q]);
      free(G->discover[q]);
      free(G->finish[q]);
    }
    G->n = 0;
    G->order = 0;
    G->size = 0;
    //G->source = 0;
    }
}

void addEdge(Graph G, int u, int v){
 if(1<=u && u<=getOrder(G) && 1<=v && v<=getOrder(G)){
  //printf("add: %d %d\n", u, v);
  G->size++;
  int Max1 = 0;
  int Max2 = 0;
  //fprintf(stdout, "Runned 1");
  if(length(G->neighbor[u]) == 0){
    //fprintf(stdout, "Runned 1");
    append(G->neighbor[u], v);
    //G->size++;
  }else{
    moveFront(G->neighbor[u]);
    //printf("%d ",v);
    //int lastV = 0;
    for(int i = 0; i< length(G->neighbor[u]); i++){
      if(get(G->neighbor[u])<v){
        //printf(" %d: %d", i, get(G->neighbor[u]));
        moveNext(G->neighbor[u]);
        Max1++;
      }
    }
    moveFront(G->neighbor[u]);
    if(Max1 == 0){
    insertBefore(G->neighbor[u],v);
    }else{
    for(int j = 1; j < Max1; j++){
    moveNext(G->neighbor[u]);
    }
    insertAfter(G->neighbor[u],v);
   }
    //G->size++;
  }

  if(length(G->neighbor[v]) == 0){
    append(G->neighbor[v], u);
  }else{
    moveFront(G->neighbor[v]);
    //int lastV = 0;
    for(int i = 0; i < length(G->neighbor[v]); i++){
      if(get(G->neighbor[v])<u){
        moveNext(G->neighbor[v]);
        Max2++;
      }
    }
    moveFront(G->neighbor[v]);
    if(Max2 == 0){
    insertBefore(G->neighbor[v],u);
    }else{
    for(int j = 1; j < Max2; j++){
      moveNext(G->neighbor[v]);
    }
    insertAfter(G->neighbor[v],u);
    }
  }
 }
}

void addArc(Graph G, int u, int v){
  if(1<=u && u<=getOrder(G) && 1<=v && v<=getOrder(G)){
  G->size++;
  int Max1 = 0;
  if(length(G->neighbor[u]) == 0){
    //fprintf(stdout, "Runned 1");
    append(G->neighbor[u], v);
    //G->size++;
  }else{
    moveFront(G->neighbor[u]);
    //printf("%d ",v);
    //int lastV = 0;
    for(int i = 0; i< length(G->neighbor[u]); i++){
      if(get(G->neighbor[u])<v){
        //printf(" %d: %d", i, get(G->neighbor[u]));
        moveNext(G->neighbor[u]);
        Max1++;
      }
    }
    moveFront(G->neighbor[u]);
    if(Max1 == 0){
    insertBefore(G->neighbor[u],v);
    }else{
    for(int j = 1; j < Max1; j++){
    moveNext(G->neighbor[u]);
    }
    insertAfter(G->neighbor[u],v);
   }
    //G->size++;
  }
 }
}

/*int GetSCC(Graph G, List SCC, int s){
  //int* found[MAX_LEN];
  int f = -1;

    List queue = newList();
    //SCC[s] = malloc(sizeof(List));
    SCC = newList();
    append(queue, s);
    int stop = 0;
    //moveFront(temp);
  while(length(queue) != 0 && stop != 1){
    moveFront(queue);
    int currentV = get(queue);
    deleteFront(queue);
    moveFront(G->neighbor[currentV]);
    int temp = get(G->neighbor[currentV]);
    //moveFront(temp);
    while(temp != -1 && G->color[currentV] == 1){
       int adjV = temp;
       if(G->color[adjV] == 0){
         if(length(G->neighbor[adjV]) == 0){
           G->color[adjV] = 2;
           stop = 1;
           return -1;
         }else if(adjV == s){
           G->color[adjV] = 1;
           stop = 1;
           append(SCC, adjV);
           f = 1;
         }else{
         G->color[adjV] = 1;
         append(queue, adjV);
         append(SCC, adjV);
         }
       }
      moveNext(G->neighbor[currentV]);
      temp = get(G->neighbor[currentV]);
    }
    G->color[currentV] = 2;
  }
  return f;
}*/

void DFS(Graph G, List S){
  if(length(S) == G->n && G->n == getOrder(G)){
  //int time;
  //List queue = newList();
  //int NIL = atoi("NIL");
  //append(queue, s);
  moveFront(S);
  int s = get(S);
  int org[length(S)];
  for(int i = 0; i < length(S) && get(S) != -1;i++){
    org[i] = get(S);
    moveNext(S);
  }

  for(int i = 0; i < getOrder(G)+1; i++){
  G->color[i] = 0;
  G->parent[i] = 0;
  }

  clear(S);
  int time = 0;
  //moveFront(S);
  for(int i = 0; i <getOrder(G); i++){
    int x = org[i];
    if(x!=0 && G->color[x] == 0){
      Visit(G, S, x, &time);
    }
    //moveNext(S);
  }
 }
}

void Visit(Graph G, List S, int x, int* time){
  ++*time;
  G->discover[x] = *time;
  G->color[x] = 1;
  List queue = G->neighbor[x];
  if(queue != NULL){
    moveFront(queue);
    for(int i = 0; i<length(queue) && get(queue) != -1;i++){
      int temp = get(queue);
      if(G->color[temp] == 0){
        G->parent[temp] = x;
        Visit(G, S, temp, time);
      }
      moveNext(queue);
    }
  }
  G->color[x] = 2;
  G->finish[x] = ++*time;
  prepend(S, x);
}



//*** Other operations ***/
Graph transpose(Graph G){
  Graph NewGraph = newGraph(G->n);
  NewGraph->n = G->n;
  NewGraph->order = G->order;
  NewGraph->size = G->size;
  for(int q = 1; q < G->n+1; q++){
    moveFront(G->neighbor[q]);
    int temp = get(G->neighbor[q]);
    while(temp != -1){
     append(NewGraph->neighbor[temp], q);
     moveNext(G->neighbor[q]);
     temp =get(G->neighbor[q]);
    }
    //NewGraph->color[q] = G->color[q];
  }
  //DFS(NewGraph);
  return NewGraph;
}

Graph copyGraph(Graph G){
  Graph NewGraph = newGraph(G->n);
  NewGraph->n = G -> n;
  NewGraph->order = G -> order;
  NewGraph->size =  G->size;

  for(int q = 0; q < G->n+1; q++){
    NewGraph->neighbor[q] = G->neighbor[q];
    NewGraph->color[q] = G->color[q];
    NewGraph->parent[q] = G->parent[q];
    NewGraph->discover[q] = G->discover[q];
    NewGraph->finish[q] = G->finish[q];
  }

  return NewGraph;
}

void printGraph(FILE* out, Graph G){
    for(int i = 1; i < getOrder(G)+1; i++){
      fprintf(out, "%d: ", i);
      moveFront(G->neighbor[i]);

      if(index(G->neighbor[i]) != -1){
       for(int j = 0; j < length(G->neighbor[i]); j++){
         fprintf(out, "%d ", get(G->neighbor[i]));
         moveNext(G->neighbor[i]);
       }
      }

      fprintf(out, "\n");
    }
}

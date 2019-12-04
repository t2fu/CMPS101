/*
 * Assignment: Programming Assignment 4(pa4)
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
   int source;
   //int path;
   List* neighbor[MAX_LEN];
   int* color[MAX_LEN];//0 white ,1 grey, 2 black
   int* parent[MAX_LEN];
   int* distance[MAX_LEN];//distance from the source
} GraphObj;

typedef struct GraphObj* Graph;

Graph newGraph(int n){
  Graph G = malloc(sizeof(GraphObj));
  G->n = n;
  //G->order = malloc(MAX_LEN);
  G->order = n;
  //printf("order: %d",G->order);
  G->size = 0;
  G->source = NIL;
  for(int i=0; i < n+1; i++){
    G->neighbor[i] = malloc(sizeof(List));
    G->neighbor[i] = newList();
    G->distance[i] = malloc(sizeof(int));
    G->distance[i] = INF;
    G->color[i] = malloc(sizeof(int));
    G->color[i] = 0;
    G->parent[i] = malloc(sizeof(int));
    G->parent[i] = NIL;

  }
  //G->neighbor = newList[n+1];
  //G->distance = new int[n+1];
  //G->color = 0;
  //G->parent = 0;
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

int getSource(Graph G){
  return (G->source);
}

int getParent(Graph G, int u){
  //if(1<=u && u <= getOrder(G)){
    return (G->parent[u]);
  //}else{
    //int NIL = 0;
  //  return NIL;
  //}
}

int getDist(Graph G, int u){
  //int index = 0;
  if(1<=u && u <= getOrder(G)){
  return (G->distance[u]);
  }else{
    //int INF = -1;
    return INF;
  }
}
void getPath(List L, Graph G, int u){
  int p = G->parent[u];
  if(G->distance[u]==INF){
     append(L,NIL);
     return;
  }
  append(L,u);
  while(p!=NIL){
    prepend(L,p);
    p = G->parent[p];
  }
}

//*** Manipulation procedures ***/
void makeNull(Graph G){
    if(G != NULL){
      //Node current = D->front;
      //Node temp = NULL;
    for(int q = 0; q < G->n; q++){
      clear(G->neighbor[q]);
      G->color[q] = 0;
      G->parent[q] = NIL;
      G->distance[q] = INF;
      free(G->color[q]);
      free(G->parent[q]);
      free(G->distance[q]);
    }
    G->n = 0;
    G->order = 0;
    G->size = 0;
    G->source = NIL;
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

void BFS(Graph G, int s){
  G->source = s;
  List queue = newList();
  //int NIL = 0;
  G->color[s] = 1;
  G->parent[s] = NIL;
  G->distance[s] = 0;
  append(queue, s);

  //List current = newList();
  //current = G->neighbor[s];
  //moveFront(queue);
  //moveFront(G->neighbor[currentV]);
  while(length(queue) != 0){
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
         }else{
         G->color[adjV] = 1;
         append(queue, adjV);
         }
         if(currentV == 0){
           //int NIL = atoi("NIL");
           G->parent[adjV] = NIL;
         }else{
         G->parent[adjV] = currentV;
         }
       }
      moveNext(G->neighbor[currentV]);
      temp = get(G->neighbor[currentV]);
    }
    G->color[currentV] = 2;
    //printList(stdout, queue);
    //printf("\n");
  }
    for(int i = 1; i < getOrder(G)+1; i++){
      int temp = getParent(G, i);
      while (temp != 0){
        G->distance[i]++;
        temp = getParent(G, temp);
      }
      int f = G->distance[i];
      if(f == 0){
      //int INF = -1;
      G->distance[i] = INF;
      }else{
      G->distance[i] = f/4;
      }
    }

}

//*** Other operations ***/
void printGraph(FILE* out, Graph G){
    //while(a != NULL){
      //fprintf(out, "%d", a->Data);
      //fprintf(out, " ");
      //a = a->next;
    //}
    for(int i = 1; i < getOrder(G)+1; i++){
      fprintf(out, "%d: ", i);
      //fprintf(out, "%d", a->Data);
      //fprintf(out, " ");
      //a = a->next;
      moveFront(G->neighbor[i]);
      if(index(G->neighbor[i]) != -1){
       for(int j = 0; j < length(G->neighbor[i]); j++){
         fprintf(out, "%d ", get(G->neighbor[i]));
         moveNext(G->neighbor[i]);
       }
      }
      fprintf(out, "\n");
    }

    //for(int i = 1; i < getOrder(G); i++){
    //  moveFront(G->neighbor[i]);
    //  if(index(G->neighbor[i]) != -1){
    //   for(int j = 0; j < length(G->neighbor[i])-1; j++){
         //fprintf(out, "%d ", get(G->neighbor[i]));
    //     if(neighbor)
    //     moveNext(G->neighbor[i]);
    //   }
    //  }
    //  fprintf(out, "\n");
    //}

}

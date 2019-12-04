/*
 * Assignment: Programming Assignment 5(pa5)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#define NIL 0
#define UNDEF -1
#include"List.h"

//*** Constructors-Destructors ***/
typedef struct GraphObj* Graph;
Graph newGraph(int n);
void freeGraph(Graph* pG);

/* Access functions */
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getDiscover(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u); /* Pre: 1<=u<=n=getOrder(G) */

/* Manipulation procedures */
void makeNull(Graph G);
void addArc(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void addEdge(Graph G, int u, int v); /* Pre: 1<=u<=n, 1<=v<=n */
void DFS(Graph G, List S); /* Pre: length(S)==getOrder(G) */
void Visit(Graph G, List S, int x, int* time);

/* Other Functions */
Graph transpose(Graph G);
Graph copyGraph(Graph G);
void printGraph(FILE* out , Graph G);

#endif // GRAPH_H_INCLUDED

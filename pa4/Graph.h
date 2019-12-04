/*
 * Assignment: Programming Assignment 4(pa4)
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#define NIL 0
#define INF -1
#include"List.h"

//*** Constructors-Destructors ***/
typedef struct GraphObj* Graph;
Graph newGraph(int n);
void freeGraph(Graph* pG);

//*** Access functions ***/
int getOrder(Graph G);
int getSize(Graph G);
int getSource(Graph G);
int getParent(Graph G, int u);
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);

//*** Manipulation procedures ***/
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);

//*** Other operations ***/
void printGraph(FILE* out, Graph G);

#endif // GRAPH_H_INCLUDED

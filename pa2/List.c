/*
 * Assignment: Programming Assignment 2
 * Programmer: Tiancheng Fu
 * CruzId: tfu6
 * Student id: 1600058
 */
#include<stdio.h>
#include<stdlib.h>
#include"List.h"

typedef struct NodeObj{
   int Data;
   struct NodeObj* next;
   struct NodeObj* previous;
} NodeObj;

// Node
typedef NodeObj* Node;

// newNode()
// constructor of the Node type
Node newNode(int data) {
   Node N = malloc(sizeof(NodeObj));
   //assert(N!=NULL);
   N->Data = data;
   N->next = NULL;
   N->previous = NULL;
   return(N);
}

// freeNode()
// destructor for the Node type
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// Declare ListObj
typedef struct ListObj{
   Node front;
   Node back;
   Node cursor;
   int length;
   int indexF;
} ListObj;

// List
// Exported reference type
typedef struct ListObj* List;

// newList()
// constructor for the List type
List newList(void){
   List D = malloc(sizeof(ListObj));
   // malloc(sizeof(NodeObj))
   D->front = NULL;
   D->back = NULL;
   D->cursor = NULL;
   D->length = 0; // The length of the List
   D->indexF = -1;
   //assert(D!=NULL);
   //D->Value = NULL;
   return D;
}

// freeList()
// destructor for the List type
void freeList(List* pD){
   if( pD!=NULL && *pD!=NULL ){
      //Node current = *pD->front;
      //Node temp = NULL;
      if( *pD != NULL){
        //Node *nd = pD->hashtable;
        //free(*nd);
        //temp = current;
        //freeNode(&temp);
        //current = current->next;
        clear(*pD);
      }
      free(*pD);
      *pD = NULL;
   }
}

int length(List L){
    return(L->length);
}

int index(List L){
    if(L->cursor != NULL){
      return(L->indexF);
    }else{
      return -1;
    }
}

int front(List L){
 int d = -1;
 if(length(L) > 0){
    d = L->front->Data;
 }
    return d;
}

int back(List L){
  int d = -1;
  if(length(L) > 0){
    d = L->back->Data;
  }
  return d;
}

int get(List L){
  int d = -1;
  if(length(L)>0 && index(L) >= 0){
    d = L->cursor->Data;
  }
  return d;
}

int equals(List A, List B){
    int equal = 0;
    Node a1 = A->front;
    Node b1 = B->front;
    //printf("A front %d", front(A));
    if(a1 == NULL && b1 == NULL){
        //freeNode(&a1);
        //freeNode(&b1);
        return 1;
    }
    while(a1 != NULL && b1 !=NULL){
      int eq = (a1->Data == b1->Data);
      if(eq){
        equal = 1;
      }else{
        //freeNode(&a1);
        //freeNode(&b1);
        //printf("B front %d", front(B));
        return 0;
      }
      a1 = a1->next;
      b1 = b1->next;
    }
    //printf("A front %d", front(A));
    //freeNode(&a1);
    //freeNode(&b1);
    return equal;
}

void clear(List D){
    //printf("Runned");
    if(D != NULL){
      Node current = D->front;
      Node temp = NULL;
    while(current != NULL){
      temp = current;
      freeNode(&temp);
      current = current->next;
    }
    D->front = NULL;
    D->back = NULL;
    D->cursor = NULL;
    D->indexF = -1;
    D->length = 0;
    }
}

void moveFront(List L){
    if(length(L) > 0){
      L->cursor = L->front;
      L->indexF = 0;
    }
}
void moveBack(List L){
    if(length(L) > 0){
      L->cursor = L->back;
      L->indexF = length(L) - 1;
    }
}
void movePrev(List L){
    if(L->cursor != NULL && L->cursor != L->front){
      L->cursor = L->cursor->previous;
      L->indexF--;
    }else if(L->cursor != NULL && L->cursor == L->front){
      L->cursor = NULL;
      L->indexF = -1;
    }
}

void moveNext(List L){
    if(L->cursor != NULL && L->cursor != L->back){
      L->cursor = L->cursor->next;
      L->indexF++;
    }else if(L->cursor != NULL && L->cursor == L->back){
      L->cursor = NULL;
      L->indexF = -1;
    }
}

void prepend(List L, int data){
      Node new_Node = newNode(data);
      new_Node->next = L->front;
      new_Node->previous = NULL;

      if(L->front != NULL){
       L->front->previous = new_Node;
      }
       L->front = new_Node;
       if(L->indexF != -1){
         L->indexF++;
       }
       if(L->length == 0 && L->back == NULL){
         L->back = new_Node;
       }
       L->length++;
       //printf("%d ",L->front->Data);
}

void append(List L, int data){
     L->length++;
     Node new_Node = newNode(data);
     if(L->back != NULL){
      new_Node->previous = L->back;
      new_Node->next = NULL;

      L->back->next = new_Node;
      L->back = new_Node;
     }else{
      L->front = new_Node;
      L->back = new_Node;
     }
}

void insertBefore(List L, int data){
    if(length(L) > 0 && index(L) >= 0){
    if(index(L) == 0){
        prepend(L, data);
    }else{
       movePrev(L);
       insertAfter(L, data);
       moveNext(L);
       moveNext(L);
       //System.out.println(toString());
    }
  }
}

void insertAfter(List L, int data){
    if(length(L) > 0 && index(L) >= 0){
    if(index(L) == length(L) -1){
        append(L, data);
    }else{
       L->length++;
       Node new_Node = newNode(data);
       new_Node->next = L->cursor->next;
       new_Node->previous = L->cursor;
       L->cursor->next = new_Node;
    }
   }
}

void deleteFront(List L){
   if(length(L) > 0){
    Node N = L->front;
    if(length(L) > 1){
      L->front = L->front->next;
      L->length--;
      if(L->indexF >= 1){
        L->indexF--;
      }else{
        L->cursor = NULL;
        L->indexF = -1;
      }
    }else if(length(L) == 1){
      L->front = NULL;
      L->back = NULL;
      L->cursor = NULL;
      L->length--;
      L->indexF = -1;
    }
    freeNode(&N);
   }
}

void deleteBack(List L){
    if(length(L) > 0){
        Node N = L->back;
     if(length(L) > 1){
       L->back = L->back->previous;
       if(L->indexF == length(L) -1){
         L->indexF = -1;
         L->cursor = NULL;
       }
       L->length--;

     }else if(length(L) == 1){
      L->front = NULL;
      L->back = NULL;
      L->cursor = NULL;
      L->length--;
      L->indexF = -1;
     }
     freeNode(&N);
    }
}

void delete(List L){
    if(length(L) > 0 && index(L) >= 0){
        Node N = NULL;
        N = L->cursor;
      if(L->front == L->cursor && index(L) == 0) {
        //N = L->cursor;
        L->front = L->cursor->next;
      }
      if (L->cursor->next != NULL) {
        //N = L->cursor;
        L->cursor->next->previous = L->cursor->previous;
      }
      if(L->cursor->previous != NULL) {
        //N = L->cursor;
        L->cursor->previous->next = L->cursor->next;
      }
     freeNode(&N);
     L->cursor = NULL;
     L->indexF = -1;
     L->length--;
   }
}

void printList(FILE *out, List L){
    Node a = L->front;
    while(a != NULL){
      fprintf(out, "%d", a->Data);
      fprintf(out, " ");
      a = a->next;
    }
    //freeNode(&a);
    //fprintf(out, "\n");
    //fclose(out);
}

List copyList(List L){
    List new_List = newList();
    Node a = L->front;
    while(a != NULL){
      append(new_List, a->Data);
      a = a->next;
      new_List->length++;
    }
    //freeNode(&a);
    return new_List;
}

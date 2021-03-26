#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};


typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* l = (List*) calloc(1, sizeof(List));
  return l;
}

void * firstList(List * list) {
  list->current = list->head;
  const void* data = list->current->data;
  return (void*) data;
}

void * nextList(List * list) {
  if (list->current != NULL && list->current->next ){
    list->current = list->current->next;
    return (void*)list->current->data;
  }
  return NULL;
}

void * lastList(List * list) {
  list->current = list->tail;
    return (void*)list->current->data;
}

void * prevList(List * list) {
  if( list->current != NULL && list->current->prev != NULL){
    list->current = list->current->prev;
    return (void*)list->current->data;
  }
  return NULL;  
}

void pushFront(List * list, const void * data) {
  Node* nuevoNodo = createNode(data);
  
  if( list->head == NULL){
    list->tail = nuevoNodo;
  }
  else{
    nuevoNodo->next = list->head;
    list->head->prev = nuevoNodo;
  }

  list->head = nuevoNodo;
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {

  if( list->current == NULL) return;

  Node* nuevoNodo = createNode(data);
  
  nuevoNodo->next = list->current->next;
  nuevoNodo->prev = list->current;
  
  if (list->current->next != NULL) {
        list->current->next->prev = nuevoNodo;
    }

    list->current->next = nuevoNodo;

    if (list->current == list->tail) {
        list->tail = nuevoNodo;
    }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if(list == NULL) return NULL;
  if (list->head == NULL || list->current == NULL) return NULL;

    Node * aux = list->current;

    if (list->current == list->head) {
        return popFront(list);
    } else if (list->current == list->tail) {
        return popBack(list); 
    } else {
        if (aux->next != NULL) {
            aux->next->prev = aux->prev;
        }

        if (aux->prev != NULL) {
            aux->prev->next = aux->next;
        }
    }
    const void* data = aux->data;
    list->current = aux->next;
    return (void*) data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
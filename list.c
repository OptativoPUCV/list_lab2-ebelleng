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

Node * createNode(void * data) {
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
  if ( list->current->next ){
    list->current = list->current->next;
    return (void*)list->current->data;
  }
  return NULL;
}

void * lastList(List * list) {
  list->current = list->tail;
    return list->current;
}

void * prevList(List * list) {
  if( list->current ){
    list->current = list->current->prev;
    return list->current;
  }
  else{
    return NULL;
  }
  
}

void pushFront(List * list, const void * data) {
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
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
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
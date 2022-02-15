#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int value;
  struct _node *next;
} Node;

typedef struct _linkedlist {
  Node *head;
  Node *tail;
  Node *current;
} LinkedList;

void initializeList(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
}

void displayList(LinkedList *list) {
  printf("Displaying current List: \n");
  Node *current = list->head;
  while(current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
}

void addHead(LinkedList *list, int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = data;
  if (list->head == NULL) {
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head;
  }
  list->head = node;
}

int main(void) {
  LinkedList list1;
  initializeList(&list1);
  addHead(&list1, 1);
  addHead(&list1, 3);
  addHead(&list1, 5);
  addHead(&list1, 4);
  addHead(&list1, 2);
  displayList(&list1);

// Displaying current List: 
// 2
// 4
// 5
// 3
// 1
  return 0;
}
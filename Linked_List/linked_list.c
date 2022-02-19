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
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
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

void addTail(LinkedList *list, int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = data;
  node->next = NULL;
  if (list->head == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

Node *getNode(LinkedList *list, int data) {
  Node *node = list->head;
  while (node != NULL) {
    if (node->value == data) {
      printf("Value found\n");
      return node;
    }
    node = node->next;
  }
  printf("Value Not Found\n");
  return NULL;
}

void deleteNode(LinkedList *list, Node *node) {
  if (node == list->head) {

  }
  free(node);
}

int main(void) {
  LinkedList list1;
  initializeList(&list1);
  addHead(&list1, 1);
  addHead(&list1, 2);
  addHead(&list1, 5);
  addHead(&list1, 4);
  addHead(&list1, 6);
  displayList(&list1);

// Displaying current List: 
// 6 4 5 2 1

  addTail(&list1, 3);
  addTail(&list1, 7);
  displayList(&list1);

// Displaying current List:
// 6 4 5 2 1 3 7

  getNode(&list1, 10);

  return 0;
}
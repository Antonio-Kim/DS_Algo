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
  // If the node is at head
  if (node == list->head) { 
    // and there's only one node
    if (list->head->next == NULL) {
      list->head = list->tail = NULL;
    } else {
      list->head = list->head->next;
    }
  } else {
    // Create a temporary pointer to Linked List and assign to head
    // while the pointer is not empty, and the next value is not the node,
    // traverse through the Linked List. The while-loop will terminate
    // if the value is empty, or it has found the node to be deleted on 
    // the next node that it's pointing to.
    Node *temp = list->head;
    while (temp != NULL && temp->next != node) {
      temp = temp->next;
    }
    // Once the node is found, it will then assign the node that is currently
    // is at, to point to the node after the targeted node. The function will
    // delete the node and terminate.
    temp->next = node->next;
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

  deleteNode(&list1, getNode(&list1, 7));
  deleteNode(&list1, getNode(&list1, 6));
  deleteNode(&list1, getNode(&list1, 5));
  deleteNode(&list1, getNode(&list1, 4));
  displayList(&list1);


  return 0;
}
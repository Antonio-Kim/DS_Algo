#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
};

void initializeList(struct LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
}

void addHead(struct LinkedList *list, int value) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = value;
  if (list->head == NULL) {
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head;
  }
  list->head = node;
}

void addTail(struct LinkedList *list, int value) {
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));
  node->data = value;
  node->next = NULL;
  if (list->head == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
}

void displayList(struct LinkedList *list) {
  printf("Displaying current list: \n");
  struct Node *current = list->head;
  while(current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

struct Node *getNode(struct LinkedList *list, int value) {
  struct Node *node = list->head;
  while (node != NULL) {
    if (node->data == value) {
      printf("Value found\n");
      return node;
    }
    node = node->next;
  }
  printf("Value not found\n");
  return NULL;
}

void deleteNode(struct LinkedList *list, struct Node *node) {
  if (node == list->head) {
    if (list->head->next == NULL) {
      list->head = list->tail = NULL;
    } else {
      list->head = list->head->next;
    }
  } else {
    struct Node *temp = list->head;
    while (temp != NULL && temp->next != node) {
      temp = temp->next;
    }
    temp->next = node->next;
  }
  free(node);
}

int main(void)
{
  struct LinkedList list;
  initializeList(&list);
  addHead(&list, 1);
  addHead(&list, 2);
  addHead(&list, 5);
  addHead(&list, 4);
  addHead(&list, 6);
  displayList(&list);

  // Displaying current List: 
// 6 4 5 2 1

  addTail(&list, 3);
  addTail(&list, 7);
  displayList(&list);

// Displaying current List:
// 6 4 5 2 1 3 7

  deleteNode(&list, getNode(&list, 7));
  deleteNode(&list, getNode(&list, 6));
  deleteNode(&list, getNode(&list, 5));
  deleteNode(&list, getNode(&list, 4));
  displayList(&list);
  return 0;
}
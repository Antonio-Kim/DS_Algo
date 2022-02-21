#include <iostream>
using namespace std;

template <typename T>
struct LinkedList {
  LinkedList() {
    head = NULL;
    tail = NULL;
    current = NULL;
  }
  void displayList() {
    cout << "Displaying current list: " << endl;
    Node *p = head;
    while(p != NULL) {
      cout << p->data << " ";
      p = p->next;
    }
    cout << "\n";
  }
  void addHead(int value) {
    Node *node = new Node();
    node->data = value;
    if (head == NULL) {
      node->next = NULL;
      tail = node;
    } else {
      node->next = head;
    }
    head = node;
  }

  void addTail(int value) {
    Node *node = new Node();
    node->data = value;
    node->next = NULL;
    if (head == NULL) {
      head = node;
    } else {
      tail->next = node;
    }
    tail = node;
  }

  struct Node *getNode(int value) {
    Node *node = head;
    while (node != NULL) {
      if (node->data == value) {
        cout << "Value found\n";
        return node;
      }
      node = node->next;
    }
    cout << "Value not found\n";
    return NULL;
  }

  // Not Complete
  void deleteNode(struct Node *node) {
    if (node == head) {
      if (head->next == NULL) {
        head = tail = NULL;
      } else {
        head = head->next;
      }
    } else {
      struct Node *temp = head;
      while (temp != NULL && temp->next != node) {
        temp = temp->next;
      }
      temp->next = node->next;
    }
    delete(node);
  }
private:
  struct Node {
    T data;
    Node *next;
  };
  Node *head;
  Node *tail;
  Node *current;
};

int main() {
  LinkedList <int>list1{};
  list1.addHead(1);
  list1.addHead(2);
  list1.addHead(5);
  list1.addHead(4);
  list1.addHead(6);
  list1.displayList();
  list1.addTail(3);
  list1.addTail(7);
  list1.displayList();
//   struct Node *node = list1.getNode(7);
//   list1.deleteNode(node);
//   list1.displayList();
}
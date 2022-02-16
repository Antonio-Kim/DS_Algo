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
      cout << p->data << endl;
      p = p->next;
    }
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
}
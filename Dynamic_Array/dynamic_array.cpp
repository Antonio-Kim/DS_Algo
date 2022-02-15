#include <iostream>
using namespace std;

// struct Node {
//   string item;
//   Node *next;
// };

int main()
{
    // Node n1, n2, n3;
    // n1.item = "to";
    // n2.item = "be";
    // n3.item = "or";
    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = NULL;

    // for (Node *p = &n1; p != NULL; p = p->next) {
    //   cout << "Item : " << p->item << endl; 
    // }
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *a = new int[size];
    for (int i = 0; i < size; i++) {
      a[i] = i;
    }
    for (int i = 0; i < size; i++) {
      cout << a[i] << endl;
    }
    
    delete[] a;
}
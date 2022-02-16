#include <iostream>
#include <memory>
using namespace std;

int main()
{
  // Using regular pointers
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
  
  // Using Smart Pointers
  int size2;
  cout << "Enter size of second array: ";
  cin >> size2;
  unique_ptr<int[]> b (new int[size2]);
  for (int i = 0; i < size2; i++) {
    b[i] = i;
  }
  for (int i = 0; i < size2; i++) {
    cout << b[i] << endl;
  }
  
  delete[] a;
}
#include <bits/stdc++.h>
#include "dsa_help.h"
using namespace std;

int main()
{
  Writer w;
  LinkedList l1;
  w.writetopic("LinkedLists-->", "test.txt");
  l1.insert(10);
  l1.insert(21);
  l1.insert(10);
  l1.insert(21);
  l1.show();
  l1.savefile("test.txt");
  w.writenotes("NOTE:", "Linked list is a data structure that stores elements in it's node, each node points to a next node, hence the nodes can access the next element starting from head to tail.", "test.txt");

  w.writetopic("----Trees---", "test.txt");
  w.writenotes("NOTES:", "this is a BST", "test.txt");
  BST t1(10);
  t1.insert(10);
  t1.insert(5);
  t1.insert(6);
  t1.insert(11);
  t1.insert(4);
  t1.show();
  int height = t1.get_height();
  cout << "height: " << height << endl;
  t1.writebeautiful("test.txt");

  // array of character
  Array<int> a;
  a.insert(10);
  a.insert(20);
  a.show();

  // stack and queue
      DataStructure* ds;
    
    // Demonstrate stack operations
    std::cout << "Stack Operations:\n";
    ds = new Stack();
    
    int n;
    std::cout << "Enter the number of elements in stack: ";
    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        int e;
        std::cout << "Enter element " << i+1 << ": ";
        std::cin >> e;
        ds->insert(e);
    }
    
    ds->display();
    
    int n1;
    std::cout << "Enter the number of elements you want to delete: ";
    std::cin >> n1;
    
    for(int i = 0; i < n1; i++) {
        ds->remove();
    }
    
    std::cout << "After removing elements from stack:\n";
    ds->display();
    
    // Sorting the stack
    Stack* stackObj = dynamic_cast<Stack*>(ds);
    if (stackObj) {
        stackObj->sortStack();
        std::cout << "Stack after sorting: ";
        stackObj->display();
    }
    
    delete ds;
    
    // Demonstrate queue operations
    std::cout << "\nQueue Operations:\n";
    ds = new Queue();
    
    int n2;
    std::cout << "Enter the number of elements in Queue: ";
    std::cin >> n2;
    
    for(int i = 0; i < n2; i++) {
        int e;
        std::cout << "Enter element " << i+1 << ": ";
        std::cin >> e;
        ds->insert(e);
    }
    
    ds->display();
    
    int n3;
    std::cout << "Enter the number of elements you want to delete: ";
    std::cin >> n3;
    
    for(int i = 0; i < n3; i++) {
        ds->remove();
    }
    
    std::cout << "After removing elements from queue:\n";
    ds->display();
    
    delete ds;

  return 0;
}
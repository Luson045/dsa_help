// dsa_help.h
#ifndef DSA_HELP_H
#define DSA_HELP_H


/*------------------------------dhruv nagori-------------------------*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Base class
class DataStructure {
public:
    // Pure virtual functions to be overridden by derived classes
    virtual void insert(int value) = 0;
    virtual void remove() = 0;
    virtual void display() = 0;
    virtual ~DataStructure() {}
};

// Derived class for Stack
class Stack : public DataStructure {
private:
    stack<int> stack;

    // Helper function to insert an element in sorted order
    void insertSorted(int value) {
        if (stack.empty() || value > stack.top()) {
            stack.push(value);
            return;
        }
        int temp = stack.top();
        stack.pop();
        insertSorted(value);
        stack.push(temp);
    }

public:
    void insert(int value) {
        stack.push(value);
        cout << "Inserted " << value << " into the stack.\n";
    }

    void remove() {
        if (stack.empty()) {
            cout << "Stack is empty. Cannot remove.\n";
            return;
        }
        int top = stack.top();
        stack.pop();
        cout << "Removed " << top << " from the stack.\n";
    }

    void display() {
        if (stack.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
         std:: stack<int> temp = stack; // Temporary stack for display
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << "\n";
    }

    void sortStack() {
        if (stack.empty()) {
            return;
        }
        int temp = stack.top();
        stack.pop();
        sortStack();
        insertSorted(temp);
    }
};

// Derived class for Queue
class Queue : public DataStructure {
private:
    queue<int> queue;

public:
    void insert(int value) {
        queue.push(value);
        cout << "Inserted " << value << " into the queue.\n";
    }

    void remove() {
        if (queue.empty()) {
            cout << "Queue is empty. Cannot remove.\n";
            return;
        }
        int front = queue.front();
        queue.pop();
        cout << "Removed " << front << " from the queue.\n";
    }

    void display() {
        if (queue.empty()) {
            cout << "Queue is empty.\n";
            return;
        }
        std:: queue<int> temp = queue; // Temporary queue for display
        cout << "Queue elements (front to back): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};
/*-----------------------------------------------------------------*/


class Node{
  public:
  int val;
  Node * next;
  Node(int value):val(value),next(nullptr){};
};
class LinkedList{
  private:
  Node *head;
  Node *tail;
  public:
  LinkedList() : head(nullptr), tail(nullptr) {}
  void insert(int val);
  void remove(int val);
  void show();
  int search(int val);
  void savefile(char* s1);
  void help();
};
//class DLL;
//class Stack;
//class Binary Search Tree
class BST{
  int * arr;
  int nodes;
  public:
  BST(int n){
    nodes=n;
    arr= new int[n]();
  }
  void insert(int n,int i=1){
    int idx=0;
    bool found=false;
    if(arr[i-1]==0){
      arr[i-1]=n;
      return;
    }
    if(n<arr[i-1]){
      insert(n,2*i);
    }else{
      insert(n,2*i+1);
    }
  }
  //void remove(int val);
  void show();
  void writebeautiful(char * f);
  int get_height();
};


class Writer{
  public:
  void writenotes(char* topic, char* notes, char* f);
  void writetopic(char* topic, char* f);
};



//templates implemented
template <typename T>
class Array{
  T* arr;
  int idx;int size;
  public:
  Array();
  void insert(T i);
  void show();
};
template <typename T>
void Array<T>::insert(T i) {
    if (idx < size) {
        arr[idx++] = i; // Insert the element and increment index
    } else {
        std::cout << "Array is full!" << std::endl;
    }
}

template <typename T>
void Array<T>::show() {
    for (int i = 0; i < idx; i++) { // Show only inserted elements
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
Array<T>::Array() : size(10), idx(0) {  // Default size = 10
    arr = new T[10];
}


#endif
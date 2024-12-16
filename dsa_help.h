// dsa_help.h
#ifndef DSA_HELP_H
#define DSA_HELP_H

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

#endif

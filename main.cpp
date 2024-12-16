#include <bits/stdc++.h>
#include "dsa_help.h"
using namespace std;

int main(){
  Writer w;
  LinkedList l1;
  w.writetopic("LinkedLists-->","test.txt");
  l1.insert(10);
  l1.insert(21);
  l1.insert(10);
  l1.insert(21);
  l1.show();
  l1.savefile("test.txt");
  w.writenotes("NOTE:","Linked list is a data structure that stores elements in it's node, each node points to a next node, hence the nodes can access the next element starting from head to tail.","test.txt");

  w.writetopic("----Trees---","test.txt");
  w.writenotes("NOTES:","this is a BST", "test.txt");
  BST t1(10);
  t1.insert(10);
  t1.insert(5);
  t1.insert(6);
  t1.insert(11);
  t1.insert(4);
  t1.show();
  int height=t1.get_height();
  cout<<"height: "<<height<<endl;
  t1.writebeautiful("test.txt"); 
  return 0;
}
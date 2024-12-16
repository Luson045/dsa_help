#include <bits/stdc++.h>
#include "dsa_help.h"
#include <iostream>
#include <fstream>
using namespace std;

bool file_exists(const string &filename) {
    ifstream infile(filename);
    return infile.good();
}

//linked list
void LinkedList::insert(int val)
{
  Node *temp = new Node(val);
  if (head == NULL)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}
void LinkedList::remove(int val)
{
  Node *temp = head;
  Node *prev = nullptr;

  if (temp != nullptr && temp->val == val)
  {
    head = temp->next;
    delete temp;
    return;
  }

  while (temp != nullptr && temp->val != val)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == nullptr)
    return;

  prev->next = temp->next;
  delete temp;
}
void LinkedList::show()
{
  if (head == NULL)
  {
    cout << -1 << endl;
  }
  else
  {
    Node *offset = head;
    while (offset->next != NULL)
    {
      cout << offset->val << ",";
      offset = offset->next;
    }
    cout << offset->val << endl;
  }
}
int LinkedList::search(int val)
{
  Node *temp = head;
  int count = 0;
  while (temp->next != NULL)
  {
    if (temp->val == val)
    {
      return count;
    }
    count++;
    temp = temp->next;
  }
  if (temp->val == val)
  {
    return count;
  }
  else
  {
    return -1;
  }
}
void LinkedList::savefile(char* f){
  string filename=f;
  ofstream file(file_exists(filename) ? filename : filename, ios::app);
  Node* temp=head;
  file<<"the linked list is: \n";
  while(temp!=NULL){
    file<<temp->val;
    file<<"->";
    temp=temp->next;
  }
  file<<"null";
  file<<"\n";
  file.close();
}
void LinkedList::help(){
  cout<<"open docs.md\n";
}

//Binary Serch Tree
void BST::show(){
  for(int i=0;i<nodes;i++){
    cout<<arr[i]<<",";
  }
  cout<<endl;
}

int BST::get_height(){
  int mul_idty=2;
  int diff=nodes-1;
  int height=0;
  while(diff>0){
    diff-=mul_idty;
    mul_idty*=2;
    height++;
  }
  return height;
}

void BST::writebeautiful(char* f){
  string filename=f;
  ofstream file(file_exists(filename) ? filename : filename, ios::app);
  file<<"the tree is: \n";
  int tab_count=get_height();
  int level_nodes=1;
  int idx=0;
  for(int i=0;i<get_height()+1;i++){
    for(int i=0;i<tab_count;i++) file<<'\t';
    for(int i=0;i<level_nodes;i++){
      if(idx==nodes-1){
        file<<arr[nodes-1]<<'\t';
        break;
      }
      if(arr[idx]==0) continue;
      file<<arr[idx];
      if((i+1)%2!=0) file<<"\t\t";
      else file<<" ";
      idx++;
    }
    level_nodes*=2;   
    file<<'\n';
    tab_count--;
  }
  file<<"\n";
  file.close();
}


//writer
void Writer::writenotes(char* topic, char* notes, char* f){
  string filename=f;
  ofstream file(file_exists(filename) ? filename : filename, ios::app);
  file<<topic;
  file<<"\n";
  file<<notes;
  file<<"\n";
  file.close();
}
void Writer::writetopic(char* topic, char* f){
  string filename=f;
  ofstream file(file_exists(filename) ? filename : filename, ios::app);
  file<<topic;
  file<<"\n";
  file.close();
}


#pragma once
#include "node.h"
#include <iostream>
using std::ostream;

class List
{
 private:
  Node *head;
  Node *findNode(string uid);
 public:
 List(): head(nullptr) {}
  ~List();
  bool insert(string uid, int priority);
  bool insertBefore(string uid, int priority, string before);
  bool insertAfter(string uid, int priority, string after);
  bool remove(string uid);
  bool find(string uid, int &priority);
  friend ostream &operator<<(ostream &os, List &rhs);

};

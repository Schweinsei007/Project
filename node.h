#pragma once
#include <string>
using std::string;
class Node
{
 public:
  string uid;
  int priority;
  Node *prev;
  Node *next;
 Node(string uid, int priority, Node *prev, Node *next): uid(uid), priority(priority), prev(prev), next(next) {}
 Node(): Node("",0,nullptr,nullptr) {}
};

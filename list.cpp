#include "list.h"
#include <string>
using std::string;

List::~List()
{
  Node *tmp = head;
  Node *curr = nullptr;
  while (tmp != nullptr)
    {
      curr = tmp;
      tmp = tmp->next;
      delete curr;
    }
}
bool List::insert(string uid, int priority)
{
  Node *tmp = head;
  if (!tmp)
    {
      head = new Node(uid,priority,nullptr,nullptr);
    }
  else
    {
      while (tmp->next != nullptr)
	{
	  tmp = tmp->next;
	}
      tmp->next = new Node(uid,priority,tmp,nullptr);
    }
  return true;
}
bool List::insertBefore(string uid, int priority, string before)
{
  Node *tmp = findNode(before);
  if (tmp)
    {
      Node *prev = tmp->prev;
      Node *ins = new Node(uid,priority, prev, tmp);
      if (prev) { prev->next = ins;}
      if (tmp == head) { head = ins;}
      tmp->prev = ins;
      return true;
    }
  return false;
}
bool List::insertAfter(string uid, int priority, string after)
{
  Node *tmp = findNode(after);
  if (tmp)
    {
      Node *next = tmp->next;
      Node *ins = new Node(uid,priority, tmp, next);
      if (next) { next->prev = ins;}
      tmp->next = ins;
      return true;
    }
  return false;
}
bool List::remove(string uid)
{
  Node *tmp = findNode(uid);
  if (tmp) {
    Node *prev = tmp->prev;
    Node *next = tmp->next;
    if (prev) {prev->next = next;}
    if (next) {next->prev = prev;}
    if (tmp == head) {head = next;}
    delete tmp;
    return true;
  }
  return false;
}
bool List::find(string uid, int &priority)
{
  Node *tmp = findNode(uid);
  if (tmp) { priority = tmp->priority; return true;}
  return false;
}

Node * List::findNode(string uid)
{
  Node *tmp = head;
  while (tmp != nullptr && tmp->uid != uid)
    tmp = tmp->next;

  return tmp;
}

ostream &operator<<(ostream &os, List &rhs)
{
  Node *tmp = rhs.head;
  while (tmp != nullptr)
    {
      os << tmp->uid << "(" << tmp->priority << ")";
      os << std::endl;
      tmp = tmp->next;
    }

  return os;
}

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;
// Node for Circular Linked List

// Circular Linked List Class behavior.
class CircularLinkedList
{
	

private:
	circularnode* head;
	circularnode* tail;
	int size;

public:
	CircularLinkedList();
	CircularLinkedList(int integer);
	~CircularLinkedList();
	CircularLinkedList(const CircularLinkedList& rhs);
	void operator=(const CircularLinkedList& rhs);
	friend ostream &operator<<(ostream& out, CircularLinkedList& rhs);
	int getSize();
	void pushBack(int data);
	void pushFront(int data);
	void popBack();
	void popFront();
	void insert(int index, int val);
	void deleteDuplicates(int val);
	void printList();
	void deleteNode(int index);
	int mtoLastElement(int M);
	void reverseList();
	void deleteList();
	CircularLinkedList mergeLists(CircularLinkedList& one, CircularLinkedList& two);
};

#endif
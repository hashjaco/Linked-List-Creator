#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

	// Node for DoubleLinked List
	
	// Double Linked List Class behavior.
	class DoubleLinkedList
	{
	private:
		doublenode* head;
		doublenode* tail;
		int size;

	public:
		DoubleLinkedList();
		DoubleLinkedList(int data);
		~DoubleLinkedList();
		DoubleLinkedList(const DoubleLinkedList& rhs);
		void operator=(const DoubleLinkedList& rhs);
		friend ostream &operator<<(ostream& out, const DoubleLinkedList& rhs);
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
		DoubleLinkedList mergeLists(DoubleLinkedList& one, DoubleLinkedList& two);

	};

#endif

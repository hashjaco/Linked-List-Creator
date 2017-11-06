#include "DoubleLinkedList.h"
#include <iostream>
#include "Node.h"
using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

DoubleLinkedList::DoubleLinkedList(int data)
{
	doublenode* first = new doublenode;
	first->data = data;
	first->next = NULL;
	head = first;
}

DoubleLinkedList::~DoubleLinkedList()
{
	delete this;
}



DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& rhs) {
	if (rhs.head != NULL) {
		head = rhs.head;
		doublenode* walk;
		doublenode* cur;
		walk = rhs.head;
		cur = head;
		while (walk != NULL) {
			pushBack(walk->data);
			walk = walk->next;
		}
	}
	else
		head = NULL;
}

void DoubleLinkedList::operator=(const DoubleLinkedList& rhs) {
	if (rhs.head != NULL) {
		doublenode* walk;
		walk = rhs.head;
		while (walk != NULL) {
			pushBack(walk->data);
		}
	}
	else
		head = NULL;
}

ostream &operator<<(ostream& out, const DoubleLinkedList& rhs) {
	if (rhs.head != NULL) {
		doublenode* cur = rhs.head;
		while (cur != NULL) {
			out << cur->data << " -> ";
			cur = cur->next;
		}
		out << "NULL\n";
	}
	return out;
}


int DoubleLinkedList::getSize()
{
	return size;
}


void DoubleLinkedList::printList()
{
	doublenode* walk = head;
	while (walk != NULL)
	{
		cout << walk->data << " -> ";
		//cout<<walk->data<<"("<<walk<<")"<<" -> ";
		walk = walk->next;
	}
	cout << "NULL" << endl;
}

void DoubleLinkedList::pushBack(int data)
{

	if (head == NULL)
	{
		head = new doublenode;
		head->data = data;
		head->next = NULL;
		//size = 1
	}
	else
	{
		doublenode* walk = head;
		while (walk->next != NULL)
			walk = walk->next;
		doublenode* last = new doublenode;
		last->data = data;
		last->next = NULL;
		walk->next = last;
		last->prev = walk;
		tail = last;
		// walk->next = new doublenode;
		// walk->next->data = data;
		// walk->next->next = NULL;
		//size++;
	}

	size++;
}

void DoubleLinkedList::pushFront(int data)
{
	doublenode* first = new doublenode;
	first->data = data;
	first->next = head;
	head = first;
	size++;
}

void DoubleLinkedList::popFront()
{
	// doublenode* walk = head;
	// if(walk != NULL){
	// 	doublenode* temp = walk;
	// 	walk = walk->next;
	// 	delete temp;
	// }

	if (head != NULL)
	{
		doublenode* temp = head;
		head = head->next;
		head->prev = NULL;
		--size;
		delete temp;
	}
}


void DoubleLinkedList::popBack()
{
	if (head == NULL)
		cout << "Empty List\n";
	else if (head->next == NULL)
	{
		doublenode* temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		doublenode* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->prev->next = NULL;
		tail = last->prev;
		delete last;
		--size;
	}
}

void DoubleLinkedList::deleteList()
{
	if (head == NULL)
		return;
	doublenode* walk = head;
	while (walk != NULL)
	{
		doublenode* temp = walk;
		walk = walk->next;
		delete temp;
	}

	size = 0;
	head = NULL;
}

void DoubleLinkedList::deleteNode(int index)
{

	if (index >= size)
	{
		cout << "Invalid index" << endl;
		return;
	}

	if (index == 0)
		popFront();
	else if (index == size - 1)
		popBack();
	else
	{
		doublenode* cur = head;
		while (index-- > 0)
		{
			cur = cur->next;
		}
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		delete cur;
		--size;
	}

}

void DoubleLinkedList::insert(int index, int val)
{
	if (index > size)
	{
		cout << "Invalid index" << endl;
		return;
	}

	if (index == 1)
		pushFront(val);
	else if (index == size) {
		pushBack(val);
	}
	else
	{
		doublenode* newNode = new doublenode;
		newNode->data = val;
		doublenode* cur = head;
		doublenode* prevNode = new doublenode;
		while (index-- > 0)
		{
			prevNode = cur;
			cur = cur->next;
		}
		prevNode->next = newNode;
		newNode->next = cur;
		cur->prev = newNode;
		++size;
	}

}

void DoubleLinkedList::deleteDuplicates(int val) {
	if (head != NULL) {
		doublenode* walk = head;
		int count = 1;
		while (walk != NULL) {
			if (walk->data == val && count > 1) {
				doublenode* temp = walk;
				walk->prev->next = walk->next;
				walk->next->prev = walk->prev;
				walk = walk->next;
				delete temp;
				count++;
			}
		}
		tail = walk->prev;
	}
}

int DoubleLinkedList::mtoLastElement(int M) {
	if (M > size - 1) {
		cout << "index non-existent\n";
		return 0;
	}
	else {
		doublenode* walk = tail;
		while (M > 1) {
			walk = walk->prev;
			--M;
		}
		return walk->data;
	}
}

void DoubleLinkedList::reverseList() {
	if (size == 0)
		cout << "Empty List\n";
	else if (size == 1)
		cout << "Only one item\n";
	else {
		doublenode* lhs = head;
		doublenode* rhs = tail;
		int count = size / 2;
		while (count > 0) {
			int temp = lhs->data;
			lhs->data = rhs->data;
			rhs->data = temp;
			lhs = lhs->next;
			rhs = rhs->prev;
			count--;
		}
	}
}

DoubleLinkedList DoubleLinkedList::mergeLists(DoubleLinkedList& one, DoubleLinkedList& two) {
	DoubleLinkedList newList;
	return newList;
}


#include "CircularLinkedList.h"
#include <iostream>
using namespace std;
#include "Node.h"

CircularLinkedList::CircularLinkedList()
{
	head = new circularnode;
	head = NULL;
	tail = new circularnode;
	tail = NULL;
	size = 0;
}

CircularLinkedList::CircularLinkedList(int integer) {
	head = new circularnode;
	head->data = integer;
	head->next = NULL;
	size = 1;
}

CircularLinkedList::~CircularLinkedList()
{
	delete this;
}


CircularLinkedList::CircularLinkedList(const CircularLinkedList& rhs) {
	if (rhs.head != NULL) {
		head = new circularnode;
		head = rhs.head;
		circularnode* walk = new circularnode;
		circularnode* cur = new circularnode;
		walk = rhs.head;
		cur = head;
		while (walk != NULL) {
			cur->next = walk->next;
			walk = walk->next;
		}
	}
	else
		head = NULL;
}

void CircularLinkedList::operator=(const CircularLinkedList& rhs) {
	if (rhs.head != NULL) {
		head = new circularnode;
		head = rhs.head;
		circularnode* walk = new circularnode;
		circularnode* cur = new circularnode;
		walk = rhs.head;
		cur = head;
		while (walk != NULL) {
			cur->next = walk->next;
			walk = walk->next;
		}
		size = rhs.size;
	}
	else
		head = NULL;
}

ostream &operator<<(ostream& out, CircularLinkedList& rhs) {
	if (rhs.head != NULL) {
		circularnode* cur = rhs.head;
		int count = 0;
		while (count < rhs.getSize()) {
			out << cur->data << " -> ";
			cur = cur->next;
			count++;
		}
		out << " -> NULL\n";
	}
	return out;
}




int CircularLinkedList::getSize()
{
	return size;
}

void CircularLinkedList::printList()
{
	circularnode* walk = head;
	int count = 0;
	while (count < size)
	{
		cout << walk->data << " -> ";
		walk = walk->next;
	}
	cout << "NULL" << endl;
}

void CircularLinkedList::pushBack(int data)
{

	if (head == NULL)
	{
		head = new circularnode;
		head->data = data;
		head->next = NULL;
		//size = 1
	}
	else
	{
		circularnode* walk = head;
		while (walk != NULL)
			walk = walk->next;
		circularnode* last = new circularnode;
		last->data = data;
		last->next = NULL;
		walk = last;
		tail = last;
		tail->next = head;
		// walk->next = new circularnode;
		// walk->next->data = data;
		// walk->next->next = NULL;
		size++;
	}

	size++;
}

void CircularLinkedList::pushFront(int data)
{
	circularnode* first = new circularnode;
	first->data = data;
	first->next = head;
	head = first;
	size++;
}

void CircularLinkedList::popFront()
{
	// circularnode* walk = head;
	// if(walk != NULL){
	// 	circularnode* temp = walk;
	// 	walk = walk->next;
	// 	delete temp;
	// }

	if (head != NULL)
	{
		circularnode* temp = head;
		head = head->next;
		--size;
		delete temp;
	}
}


void CircularLinkedList::popBack()
{
	if (head == NULL)
		cout << "Empty List\n";
	else if (head->next == NULL)
	{
		circularnode* temp = head;
		head = head->next;
		size = 0;
		delete temp;
	}
	else
	{
		circularnode* last = head;
		int count = 0;
		while (count < size - 1)
		{
			last = last->next;
		}
		circularnode* temp = last->next;
		last->next = NULL;
		tail = last;
		delete temp;
		--size;
	}
}

void CircularLinkedList::deleteList()
{
	if (head == NULL)
		return;
	else {
		circularnode* walk = head;
		int count = 0;
		while (count<size)
		{
			circularnode* temp = walk;
			walk = walk->next;
			delete temp;
		}
	}

	size = 0;
	head = NULL;
}

void CircularLinkedList::deleteNode(int index)
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
		circularnode* cur = head;
		while (index-- > 1)
		{
			cur = cur->next;
		}
		circularnode* temp = cur->next;
		cur->next = cur->next->next;
		delete temp;
		--size;
	}

}

void CircularLinkedList::insert(int index, int val)
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
		circularnode* newNode = new circularnode;
		newNode->data = val;
		circularnode* cur = head;
		while (index-- > 1)
		{
			cur = cur->next;
		}
		circularnode* temp = cur->next;
		cur->next = newNode;
		newNode->next = temp;
		++size;
	}

}

void CircularLinkedList::deleteDuplicates(int val) {
	if (head != NULL) {
		circularnode* ahead = head->next;
		circularnode* behind = head;
		int trav = 0;
		int count = 1;
		if (behind->data == val) {
			count++;
		}
		while (trav < size) {
			if (ahead->data == val && count > 1) {
				circularnode* temp = ahead;
				ahead = ahead->next;
				behind->next = ahead;
				delete temp;
				count++;
				size--;
				trav++;
			}
			else {
				ahead = ahead->next;
				behind = behind->next;
			}
		}
		tail = behind;
	}
}

int CircularLinkedList::mtoLastElement(int M) {
	if (M > size) {
		cout << "index non-existent\n";
		return 0;
	}
	else {
		circularnode* walk = head;
		int count = size - M;
		while (count > 0) {
			walk = walk->next;
			--M;
		}
		return walk->data;
	}
}

void CircularLinkedList::reverseList() {
	if (size == 0)
		cout << "Empty List\n";
	else if (size == 1)
		cout << "Only one item\n";
	else {
		int pos = 0;
		while (pos < size) {
			circularnode* temp = tail;
			popBack();
			insert(pos, temp->data);
			pos++;
		}
	}
}

CircularLinkedList CircularLinkedList::mergeLists(CircularLinkedList& one, CircularLinkedList& two) {
	CircularLinkedList newList;
	return newList;
}


// ConsoleApplication11.cpp : Defines the entry point for the console application.
//
#include "CircularLinkedList.h"
#include "DoubleLinkedList.h"
#include <vector>

int main() {
		vector<DoubleLinkedList> doubleLinkedVector;
		vector<CircularLinkedList> circularLinkedVector;
		vector<DoubleLinkedList>& vecCopy = doubleLinkedVector;
		vector<CircularLinkedList>& cirVec = circularLinkedVector;
		char resp;
		cout << "Welcome to the Linked List creator! Below, you will find your options to begin building your list/n" << endl << endl << endl;
		do {
		
			int option;
			cout << "Please choose from the options below by entering the respective number\n";
			cout << "*******************************\n" << endl;
			cout << "1) Double Linked List" << endl << "2) Circular Linked List" << endl << "3) Exit\n";
			cin >> option;
			cout << endl << endl;
			switch (option) {
				//Double Linked List
			case 1:
				char choice;
				cout << "**************DOUBLE LINKED LIST*****************" << endl << endl;
				do {
					int action;
					cout << "MAIN MENU\n" << "_________\n" << endl << "1) Create and Modify Empty List\n" << "2) Create and modify list with first element\n" << "3) List all lists\n" << "4) Delete a list\n" << "5) Exit\n";
					cout << "Choose action from the menu by entering the number of your choice: ";
					cin >> action;
					switch (action) {
					case 1:
					{
						char dec;
						DoubleLinkedList newList;
						do {
							int n, integer;
							cout << "What would you like to do?\n" << endl;
							cout << "******************\n" << endl;
							cout << "1) Append Node\n" << "2) Add Node to front\n" << "3) Delete tail node\n" << "4) Delete head node\n" << "5) Insert Node\n" << "6) Delete Duplicates\n" << "7) Print List\n" << "8) Get M to last element\n" << "9) Reverse List\n" << "10) Delete List\n" << "11) Get Size\n" << endl;
							cout << "Enter number: ";
							cin >> n;
							switch (n) {
								//Use default constructor
								//case 1: append node
							case 1:
								cout << "Enter integer to append and press enter: ";
								cin >> integer;
								newList.pushBack(integer);
								break;
								//case 2: pushfront
							case 2:
								cout << "Enter integer to insert at beginning of list and press enter: ";
								cin >> integer;
								newList.pushFront(integer);
								break;
								//case 3: popback
							case 3:
								newList.popBack();
								break;
								//case 4: popfront
							case 4:
								newList.popFront();
								break;
								//case 5: insert node
							case 5:
								int pos;
								cout << "Enter position of new element: ";
								cin >> pos;
								cout << "Enter integer of new element: ";
								cin >> integer;
								newList.insert(pos, integer);
								break;
								//case 6: delete duplicates
							case 6:
								cout << "Enter number to delete duplicates of: ";
								cin >> integer;
								newList.deleteDuplicates(integer);
								break;
								//case 7: print list using overloaded operator
							case 7:
								cout << newList;
								break;
								//case 8: m to last element
							case 8:
								cout << "Enter which element from the last you want to view: ";
								cin >> integer;
								cout << newList.mtoLastElement(integer) << endl;
								break;
								//case 9: reverse list
							case 9:
								newList.reverseList();
								break;
								//case 10: delete list
							case 10:
								newList.deleteList();
								break;
							case 11:
								cout << newList.getSize() << endl;
								break;
								//default case for invalid input
							default:
								cout << "Not an option\n";
								break;
							}
							cout << "Would you like to edit the list further? ";
							cin >> dec;
						} while (dec == 'y' || dec == 'Y');
						doubleLinkedVector.push_back(newList); //add newList to list vector
					}
					break;
					//Use custom constructor
					case 2:
					{
						char dec;
						int element;
						cout << "Please Enter an integer to insert as your first element: ";
						cin >> element;
						DoubleLinkedList newList(element);
						do {
							int n;
							cout << "What would you like to do?\n" << endl;
							cout << "******************\n" << endl;
							cout << "1) Append Node\n" << "2) Add Node to front\n" << "3) Delete tail node\n" << "4) Delete head node\n" << "5) Insert Node\n" << "6) Delete Duplicates\n" << "7) Print List\n" << "8) Get M to last element\n" << "9) Reverse List\n" << "10) Delete List\n" << endl;
							cout << "Enter number: ";
							cin >> n;
							switch (n) {
								int integer;
							case 1:
								cout << "Enter integer to append and press enter: ";
								cin >> integer;
								newList.pushBack(integer);
								break;
							case 2:
								cout << "Enter integer to insert at beginning of list and press enter: ";
								cin >> integer;
								newList.pushFront(integer);
								break;
							case 3:
								newList.popBack();
								break;
							case 4:
								newList.popFront();
								break;
							case 5:
								int pos;
								cout << "Enter position of new element: ";
								cin >> pos;
								cout << "Enter integer of new element: ";
								cin >> integer;
								newList.insert(pos, integer);
								break;
							case 6:
								cout << "Enter number to delete duplicates of: ";
								cin >> integer;
								newList.deleteDuplicates(integer);
								break;
							case 7:
								cout << newList;
								break;
							case 8:
								cout << "Enter which element from the last you want to view: ";
								cin >> integer;
								cout << newList.mtoLastElement(integer);
								break;
							case 9:
								newList.reverseList();
								break;
							case 10:
								newList.deleteList();
								break;
							case 11:
								cout << newList.getSize() << endl;
								break;
							default:
								break;
							}
							cout << "Would you like to edit the list further? ";
							cin >> dec;
						} while (dec == 'y' || dec == 'Y'); //End edit list
						vecCopy.push_back(newList); // add list to vector
						break;
					}
					break;
					case 3: //print lists
					{

						int size = vecCopy.size();
						for (int i = 0; i < size; i++) {
							cout << i + 1 << ") " << vecCopy.at(i) << endl;
						}
					}
					break;
					case 4: // delete a list
					{
						int list;
						char confirm;
						int size = vecCopy.size();
						for (int i = 0; i < size; i++) {
							cout << i + 1 << ") " << vecCopy.at(i) << endl;
						}
						cout << "Which list would you like to delete? ";
						cin >> list;
						cout << "Are you sure you want to delete List #" << list << "? ";
						cin >> confirm;
						if (confirm == 'y' || confirm == 'Y')
							vecCopy.erase(vecCopy.begin() + (list - 1));
						else
							break;
					}
					cout << "Would you like to do something else? ";
					cin >> choice;
					}
				} while (choice == 'y' || choice == 'Y');
				//End double linked case

				//Circular Linked Case
			case 2:
				cout << "**************CIRCULAR LINKED LIST*****************" << endl << endl;
				do {
					int action;
					cout << "MAIN MENU\n" << "_________\n" << endl << "1) Create and Modify Empty List\n" << "2) Create and modify list with first element\n" << "3) List all lists\n" << "4) Delete a list\n" << "5) Exit\n";
					cout << "Choose action from the menu by entering the number of your choice: ";
					cin >> action;
					switch (action) {
						char dec;
					case 1:
					{
						CircularLinkedList newList;
						CircularLinkedList& listCopy = newList;
						do {
							int n;
							cout << "What would you like to do?\n" << endl;
							cout << "******************\n" << endl;
							cout << "1) Append Node\n" << "2) Add Node to front\n" << "3) Delete tail node\n" << "4) Delete head node\n" << "5) Insert Node\n" << "6) Delete Duplicates\n" << "7) Print List\n" << "8) Get M to last element\n" << "9) Reverse List\n" << "10) Delete List\n" << "11) Get Size\n" << endl << endl;
							cout << "Enter number: ";
							cin >> n;
							switch (n) {
								//Use default constructor
								//case 1: append node
								int integer;
							case 1:
								cout << "Enter integer to append and press enter: ";
								cin >> integer;
								listCopy.pushBack(integer);
								break;
								//case 2: pushfront
							case 2:
								cout << "Enter integer to insert at beginning of list and press enter: ";
								cin >> integer;
								listCopy.pushFront(integer);
								break;
								//case 3: popback
							case 3:
								listCopy.popBack();
								break;
								//case 4: popfront
							case 4:
								listCopy.popFront();
								break;
								//case 5: insert node
							case 5:
								int pos;
								cout << "Enter position of new element: ";
								cin >> pos;
								cout << "Enter integer of new element: ";
								cin >> integer;
								listCopy.insert(pos, integer);
								break;
								//case 6: delete duplicates
							case 6:
								cout << "Enter number to delete duplicates of: ";
								cin >> integer;
								listCopy.deleteDuplicates(integer);
								break;
								//case 7: print list using overloaded operator
							case 7:
								cout << listCopy;
								break;
								//case 8: m to last element
							case 8:
								cout << "Enter which element from the last you want to view: ";
								cin >> integer;
								cout << listCopy.mtoLastElement(integer);
								break;
								//case 9: reverse list
							case 9:
								listCopy.reverseList();
								break;
								//case 10: delete list
							case 10:
								listCopy.deleteList();
								break;
							case 11:
								cout << newList.getSize() << endl;
								//default case for invalid input
							default:
								cout << "Not an option\n";
								break;
							}
							cout << "Would you like to edit the list further? ";
							cin >> dec;
						} while (dec == 'y' || dec == 'Y');
						cirVec.push_back(listCopy); //add newList to list vector
					}
					break;
					//Use custom constructor
					case 2:
					{
						int element;
						cout << "Please Enter an integer to insert as your first element: ";
						cin >> element;
						CircularLinkedList newList(element);
						do {
							int n;
							cout << "What would you like to do?\n" << endl;
							cout << "******************\n" << endl;
							cout << "1) Append Node\n" << "2) Add Node to front\n" << "3) Delete tail node\n" << "4) Delete head node\n" << "5) Insert Node\n" << "6) Delete Duplicates\n" << "7) Print List\n" << "8) Get M to last element\n" << "9) Reverse List\n" << "10) Delete List\n" << endl;
							cout << "Enter number: ";
							cin >> n;
							switch (n) {
								int integer;
							case 1:
								cout << "Enter integer to append and press enter: ";
								cin >> integer;
								newList.pushBack(integer);
								break;
							case 2:
								cout << "Enter integer to insert at beginning of list and press enter: ";
								cin >> integer;
								newList.pushFront(integer);
								break;
							case 3:
								newList.popBack();
								break;
							case 4:
								newList.popFront();
								break;
							case 5:
								int pos;
								cout << "Enter position of new element: ";
								cin >> pos;
								cout << "Enter integer of new element: ";
								cin >> integer;
								newList.insert(pos, integer);
								break;
							case 6:
								cout << "What duplicated integers would you like to delete? ";
								cin >> integer;
								newList.deleteDuplicates(integer);
								break;
							case 7:
								cout << newList;
								break;
							case 8:
								cout << "Enter which element from the last you want to view: ";
								cin >> integer;
								cout << newList.mtoLastElement(integer);
								break;
							case 9:
								newList.reverseList();
								break;
							case 10:
								newList.deleteList();
								break;
							default:
								cout << "Not an option\n";
								break;
							}
							cout << "Would you like to edit the list further?(y/n) ";
							cin >> dec;
						} while (dec == 'y' || dec == 'Y'); //End edit list

						cirVec.push_back(newList); // add list to vector
						break;
					}
					case 3: //print lists
					{
						int size = cirVec.size();
						for (int i = 0; i < size; i++) {
							cout << i + 1 << ") " << cirVec[i] << endl;
						}
						break;
					}
					case 4: // delete a list
					{
						int list;
						char confirm;
						int size = cirVec.size();
						for (int i = 0; i < size; i++) {
							cout << i + 1 << ") " << cirVec[i] << endl;
						}
						cout << "Which list would you like to delete? ";
						cin >> list;
						cout << "Are you sure you want to delete List #" << list << "? ";
						cin >> confirm;
						if (confirm == 'y' || confirm == 'Y')
							cirVec.erase(cirVec.begin() + (list - 1));
						else
							break;
					}
					cout << "Would you like to do something else? ";
					cin >> choice;
					}
				} while (choice == 'y' || choice == 'Y');

			}
			cout << "Want to do something else? ";
			cin >> resp;
		} while (resp == 'y' || resp == 'Y');
		cout << "Hope you enjoyed it! Bye!\n";
		return 0;
	}



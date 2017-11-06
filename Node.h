#ifndef NODE_H
#define NODE_H
#pragma once

struct doublenode {
	int data;
	doublenode* prev;
	doublenode* next;
};

struct circularnode {
	int data;
	circularnode* next;
};

#endif
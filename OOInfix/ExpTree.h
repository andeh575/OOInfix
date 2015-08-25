// ExpTree.h
#ifndef EXPTREE_H
#define EXPTREE_H
#pragma once

#include <iostream>
#include <stack>
#include "Node.h"
using namespace std;

class ExpTree {
private:
	class Node* root;		// The root of the expression tree
public:
	ExpTree(Node* node);	// Constructor
	~ExpTree();				// Destructor
	Node* getRoot();

	void parseExpression(string m, Node* data);
	void insertOp(stack<BinOpNode*>& m, stack<Node*>& b);
	bool isOperator(char val);
	int priority(char m);
	void preOrder(Node* node);
	void inOrder(Node* node);
	void postOrder(Node* node);
	int evaluate(Node* node);

};

#endif
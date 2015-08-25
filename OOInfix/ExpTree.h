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
	Node* getRoot();		// Return the root of the expression tree

	void parseExpression(string m, Node* data);				// Parse an infix expression string and assemble it onto the tree
	void insertOp(stack<BinOpNode*>& m, stack<Node*>& b);	// Assemble a new node with it's children
	bool isOperator(char val);		// Check to see if the char input is a valid operator
	int priority(char m);			// Check to see what the 'priority' of an operator is in the order of operations
	void preOrder(Node* node);		// Preorder traversal of the tree - results in prefix notation
	void inOrder(Node* node);		// Inorder traversal of the tree - results in infix notation -- Parenthesis will be missing!
	void postOrder(Node* node);		// Postorder traversal of the tree - results in postfix notation
	int evaluate(Node* node);		// Traverse the tree and calculate the solution

};

#endif
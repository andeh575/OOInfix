#pragma once
#include <iostream>
using namespace std;

class ExpTree {
private:
	class Node* root;		// The root of the expression tree
public:
	ExpTree(Node* node);	// Constructor
	Node* getRoot();

	void parseExpression(string m, Node* data);
	void insertOp(stack<BinOpNode*>& m, stack<Node*>& b);
	bool isOperator(char val);
	void preOrder(Node* node);
	void inOrder(Node* node);
	void postOrder(Node* node);
	int evaluate(Node* node);

};
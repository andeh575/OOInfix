#include <iostream>
#include "Node.h" 

// Base class for all nodes that can be in an expression tree
class Node {
protected:
	Node* left;
	Node* right;
public:
	virtual char value() = 0;
	virtual ~Node() {}

	Node* goLeft() {
		return left;
	}

	Node* goRight() {
		return right;
	}

};

// Contains nodes that have operands (Integers) - They are leaves and have no children
class IntNode : public Node {
private:
	char val;

public:
	// Constructor
	IntNode(char data) { 
		val = data; 
		left = NULL;
		right = NULL;
	}

	// Value at this node of the tree
	char value() { 
		return val; 
	}	
};

// Contains nodes that have operator values - binary operator nodes require two children
class BinOpNode : public Node {
private:
	char op;

public:
	//Constructor
	BinOpNode(char data, Node* l, Node* r) {
		op = data;
		left = l;
		right = r;
	}

	// Value at this node of the tree
	char value() { 
		return op; 
	}
};
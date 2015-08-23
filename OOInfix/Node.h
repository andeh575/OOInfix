#pragma once

// Base class for all nodes that can be in an expression tree
class Node {
protected:
	Node* left;
	Node* right;
public:
	virtual char value() = 0;	// No definition of value() in this class
	virtual ~Node();
	Node* goLeft();
	Node* goRight();
};

// Contains nodes that have operands (Integers) - They are leaves and have no children
class IntNode : public Node {
private:
	char val;
public:
	IntNode(char data);		// Constructor
	char value();			// Value at this node of the tree
};

// Contains nodes that have operator values - binary operator nodes require two children
class BinOpNode : public Node {
private:
	char op;

public:
	
	BinOpNode(char data, Node* l, Node* r);	//Constructor
	char value();		// Value at this node of the tree
};
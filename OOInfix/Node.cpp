#include <iostream>
#include "Node.h" 

// Visit the left child of this Node
Node* Node::goLeft() {
	return left;
}

// Visit the right child of this Node
Node* Node::goRight() {
	return right;
}

// Return the value held at this Node
char Node::value() {
	return val;
}

// Destructor
Node::~Node() {
	delete left;
	delete right;
}

// Constructor for Integer Nodes
IntNode::IntNode(char data) { 
	val = data; 
	left = NULL;
	right = NULL;
}

// Value at this node of the tree
char IntNode::value() { 
	return val; 
}	

//Constructor
BinOpNode::BinOpNode(char data, Node* l, Node* r) {
	op = data;
	left = l;
	right = r;
}

// Value at this node of the tree
char BinOpNode::value() { 
	return op; 
}

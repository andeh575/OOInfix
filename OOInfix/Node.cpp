#include <iostream>
#include "Node.h" 

Node* Node::goLeft() {
	return left;
}

Node* Node::goRight() {
	return right;
}

char Node::value() {
	return val;
}

Node::~Node() {
	delete left;
	delete right;
}

// Constructor
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

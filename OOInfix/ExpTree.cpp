#include <iostream>
#include "ExpTree.h"
#include "Node.h"
using namespace std;

class ExpTree {
private:
	class Node* root;	// The root of the expression tree

public:
	// Constructor
	ExpTree(Node* node) { 
		root = node; 
	}

	// Return the root Node* of this expression tree
	Node* getRoot() { 
		return root; 
	}	
	
	Node* parseExpression(string m, Node* data) {
	
	}
	
	// Test Function: Preorder Traversal - Recursively print Prefix Notation
	void preOrder(Node* node) {
		if (node != NULL) {
			cout << node->value() << " ";
			preOrder(node->goLeft());
			preOrder(node->goRight());
		}
	}
	
	// Test Function: Inorder Traversal - Recursively print Infix Notation
	void inOrder(Node* node) {
		if (node != NULL) {
			inOrder(node->goLeft());
			cout << node->value() << " ";
			inOrder(node->goRight());
		}
	}
	
	// Test Function: Postorder Traversal - Recursively print Postfix Notation
	void postOrder(Node* node) {
		if (node != NULL) {
			postOrder(node->goLeft());
			postOrder(node->goRight());
			cout << node->value() << " ";
		}
	}
	
	int evaluate(Node* node) {
	
	}
};
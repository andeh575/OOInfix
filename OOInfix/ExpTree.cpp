#include <iostream>
#include <stack>
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
	
	void parseExpression(string infix, Node* data) {
		char temp;
		stack<char> input;			// Stack for the input string
		stack<Node*> operators;		// Stack for handling operator nodes
		stack<Node*> treeNodes;		// Stack for arranging nodes for assembly on the tree

		// Push the input string (in infix notation) onto the input stack
		for (int i = 0; i < infix.length(); i++)
			input.push(infix[i]);

		while (!input.empty()) {
			// Take first item off input stack
			temp = input.top();
			input.pop();

			// Check to see if it's an operand or a closing parenthesis ')'
			if (isdigit(temp) || temp == ')')
				treeNodes.push(new IntNode(temp)); // Turn temp into an IntNode and push onto treeNodes stack
			 // is it an operator?
			if (isOperator(temp)) {
				bool control = false;	// Prevent operators from getting lost in the event that operators.top() has higher priority than temp

				while (!control) {
					if (operators.empty()) {

					}
					else if (operators.top()->value() == ')') {

					}
					else if (operators.top()->value() <= priority(temp)) {

					}
					else
						
				}
			}
			// Is it an opening parenthesis '('?
			if (temp == '(') {
				while (operators.top()->value() != ')') {

				}

				operators.pop();	// Discard the connecting ')'
			}
		}

		// The input stack should now be empty - so unstack remaining operators and insert them into the tree
		while (!operators.empty()) {

		}

		// Assign the top of the treeNodes stack to the root of the tree
		root = treeNodes.top();
		return;
	}

	/*	Build a tree Node* with an operator and two children - Push onto treeNodes stack.
	/	Valid children are:
	/		- Two Operands (ie: 1 and 2) - Can be leafs
	/		- Two Operators (ie: + and *) - Need to have subtrees of their own
	/		- An Operator and an Operand (ie: 1 and +) - Operand is a leaf and Operators have subtrees of their own
	*/
	void insertOp(stack<BinOpNode*>& operators, stack<Node*>& treeNodes) {

	}

	// Helper function for identifying operators
	bool isOperator(char val) {
		if (val == '+' || val == '*')
			return true;
		else
			return false;
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
	
	// Recusrively calculate the solution to the expression tree
	int evaluate(Node* node) {
		int x, y, z;
		char val = node->value();

		// Does the node contained an operator?
		if (isOperator(val))
		{
			x = evaluate(node->goLeft());
			y = evaluate(node->goRight());

			if (val == '+')
				z = x + y;
			else if (val == '*')
				z = x * y;

			return z;
		}
		// Does the node contained an operand?
		else
			return(val - '0');
	}
};
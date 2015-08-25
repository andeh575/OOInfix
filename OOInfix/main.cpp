/*	Author:		Andrew Graham
	Date:		21 August 2015
	Purpose:	A re-attempt at solving infix equations using Object Oriented design techniques.
*/

#include <iostream>
#include <string>
#include "Node.h"
#include "ExpTree.h"
using namespace std;

string getInfix(void);	// Helper function to get infix expression to solve

int main(void) {
	string infix;	// Input string
	int solution;	// Solution to the expression tree
	bool control;	// Loop flag to allow multiple iterations of input
	char loop;		// User input for control loop
	ExpTree tree = ExpTree(NULL);	// Declaring an instance of ExpTree
	
	cout << "Welcome to the Improved Infix Equation Solver" << endl;
	control = true;

	// Continue to loop the program until the user presses the 'n' key
	while (control) {
		infix = getInfix();							
		tree.parseExpression(infix, NULL);			// Parse the infix expression and assemble it on the tree
		solution = tree.evaluate(tree.getRoot());	// Evaluate the results of the infix expression

		// Testing for proper arrangement of tree nodes and traversal
		cout << endl << "Pre Order: ";
		tree.preOrder(tree.getRoot());
		
		cout << endl << "In Order: ";
		tree.inOrder(tree.getRoot());

		cout << endl << "Post Order: ";
		tree.postOrder(tree.getRoot());

		cout << endl;

		cout << endl << "The solution to the expression is: " << solution << endl;
		cout << "Do you want to enter another expression (y/n)? ";
		cin >> loop;

		if (loop == 'n')
			control = false;
	}

	system("PAUSE");
	return 0;
}

// Helper function to get initial expression - should be infix notation (We don't currently test)
string getInfix(void) {

	string infix;

	cout << endl << "Please enter an equation in infix format (Acceptable Operators: + and *):" << endl;
	cin >> infix;

	return(infix);
}
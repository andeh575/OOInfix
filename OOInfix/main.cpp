/*	Author:		Andrew Graham
	Date:		21 August 2015
	Purpose:	A re-attempt at solving infix equations using Object Oriented design techniques.
*/

#include <iostream>
using namespace std;

int main(void) {

	cout << "This is only a test for class design." << endl;

	char test = '+';

	Node* left = new IntNode('1');
	Node* right = new IntNode('2');
	Node* root = new BinOpNode(test, left, right);

	cout << "Root: " << root->value();

	system("PAUSE");
	return 0;
}
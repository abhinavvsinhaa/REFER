#include <iostream>
#include "binarytree.h"
using namespace std;

int main() {
    BinaryTree<int>* root;
    root = root->takeInputLevel();

	cout << "\nPrinting binarytree: " << endl;
	root->printLevelWise(root);
	
	cout << "\nTotal nodes " << root->countNodes(root); 
	delete root;
}
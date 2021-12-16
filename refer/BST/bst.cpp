#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    BST b, *root = NULL;
    root = b.insert(root, 80);
    b.insert(root, 35);
	b.insert(root, 60);
	b.insert(root, 50);
	b.insert(root, 90);
    b.insert(root, 40);
	b.insert(root, 85);
	b.insert(root, 30);
    b.insert(root, 70);

    cout << "Post Order traversal" << endl;
    b.postOrder(root);

    cout << "\nPre Order traversal" << endl;
    b.preOrder(root);

    cout << "\nIn order traversal" << endl;
    b.inOrder(root);
    
    return 0;
}
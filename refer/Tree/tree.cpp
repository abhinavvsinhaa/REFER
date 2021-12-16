#include <iostream>
#include "tree.h"
using namespace std;

int main()
{
    //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> *root = root->takeInputLevelWise();
    root->printLevelWise(root);
    cout << "\nHeight of tree: " << endl;
    cout << root->treeHeight(root);

    int k = 4;
    cout << "\nPrinting all nodes at depth " << k << endl;
    root->printAtLevel(root, k);

    cout << "\nTotal num of leaf nodes in the tree is: " << root->countLeafNodes(root) << endl;
    delete root;
    return 0;
}
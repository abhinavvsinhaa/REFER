#include <iostream>
using namespace std;

class BST {
	int data;
	BST *left, *right;
public:
	BST() {
        data = 0;
        left = NULL;
        right = NULL;
    };

	BST(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

	BST* insert(BST* root, int value) {
        if (root == NULL) return new BST(value);
        if (value > root->data) {
            root->right = insert(root->right, value);
        } else {
            root->left = insert(root->left, value);
        }
        return root;
    }

	void preOrder(BST* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(BST* root) {
        if (root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    void inOrder(BST* root) {
        if (root == NULL) return;
        inOrder(root->right);
        cout << root->data << " ";
        inOrder(root->left);
    }

    ~BST() {
        delete left, right;
    }
};
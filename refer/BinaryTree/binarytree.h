#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree<T> *left;
    BinaryTree<T> *right;

    BinaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTree()
    {
        delete left;
        delete right;
    }

    BinaryTree<int> *takeInputLevel()
    {
        int rootData;
        cout << "Enter root data" << endl;
        cin >> rootData;
        BinaryTree<int> *root = new BinaryTree<int>(rootData);

        queue<BinaryTree<int> *> q;
        q.push(root);

        while (!q.empty())
        {
            BinaryTree<int> *front = q.front();
            q.pop();

            int leftChildData;
            cout << "Enter left child of " << front->data << endl;
            cin >> leftChildData;
            if (leftChildData != -1)
            {
                BinaryTree<int> *child = new BinaryTree<int>(leftChildData);
                front->left = child;
                q.push(child);
            }

            int rightChildData;
            cout << "Enter right child of " << front->data << endl;
            cin >> rightChildData;
            if (rightChildData != -1)
            {
                BinaryTree<int> *child = new BinaryTree<int>(rightChildData);
                front->right = child;
                q.push(child);
            }
        }

        return root;
    }

    void print(BinaryTree<int> *root)
    {
        if (root == NULL)
            return;

        cout << root->data << ":";
        if (root->left)
            cout << "L" << root->left->data;

        if (root->right)
            cout << "R" << root->right->data;

        cout << endl;
        print(root->left);
        print(root->right);
    }

    //print level wise
    void printLevelWise(BinaryTree<int> *root)
    {
        queue<BinaryTree<int> *> q;
        q.push(root);

        while (!q.empty())
        {
            cout << q.front()->data << ": ";
            if (q.front()->left)
            {
                cout << "L" << q.front()->left->data;
                q.push(q.front()->left);
            }

            if (q.front()->right)
            {
                cout << ",R" << q.front()->right->data;
                q.push(q.front()->right);
            }

            cout << endl;
            q.pop();
        }
    }

    //recursive print level wise
    void printLevelWiseRecursive(BinaryTree<int> *root)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
            return;

        if (root->left)
            cout << "L" << root->left->data;
        if (root->right)
            cout << "R" << root->right->data;
    }

    int countNodes(BinaryTree<int> *root)
    {
        if (root == NULL)
            return 0;

        int countL = 0, countR = 0;
        countL += countNodes(root->left);
        countR += countNodes(root->right);

        return countL + countR + 1;
    }
};
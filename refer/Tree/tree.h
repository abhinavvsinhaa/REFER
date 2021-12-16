#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(int data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); ++i)
            delete children[i]; //this will call the destructor of the class TreeNode again
    }

    TreeNode<int> *takeInputLevelWise()
    {
        int rootData;
        cout << "Enter data " << endl;
        cin >> rootData;
        TreeNode<int> *root = new TreeNode<int>(rootData);

        queue<TreeNode<int> *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();

            int n;
            cout << "Enter num of children of  " << front->data << endl;
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                int childData;
                cout << "Enter " << i << "th child of " << front->data << endl;
                cin >> childData;

                //don't allocate static memory otherwise we'll lose it because it's scope is limited to the while loop
                TreeNode<int> *child = new TreeNode<int>(childData);
                front->children.push_back(child);
                pendingNodes.push(child);
            }
        }

        return root;
    }

    void printLevelWise(TreeNode<int> *root)
    {
        queue<TreeNode<int> *> q;
        //pushes the root node into the queue
        q.push(root);

        while (!q.empty())
        {
            cout << q.front()->data << ": ";
            for (int i = 0; i < q.front()->children.size(); i++)
            {
                q.push(q.front()->children[i]);
                cout << q.front()->children[i]->data << ",";
            }

            cout << endl;
            q.pop();
        }
    }

    TreeNode<int> *takeInput()
    {
        int rootData;
        cout << "Enter data " << endl;
        cin >> rootData;
        TreeNode<int> *root = new TreeNode<int>(rootData);

        int n;
        cout << "Enter num of children of " << rootData << endl;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            TreeNode<int> *child = takeInput();
            root->children.push_back(child);
        }

        return root;
    }

    void printTree(TreeNode<int> *root)
    {
        if (root == NULL)
            return;

        cout << root->data << ": ";
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ",";
        }

        cout << endl;
        for (int i = 0; i < root->children.size(); i++)
        {
            printTree(root->children[i]);
        }
    }

    //count total no. of tree nodes
    int countNodes(TreeNode<int> *root)
    {
        int count = 1;
        for (int i = 0; i < root->children.size(); i++)
        {
            count += countNodes(root->children[i]);
        }

        return count;
    }

    //height of tree
    int treeHeight(TreeNode<int> *root)
    {
        if (root == NULL)
            return 0;

        int height = 1;
        vector<int> v;
        v.push_back(height);

        for (int i = 0; i < root->children.size(); ++i)
        {
            height += treeHeight(root->children[i]);
            v.push_back(height); //push back all the children heights to the vector, so that we can return the max height from the vector
            height = 1;          //make height again 1, for other children of the root
        }

        return *max_element(v.begin(), v.end());
    }

    //print at level K or depth K
    void printAtLevel(TreeNode<int> *root, int k)
    {
        if (root == NULL)
            return;

        if (k == 0)
        {
            cout << root->data << endl;
            return;
        }

        for (int i = 0; i < root->children.size(); i++)
        {
            printAtLevel(root->children[i], k - 1);
        }
    }

    //prints root first children second
    void preOrderPrinting(TreeNode<int> *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        for (int i = 0; i < root->children.size(); ++i)
        {
            preOrderPrinting(root->children[i]);
        }

        return;
    }

    //prints children first root second
    void postOrderPrinting(TreeNode<int> *root)
    {
        if (root == NULL)
            return;

        for (int i = 0; i < root->children.size(); ++i)
        {
            postOrderPrinting(root->children[i]);
        }
        cout << root->data << " ";

        return;
    }

    //we need to delete all the childrens first and then we will delete the root
    void deleteTree(TreeNode<int> *root)
    {
        for (int i = 0; i < root->children.size(); ++i)
        {
            deleteTree(root->children[i]);
        }

        delete root;
    }

    int countLeafNodes(TreeNode<int> *root)
    {
        int count = 0;

        if (root == NULL)
            return 0;

        if (root->children.size() == 0)
        {
            // uncomment cout to see which nodes are leaf
            // cout << "\nLeaf node" << root->data << endl;
            return 1;
        }

        for (int i = 0; i < root->children.size(); ++i)
        {
            count += countLeafNodes(root->children[i]);
        }

        return count;
    }
};
#include <iostream>
#include "refer/refer.h"
using namespace std;

int main()
{
    
    //  Array<int> s;
    //  s.push_back(10);
    //  s.push_back(100);
    //  s.push_back(1000);
    //  s.push_back(1000);

    //  for (int i = 0; i < s.size(); i++)
    //      cout << s[i] << " ";
    

    // **Binary Tree**
    // BinaryTree<int> *root;
    // root = root->takeInputLevel();

    // cout << "\nPrinting binarytree: " << endl;
    // root->printLevelWise(root);

    // cout << "\nTotal nodes " << root->countNodes(root);
    // delete root;

    // **Binary Search tree**
    // BST b, *root = NULL;
    // root = b.insert(root, 80);
    // b.insert(root, 35);
    // b.insert(root, 60);
    // b.insert(root, 50);
    // b.insert(root, 90);
    // b.insert(root, 40);
    // b.insert(root, 85);
    // b.insert(root, 30);
    // b.insert(root, 70);

    // cout << "Post Order traversal" << endl;
    // b.postOrder(root);

    // cout << "\nPre Order traversal" << endl;
    // b.preOrder(root);

    // cout << "\nIn order traversal" << endl;
    // b.inOrder(root);

    // **Graph**
    // graph g;
    // int e;
    // cin >> e;
    // for (int i = 0; i < e; i++)
    // {
    //     int f, s;
    //     cin >> f >> s;
    //     g.addEdge(f, s);
    // }

    // g.adjacencyList();
    // cout << endl;
    // g.dfs();
    // cout << endl;
    // g.bfs();
    

    // **HashMaps**
    // HashMap<int> m;
    // m.insert("abc", 1);
    // m.insert("def", 2);
    // m.insert("ghi", 3);
    // cout << "Size" << m.size() << endl;
    // cout << "Value" << m.getValue("def") << endl;
    // cout << m.removeKey("ghi");
    

    // Stack
    // stackTemplate<int> st;
    // st.push(10);
    // st.push(11);
    // st.push(12);
    // st.push(13);
    // st.push(14);

    // while (!st.isEmpty())
    // {
    //     cout << st.top() << " ";
    //     st.pop();
    // }
    // cout << endl;

    // queue
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);

    q.print();
    cout << endl;
    


    // Array s;
    // cout << s.getN();
    /* queue<int> x1;
    x1.enqueue(1);
    queue<string> q(4);

    q.enqueue("a");
    q.enqueue("b");
    q.enqueue("c");

    cout << "The front element is " << q.peek() << endl;
    q.dequeue();

    q.enqueue("d");

    cout << "The queue size is " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    if (q.isEmpty())
    {
        cout << "The queue is empty\n";
    }
    else
    {
        cout << "The queue is not empty\n";
    }
    */
    return 0;
}
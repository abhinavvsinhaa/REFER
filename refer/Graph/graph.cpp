#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    graph g;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        g.addEdge(f, s);
    }

    g.adjacencyList();
    cout << endl;
    g.dfs();
    cout << endl;
    g.bfs();
    return 0;
}
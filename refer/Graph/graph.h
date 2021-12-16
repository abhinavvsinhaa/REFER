#include <bits/stdc++.h>
using namespace std;

class graph {
public:
    map<int, list<int>> g;

    //add new edge to graph
    void addEdge(int f, int s) {
        g[f].push_back(s);
        g[s].push_back(f);
    }

    //depth first search print
    void dfsUtil(int sv, unordered_map<int, bool>& visited) {
        cout << sv << " ";
        visited[sv] = true;

        for (auto i = g[sv].begin(); i != g[sv].end(); i++) {
            if (visited.count(*i) == 0) {
                dfsUtil(*i, visited);
            }
        }
    }

    //breadth first search print
    void bfsUtil(int sv, unordered_map<int, bool>& visit) {
        queue<int> pending;
        pending.push(sv);

        while (!pending.empty()) {
            int cur = pending.front();
            pending.pop();

            if (visit.count(cur) == 0) {
                cout << cur << " ";
                visit[cur] = true;
            }

            for (auto i = g[cur].begin(); i != g[cur].end(); i++) {
                if (visit.count(*i) == 0)
                    pending.push(*i);
            }
        }
    }

    void dfs() {
        unordered_map<int, bool> visited;
        int count = 0;
        for (int i = 0; i < g.size(); i++) {
            if (visited.count(i) == 0) {
                cout << "\ngraph " << count + 1 << endl;
                dfsUtil(i, visited);
                ++count;
            }
        }
    }

    void bfs() {
        unordered_map<int, bool> visited;
        int count = 0;
        for (int i = 0; i < g.size(); i++) {
            if (visited.count(i) == 0) {
                cout << "\ngraph " << count + 1 << endl;
                bfsUtil(i, visited);
                ++count;
            }
        }
    }

    void adjacencyList() {
        for (auto m = g.begin(); m != g.end(); m++) {
            cout << m->first << " -> ";
            for (auto l = m->second.begin(); l != m->second.end(); l++) {
                cout << *l << " ";
            }
            cout << endl;
        }
    }
};
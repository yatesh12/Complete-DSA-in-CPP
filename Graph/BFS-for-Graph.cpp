#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    void BFSTraversal(int start) { // Time: O(V + E)
        // BFS logic goes here
        // u -> source & v -> destination
        queue<int> q;
        q.push(start);
        vector<bool> visited(V, false);
        visited[start] = true;
        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout << u << " ";
            for(int v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.BFSTraversal(0); // Call BFS from node 0

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;

    public:

    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFSTraversal(int u, vector<bool>& visited){ // Time: O(V + E)
        cout << u << " ";
        visited[u] = true;

        for(int v : adj[u]){
            if(!visited[v]){
                DFSTraversal(v, visited);
            }
        }
    }
};

int main() {
    vector<bool> visited(5, false);
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.DFSTraversal(0, visited);

    return 0;
}
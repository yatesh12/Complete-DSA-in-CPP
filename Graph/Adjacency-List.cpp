#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;            // Number of vertices
    list<int>* adj;   // Array of adjacency lists

public:
    // Constructor: allocate array of lists
    Graph(int V) : V(V) {
        adj = new list<int>[V];
    }

    // Destructor: clean up the adjacency lists array
    ~Graph() {
        delete[] adj;
    }

    // Add undirected edge u–v
    void addEdge(int u, int v) {
        // Validate vertex indices
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cerr << "Error: vertex out of range\n";
            return;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print the adjacency list representation
    void printAdjList() const {
        for (int i = 0; i < V; ++i) {
            cout << i << " : ";
            for (int neigh : adj[i]) {
                cout << neigh << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjList();
    return 0;
}
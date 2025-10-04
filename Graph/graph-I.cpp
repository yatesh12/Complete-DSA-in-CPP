#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;

public:
    // Add an edge to the graph
    void addEdge(int u, int v, bool isDirected) {
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    // Print the adjacency list
    void printAdjList() {
        for (const auto& pair : adjList) {
            cout << pair.first << " -> ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    int nodes, edges;

    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter each edge as: node1 node2 direction (1 for directed, 0 for undirected):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        bool isDirected;
        cin >> u >> v >> isDirected;
        g.addEdge(u, v, isDirected);
    }

    cout << "\nAdjacency List Representation:\n";
    g.printAdjList();

    return 0;
}
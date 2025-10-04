#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    int depth = 1;

    while (!q.empty()) {
        int levelSize = q.size(); // number of nodes at current depth
        for (int i = 0; i < levelSize; ++i) {
            Node* node = q.front();
            q.pop();

            // If it's a leaf node, return current depth
            if (!node->left && !node->right)
                return depth;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ++depth;
    }

    return 0; // Should never reach here
}

int main() {
    /*
        Constructing the following tree:
              1
             / \
            2   3
           /
          4
        Min depth = 2 (via node 3)
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Minimum Depth: " << minDepth(root) << endl;

    // Clean up memory (optional for small test cases)
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}



// - Time Complexity: O(n) 
// - Space Complexity: O(n) 

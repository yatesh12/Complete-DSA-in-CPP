#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    int value;
    Node* next;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

Node* sortByKey(Node* head) {
    if (!head || !head->next) return head;

    vector<Node*> nodes;
    Node* curr = head;

    // Step 1: Store nodes in a vector
    while (curr) {
        nodes.push_back(curr);
        curr = curr->next;
    }

    // Step 2: Sort by key
    sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        return a->key < b->key;
    });

    // Step 3: Rebuild the linked list
    for (int i = 0; i < nodes.size() - 1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes.back()->next = nullptr;

    return nodes[0];
}

int main() {
    // Create sample linked list: (key, value)
    Node* head = new Node(3, 50);
    head->next = new Node(1, 20);
    head->next->next = new Node(2, 40);
    head->next->next->next = new Node(4, 10);

    cout << "Original List:\n";
    Node* temp = head;
    while (temp) {
        cout << "(" << temp->key << ", " << temp->value << ") -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    // Sort by key
    Node* sortedByKey = sortByKey(head);
    cout << "\nSorted by Key:\n";
    temp = sortedByKey;
    while (temp) {
        cout << "(" << temp->key << ", " << temp->value << ") -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}
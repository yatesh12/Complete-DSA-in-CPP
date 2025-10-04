#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to reverse k nodes in the linked list
Node* kReverse(Node* head, int k) {
    // Base case
    if (head == NULL) {
        return NULL;
    }

    // Step 1: Reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int cnt = 0;
    while (curr != NULL && cnt < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // Step 2: Recursion for remaining list
    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    // Step 3: Return new head of reversed list
    return prev;
}

// Helper function to insert node at the end
void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    for (int i = 1; i <= 6; i++) {
        insertAtTail(head, i);
    }

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = kReverse(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
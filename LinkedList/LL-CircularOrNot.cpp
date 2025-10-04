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

// Function to check if the list is circular
bool isCircular(Node* &tail) {
    // Empty list
    if (tail == NULL) {
        return false;
    }

    Node* temp = tail->next;
    while (temp != NULL && temp != tail) {
        temp = temp->next;
    }

    return (temp == tail);
}

// Helper function to insert node at tail
void insertNode(Node* &tail, int element, int data) {
    // Empty list
    if (tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode; // circular
        return;
    }

    // Non-empty list
    Node* curr = tail;
    do {
        if (curr->data == element) {
            Node* newNode = new Node(data);
            newNode->next = curr->next;
            curr->next = newNode;
            if (curr == tail) {
                tail = newNode;
            }
            return;
        }
        curr = curr->next;
    } while (curr != tail);
}

// Helper function to print the list (prints only once around the circle)
void printList(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main() {
    Node* tail = NULL;

    // Create circular linked list: 10 -> 20 -> 30 -> 40 -> back to 10
    insertNode(tail, 0, 10); // first node
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 30, 40);

    cout << "Circular Linked List: ";
    printList(tail);

    if (isCircular(tail)) {
        cout << "The list is circular." << endl;
    } else {
        cout << "The list is not circular." << endl;
    }

    return 0;
}
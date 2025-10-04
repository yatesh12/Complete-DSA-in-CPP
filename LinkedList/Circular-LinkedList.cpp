#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // Destructor for recursive cleanup
    ~Node() {
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
    }
};

void insertNode(Node*& tail, int element, int data) {
    // Case 1: Empty list
    if (tail == nullptr) {
        Node* newNode = new Node(data);
        newNode->next = newNode;
        tail = newNode;
        return;
    }

    // Case 2: Non-empty list, search for element
    Node* curr = tail;
    do {
        if (curr->data == element) {
            Node* newNode = new Node(data);
            newNode->next = curr->next;
            curr->next = newNode;
            // Optional: update tail if inserting after tail
            if (curr == tail) tail = newNode;
            return;
        }
        curr = curr->next;
    } while (curr != tail);

    cout << "Element " << element << " not found in the list.\n";
}

void print(Node* tail) {
    if (tail == nullptr) {
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

void deleteNode(Node*& tail, int element) {
    if (tail == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* prev = tail;
    Node* curr = tail->next;

    do {
        if (curr->data == element) {
            prev->next = curr->next;

            // Deleting the only node in list
            if (curr == prev) {
                tail = nullptr;
            } 
            // Deleting tail node
            else if (curr == tail) {
                tail = prev;
            }

            curr->next = nullptr;
            delete curr;
            return;
        }

        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    cout << "Element " << element << " not found in the list.\n";
}

int main() {
    Node* tail = nullptr;

    insertNode(tail, 5, 3);     // Creating first node with data=3
    print(tail);

    insertNode(tail, 3, 5);     // Insert 5 after 3
    print(tail);

    insertNode(tail, 5, 15);    // Insert 15 after 5
    print(tail);

    insertNode(tail, 5, 16);    // Insert 16 after 5
    print(tail);

    deleteNode(tail, 3);        // Delete node with data=3
    print(tail);

    return 0;
}
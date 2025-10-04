#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at end
void insertAtEnd(Node*& head, int data) {
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

// Iterative Reverse the list (More Efficient)
void reverse(Node*& head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
}

// Time: O(n)
// Space: O(1)

// Recursive function to reverse the list
Node* reverseRecursive(Node* head) {
    if (!head || !head->next) return head;

    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

// Time: O(n)
// Space: O(n) Recursive call stack depth

// Print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Original list: ";
    printList(head);

    reverse(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
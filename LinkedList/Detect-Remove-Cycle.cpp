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
 
// Floyd’s Cycle Detection
Node* detectLoop(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // loop detected
        }
    }

    return NULL; // no loop
}

// Find starting point of loop
Node* getStartingNode(Node* head) {
    Node* intersection = detectLoop(head);
    if (intersection == NULL) return NULL;

    Node* ptr1 = head;
    Node* ptr2 = intersection;

    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1; // start of loop
}

// Remove loop
void removeLoop(Node* head) {
    Node* startOfLoop = getStartingNode(head);
    if (startOfLoop == NULL) return;

    Node* temp = startOfLoop;
    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL; // break the loop
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a looped list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 ...
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // loop at node 3

    // Detect and remove loop
    if (detectLoop(head)) {
        cout << "Loop detected!" << endl;
        Node* loopStart = getStartingNode(head);
        cout << "Loop starts at node with data: " << loopStart->data << endl;
        removeLoop(head);
        cout << "Loop removed." << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    // Print list after loop removal
    printList(head);

    return 0;
}
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

    ~Node() {
        // Optional: clean-up logic if needed
    }
};

// Insert at end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Efficient middle finder using slow/fast pointers
Node* findMiddle(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    Node* head = nullptr;

    // Build the list: 10 -> 20 -> 30 -> 40 -> 50
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    Node* middle = findMiddle(head);
    if (middle != nullptr) {
        cout << "Middle node data: " << middle->data << endl;
    } else {
        cout << "List is empty." << endl;
    }

    return 0;
}
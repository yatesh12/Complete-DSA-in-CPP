#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    // Destructor
    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node*& head, int data) {
  if(head == NULL){
    Node* temp = new Node(data);
    head = temp;

  }else{
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != nullptr) head->prev = newNode;
    head = newNode;
  }
}

void insertAtTail(Node*& tail, int data) {
    if(tail == NULL){
        Node* temp = new Node(data);
        tail = temp;

    }else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node*& tail, Node*& head, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp->next != nullptr) {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr) {
        insertAtTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNode(Node* & head, int pos){
    if(pos == 1){
        Node* temp = head;
        head -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;

    }else{
        // deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < pos){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr; 
    }
}

int main() {
    Node* head = new Node(10);
    Node* tail = head;

    print(head);
    cout << "Length of linked list: " << getLength(head) << endl;

    insertAtHead(head, 25);
    print(head);

    insertAtTail(tail, 255);
    print(head);

    insertAtPosition(tail, head, 2, 35);
    print(head);  // updated from print(tail) to reflect full list

    deleteNode(head, 3);
    print(head);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* MergeTwoSortedLL(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr){
        return head1 == nullptr ? head2 : head1;
    }

    if(head1->data <= head2->data){
        head1->next = MergeTwoSortedLL(head1->next, head2);
        return head1;
    }else{
        head2->next = MergeTwoSortedLL(head1, head2->next);
        return head2;
    }

}

// Helper function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
Node* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> list1 = {1, 3, 5};
    vector<int> list2 = {2, 4, 6};
    Node* head1 = createList(list1);
    Node* head2 = createList(list2);

    Node* merged = MergeTwoSortedLL(head1, head2);
    cout << "Merged List: ";
    printList(merged);

    return 0;
}
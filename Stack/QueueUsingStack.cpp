#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:
    // Enqueue element
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue element
    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty()) {
            s2.pop();
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    // Get front element
    int front() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty()) {
            return s2.top();
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }

    // Check if queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }

    // Print queue from front to back
    void printQueue() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        // Transfer to s2 if needed
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        stack<int> temp = s2;
        vector<int> output;
        while (!temp.empty()) {
            output.push_back(temp.top());
            temp.pop();
        }

        cout << "Queue (front to back): ";
        for (int i = 0; i < output.size(); ++i) {
            cout << output[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.printQueue(); // Output: 10 20 30

    cout << "Front: " << q.front() << endl; // 10
    q.dequeue();

    q.printQueue(); // Output: 20 30
    cout << "Front after dequeue: " << q.front() << endl; // 20

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> order){
    idx++;
    if(order[idx] == -1){
        return NULL;
    }

    Node* root = new Node(order[idx]);
    root->left = buildTree(order);
    root->right = buildTree(order);

    return root;
}

// Height of Tree
int heightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHT = heightOfTree(root->left);
    int rightHT = heightOfTree(root->right);

    return max(leftHT, rightHT) + 1;
}

// Count node of the Tree
int countNode(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);

    return leftCount + rightCount + 1;
}

// Sum of all Nodes
int sum = 0;
int sumOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    sum += root->data;
    sumOfNodes(root->left);
    sumOfNodes(root->right);

    return sum;
}

int main() {
    vector<int> order = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(order);

    int result = heightOfTree(root);
    cout << "Height of Tree: " << result << endl;

    int count = countNode(root);
    cout << "Total Number of Node in Tree: " << count << endl;

    int sum = sumOfNodes(root);
    cout << "Sum of all Tree nodes: " << sum << endl;
  
  return 0;
}
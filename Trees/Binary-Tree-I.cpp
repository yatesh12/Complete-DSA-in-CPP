#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:    
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {};
    
};

static int idx = -1;
Node* buildTree(vector<int> order){
    idx++;
    if(order[idx] == -1){
        return NULL;
    }

    Node* root = new Node(order[idx]);
    root->left = buildTree(order); //Left
    root->right = buildTree(order); // Right

    return root;
}

// PreOrder Traversal
void preOrder(Node* root){
    // Base case
    if(root == NULL){
        return;
    }

    cout << root-> data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// inOrder Traversal
void inOrder(Node* root){
    // Base case
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// postOrder Traversal
void postOrder(Node* root){
    // Base case
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root-> data << " ";
}

// Level wise Traversal
void levelWiseTraversal(Node* root){

    if(root == nullptr){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        // level wise tracking
        if(curr == NULL){
        if(!q.empty()){
            cout << endl;
            q.push(NULL);
            continue;
        }else{
                break;
            }
        }
        
        cout << curr->data << " ";

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

    cout << endl;
}

void BFS(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main() {

    vector<int> order = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(order);

    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data  << endl;

    // cout << "Preorder Traversal: ";
    // preOrder(root);
    // cout << "\n";

    // cout << "Inorder Traversal: ";
    // inOrder(root);
    // cout << "\n";

    // cout << "Postorder Traversal: ";
    // postOrder(root);
    // cout << "\n";

    // cout << "Level order Traversal:\n ";
    // levelWiseTraversal(root);
    // cout << "\n";
  
    
    cout << "BFS Traversal:\n ";
    BFS(root);
    cout << "\n";
  return 0;
}
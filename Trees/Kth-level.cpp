#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// Print k level elements of a tree
void func(TreeNode* root, int k) {
    // Logic to process k-th level goes here
    if(root == NULL){
        return;
    }

    if(k == 1){
        cout << root->val << " ";
        return;
    }

    func(root->left, k-1);
    func(root->right, k-1);
}

int main() {
    // Create a sample binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int k = 3; // Level to process

    func(root, k); // Call your function

    // Clean up memory (in practice, you'd use smart pointers or recursive cleanup)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
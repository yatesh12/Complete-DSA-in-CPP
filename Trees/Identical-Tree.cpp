#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// find tree is identical or not
bool isIdentical(TreeNode*& p, TreeNode*& q){
    if(p == nullptr || q == nullptr){
        return p == q;
    }


    bool isLeftsame = isIdentical(p->left, q->left);
    
    bool isRightsame = isIdentical(p->right, q->right);

    return isLeftsame && isRightsame && p->val == q->val;
}

int main() {
    // Create first tree
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Create second tree
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // TODO: Add your logic to compare trees p and q

    bool ans = isIdentical(p, q);
    cout << (ans ? "Identical" : "Not Identical");

    return 0;
}
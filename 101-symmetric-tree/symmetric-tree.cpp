/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool mirror(TreeNode* p, TreeNode* q){
    if(p==nullptr or q==nullptr){
        return p==q;
    }
    if(p->val != q->val) return false; 
    return (mirror(p->left, q->right) and mirror(p->right, q->left));
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return mirror(root->left, root->right);
    }
};
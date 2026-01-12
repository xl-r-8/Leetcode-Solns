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

void post(TreeNode* node){
    if(node==nullptr) return;
    post(node->left);
    post(node->right);
    if(node->left==nullptr) return;
    TreeNode* tree=node->left;
    while(tree->right!=nullptr) tree=tree->right;
    tree->right=node->right;
    node->right=node->left;
    node->left=nullptr;
} 

class Solution {
public:
    void flatten(TreeNode* root) {
        post(root);
    }
};
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
 void preorder(TreeNode* root,vector<int>& storage){
    if(root==nullptr)return;
    storage.push_back(root->val);
    preorder(root->left,storage);
    preorder(root->right,storage);
    
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};
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
int height(TreeNode* node, unordered_map<TreeNode*, int>& mp){
    if(node==nullptr) return 0;
    return mp[node]=max(height(node->left, mp), height(node->right, mp))+1;
}
bool preorder(TreeNode* node, unordered_map<TreeNode*, int>& mp){
    if(node==nullptr) return true;
    int leftht= (node->left==nullptr)? 0 : mp[node->left]; 
    int rightht= (node->right==nullptr)? 0 : mp[node->right]; 
    if(abs(leftht-rightht)>1) return false;
    return (preorder(node->left, mp) and preorder(node->right, mp));
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode*,int> mp; 
        height(root, mp);
        return preorder(root, mp);
    }
};
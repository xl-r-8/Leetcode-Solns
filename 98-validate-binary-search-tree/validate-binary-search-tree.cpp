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

bool validity(TreeNode* node, long long mn, long long mx){
    if(node==nullptr) return true;
    long long left=(node->left==nullptr)?LLONG_MIN: node->left->val;
    long long right=(node->right==nullptr)?LLONG_MAX: node->right->val;
    long long finalmn=max(left, mn);
    long long finalmx=min(right, mx);
    // cout<<node->val<<" "<<finalmn<<" "<<finalmx<<endl;
    if(node->val<=finalmn or node->val>=finalmx) return false;
    return (validity(node->left, mn, node->val) and validity(node->right, node->val, mx));
}
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validity(root, LLONG_MIN, LLONG_MAX);
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* lca(TreeNode* node, int mn, int mx){
    if(mn<=node->val and node->val<=mx) return node;
    if(mx<node->val) return lca(node->left, mn,  mx);
    if(node->val<mn) return lca(node->right,  mn,  mx);
    return nullptr;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mn=min(p->val, q->val);
        int mx=max(p->val, q->val);
        return lca(root, mn, mx);
    }
};
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
TreeNode* bst(vector<int>& preorder, int i, int mn, int mx){
    if(i>=preorder.size()) return nullptr;
    if(preorder[i]<=mn or preorder[i]>=mx) return bst(preorder, i+1, mn, mx); //if i+1 is not the node then the next one might be
    TreeNode* node=new TreeNode(preorder[i]);
    node->left = bst(preorder, i+1, mn, node->val);
    node->right = bst(preorder, i+1, node->val, mx);
    return node;
}


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder, 0, INT_MIN, INT_MAX);
        
    }
};
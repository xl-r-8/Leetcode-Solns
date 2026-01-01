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
TreeNode* bst(vector<int>& preorder, int& i, int mn, int mx){
    if(i>=preorder.size() or preorder[i]<=mn or preorder[i]>=mx) return nullptr;
    
    TreeNode* node=new TreeNode(preorder[i]);
    i++;
    node->left = bst(preorder, i, mn, node->val);
    node->right = bst(preorder, i, node->val, mx);
    return node;
}


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(preorder, i, INT_MIN, INT_MAX);
    }
};
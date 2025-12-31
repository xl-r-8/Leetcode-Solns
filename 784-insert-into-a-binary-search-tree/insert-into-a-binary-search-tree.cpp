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
void ins(TreeNode* node, int val){

    if(val>node->val){
        if(node->right==nullptr)node->right=new TreeNode(val);
        else ins(node->right, val);
    }
    else if(val<node->val){
        if(node->left==nullptr)node->left=new TreeNode(val);
        else ins(node->left, val);
    }
}
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root!=nullptr)ins(root, val);
        else root=new TreeNode(val);
        return root;
    }
};
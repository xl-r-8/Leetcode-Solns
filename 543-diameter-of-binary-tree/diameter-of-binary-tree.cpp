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
class Solution {
public:
int maxdepth(TreeNode*root){
    if(root==nullptr)return 0;//no node 0 depth
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    return 1+max(lh,rh);
}
int helper(TreeNode*root,int &maxi){
    if(root==nullptr)return 0;
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    maxi=max(maxi,lh+rh);
    helper(root->left,maxi);
    helper(root->right,maxi);
    return maxi;
}
    int diameterOfBinaryTree(TreeNode* root) {
    int maxi=INT_MIN;
    helper(root,maxi);
    return maxi;
    }
};
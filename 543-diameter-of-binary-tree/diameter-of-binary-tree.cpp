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
    int diameterOfBinaryTree(TreeNode* root) {
    int maxi=INT_MIN;
    maxd(root,maxi);
    return maxi;
    }
// efficient o(n) solution
int maxd(TreeNode*root,int &maxi){
    if(root==nullptr)return 0;//no node 0 depth
    int lh=maxd(root->left,maxi);
    int rh=maxd(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}
};
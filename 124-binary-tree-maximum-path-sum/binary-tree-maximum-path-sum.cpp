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

int psum(TreeNode* node, int &maxps){
    if(node==nullptr) return 0;
    int leftp=psum(node->left, maxps);
    int rightp=psum(node->right, maxps);

    maxps=max(maxps, node->val);//only node
    maxps=max(maxps, node->val+leftp);//node+left
    maxps=max(maxps, node->val+rightp);//node+right
    maxps=max(maxps, node->val+leftp+rightp);//node+left+right
    //choose which path would be best for par(node)
    if(max(leftp, rightp)<=0) return node-> val; //only node
    return node->val + max(leftp, rightp);//node + max(left child of node, right child)
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxps=INT_MIN;
        psum(root, maxps);
        return maxps;
    }
};
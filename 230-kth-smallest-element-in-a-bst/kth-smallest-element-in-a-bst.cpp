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

void inorder(TreeNode* node, int &count, int k, int& ans){
    if(node==nullptr or ans!=-1) return;

    inorder(node->left, count, k, ans);
    count++;
    if(count==k) ans=node->val;
    inorder(node->right, count, k, ans);

}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0, ans=-1;
        inorder(root, count, k, ans);
        return ans;
    }
};
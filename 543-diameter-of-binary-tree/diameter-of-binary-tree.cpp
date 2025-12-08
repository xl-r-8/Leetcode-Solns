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
int height(TreeNode* node, int& maxd){
    if(node==nullptr) return 0;
    int leftht=height(node->left, maxd);
    int rightht=height(node->right, maxd);
    int totald=leftht+rightht+1 -1; //max path including the node = left subtree + node + right subtree, -1 coz we just want num of edges and not num of nodes
    maxd= max(maxd, totald);
    return max(leftht, rightht) + 1;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd=0;
        height(root, maxd);
        return maxd;
    }
};
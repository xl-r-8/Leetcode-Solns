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

bool soln(TreeNode* node, int targetSum, int sum){
    if (!node) return false;
    sum+=node->val;
    if (!node->left && !node->right) {//i.e. its a leaf node
        if(sum==targetSum) return true;
        return false;
    }

    bool soln1= soln(node->left, targetSum, sum);//soln from left child
    bool soln2= soln(node->right, targetSum, sum);//soln from right child

    if(soln1 or soln2) return true; //if soln exists from any child then a path exists, otherwise it does not exist for the current node
    return false;
}
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return soln(root, targetSum,0);    
    }
};
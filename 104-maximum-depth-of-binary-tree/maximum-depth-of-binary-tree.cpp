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
int height(TreeNode* node){
    if(node==nullptr) return 0;
    return max(height(node->left), height(node->right))+1;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //M1: recursive
        // return height(root);

        //M2: iterative
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int height=0;
        while(!q.empty()){
            int size=q.size();
            height++;
            for(int i=1; i<=size; i++){
                TreeNode* node=q.front(); q.pop();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
        }
        return height;
    }
};
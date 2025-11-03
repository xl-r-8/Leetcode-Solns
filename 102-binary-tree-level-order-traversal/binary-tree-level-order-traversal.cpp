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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root!=nullptr)q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int size=q.size(); //q.size is dynamic as we are inserting and deleting eles in the q, so must store the size in some static variable before using it
            vector<int>temp;
            for(int i=1; i<=size; i++){
                TreeNode* node=q.front(); q.pop();
                temp.push_back(node->val);
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
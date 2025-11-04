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

void pre(TreeNode* node, vector<int>&ans){
    if(node==nullptr) return;
    ans.push_back(node->val);
    pre(node->left,ans);
    pre(node->right,ans);
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // M1: recursive soln
        // pre(root, ans);
        // return ans;

        // M2: iterative soln
        stack<TreeNode*> st;
        if(root!=nullptr)st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top(); st.pop();
            ans.push_back(node->val);
            if(node->right!=nullptr) st.push(node->right);
            if(node->left!=nullptr) st.push(node->left);

        }
        return ans;

    }
};
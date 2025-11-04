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
void in(TreeNode* node, vector<int>&ans){
    if(node==nullptr) return;
    in(node->left,ans);
    ans.push_back(node->val);
    in(node->right,ans);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //M1: recursive soln
        // in(root, ans);
        // return ans;

        //M2: iterative soln
        stack<TreeNode*> st; unordered_map<TreeNode*, bool> mp;
        if(root!=nullptr)st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            if(mp.find(node)==mp.end()){ //node dne in the map
                if(node->left!=nullptr){
                    st.push(node->left);
                    continue;
                } 
                else{
                    ans.push_back(node->val);
                    mp[node]=true;
                }
            }

            //Before checking right you are sure ki root is printed so just remove it from the stack
            st.pop();

            if(node->right!=nullptr){
                st.push(node->right);
                continue;
            } 
            else{
                if(st.empty())break;
                node=st.top();
                ans.push_back(node->val);
                mp[node]=true;
            }

        }
        return ans;

    }
};
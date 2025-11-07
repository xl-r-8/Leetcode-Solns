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
        // stack<TreeNode*> st; unordered_map<TreeNode*, bool> mp;
        // if(root!=nullptr)st.push(root);
        // while(!st.empty()){
        //     TreeNode* node=st.top();
        //     if(mp.find(node)==mp.end()){ //node dne in the map
        //         if(node->left!=nullptr){
        //             st.push(node->left);
        //             continue;
        //         } 
        //         else{
        //             ans.push_back(node->val);
        //             mp[node]=true;
        //         }
        //     }

        //     //Before checking right you are sure ki root is printed so just remove it from the stack
        //     st.pop();

        //     if(node->right!=nullptr){
        //         st.push(node->right);
        //         continue;
        //     } 
        //     else{
        //         if(st.empty())break;
        //         node=st.top();
        //         ans.push_back(node->val);
        //         mp[node]=true;
        //     }

        // }
        // return ans;

        //M3: iterative better soln
        // stack<TreeNode*>st;
        // TreeNode* node=nullptr;
        // if(root!=nullptr)st.push(root);
        // while(true){
        //     if(node==nullptr){
        //         if(st.empty())break;
        //         node=st.top(); st.pop();
        //         ans.push_back(node->val);
        //         node=node->right;
        //     }
        //     else{
        //         st.push(node);
        //         node=node->left;
        //     }
        // }

        //M3 but correct one
        // stack<TreeNode*> st;
        // TreeNode* node = root;               // start at root (IMPORTANT)

        // while (node != nullptr || !st.empty()) {
        //     if (node != nullptr) {
        //         // go left as far as possible, pushing nodes on stack
        //         st.push(node);
        //         node = node->left;
        //     } else {
        //         // left is exhausted -> visit top, then go right
        //         node = st.top(); st.pop();
        //         ans.push_back(node->val);
        //         node = node->right;
        //     }
        // }
        // return ans;

        //M4: my way
        stack<TreeNode*> st;
        if(root!=nullptr)st.push(root);
        unordered_map<TreeNode*, bool> mp;
        while(!st.empty()){
            TreeNode* node=st.top();

            if(node->left!=nullptr and mp.find(node->left)==mp.end()){
                st.push(node->left);
                continue;
            }
            else{
                ans.push_back(node->val); st.pop();
                if(node->right!=nullptr) st.push(node->right);
                // node=nullptr;
                mp[node]=true;
            }
        }
        return ans;
    }
};
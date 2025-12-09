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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        q.push(root);
        int count=0; 
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            stack<TreeNode*> s;
            if(count%2==0){
                for(int i=1; i<=size; i++){
                    TreeNode* node=q.front(); q.pop();
                    temp.push_back(node->val);
                    s.push(node);
                }
                while(!s.empty()){
                    TreeNode* node=s.top(); s.pop();
                    if(node->right!=nullptr) q.push(node->right);
                    if(node->left!=nullptr) q.push(node->left);
                }
            }
            else{
                for(int i=1; i<=size; i++){
                    TreeNode* node=q.front(); q.pop();
                    temp.push_back(node->val);
                    s.push(node);
                }
                while(!s.empty()){
                    TreeNode* node=s.top(); s.pop();
                    if(node->left!=nullptr) q.push(node->left);
                    if(node->right!=nullptr) q.push(node->right);
                }
            }
            count++;
            ans.push_back(temp);
        }
        return ans;
    }
};
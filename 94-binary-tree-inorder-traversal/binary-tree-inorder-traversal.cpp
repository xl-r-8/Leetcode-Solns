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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        unordered_map<TreeNode*, TreeNode*> next;

        while(curr!=nullptr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                if(curr->right!=nullptr)curr=curr->right;
                else{
                    if(next.find(curr)!= next.end()) curr=next[curr];//ie when curr exists in next
                    else curr=nullptr;
                }
            }
            else{
                TreeNode* node=curr->left;
                while(node->right!=nullptr) node=node->right;
                if(next.find(node)!= next.end()){
                    ans.push_back(curr->val);
                    if(curr->right!=nullptr)curr=curr->right;
                    else{
                        if(next.find(curr)!= next.end()) curr=next[curr];
                        else curr=nullptr;
                    }
                }
                else{
                    next[node]=curr;
                    curr=curr->left;
                }
            }
        }
        return ans;
    }
};
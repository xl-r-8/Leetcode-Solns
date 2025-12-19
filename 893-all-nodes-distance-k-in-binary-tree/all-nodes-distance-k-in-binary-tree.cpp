/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//1.2: dfs way of marking node->par 
void dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>&mp){
    if(node->left!=nullptr){
        mp[node->left]=node;//par(node->left)=node
        dfs(node->left,mp);
    }
    if(node->right!=nullptr){
        mp[node->right]=node;//par(node->right)=node
        dfs(node->right,mp);
    }
}

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;//{key:val}, where key is node and val is par, so mp stores node->par pointers
        mp[root]=nullptr;//root doesnt have a par

        //1.1: marking node->par pointers through bfs
        // queue<TreeNode*>q;
        // if(root!=nullptr) q.push(root);
        // while(!q.empty()){
        //     TreeNode* node=q.front(); q.pop();
        //     if(node->left!=nullptr){
        //         mp[node->left]=node;//par(node->left)=node
        //         q.push(node->left);
        //     }
        //     if(node->right!=nullptr){
        //         mp[node->right]=node;//par(node->right)=node
        //         q.push(node->right);
        //     }
        // }

        //or
        //1.2
        if(root!=nullptr)dfs(root, mp);

        //2.1: bfs for finding nodes at dist k
        queue<pair<TreeNode*,int>> q2;//{node,dist}
        q2.push({target,0});
        vector<int> ans;
        unordered_map<TreeNode*,bool> vis;
        while(!q2.empty()){
            TreeNode* node=q2.front().first;
            int dist=q2.front().second;
            q2.pop();
            vis[node]=true;
            if(dist==k) ans.push_back(node->val);
            if(mp[node]!=nullptr and vis.find(mp[node])==vis.end()) q2.push({mp[node],dist+1});//mp[node]=par(node)
            if(node->left!=nullptr and vis.find(node->left)==vis.end()) q2.push({node->left,dist+1});
            if(node->right!=nullptr and vis.find(node->right)==vis.end()) q2.push({node->right,dist+1});
        }
        return ans;
    }
};
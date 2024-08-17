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
int LevelWise(TreeNode* rootptr){
    // vector<vector<int>> ans;
    if(rootptr==nullptr) return 0;
    int count=0;
    queue<TreeNode*> q;
    q.push(rootptr);
    while(!q.empty()){
        int size=q.size();
        // vector<int> level;
        for(int i=1; i<=size;i++){
            TreeNode* nodeptr=q.front(); q.pop();
            // level.push_back(nodeptr->data);
            if(nodeptr->left!=NULL) q.push(nodeptr->left);
            if(nodeptr->right!=NULL) q.push(nodeptr->right);
        }
        // ans.push_back(level);
        count++;
    }
    
    return count;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return LevelWise(root);
    }
};
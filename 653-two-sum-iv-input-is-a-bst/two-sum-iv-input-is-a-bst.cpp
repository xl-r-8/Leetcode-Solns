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

void ino(TreeNode* node, vector<int>& v){
    if(node==nullptr) return;

    ino(node->left, v);
    v.push_back(node->val);
    ino(node->right, v);

}

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        ino(root, v);

        int i=0, j=v.size()-1;
        while(i<j){
            if(v[i]+v[j]==k) return true;
            else if(v[i]+v[j]>k)j--;
            else{ //if(v[i]+v[j]>k)
                i++;
            }
        }
        return false;
    }
};
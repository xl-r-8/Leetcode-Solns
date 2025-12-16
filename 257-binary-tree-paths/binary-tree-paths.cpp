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

//M2: findPath and find leaves combined into 1
void pathTL(TreeNode* node, TreeNode* root, vector<string>&ans, string s){//path to leaves
    if(node==nullptr) return;
    if(node!=root)s+="->"; 
    s+=to_string(node->val);
    if(node->left==nullptr and node->right==nullptr)ans.push_back(s);
    //cool trick: shift+INS = ctrl+v
    pathTL(node->left, root, ans, s);
    pathTL(node->right, root, ans, s);
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        pathTL(root, root, ans, "");
        return ans;
    }
};
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
//M1: traverse again for every next node, basically separate funcns for finding path and finding leaf
bool pathTN(TreeNode* node, TreeNode* key, vector<int>&path, vector<int> temp){//path to node
// can also use int key but for that all the nodevals must be unique
    if(node==nullptr) return false;
    temp.push_back(node->val);
    if(node==key){
        path=temp;
        return true;
    }
    return (pathTN(node->left, key, path, temp) or pathTN(node->right, key, path, temp));
}

void findLeaves(TreeNode* node, vector<TreeNode*>& leaves){
    if(node==nullptr) return;
    if(node->left==nullptr and node->right==nullptr) leaves.push_back(node);
    findLeaves(node->left, leaves);
    findLeaves(node->right, leaves);
}

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<TreeNode*> leaves;
        findLeaves(root, leaves);
        for(TreeNode* leaf: leaves){
            vector<int> path;
            pathTN(root, leaf, path, {});
            string s="";
            int n=path.size();
            for(int i=0; i<n-1; i++){
                s+=to_string(path[i]);
                s+="->";
            }
            s+=to_string(path[n-1]);
            ans.push_back(s);
        }

        return ans;
    }
};
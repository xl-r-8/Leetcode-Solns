/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// bool pathTN(TreeNode* node, TreeNode* key, vector<TreeNode*>&path, vector<TreeNode*> temp){//path to node
// // can also use int key but for that all the nodevals must be unique
//     if(node==nullptr) return false;
//     temp.push_back(node);
//     if(node==key){
//         path=temp;
//         return true;
//     }
//     return (pathTN(node->left, key, path, temp) or pathTN(node->right, key, path, temp));
// }

TreeNode* lca(TreeNode* node, TreeNode* p, TreeNode* q){
    if(node==nullptr) return nullptr;
    if(node==p or node==q) return node;
    TreeNode* left=lca(node->left, p, q);
    TreeNode* right=lca(node->right, p, q);
    if(left==nullptr) return right;
    else if(right==nullptr) return left;
    else return node;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //M1
        // vector<TreeNode*> path1;
        // vector<TreeNode*> path2;
        // if(pathTN(root, p, path1,{}) and pathTN(root, q, path2, {})){
        //     TreeNode* ans=nullptr;
        //     int m=path1.size(), n=path2.size();
        //     for(int i=0; i<min(m,n); i++){
        //         if(path1[i]==path2[i]) ans=path1[i];
        //     }

        //     return ans;
        // }
        // return nullptr;

        //M2
        return lca(root, p, q);
    }
};
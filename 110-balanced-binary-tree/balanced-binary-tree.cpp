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

//M1:
// int height(TreeNode* node, unordered_map<TreeNode*, int>& mp){
//     if(node==nullptr) return 0;
//     return mp[node]=max(height(node->left, mp), height(node->right, mp))+1;
// }
// bool preorder(TreeNode* node, unordered_map<TreeNode*, int>& mp){
//     if(node==nullptr) return true;
//     int leftht= (node->left==nullptr)? 0 : mp[node->left]; 
//     int rightht= (node->right==nullptr)? 0 : mp[node->right]; 
//     if(abs(leftht-rightht)>1) return false;
//     return (preorder(node->left, mp) and preorder(node->right, mp));
// }

//M2:
int height2(TreeNode* node){
    if(node==nullptr) return 0;
    int leftht=height2(node->left);
    int rightht=height2(node->right);
    if(abs(leftht-rightht)>1 or leftht==-1 or rightht==-1) return -1; //if(abs(leftht-rightht)>1 or leftht==-1 or rightht==-1), do we need these extra conditions?
    return max(leftht, rightht)+1;
}
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //M1:
        // unordered_map<TreeNode*,int> mp; 
        // height(root, mp);
        // return preorder(root, mp);

        //M2
        if(height2(root)==-1)return false;
        return true;
    }
};
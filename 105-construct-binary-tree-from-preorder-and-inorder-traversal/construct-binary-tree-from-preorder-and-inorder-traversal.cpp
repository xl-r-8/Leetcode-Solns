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

TreeNode* maketree(vector<int>& in, int loi, int hii, vector<int>& pre, int lop, int hip){
    if(loi>hii) return nullptr;
    int ele=pre[lop];
    TreeNode* node=new TreeNode(ele);
    int index=-1;
    for(int i=loi; i<=hii; i++){
        if(in[i]==ele) index=i;
    }
    TreeNode* left=maketree(in, loi, index-1, pre, lop+1, lop+(index-loi)); //index-loi=number of eles b/w loi and index
    TreeNode* right=maketree(in, index+1, hii, pre, lop+(index-loi)+1, hip);
    node->left=left;
    node->right=right;

    return node;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return maketree(inorder, 0, n-1, preorder, 0, n-1);
    }
};
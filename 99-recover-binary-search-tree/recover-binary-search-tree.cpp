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

void ino(TreeNode* node, vector<TreeNode*>& v){
    if(node==nullptr) return;

    ino(node->left, v);
    v.push_back(node);
    ino(node->right, v);
}

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> v;
        ino(root, v);
        int n=v.size();
        TreeNode* p=nullptr;
        TreeNode* q=nullptr;
        for(int i=0; i<n-1; i++){
            TreeNode* curr=v[i];
            TreeNode* next=v[i+1];
            if(curr->val > next->val){
                if(p==nullptr){
                    p=curr; q=next;
                }
                else q=next;
            }
        }
        swap(p->val, q->val);
    }
};
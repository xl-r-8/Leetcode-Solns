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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // search(root, nullptr, root, key);
        //let's write iterative code so that we can have everything here

        TreeNode* node=root;
        TreeNode* par=nullptr;
        while(node!=nullptr and node->val!=key){
            // cout<<node->val<<endl;
            if(node==nullptr) return root;
            if(key<node->val){
                par=node;
                node=node->left;
            }
            else if(key>node->val){
                par=node;
                node=node->right;
            }
        }
        if(node==nullptr) return root;
        // cout<<node->val<<endl;
        TreeNode* lft=node->left;
        TreeNode* rt=node->right;
        if(par!=nullptr){
            if(lft!=nullptr){
                if(par->left==node)par->left=lft;
                else par->right=lft; //par->right=node->left
            }
            else{
                if(par->left==node)par->left=rt;
                else par->right=rt; //par->right=node->right
            }
        }
        else{
            if(lft!=nullptr) root=lft;
            else root=rt;
        }
        if(lft!=nullptr){
            while(lft->right!=nullptr){
                lft=lft->right;
            }
            lft->right=node->right;
        }
        
        node->left=nullptr; node->right=nullptr;
        delete node;

        return root;
    }
};
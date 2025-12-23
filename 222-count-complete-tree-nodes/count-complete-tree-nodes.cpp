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

long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int leftheight(TreeNode* node){
    if(node==nullptr) return 0;
    return 1+leftheight(node->left);
}
int rightheight(TreeNode* node){
    if(node==nullptr) return 0;
    return 1+rightheight(node->right);
}

int numNodes(TreeNode* node){//number of nodes
    if(node==nullptr) return 0;
    int lht=leftheight(node->left);
    int rht=rightheight(node->right);
    // cout<<node->val<<" "<<lht<<" "<<rht<<endl;
    if(lht==rht){
        return power(2,lht+1)-1;
    }
    return 1+numNodes(node->left)+numNodes(node->right);
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        return numNodes(root);      
    }
};
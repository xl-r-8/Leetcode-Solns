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
 TreeNode* bstfromsortedarr(vector<int> nums, int low, int high){ //or bst from inorder
    if(low>=high) return NULL;
    int mid=(low+high)/2;

    TreeNode* root =new TreeNode(nums[mid]);

    // Left subtree
    root->left = bstfromsortedarr(nums, low, mid);

    // Right subtree
    root->right = bstfromsortedarr(nums, mid + 1, high);

    return root;

}
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bstfromsortedarr(nums,0,nums.size());
    }
};
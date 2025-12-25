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

TreeNode* maketree(vector<int>& in, int inStart, int inEnd, vector<int>& post, int postStart, int postEnd, unordered_map<int, int>& inMap){
    if(inStart>inEnd) return nullptr;
    int root=post[postEnd];
    TreeNode* node=new TreeNode(root);
    
    //M1: find root by traversing every time for every root=> all other things take O(1) TC, this will take O(in.size()) as TC and on summing it up the total TC will be O(n^2)=> TC of maketree=O(n^2)
    // int inRootind=-1;//inRootindex=index of root in inorder traversal
    // for(int i=inStart; i<=inEnd; i++){
    //     if(in[i]==root) {
    //         inRootind=i;
    //         break;
    //     }
    // }

    //M2: find index of root in inorder traversal using map
    int inRootind=inMap[root];

    int numsRight=inEnd-inRootind;//numsRight=num of elements on the right of Root in inorder traversal=num of elements b/w Root and end of inorder

    TreeNode* right=maketree(in, inRootind+1, inEnd, post, postEnd-numsRight, postEnd-1, inMap);
    TreeNode* left=maketree(in, inStart, inRootind-1, post, postStart, postEnd-numsRight-1, inMap); 
    node->right=right;
    node->left=left;

    return node;
}
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> inMap;//{ele: index} for inorder traversal
        for(int i=0; i<n; i++){
            inMap[inorder[i]]=i;//inorder[i]=ele
        }
        return maketree(inorder, 0, n-1, postorder, 0, n-1, inMap);
    }
};
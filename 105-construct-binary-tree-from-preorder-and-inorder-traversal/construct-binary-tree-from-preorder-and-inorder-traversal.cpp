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

TreeNode* maketree(vector<int>& in, int inStart, int inEnd, vector<int>& pre, int preStart, int preEnd, unordered_map<int, int>& inMap){
    if(inStart>inEnd) return nullptr;
    int root=pre[preStart];
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

    int numsLeft=inRootind-inStart;//numsLeft=num of elements on the left of Root in inorder traversal=num of elements b/w Root and start of inorder

    TreeNode* left=maketree(in, inStart, inRootind-1, pre, preStart+1, preStart+numsLeft, inMap); 
    TreeNode* right=maketree(in, inRootind+1, inEnd, pre, preStart+numsLeft+1, preEnd, inMap);
    node->left=left;
    node->right=right;

    return node;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> inMap;//{ele: index} for inorder traversal
        for(int i=0; i<n; i++){
            inMap[inorder[i]]=i;//inorder[i]=ele
        }
        return maketree(inorder, 0, n-1, preorder, 0, n-1, inMap);
    }
};
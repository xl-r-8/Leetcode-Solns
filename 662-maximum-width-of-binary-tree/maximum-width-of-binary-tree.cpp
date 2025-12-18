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
    int widthOfBinaryTree(TreeNode* root) {
        //Bfs is enough ig, coz level wise traverse karenge, left most node ko 1 rakh denge, say rightmost node=m ho gya then width of the level=m, yeh tab possible hota jab saare nodes exist karte b/w 1st and the last node
        // so we have to make structure like:
        //     1
        //   2   3
        // 4  5 6  7
        //say node 5 and 7 are null then we just have to find pos of first node which is 4 and pos of the last node which is 6, then width of this level=6-4+1=3
        queue<pair<TreeNode*, long long>> q;//{node,pos}
        q.push({root,0});
        long long ans=0;
        while(!q.empty()){
            int size=q.size();
            long long mn=-1, mx=-1;
            long long base = q.front().second; // normalization base
            for(int i=1; i<=size; i++){
               TreeNode* node= q.front().first;
               long long pos= q.front().second;
               pos-=base;
               q.pop();
               if(mn==-1)mn=pos;
               mx=pos;
               if(node->left!=nullptr) q.push({node->left, pos*2});
               if(node->right!=nullptr) q.push({node->right, pos*2+1});
            }
            ans=max(ans, mx-mn+1);
        }
        return ans;
    }
};
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

vector<int> bstinbt(TreeNode* node, int& ans){ //{min, max, size, validBST}
	vector<int> v={INT_MAX, INT_MIN, 0, 1};
	if(node==nullptr) return v;
	vector<int> left = bstinbt(node->left, ans);
	vector<int> right = bstinbt(node->right, ans);
	int leftmin=left[0], leftmax=left[1], leftdata=left[2], leftvalid=left[3];
	int rightmin=right[0], rightmax=right[1], rightdata=right[2], rightvalid=right[3];
	int nodemin=INT_MAX, nodemax=INT_MIN, nodedata=leftdata+rightdata+node->val, nodevalid=0;
	if(leftvalid==1 and rightvalid==1){
		if(leftmax==INT_MIN){//if left does not exist
			if(rightmin==INT_MAX){//if right dne
				ans=max(ans, nodedata);//if both righ and left dne then node is bst
				nodevalid=1;
			}
			else{//if right exists
				if(node->val<rightmin){
					ans=max(ans, nodedata);
					nodevalid=1;
				} 
			}
		}
		else if(rightmin==INT_MAX){//if right does not exist
			if(leftmax<node->val){
				ans=max(ans, nodedata);//ofc left exists
				nodevalid=1;
			} 
		}
		else { // if both left and right exist
			if(leftmax<node->val and node->val<rightmin){
				ans=max(ans, nodedata);
				nodevalid=1;
			} 
		}
	}
	

	nodemin=min({node->val, leftmin, rightmin});
	nodemax=max({node->val, leftmax, rightmax});
	v[0]=nodemin, v[1]=nodemax, v[2]=nodedata, v[3]=nodevalid;
	// cout<<"node: "<<" "<<node->val<<" "<<nodemin<<" "<<nodemax<<" "<<nodedata<<endl;
	// cout<<"left: "<<" "<<leftmin<<" "<<leftmax<<" "<<leftsize<<endl;
	// cout<<"right: "<<" "<<rightmin<<" "<<rightmax<<" "<<rightsize<<endl;
	// cout<<endl;
	return v;
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans=0;
        bstinbt(root, ans);
        return ans;
    }
};
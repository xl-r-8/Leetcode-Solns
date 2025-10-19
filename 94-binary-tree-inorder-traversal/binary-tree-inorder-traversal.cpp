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
    //vector return karega jisme inorder will be stored and hum tree ka root pass karenge as arg to perform inorder
vector<int>inorderTraversal(TreeNode* root){
vector<int>result;// to store and return inorder traversal
if(root==NULL)return result;//return empty vector if root is null ptr i.e tree is empty
//otherwise create a stack since this is dfs and we will go depth wise
stack<TreeNode*>st;//stack me treenodes push kar rahe to wohi type of stack
//go as left as possible first
TreeNode* node=root;
while(true){
    if(node!=nullptr){
        st.push(node);
        node=node->left;
    }
    //ab jab left me jate jate dead end aagya to
    else{
    if(st.empty()==true)break;//stack bhi khali hogya
    //ab stack me tos pe leftmost aadmi hai to wahi to inorder me chahiye
    //inorder is left->root>right
    //so push karo result me tos ko
    node=st.top();
    st.pop();
    result.push_back(node->val);
    // now move as right as possible
    node=node->right;
    }
}
return result;
}
        
    };

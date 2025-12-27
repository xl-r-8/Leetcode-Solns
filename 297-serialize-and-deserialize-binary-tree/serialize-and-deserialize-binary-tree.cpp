/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//M1: fake the system 😎
// TreeNode* node=nullptr;

//M2: real way
// TreeNode* makeTree(vector<int> v, int i. int j){
//     if(j>=v.size() or i>=v.size() or v[i]==1001 ) return nullptr;
//     TreeNode* node=new TreeNode(v[i]);
//     node->left=makeTree(v, 2*i+1);
//     node->right=makeTree(v, 2*i+2);

//     return node;
// }

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res="";

        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            if(node!=nullptr){
                res+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            else res+="#,";
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string cur="";

        for(int i=0; i<data.size();i++) {
            char ch=data[i];
            if(ch==','){
                tokens.push_back(cur);
                cur="";//or cur.clear()
            }            
            else cur+=data[i];
        }
        
        unordered_map<int, TreeNode*> mp;
        int i=0, j=1;
        TreeNode* root;
        if(tokens[0]=="#") root=nullptr;
        else{
            int val=stoi(tokens[0]);
            root=new TreeNode(val);
        }
        mp[0]=root; 
        while(j<tokens.size()){
            if(tokens[i]=="#") i++;
            else{
                TreeNode* node=mp[i];
                TreeNode* left;
                if(tokens[j]=="#") left=nullptr;
                else left=new TreeNode(stoi(tokens[j]));
                mp[j]=left;
                node->left=left;
                j++;
                TreeNode* right;
                if(tokens[j]=="#") right=nullptr;
                else right=new TreeNode(stoi(tokens[j]));
                mp[j]=right;
                node->right=right;
                j++;
                i++;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
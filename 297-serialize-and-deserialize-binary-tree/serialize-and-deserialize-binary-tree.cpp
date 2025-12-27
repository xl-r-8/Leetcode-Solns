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
        // node=root;
        // return "";

        queue<TreeNode*> q;
        q.push(root);
        string s="";
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node!=nullptr)s+=to_string(node->val)+",";
            else s+="#,";
            if(node!=nullptr){//if you dont keep this if condition then error will occur as nullptr does not have a left or right
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout<<s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // return node;
        vector<int> v;
        int num = 0;

        int sign=1;
        for(int i=0; i<data.size();i++) {
            char ch=data[i];
            if(ch==','){
                v.push_back(num);
                num=0;
                sign=1;
            }
            else if(ch=='#'){
                v.push_back(1001);
                i++;//skip the comma of #
            }
            else if(ch=='-') sign=-1;            
            else num = num * 10 + (ch - '0')*sign;
        }
        for(int ele:v) cout<<ele<<" ";
        
        unordered_map<int, TreeNode*> mp;
        int i=0, j=1;
        TreeNode* root;
        if(v[0]==1001) root=nullptr;
        else root= new TreeNode(v[0]);
        mp[0]=root; 
        while(j<v.size()){
            if(v[i]==1001) i++;
            else{
                TreeNode* node=mp[i];
                TreeNode* left;
                if(v[j]==1001) left=nullptr;
                else left=new TreeNode(v[j]);
                mp[j]=left;
                node->left=left;
                j++;
                TreeNode* right;
                if(v[j]==1001) right=nullptr;
                else right=new TreeNode(v[j]);
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
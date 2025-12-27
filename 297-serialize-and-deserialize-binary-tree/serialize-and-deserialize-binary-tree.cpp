/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    
    //M2.3: cleaner and without map
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

        for(int i=0; i<data.size();i++){//i=index of chars in data
            char ch=data[i];
            if(ch==','){
                tokens.push_back(cur);
                cur="";//or cur.clear()
            }            
            else cur+=data[i];
        }

        TreeNode* root;
        if(tokens[0]=="#"){
            root=nullptr;
            return root;
        } 
        root=new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i=1;//i=index of a str in tokens
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();

            if(i<tokens.size() and tokens[i]!="#"){
                //you dont create node for token "#", i.e. you are not creating node for nullptr nodes then how would you mark node->left=nullptr?: we dont have to do this coz by default if you dont assign any value then node->left=nullptr
                TreeNode* left=new TreeNode(stoi(tokens[i]));
                q.push(left);
                node->left=left; 
            }
            i++;
            //why outside if? coz even if node->left is nullptr and already marked by default but we have to move to the next token to mark node-> right
            if(i<tokens.size() and tokens[i]!="#"){
                TreeNode* right=new TreeNode(stoi(tokens[i]));
                q.push(right);
                node->right=right; 
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
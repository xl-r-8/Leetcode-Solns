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

class BSTnext {
    stack<TreeNode*> s;
public:
    BSTnext(TreeNode* root) {
        pushall(root);
    }
    
    int ele() {
        TreeNode* node=s.top();
        return node->val;
    }

    void next(){
        TreeNode* node=s.top(); s.pop();
        pushall(node->right);
    }
    
    bool hasnext() {
        return !s.empty();
    }

    void pushall(TreeNode* node){ //order of function execution in cpp
        while(node!=nullptr){
            s.push(node);
            node=node->left;
        }
    }
};

class BSTprev {
    stack<TreeNode*> s;
public:
    BSTprev(TreeNode* root) {
        pushall(root);
    }
    
    int ele() {
        TreeNode* node=s.top();
        return node->val;
    }

    void prev(){//move previous
        TreeNode* node=s.top(); s.pop();
        pushall(node->left);
    }
    
    bool hasprev() {
        return !s.empty();
    }

    void pushall(TreeNode* node){ //order of function execution in cpp
        while(node!=nullptr){
            s.push(node);
            node=node->right;
        }
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTnext a(root);
        BSTprev b(root);
        while(a.hasnext() and b.hasprev()){
            if(a.ele()+b.ele()==k){
                if(a.ele()==b.ele())break;
                return true;
            } 
            else if(a.ele()+b.ele()>k)b.prev();
            else{ //if(a.ele()+b.ele()<k)
                a.next();
            }
        }

        return false;
    }
};
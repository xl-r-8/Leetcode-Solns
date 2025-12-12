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

bool comparator(pair<int,int> a, pair<int, int> b){
    if(a.second != b.second) return a.second < b.second; //sort by cols
    else return a.first < b.first;//if a and have same cols then sort by value
    //coz we are using this comparator and sort in a vector v which are storing nodes of a particular row only, therefore for a and b they always have the same row num so when the col nums are also same then we will have the overlapping case on the same grid and we will sort by values in this case
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // the solution needs to be in vector of vector, but how do i store vector of vector when i dont even know all the levels, so what if i use map, but in the end i would have to convert it into vector of vector soln so in the end i would just pushback the val, but for that keys must be sorted so i should use map<int, vector<int>> mp; i have to write bfs coz in that only i would know if nodes are in the same grid or not, store the ans in vector<pair<int,int>> {{nodeval, lvl}}; sort by lvl and then by nodeval
        map<int, vector<int>> mp;
        // preorder(root, mp, 0);

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty()){

            int size=q.size();
            vector<pair<int,int>>v;
            for(int i=1; i<=size; i++){
                TreeNode* node=q.front().first;
                int col=q.front().second;
                q.pop();
                v.push_back({node->val, col});
                if(node->left!=nullptr) q.push({node->left, col-1});
                if(node->right!=nullptr) q.push({node->right, col+1});
            }
            sort(v.begin(), v.end(), comparator);
            for(pair<int, int> it: v){
                int col=it.second;
                int nodeval=it.first;
                mp[col].push_back(nodeval);
            }
        }
        vector<vector<int>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;


    }
};
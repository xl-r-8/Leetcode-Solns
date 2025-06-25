void pnotp(int i, vector<int>v, vector<vector<int>>& ans, vector<int> subseq){
    if(i>=v.size()){
        ans.push_back(subseq);
        return;
    } 
    //if you dont want to use pop_back then first not pick then pick
    //not pick
    pnotp(i+1,v,ans,subseq);
    //pick
    subseq.push_back(v[i]);
    pnotp(i+1,v,ans,subseq);
}

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        pnotp(0,nums,ans,{});
        return ans;
    }
};
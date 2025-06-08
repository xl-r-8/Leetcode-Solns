void rec(int i, int n, vector<int> & ans){
    if(i>n) return;
    ans.push_back(i);
    rec(i*10,n,ans);
    if(i+1>n or (i+1)%10==0)return;
    rec(i+1,n,ans);
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        rec(1,n,ans);
        return ans;
    }
};
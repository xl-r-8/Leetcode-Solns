int pnotp(int i, vector<int>&v, vector<int>&dp){
    if(i>=v.size()){//i>=n
        return 0;
    } 
    if(dp[i]>=0) return dp[i];
    //not pick
    int val1=pnotp(i+1,v,dp);
    //pick
    int val2=pnotp(i+2,v,dp)+v[i];
    dp[i]=max(val1,val2);
    return dp[i];
}

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return pnotp(0, nums,dp);
    }
};
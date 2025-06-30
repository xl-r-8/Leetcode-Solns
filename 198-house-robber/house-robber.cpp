//recursion but not correct approach for memoization

// int pnotp(int i, vector<int>&v, vector<int>&dp){
//     if(i>=v.size()){//i>=n
//         return 0;
//     } 
//     if(dp[i]>=0) return dp[i];
//     //not pick
//     int val1=pnotp(i+1,v,dp);
//     //pick
//     int val2=pnotp(i+2,v,dp)+v[i];
//     dp[i]=max(val1,val2);
//     return dp[i];
// }

class Solution {
public:
    int rob(vector<int>& nums) {
        //Memoization
        // vector<int> dp(nums.size(),-1);
        // return pnotp(0, nums,dp);


        //tabulation
        int n=nums.size();
        if(n<=1) return nums[0];
        // vector<int> dp(n,-1);
        // dp[n-1]=nums[n-1];
        // dp[n-2]=max(0+dp[n-1],nums[n-2]);
        // for(int i=n-3;i>=0;i--){
        //     dp[i]=max(0+dp[i+1],nums[i]+dp[i+2]);
        // }
        // return dp[0];

        //optimized tabulation
        int pop=nums[n-1];
        int p=max(0+pop,nums[n-2]);
        for(int i=n-3;i>=0;i--){
            int temp=max(0+p,nums[i]+pop);
            pop=p;
            p=temp;
        }
        return p;



    }
};
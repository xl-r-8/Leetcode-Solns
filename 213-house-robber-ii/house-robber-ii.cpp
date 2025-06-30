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
        //tabulation
        int n=nums.size();
        if(n==1) return nums[0];
        // vector<int> dp(n,-1);
        // dp[n-1]=nums[n-1];
        // dp[n-2]=max(0+dp[n-1],nums[n-2]);
        // for(int i=n-3;i>=0;i--){
        //     dp[i]=max(0+dp[i+1],nums[i]+dp[i+2]);
        // }
        // return dp[0];

        //optimized tabulation
        //case 1
        int pop1=nums[0];
        int p1=max(0+pop1,nums[1]);
        if(n==2) return p1;
        for(int i=2;i<n-1;i++){
            int temp=max(0+p1,nums[i]+pop1);
            pop1=p1;
            p1=temp;
        }

        int pop2=nums[1];
        int p2=max(0+pop2,nums[2]);
        for(int i=3;i<n;i++){
            int temp=max(0+p2,nums[i]+pop2);
            pop2=p2;
            p2=temp;
        }
        return max(p1,p2);
    }
};
class Solution {
public:
    //brute force
    /* int climbStairs(int n) {
        if(n<=2) return n;
        int ways=climbStairs(n-1)+climbStairs(n-2);
        return ways;
    } */
    //better approach
    /* int recfunc(int n,int dp[]){
        if(n<=2) return n;
        if(dp[n]!=0) return dp[n];
        int ways=climbStairs(n-1)+climbStairs(n-2);
        return dp[n]=ways;
    }
    int climbStairs(int n) {
        int dp[n+1];
        for(int i=0; i<=n; i++){
            dp[i]=0;
        }
        return recfunc (n,dp);
    } */

    //best approach without memory optimization
    int climbStairs(int n) {
        if(n<=2) return n;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3; i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    } 
};
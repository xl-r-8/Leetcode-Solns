int rec(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    int n=triangle.size();
    if(i>=n or j>i) return 0;
    vector<int> v=triangle[i];
    if(i==n-1) return v[j];
    if(dp[i][j]!=1e9)return dp[i][j];

    dp[i][j]=v[j] + min(rec(i+1,j,triangle,dp), rec(i+1,j+1,triangle,dp));

    return dp[i][j];

}

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        //Memoization
        //M1: dp of size (n)^2
        // vector<vector<int>> dp(n, vector<int> (n,1e9));
        //M2: dp of size(1+2+...+n = n(n+1)/2)
        vector<vector<int>> dp;
        for(int i=1; i<=n; i++){
            vector<int> v(i,1e9);
            dp.push_back(v);
        }
        return rec(0,0,triangle,dp);


        
        //Tabulation
        // vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        // for(int i=n-1; i>=0; i--){
        //     // vector<int> temp(n+1,0);
        //     vector<int> v=triangle[i];
        //     for(int j=0; j<v.size();j++){
        //         // temp[j]=v[j] + min(dp[j],dp[j+1]);
        //         dp[i][j]=v[j] + min(dp[i+1][j],dp[i+1][j+1]);
        //     }
        // }
        // return dp[0][0];
        //optimised
        // vector<int> dp(n+1,0);
        // for(int i=n-1; i>=0; i--){
        //     vector<int> temp(n+1,0);
        //     vector<int> v=triangle[i];
        //     for(int j=0; j<v.size();j++){
        //         temp[j]=v[j] + min(dp[j],dp[j+1]);
        //     }
        //     dp=temp;
        // }
        // return dp[0];
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();



        //Tabulation
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));
        for(int i=n-1; i>=0; i--){
            // vector<int> temp(n+1,0);
            vector<int> v=triangle[i];
            for(int j=0; j<v.size();j++){
                // temp[j]=v[j] + min(dp[j],dp[j+1]);
                dp[i][j]=v[j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
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
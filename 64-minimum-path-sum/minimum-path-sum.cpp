class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<long long> dp(n,LLONG_MAX);
        for(int i=m-1; i>=0; i--){
            vector<long long> temp(n,0);
            for(int j=n-1; j>=0; j--){
                if(i==m-1 and j==n-1){
                    temp[j]=grid[i][j];
                    continue;
                }
                long long right = (j+1<n)? temp[j+1] : LLONG_MAX;
                long long down= dp[j];
                temp[j] = grid[i][j] + min(right,down);
            }
            dp=temp;
        }
        return dp[0];
    }
};
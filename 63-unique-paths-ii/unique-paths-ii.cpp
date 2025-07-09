int rec(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
    int m=grid.size();
    int n=grid[0].size();
    if(i>=m or j>=n or grid[i][j]==1) return 0;
    if(i==m-1 and j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j]=rec(i,j+1,grid,dp) + rec(i+1,j,grid,dp);
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        // return rec(0,0,obstacleGrid,dp);

        //M2: Tabulation
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==m-1 and j==n-1){
                    dp[i][j]=1;
                    continue;
                }
                long long right = (j+1<n)? dp[i][j+1] : 0;
                long long down = (i+1<m)? dp[i+1][j] : 0;
                dp[i][j] = right + down;
            }
        }

        return dp[0][0];
    }
};
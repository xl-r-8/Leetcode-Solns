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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(0,0,obstacleGrid,dp);
    }
};
int dfs(int i, int j, vector<vector<int>>& matrix, int prev, vector<vector<int>>&dp) {
    int n = matrix.size(), m = matrix[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] <= prev ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int val=matrix[i][j];
    return dp[i][j]= 1 + max ({dfs(i+1, j, matrix,val,dp), dfs(i-1, j, matrix,val,dp), dfs(i, j+1, matrix,val,dp), dfs(i, j-1, matrix,val,dp)});
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int mx=1; vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                mx= max(mx, dfs(i,j,matrix,-1,dp));
            }
        }
        return mx;
    }
};
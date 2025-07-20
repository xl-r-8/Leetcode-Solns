int rec(int i, int j1, int j2, vector<vector<vector<int>>>&dp,vector<vector<int>>& grid){
    int m=grid.size(); int n=grid[0].size();
    if(i>=m or j1<0 or j1>=n or j2<0 or j2>=n) return -1; //if any bot is out of bounds then cant pick any cherries
    if(i==m-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    vector<int> ind={-1,0,1};
    for(int a: ind){
        for(int b:ind){
            int addition=0;
            if(j1==j2)addition=grid[i][j1];
            else addition=grid[i][j1]+grid[i][j2];
            dp[i][j1][j2]= max(dp[i][j1][j2], addition+rec(i+1, j1+a,j2+b,dp,grid));
        }
    }
    return dp[i][j1][j2];    
}

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(); int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n, vector<int>(n,-1)));
        return rec(0,0,n-1,dp,grid);
    }
};
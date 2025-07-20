int rec(int i, int j1, int j2, vector<vector<vector<int>>>&dp,vector<vector<int>>& grid){
    int m=grid.size(); int n=grid[0].size();
    if(i>=m or j1<0 or j1>=n or j2<0 or j2>=n) return -1; //if any bot is out of bounds then cant pick any cherries,, why return -1? why not 0, coz 0 can be returned by a valid path and then if an invalid path or a path that doesnt even exist returns 0 then how do we check the validity of a path? eg: in this condition :if(dp[i][j1][j2]!=-1) return dp[i][j1][j2]; if we replace -1 with 0 then all the valid paths which return 0 have to re calculated and re computed by recursion again and again coz you are just ignoring valid paths with 0 cherry pick ups. but we can ignore the ones where we pick up -1 cherries, coz that would always be invalid.

    if(i==m-1){
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    vector<int> ind={-1,0,1};
    int maxval=0;
    for(int a: ind){
        for(int b:ind){
            maxval=max(maxval,rec(i+1, j1+a,j2+b,dp,grid));
        }
    }
    int addition=0;
    if(j1==j2)addition=grid[i][j1];
    else addition=grid[i][j1]+grid[i][j2];
    dp[i][j1][j2]= addition + maxval;
    return dp[i][j1][j2];    
}

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(); int n=grid[0].size();

        //Memoization
        // vector<vector<vector<int>>>dp(m,vector<vector<int>>(n, vector<int>(n,-1)));
        // return rec(0,0,n-1,dp,grid);


        //tabulation
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=m-1; i>=0; i--){
            vector<vector<int>> temp(n, vector<int>(n,0));
            for(int j1=0; j1<n;j1++){
                for(int j2=0; j2<n;j2++){
                    int addition=0;
                    if(j1==j2)addition=grid[i][j1];
                    else addition=grid[i][j1]+grid[i][j2];

                    vector<int> ind={-1,0,1};
                    int maxval=0;
                    for(int a: ind){
                        int j1ind=j1+a;
                        if(j1ind<0 or j1ind>=n) continue;
                        for(int b:ind){
                            int j2ind=j2+b;
                            if( j2ind<0 or j2ind>=n) continue;
                            maxval=max(maxval,dp[j1ind][j2ind]);
                        }
                    }
                    temp[j1][j2]=addition+maxval;
                }
            }
            dp=temp;
        }

        return dp[0][n-1];
    }
};
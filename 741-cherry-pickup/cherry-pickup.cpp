class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // dp[i1][j1][i2] represents maximum cherries when:
        // Person 1 is at (i1, j1) and Person 2 is at (i2, j2)
        // where j2 = i1 + j1 - i2 (since both have taken same number of steps)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return max(0, dfs(0, 0, 0, grid, dp));
    }
    
private:
    int dfs(int i1, int j1, int i2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int j2 = i1 + j1 - i2; // Calculate j2 based on equal steps constraint
        
        // Check bounds and validity
        if (i1 >= n || j1 >= n || i2 >= n || j2 >= n || 
            grid[i1][j1] == -1 || grid[i2][j2] == -1) {
            return -1000000; // Invalid path
        }
        
        // Base case: both reached destination
        if (i1 == n-1 && j1 == n-1) {
            return grid[i1][j1];
        }
        
        // Memoization
        if (dp[i1][j1][i2] != -1) {
            return dp[i1][j1][i2];
        }
        
        // Calculate cherries at current positions
        int cherries = grid[i1][j1];
        if (i1 != i2 || j1 != j2) { // Different positions
            cherries += grid[i2][j2];
        }
        
        // Try all possible moves for both persons
        int maxFuture = -1000000;
        
        // Person 1 can go right or down, Person 2 can go right or down
        maxFuture = max(maxFuture, dfs(i1+1, j1, i2+1, grid, dp)); // Both down
        maxFuture = max(maxFuture, dfs(i1+1, j1, i2, grid, dp));   // P1 down, P2 right
        maxFuture = max(maxFuture, dfs(i1, j1+1, i2+1, grid, dp)); // P1 right, P2 down
        maxFuture = max(maxFuture, dfs(i1, j1+1, i2, grid, dp));   // Both right
        
        // If no valid future path exists
        if (maxFuture < 0) {
            return dp[i1][j1][i2] = -1000000;
        }
        
        return dp[i1][j1][i2] = cherries + maxFuture;
    }
};

/*
Alternative bottom-up DP approach (more efficient):
*/
class SolutionBottomUp {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // dp[i1][j1][i2] where j2 = i1 + j1 - i2
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        
        // Base case
        dp[n-1][n-1][n-1] = grid[n-1][n-1];
        
        // Fill DP table backwards
        for (int i1 = n-1; i1 >= 0; i1--) {
            for (int j1 = n-1; j1 >= 0; j1--) {
                for (int i2 = n-1; i2 >= 0; i2--) {
                    int j2 = i1 + j1 - i2;
                    
                    // Check validity
                    if (j2 < 0 || j2 >= n || grid[i1][j1] == -1 || grid[i2][j2] == -1) {
                        continue;
                    }
                    
                    // Skip if already computed (base case)
                    if (i1 == n-1 && j1 == n-1) {
                        continue;
                    }
                    
                    // Calculate cherries
                    int cherries = grid[i1][j1];
                    if (i1 != i2 || j1 != j2) {
                        cherries += grid[i2][j2];
                    }
                    
                    // Try all moves
                    int maxNext = -1;
                    
                    // Both go down
                    if (i1+1 < n && i2+1 < n) {
                        maxNext = max(maxNext, dp[i1+1][j1][i2+1]);
                    }
                    
                    // P1 down, P2 right
                    if (i1+1 < n && j2+1 < n) {
                        maxNext = max(maxNext, dp[i1+1][j1][i2]);
                    }
                    
                    // P1 right, P2 down
                    if (j1+1 < n && i2+1 < n) {
                        maxNext = max(maxNext, dp[i1][j1+1][i2+1]);
                    }
                    
                    // Both go right
                    if (j1+1 < n && j2+1 < n) {
                        maxNext = max(maxNext, dp[i1][j1+1][i2]);
                    }
                    
                    if (maxNext >= 0) {
                        dp[i1][j1][i2] = cherries + maxNext;
                    }
                }
            }
        }
        
        return max(0, dp[0][0][0]);
    }
};

/*
Example walkthrough for grid = [[1,1,-1],[1,-1,1],[-1,1,1]]:

Initial state: Both persons at (0,0)
- Person 1: (0,0), Person 2: (0,0) - collect 1 cherry

Step 1: Person 1 goes down to (1,0), Person 2 goes right to (0,1)
- Person 1: (1,0) = 1, Person 2: (0,1) = 1 - collect 2 cherries

Step 2: Person 1 goes right to (1,1), Person 2 goes down to (1,1)  
- Both at (1,1) = -1 (blocked) - invalid path

This explores all possible combinations and finds the optimal solution.
*/
void dfsrec(vector<vector<int>>& grid, vector<vector<bool>>& check, int i, int j, bool &boundary, int &count) {
    int m = grid.size();
    int n = grid[0].size();
    
    if (i < 0 || j < 0 || i >= m || j >= n || check[i][j] || grid[i][j] == 0) return;

    count++;
    check[i][j] = true;

    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) boundary = true;

    dfsrec(grid, check, i, j - 1, boundary, count); // left
    dfsrec(grid, check, i, j + 1, boundary, count); // right
    dfsrec(grid, check, i - 1, j, boundary, count); // up
    dfsrec(grid, check, i + 1, j, boundary, count); // down
    //dfsrec(grid,check,i-1,j-1,boundary,count);//up left
    //dfsrec(grid,check,i-1,j+1,boundary,count);//up right
    //dfsrec(grid,check,i+1,j-1,boundary,count);//down left
    //dfsrec(grid,check,i+1,j+1,boundary,count);//down right

}

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> check(m, vector<bool>(n, false));
        int totalc = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!check[i][j]) {
                    int count = 0;
                    bool boundary = false;

                    if (grid[i][j] == 0) {
                        check[i][j] = true;
                    } else {
                        dfsrec(grid, check, i, j, boundary, count);
                        if (!boundary) totalc += count;
                    }
                }
            }
        }
        return totalc;
    }
};

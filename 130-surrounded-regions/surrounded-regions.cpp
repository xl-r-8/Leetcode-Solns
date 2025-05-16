void dfsrec(vector<vector<char>>& grid, vector<vector<bool>>& check, int i, int j, bool &boundary) {
    int m = grid.size();
    int n = grid[0].size();
    
    if (i < 0 || j < 0 || i >= m || j >= n || check[i][j] || grid[i][j] == 'X') return;

    check[i][j] = true;
    

    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) boundary = true;

    dfsrec(grid, check, i, j - 1, boundary); // left
    dfsrec(grid, check, i, j + 1, boundary); // right
    dfsrec(grid, check, i - 1, j, boundary); // up
    dfsrec(grid, check, i + 1, j, boundary); // down

}


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> check(m, vector<bool>(n, false));

        //running on the boundaries
        for (int i = 0; i < m; i++) {
            if(i==0 or i==m-1){
                for (int j = 0; j < n; j++) {
                    if (!check[i][j]) {
                        bool boundary = false;

                        if (board[i][j] == 'X') {
                            check[i][j] = true;
                        } else {
                            dfsrec(board, check, i, j, boundary);
                        }
                    }
                }
            }
            else{
                vector<int> jboundary={0,n-1};
                for(int j:jboundary){
                    if (!check[i][j]) {
                        int count = 0;
                        bool boundary = false;

                        if (board[i][j] == 'X') {
                            check[i][j] = true;
                        } else {
                            dfsrec(board, check, i, j, boundary);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if(i==0 or i==m-1) continue;
            for (int j = 0; j < n; j++) {
                if(j==0 or j==n-1)continue;
                if (!check[i][j] and board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }
    }
};
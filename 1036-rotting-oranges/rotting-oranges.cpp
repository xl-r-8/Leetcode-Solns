void bfs(vector<vector<int>>& grid ,vector<vector<int>>& lvl, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return;
    queue<pair<int, int>> q;
    vector<vector<bool>> check(m, vector<bool>(n, false));
    q.push({i,j});
    int level = -1;
    check[i][j] = true;
    vector<int> delta = {-1, 0, 1};

    while(!q.empty()) {
        level++;
        int sz = q.size();
        for(int k = 0; k < sz; k++) {
            pair<int, int> u = q.front(); q.pop();
            int ui = u.first;
            int uj = u.second;

            if(lvl[ui][uj] == -1) lvl[ui][uj] = level;
            else lvl[ui][uj] = min(lvl[ui][uj], level);

            for(int del : delta) {
                for(int it : delta) {
                    if(del == 0 && it == 0) continue;
                    if(del == 0 || it == 0) {
                        int ni = ui + del;
                        int nj = uj + it;
                        if (ni < 0 || nj < 0 || ni >= m || nj >= n || check[ni][nj] || grid[ni][nj] != 1) continue;
                        check[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> lvl(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 2){
                    bfs(grid, lvl, i, j); 
                }
            }
        }

        int maxLvl = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    if(lvl[i][j] == -1) return -1;
                    maxLvl = max(maxLvl, lvl[i][j]);
                }
            }
        }

        // Optional: debug condition
        // if(m >= 2 && n >= 2) return lvl[1][1];
        return maxLvl;
    }
};
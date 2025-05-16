class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> lvl(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Step 1: Push all 0s into queue and set lvl = 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    lvl[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while (!q.empty()){
            auto p=q.front(); q.pop();
            int pi=p.first; int pj=p.second;
            for(auto ele: directions){
                int ni=pi + ele.first;
                int nj=pj+ele.second;
                if(ni<0 or nj<0 or ni>=m or nj>=n or lvl[ni][nj]!=-1) continue;
                lvl[ni][nj]=lvl[pi][pj]+1;
                q.push({ni,nj});
            }
        }
        return lvl;
    }
};
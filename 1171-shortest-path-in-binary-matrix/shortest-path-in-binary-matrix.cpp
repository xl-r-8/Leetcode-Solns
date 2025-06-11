class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 or grid[n-1][n-1]!=0) return -1;
        //Coz all the weights are equal and graph is undirected => bfs can be used

        queue<vector<int>> q;
        vector<vector<int>> dist(n, vector<int>(n,-1));
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        q.push({0,0,1});
        visited[0][0] = true;
        dist[0][0]=1;

        vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        while(!q.empty()){
            vector<int> v = q.front(); q.pop();
            int i=v[0];
            int j=v[1];
            int distance=v[2];
            for(vector<int> temp : dirns){
                int xi=i+temp[0];
                int yj=j+temp[1];
                if(xi<0 or xi>=n or yj<0 or yj>=n or visited[xi][yj] or grid[xi][yj]==1)continue;
                visited[xi][yj] = true;
                dist[xi][yj]=distance+1;
                if(xi==n-1 and yj==n-1) return dist[xi][yj];
                q.push({xi,yj,distance+1});
                
            }
        }
        return dist[n-1][n-1];
    }
};
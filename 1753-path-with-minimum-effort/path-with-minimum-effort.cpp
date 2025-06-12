class Solution {
    struct Compare {
        bool operator()(vector<int> a, vector<int> b) {
            return a[2] > b[2]; // smaller cost comes first
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<vector<int>> cost(m, vector<int>(n,-1));//cost will store min cost of any path required to reach the node
        vector<vector<pair<int,int>>> parent(m, vector<pair<int,int>>(n,{-1,-1}));
        pq.push({0,0,0}); //{i,j, max cost of path}, max cost of path=max possible diff b/w 2 consecutive nodes present in that path and i,j represents node
        
        cost[0][0]=0;

        vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            vector<int> v = pq.top(); pq.pop();
            int i=v[0];
            int j=v[1];
            int cost_node=v[2];
            for(vector<int> temp : dirns){
                int xi=i+temp[0];
                int yj=j+temp[1];
                if(xi<0 or xi>=m or yj<0 or yj>=n)continue;
                int cost_neighbor=max(cost_node, abs(heights[xi][yj]-heights[i][j]));
                if(cost[xi][yj]==-1 or cost_neighbor<cost[xi][yj]){
                    cost[xi][yj]=cost_neighbor;
                    parent[xi][yj]={i,j};
                    pq.push({xi,yj,cost[xi][yj]});
                }                
            }
        }
        return cost[m-1][n-1];
    }
};
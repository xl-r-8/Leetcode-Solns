class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(vector<int> edge: roads){
            int u = edge[0]; int v = edge[1]; int dist= edge[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        vector<bool> visited(n+1, false);
        //min heap
        //its not a ques of dijkstra
        // its about connected components

        //we just have to check in which component the nth node lies 
        //and have to find the min edge cost in that component
        queue<int> q;
        q.push(n);
        visited[n] = true;
        int mndist=1e4;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(pair<int, int> p: adj[node]){
                int neighbor = p.first;
                int dist = p.second;
                if(dist<mndist) mndist= dist;
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
        return mndist;
    }   
};
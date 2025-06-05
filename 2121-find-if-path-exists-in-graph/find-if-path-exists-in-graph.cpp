class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        for(vector<int> ele: edges){
            int u=ele[0];
            int v=ele[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        q.push(source);
        vector<bool>visited(n,false);
        visited[source] = true;

        while(!q.empty()){
            int node = q.front(); q.pop();
            // process node here
            if(node==destination) return true;
            for(int neighbor : graph[node]){
                if(neighbor==destination) return true;
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};
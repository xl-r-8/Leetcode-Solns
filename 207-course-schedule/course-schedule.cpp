class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>> edges=prerequisites;
        vector<vector<int>> adjl(V);
        vector<int> indegree(V, 0);
        for (auto &edge : edges) {
            int u = edge[1];
            int v = edge[0];
            indegree[v]++;
            adjl[u].push_back(v);
            // For undirected graph, also do:
            // adjl[v].push_back(u);
        }
        //==============================dfs============================
        // vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
        // for (auto &edge : edges) {
        //     int u = edge[0];
        //     int v = edge[1];
        //     adjMatrix[u][v] = 1;
        //     // For undirected graph, also do:
        //     // adjMatrix[v][u] = 1;
        // }
        // vector<bool> vis(V,false);
        // vector<bool> pathvis(V,false);
        // for(int i=0; i<V;i++){
        //     if(!vis[i]){
        //         if(dfs(i,adjl,vis,pathvis)) return true;  
        //     }
        // }
        // return false;
        
        //==========================kahns==========================
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            } 
        }
        int count=0;
        while(!q.empty()){
            int ele=q.front(); q.pop();
            //vis[ele]=true;
            count++;
            for(int neighbor: adjl[ele]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
        if(count<V)return false; //cycle=> cant finish tasks
        return true;//no cycle=> can finish the tasks
    }
};
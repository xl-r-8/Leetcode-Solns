class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<vector<int>> edges=prerequisites;
        vector<vector<int>> adjl(V);
        vector<int> indegree(V,0);
        for(vector<int> temp: edges){
            int u=temp[1];
            int v=temp[0];
            indegree[v]++;
            adjl[u].push_back(v);
        }
        //===========================dfs===========================
        //TC: same as dfs
        //SC: O(2N) or O(3N) if we count the ans array too or O(4N) if we count recursive stack space too. both will be simplified to O(N)
        // vector<bool> visited(V, false);
        // vector<int> storage;
        //or we can use stack
        // stack<int>s;
        
        
        // for(int i=0; i<V;i++){
        //     if(!visited[i]){
        //         dfs(i, adjl, visited, storage);
        //     }
        // }
        // vector<int> ans;
        // for(int i=storage.size()-1; i>=0; i--){
        //     ans.push_back(storage[i]);
        // }
        // return ans;
        
        //=============================kahn==========================
        //TC: same as bfs, coz we are traversing every node and then checking their neighbors
        //SC: O(2N) q and ans
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int ele=q.front(); q.pop();
            ans.push_back(ele);
            for(int neighbor: adjl[ele]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
        if(ans.size()<V)return {};
        return ans;
    }
};
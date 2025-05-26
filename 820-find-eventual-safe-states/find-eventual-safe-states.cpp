bool dfs(int node, vector<vector<int>>&adjl, vector<bool>&vis, vector<bool>& pathvis, vector<int>&safe){
    vis[node]=true;
    pathvis[node]=true;
    if(adjl[node].empty()) safe[node]=1;
    bool EveryNeighborSafe=true;
    for(int neighbor: adjl[node]){
        if(!vis[neighbor]){
            if (dfs(neighbor, adjl, vis, pathvis,safe)) {//cycle detected 
                // if(safe[neighbor]==0) safe[node]=0;//if neighbor is unsafe then so is the node
                EveryNeighborSafe=false;// return true;//cycle detected so return true
                // break;//don't break, we have to run dfs for other neighbors too
            }
        }
        if(pathvis[neighbor]){//cycle detected 
            // for(int i=0; i<pathvis.size();i++){//maybe for loop is not needed coz recrsion se baaki nodes bhi mark ho jayenge
            //     if(pathvis[i]) safe[i]=0;//every node in the cycle path is marked as unsafe
            // } 
            EveryNeighborSafe=false;// return true;//cycle detected so return true
            // break;//don't break, we have to run dfs for other neighbors too
        }

        //if neighbor is already visited, is unsafe, but different componenet mein hai then yeh dono hee ifs kaam nahi karenge and hence we have to use one more condition
        if(safe[neighbor]==0)EveryNeighborSafe=false;
    }
    pathvis[node]=false;
    if(EveryNeighborSafe){
        safe[node]=1;
        return false;//every neighbor is safe=> no cycle
    } 
    else{
        safe[node]=0;
        return true;//a neighbor is unsafe=> cycle
    }
    
}

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //=================================dfs==========================================
        // int n=graph.size();
        // vector<bool> vis(n,false); // can we replace vis, coz safe=-1 can be used to store not visited???
        // vector<int> safe(n,-1);
        // vector<bool> pathvis(n, false);
        // for(int i=0; i<n; i++){
        //     if(!vis[i]){
        //         dfs(i,graph,vis,pathvis,safe); 
        //     }
        // }
        // vector<int> ans;
        // for(int i=0; i<n; i++){
        //     if(safe[i]==1) ans.push_back(i);
        // }
        // return ans;

        //==================================bfs==================================

        // int n=graph.size();
        // queue<int> q;
        // vector<int> ans;
        // vector<int> outdegree(n,0);

        // for(int i=0; i<n; i++){
        //     outdegree[i]=graph[i].size();
        // }

        // for(int i=0; i<n; i++){
        //     if(outdegree[i]==0) q.push(i);
        // }
        
        // //TC: of while loop: O(V), coz V vertices will go into q at max
        // // and for every vertex, V^2 for loop will run: Total TC: O(V^3)
        // while(!q.empty()){
        //     int node=q.front(); q.pop();
        //     ans.push_back(node);
        //     //TC of for loops: O(V^2)
        //     for(int i=0; i<n;i++){
        //         for(int temp: graph[i]){//coz of this for loop TC has increases
        //             if(temp==node){
        //                 outdegree[i]--;
        //                 if(outdegree[i]==0) q.push(i);
        //                 break;
        //             } 
        //         }
        //     }
        // }
        // sort(ans.begin(), ans.end());
        // return ans;

        int n=graph.size();
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(n,0);//according to revgraph
        vector<vector<int>> revgraph(n);

        for(int u=0; u<n; u++){
            for (int v: graph[u]){//in graph, edge: u->v
                revgraph[v].push_back(u);//in graph, edge: v->u
                indegree[u]++;
            }
        }

        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int ele=q.front(); q.pop();
            ans.push_back(ele);
            for(int neighbor: revgraph[ele]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
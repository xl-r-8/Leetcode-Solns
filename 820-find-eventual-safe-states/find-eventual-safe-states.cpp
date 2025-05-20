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
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<int> safe(n,-1);
        vector<bool> pathvis(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,safe); 
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(safe[i]==1) ans.push_back(i);
        }
        return ans;
    }
};
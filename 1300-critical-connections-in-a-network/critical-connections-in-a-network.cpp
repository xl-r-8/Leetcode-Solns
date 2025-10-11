void dfs(int n, vector<vector<int>> &adjl, int par, int node, vector<int> &lvl, vector<int> &minlvl, vector<vector<int>> &ans){
    //initialize node
    if(par==-1){
        lvl[node]=0;
        minlvl[node]=lvl[node];
    }
    else{
        lvl[node]=lvl[par]+1;
        minlvl[node]=lvl[node];
    }

    //process node
    for(int neighbor: adjl[node]){ //adjl[0] = {1,2}, list of neighbors of 0
        if(neighbor == par) continue;
        if(lvl[neighbor]==-1){ //neighbor is unvisited and is child of q
            dfs(n, adjl, node, neighbor, lvl, minlvl, ans);
        }
        else{//cycle node towards a descendant or an ancestor
            if(minlvl[neighbor]<minlvl[node]) minlvl[node] = minlvl[neighbor];
        }
    }

    if(par==-1) return;
    if(minlvl[node] > lvl[par]) ans.push_back({par,node});
    else{
        if(minlvl[node]<minlvl[par]) minlvl[par]=minlvl[node];
    }

}

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //0 indexed connected graph is given
        vector<vector<int>> adjl(n);
        for(vector<int> e: connections){
            int u=e[0], v=e[1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }

        vector<int> lvl(n, -1); //all nodes initialised as unvisited
        vector<int> minlvl(n, n); 
        vector<vector<int>> ans;

        dfs(n, adjl, -1, 0, lvl, minlvl, ans);
        return ans;
    }
};
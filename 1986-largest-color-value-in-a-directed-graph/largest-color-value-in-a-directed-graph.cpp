bool dfs(int node, vector<vector<int>>& adjl, vector<bool>& vis, vector<bool>& pathvis, vector<vector<int>>& dp, string& colors){
    vis[node] = true;
    //hello
    pathvis[node]=true;
    // if(adjl[node].empty()){//base case -> terminal node
    //     int cnode=colors[node]-'a';
    //     dp[node][cnode]=1;
    // }

    int cnode=colors[node]-'a'; //base case -> terminal node
    dp[node][cnode]=1;

    for(int neighbor : adjl[node]){
        if(!vis[neighbor]){
            if (dfs(neighbor, adjl, vis, pathvis, dp, colors)) return true;
        }
        if(pathvis[neighbor]) return true;
        for(int i=0; i<26; i++){
            //int cnode=colors[node]-'a';//color of node
            if(i==cnode) dp[node][i]=max(dp[neighbor][i]+1, dp[node][i]);//here is the mistake, it will compare with the initial value of dp[node][i]=0 which wont cause any error, but still needs to be correctded
            else dp[node][i]=max(dp[neighbor][i], dp[node][i]);
        }
    }
    pathvis[node]=false;
    return false;
}

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int V=colors.size();
        vector<vector<int>> adjl(V);
        for(vector<int> temp: edges){
            int u=temp[0];
            int v=temp[1];
            adjl[u].push_back(v);
        }
        vector<bool> vis(V, false);
        vector<bool> pathvis(V,false);
        vector<vector<int>> dp(V, vector<int>(26,0));
        
        
        for(int i=0; i<V;i++){
            if(!vis[i]){
                if(dfs(i, adjl, vis, pathvis, dp, colors)) return -1;
            }
        }

        int maxval=0;
        for(int i=0; i<V;i++){
            for(int j=0; j<26;j++){
                maxval=max(maxval,dp[i][j]);
            }
        }
        return maxval;
    }
};
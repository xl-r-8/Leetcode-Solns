void DFS(vector<vector<int>>& adjM, int node,vector<bool>& visited) {
    // visited[node]=true;
    for(int i=0; i<adjM.size();i++){
        if(adjM[node][i]!=0 and !visited[i]){
            visited[i]=true;
            DFS(adjM,i,visited);
        }
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0; i<n;i++){
            if(!visited[i]){
                visited[i]=true;
                DFS(isConnected,i,visited);
                ans++;
            }
        }
        return ans;
    }
};
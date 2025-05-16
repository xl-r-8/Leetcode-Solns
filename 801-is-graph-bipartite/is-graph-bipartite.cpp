bool bfs(vector<vector<int>>& graph,vector<int>& color,int start){
    queue<pair<int,int>> q;
    q.push({start,0});
    color[start]=0;

    while(!q.empty()){
        auto p=q.front(); q.pop();
        int ele=p.first;
        int elec=p.second;
        for(int neighbor:graph[ele]){
            if(color[neighbor]==color[ele]) return false;
            if(color[neighbor]==-1){
                color[neighbor]=(elec+1)%2; //alternate b/w 0 and 1
                q.push({neighbor,color[neighbor]});
            }
        }
    }
    return true;
}

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, -1);
        
        for(int i=0; i<n;i++){
            if(color[i]==-1){
                if(bfs(graph,color,i)==false)return false;
            }
        }
        return true;
    }
};
bool bfs(vector<vector<int>>& graph,vector<int>& color,int start){
    queue<pair<int,int>> q;
    q.push({start,0});
    color[start]=0;//the function will only be used again for next disconnected component and for the next one previous ki coloring kis se start ki thi farak nahi padta, so for diff components we can start coloring them with 0s

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

bool dfs(vector<vector<int>>& graph,vector<int>& color,int current, int parent){
    // if(color[current]!=-1){//this wont work coz we are pushing those elements only jinka color=-1 hai
    //     //if already colored then this is 2nd parent so..
    //     int secondColor=(color[parent]+1)%2;//secondColor of parent
    //     if(secondColor!=color[current]) return false; //second color is not same as the first one
    // }
    if(parent==-1)color[current]=0;
    else color[current]=(color[parent]+1)%2;
    for(int neighbor:graph[current]){
        if(neighbor==parent) continue;
        if(color[neighbor]==color[current]) return false;
        if(color[neighbor]==-1){
            if(dfs(graph,color,neighbor,current)==false) return false;
        }
    }
    return true;
    
}
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n, -1);
        
        // for(int i=0; i<n;i++){
        //     if(color[i]==-1){
        //         if(bfs(graph,color,i)==false)return false;
        //     }
        // }
        for(int i=0; i<n;i++){
            if(color[i]==-1){
                if(dfs(graph,color,i,-1)==false)return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //basically it is like level wise bfs traversal, and you would repeat nodes unlike bfs but number of stops can only be at max k, so as soon as stops excede k at a node say n then dont process that node 
        vector<vector<pair<int,int>>> adjl(n);
        for (auto &edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int wt=edge[2];
            adjl[u].push_back({v,wt});
        }

        //it will store [node, cost]
        queue<vector<int>> q;
        q.push({src,0,0}); //{node, stops, cost}
        //it will store minimum cost to reach each node
        vector<int> minCost(n, -1);
        minCost[src] = 0;
        
        while(!q.empty()){
            vector<int> ele=q.front();q.pop();
            int u=ele[0];
            int stop_u=ele[1];
            int cost_u=ele[2];
            if(u==dst){
                if(minCost[u]==-1 or cost_u<minCost[u]){
                    minCost[u]=cost_u;
                }
                continue; //still look for better paths with k or less stops
            } 
            if(stop_u==k+1) continue;
            for(pair<int,int> p:adjl[u]){
                int v=p.first;
                int wt=p.second;
                int cost_v=cost_u+wt;
                int stop_v=stop_u+1;
                if(minCost[v]==-1 or cost_v<minCost[v]){
                    minCost[v]=cost_v;
                    q.push({v, stop_v, cost_v});
                }
            }    
        }
        return minCost[dst];
    }
};
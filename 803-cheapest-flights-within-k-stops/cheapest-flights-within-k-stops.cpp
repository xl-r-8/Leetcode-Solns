class Solution {
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2]; // min-heap by cost
        }
    };

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

        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        pq.push({src, 0, 0});  // {node, stops, cost}
        // visited[node][stops] = min cost to reach
        vector<vector<int>> cost(n, vector<int>(k + 2, -1));
        cost[src][0] = 0;
        
        while(!pq.empty()){
            vector<int> ele=pq.top();pq.pop();
            int u=ele[0];
            int stop_u=ele[1];
            int cost_u=ele[2];
            if(u==dst){//u==dst condition is used coz if you are at node u(using k or less than k stops) then you would definitely not want to add extra outgoing edges to this path coz that would just increase the distance to destination
                if(cost[u][stop_u]==-1 or cost_u<cost[u][stop_u]){
                    cost[u][stop_u]=cost_u;
                }
                continue; //still look for better paths with k or less stops
            } 
            if(stop_u==k+1) continue;
            for(pair<int,int> p:adjl[u]){
                int v=p.first;
                int wt=p.second;
                int cost_v=cost_u+wt;
                int stop_v=stop_u+1;
                if(cost[v][stop_v]==-1 or cost_v<cost[v][stop_v]){
                    cost[v][stop_v]=cost_v;
                    pq.push({v, stop_v, cost_v});
                }
            }    
        }
        int dltks=-1;
        for(int i=0; i<=k+1;i++){
            int distance=cost[dst][i]; //min distance of u through i stops
            if(distance!=-1){
                if(dltks==-1 or distance<dltks) dltks=distance;
            }
        }
        return dltks;
    }
};
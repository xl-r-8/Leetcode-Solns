class Solution {
public:
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {

        int mod = 1e9+7;
        vector<vector<pair<ll, ll>>> adj(n);


        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<ll>dist(n,1e18);
        vector<ll>ways(n,0);

        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            ll node=pq.top().second;
            ll currdist=pq.top().first;
            pq.pop();

            for(auto it:adj[node]){
                ll d=it.second;
                ll adjNode=it.first;

                if(currdist+d<dist[adjNode]){
                    dist[adjNode]=currdist+d;
                    ways[adjNode]=ways[node];
                    pq.push({currdist+d,adjNode});
                    
                }else if(currdist+d==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
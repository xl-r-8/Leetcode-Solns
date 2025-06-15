#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll MOD=1000000007;
        vector<vector<pair<ll,ll>>> adjl(n);
        for (auto &edge : roads) {
            ll u = edge[0];
            ll v = edge[1];
            ll wt=edge[2];
            adjl[u].push_back({v,wt});
            adjl[v].push_back({u,wt});
        }

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vector<ll> dist(n,-1);
        vector<ll> paths(n, 0);
        pq.push({0,0});
        dist[0]=0;
        paths[0]=1;

        while(!pq.empty()){
            // vector<ll> ele=pq.top(); 
            ll u=pq.top().second;
            ll dist_u=pq.top().first;
            pq.pop();
            // cout<<"Node: "<<endl;
            // cout<<u<<" "<<paths_u<<" "<<dist[u]<<endl;
            // cout<<"Neighbors: "<<endl;
            for(pair<ll,ll> p: adjl[u]){
                ll v=p.first;
                ll wt=p.second;
                ll dist_v=(dist_u+wt);
                if(dist[v]==-1 or dist_v<dist[v]){
                    dist[v]=dist_v;
                    paths[v]=paths[u]%MOD;
                    // cout<<v<<" "<<paths[v]<<" "<<dist_v<<endl;
                    pq.push({dist_v,v});
                }
                else if(dist_v==dist[v]){
                    paths[v]=(paths[v]+paths[u])%MOD;
                    // cout<<v<<" "<<paths[v]<<" "<<dist_v<<endl;
                }
            }
        }
        return paths[n-1]%MOD;
    }
};

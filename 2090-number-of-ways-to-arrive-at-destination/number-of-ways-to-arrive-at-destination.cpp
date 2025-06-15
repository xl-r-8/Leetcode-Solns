#define ll long long
class Solution {
    struct Compare {
        bool operator()(vector<ll> &a, vector<ll> &b) {
            return a[1] > b[1]; // smaller dist comes first
        }
    };
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

        priority_queue<vector<ll>, vector<vector<ll>>, Compare> pq;
        vector<ll> dist(n,-1);
        vector<ll> paths(n, 0);
        pq.push({0,0});
        dist[0]=0;
        paths[0]=1;

        while(!pq.empty()){
            vector<ll> ele=pq.top(); pq.pop();
            ll u=ele[0];
            ll dist_u=ele[1];
            
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
                    pq.push({v,dist_v});
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

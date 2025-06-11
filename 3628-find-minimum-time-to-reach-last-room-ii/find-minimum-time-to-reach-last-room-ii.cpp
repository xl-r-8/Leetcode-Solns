class Solution {
public:
    struct Compare {
        bool operator()(vector<int> a, vector<int> b) {
            return a[2] > b[2]; // smaller totalCost comes first
        }
    };
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        int n=moveTime.size();
        int m=moveTime[0].size();
        pq.push({0,0,0});//{i,j,totalCost}
        vector<vector<int>> cost(n, vector<int>(m, -1));
        cost[0][0]=0;

        vector<vector<int>> dirns={{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            vector<int> ele=pq.top();
            pq.pop();
            int i=ele[0], j=ele[1], eleC=ele[2];
            if(i==n-1 and j==m-1) return cost[n-1][m-1];
            for(vector<int> temp : dirns){
                int xi=i+temp[0];
                int yj=j+temp[1];
                if(xi<0 or xi>=n or yj<0 or yj>=m)continue;
                int cst=0;
                int addition=((xi+yj)%2==1) ? 1:2;;
                if(eleC>=moveTime[xi][yj]){
                    cst=eleC+addition;
                }
                else cst= moveTime[xi][yj]+addition;

                if(cst<cost[xi][yj] or cost[xi][yj]==-1){
                    cost[xi][yj]=cst;
                    if(xi==n-1 and yj==m-1) return cost[n-1][m-1];
                    pq.push({xi,yj,cst});
                }
                
            }

        }
        return cost[n-1][m-1];
    }
};
class Solution {
public:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        }
    };

    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        int n=moveTime.size();
        int m=moveTime[0].size();
        pq.push({0,0,0});//{i,j,totalCost}
        vector<vector<int>> cost(n, vector<int>(m, -1));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        cost[0][0]=0;
        while(!pq.empty()){
            vector<int> ele=pq.top();
            pq.pop();
            int i=ele[0], j=ele[1], eleC=ele[2];
            // if(eleC<cost[i][j] or cost[i][j]==-1) cost[i][j]=eleC;
            if(visited[i][j]) continue;
            if(i==n-1 and j==m-1) break;
            visited[i][j]=true;
            if(i-1>=0 ){//up
                int cst=0;
                int addition=((i+j-1)%2==1) ? 1:2;
                if(eleC>=moveTime[i-1][j]){
                    cst=eleC+addition;
                }
                else cst= moveTime[i-1][j]+addition;
                if(cst<cost[i-1][j] or cost[i-1][j]==-1){
                    cost[i-1][j]=cst;
                    pq.push({i-1,j,cst});
                }
                // visited[i-1][j]=true;
            }
            if(i+1<n  ){//down
                int cst=0;
                int addition=((i+j+1)%2==1) ? 1:2; 
                if(eleC>=moveTime[i+1][j]){
                    cst=eleC+addition;
                }
                else cst= moveTime[i+1][j]+addition;
                if(cst<cost[i+1][j] or cost[i+1][j]==-1){
                    cost[i+1][j]=cst;
                    pq.push({i+1,j,cst});
                }
                // visited[i+1][j]=true;
            }
            if(j-1>=0 ){//left
                int cst=0;
                int addition=((i+j-1)%2==1) ? 1:2;
                if(eleC>=moveTime[i][j-1]){
                    cst=eleC+addition;
                }
                else cst= moveTime[i][j-1]+addition;
                if(cst<cost[i][j-1] or cost[i][j-1]==-1){
                    cost[i][j-1]=cst;
                    pq.push({i,j-1,cst});
                }
                // visited[i][j-1]=true;
            }
            if(j+1<m ){//right
                int cst=0;
                int addition=((i+j+1)%2==1) ? 1:2;
                if(eleC>=moveTime[i][j+1]){
                    cst=eleC+addition;
                }
                else cst= moveTime[i][j+1]+addition;
                if(cst<cost[i][j+1] or cost[i][j+1]==-1){
                    cost[i][j+1]=cst;
                    pq.push({i,j+1,cst});
                }
                // visited[i][j+1]=true;
            }

        }
        return cost[n-1][m-1];
    }
};
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
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        cost[0][0]=0;
        visited[0][0]=true;
        while(!pq.empty()){
            vector<int> ele=pq.top();
            pq.pop();
            int i=ele[0], j=ele[1], eleC=ele[2];
            if(eleC<cost[i][j] or cost[i][j]==-1) cost[i][j]=eleC;
            if(i==n-1 and j==m-1) break;
            if(i-1>=0 and visited[i-1][j]==false){//up
                int cst=0;
                if(eleC>=moveTime[i-1][j]){
                    cst=eleC+1;
                }
                else cst= moveTime[i-1][j]+1;
                pq.push({i-1,j,cst});
                visited[i-1][j]=true;
            }
            if(i+1<n and visited[i+1][j]==false){//down
                int cst=0;
                if(eleC>=moveTime[i+1][j]){
                    cst=eleC+1;
                }
                else cst= moveTime[i+1][j]+1;
                pq.push({i+1,j,cst});
                visited[i+1][j]=true;
            }
            if(j-1>=0 and visited[i][j-1]==false){//left
                int cst=0;
                if(eleC>=moveTime[i][j-1]){
                    cst=eleC+1;
                }
                else cst= moveTime[i][j-1]+1;
                pq.push({i,j-1,cst});
                visited[i][j-1]=true;
            }
            if(j+1<m and visited[i][j+1]==false){//right
                int cst=0;
                if(eleC>=moveTime[i][j+1]){
                    cst=eleC+1;
                }
                else cst= moveTime[i][j+1]+1;
                pq.push({i,j+1,cst});
                visited[i][j+1]=true;
            }

        }
        return cost[n-1][m-1];
    }
};
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //M1: brute force
        // map<pair<int,int>, bool> mp;
        map<int,bool> row;
        map<int,bool> column;
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=true;
                    column[j]=true;
                }
            }
        }
        for (auto entry : row) {
            int rownum=entry.first;
            bool rowval=entry.second;
            if(rowval){
                for(int j=0; j<n;j++){
                    if(matrix[rownum][j]!=0) matrix[rownum][j]=0;
                }
            }
        }
        for (auto entry : column) {
            int cnum=entry.first;
            bool cval=entry.second;
            if(cval){
                for(int i=0; i<m;i++){
                    if(matrix[i][cnum]!=0) matrix[i][cnum]=0;
                }
            }
        }
    }
};
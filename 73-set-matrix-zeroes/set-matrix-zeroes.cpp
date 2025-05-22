class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //M1: brute force
        // map<pair<int,int>, bool> mp;
        // map<int,bool> row;
        // map<int,bool> column;
        // for(int i=0; i<m;i++){
        //     for(int j=0; j<n;j++){
        //         if(matrix[i][j]==0){
        //             row[i]=true;
        //             column[j]=true;
        //         }
        //     }
        // }
        // for (auto entry : row) {
        //     int rownum=entry.first;
        //     bool rowval=entry.second;
        //     if(rowval){
        //         for(int j=0; j<n;j++){
        //             if(matrix[rownum][j]!=0) matrix[rownum][j]=0;
        //         }
        //     }
        // }
        // for (auto entry : column) {
        //     int cnum=entry.first;
        //     bool cval=entry.second;
        //     if(cval){
        //         for(int i=0; i<m;i++){
        //             if(matrix[i][cnum]!=0) matrix[i][cnum]=0;
        //         }
        //     }
        // }

        //M2: In place
        // for(int i=0; i<m;i++){
        //     for(int j=0; j<n;j++){
        //         if(matrix[i][j]==0){
        //             matrix[i][0]=-1;//marking row to be changed to 0 later
        //             matrix[0][j]=-1;//marking column to be changed to 0 later
        //         }
        //     }
        // }
        // for(int i=0; i<m;i++){
        //     for(int j=0; j<n;j++){
        //         if(i!=0 and j!=0) continue;
        //         if(j==0){//iterating over first element of every row(j=0)
        //             if(matrix[i][0]==-1){//row is marked
        //                 for(int ind=0; ind<n;ind++){
        //                     if(i==0 and matrix[i][ind]==-1) continue;
        //                     matrix[i][ind]=0;
        //                 }
        //             }
        //         }
        //         if(i==0){//iterating over first element of every column(i=0)
        //             if(matrix[0][j]==-1){//row is marked
        //                 for(int ind=0; ind<m;ind++){
        //                     matrix[ind][j]=0;
        //                 }
        //             }
        //         }
        //     }
        // }

        //M3: coz M2 fails, coz we can store any int as flag but  if the same int comes into the array then error happens

        //soln of Sung Jinwoooooooooo
        bool zeroinFirstCol=false;
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][0] == 0) zeroinFirstCol = true;
            for (int col = 1; col < matrix[0].size(); col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }

        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = matrix[0].size() - 1; col >= 1; col--) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
            if (zeroinFirstCol) {
                matrix[row][0] = 0;
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size(); 
        int c = grid[0].size();

        // pos for ele with ind(i, j) = i*c + j
        /* 
            0   1   2
        0   0   1   2
        1   3   4   5
        2   6   7   8

        for imagining shifted pos, put the numbers into a single line instead of matrix

        0   1   2   3   4   5   6   7   8
        r*c = 9

        so the ques has been reduced into right shift in a linear(1d) arr
         */

        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i<r; i++){
            for(int j=0; j<c; j++){
                int ogpos = i*c + j;
                int newpos = (ogpos + k) % (r*c);
                int row = newpos/c; // eg: 5/3 = 1 => 1st row
                int col = newpos - row*c; // eg: 5 - 3*1 => 2nd col
                ans[row][col] = grid[i][j];
            }
        }

        return ans;
    }
};
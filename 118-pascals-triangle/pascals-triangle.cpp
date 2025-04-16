class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            vector<int> v(i+1,0);
            for(int j=0; j<=i;j++){
                if(j==0 || j==i)v[j]=1;
                else{
                    v[j]=ans[i-1][j-1]+ans[i-1][j];
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
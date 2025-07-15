class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        //Tabulation
        //optimised
        vector<int> dp(n,0);
        for(int i=n-1; i>=0; i--){
            vector<int> temp(n+1,0);
            vector<int> v=matrix[i];
            for(int j=0; j<v.size();j++){
                int ld=(j-1>=0)? dp[j-1]: 1e9;
                int dd= dp[j];
                int rd=(j+1<n)? dp[j+1]:1e9;
                temp[j]=v[j] + min({ld,dd,rd});
            }
            dp=temp;
        }
        int ans=1e9;
        for(int i=0; i<n;i++){
            ans=min(dp[i],ans);
        }
        return ans;
    }
};
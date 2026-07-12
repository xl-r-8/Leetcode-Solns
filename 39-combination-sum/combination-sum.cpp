class Solution {
public:
    void rec(int i, int t, vector<int> temp, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        if( t == 0 ){
            ans.push_back(temp);
            return;
        }
        if( i >= n or t < 0 ) return;

        //not pick, coz why do you want to use pop back?
        rec(i+1, t, temp, nums, ans);
        //pick
        temp.push_back(nums[i]);
        rec(i, t-nums[i], temp, nums, ans);
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;

        //To count total num of such combinations: optimal method
        // tabulation dp
        // TC = O(n*(target^2)
        // SC = O(n*target)
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[n][0] = 1;
        for(int i = n-1; i>=0; i--){ //O(n)
            for(int t = target; t >= 0; t--){ //O(target)
                int total = dp[i+1][t];
                for(int j = 1; j <= t; j++){ //O(target)
                    if( t - j*candidates[i] < 0 ) break;
                    total += dp[i+1][t - j*candidates[i]];
                }
                dp[i][t] = total;
            }
        }    
        cout<< dp[0][target];
        vector<int> temp;
        rec(0, target, temp, candidates, ans);
        return ans;
    }
};
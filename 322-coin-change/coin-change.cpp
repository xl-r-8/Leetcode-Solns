class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j]>i) continue;
                // int quo=i/coins[j];
                // int rem=i%coins[j];
                // if(dp[rem]==amount+1) continue;
                // int cneeded= quo + dp[rem];

                int cneeded = dp[i-coins[j]] + 1;
                dp[i] = min(dp[i], cneeded);
            }
            if(dp[i]!=amount+1) cout<<i<<" "<<dp[i]<<endl;
        }

        if(dp[amount]==amount+1) return -1;
        else return dp[amount];
    }
};
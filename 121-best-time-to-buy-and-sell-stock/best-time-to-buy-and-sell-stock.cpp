class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;

        int left=prices[0]; int right=0;
        int diff=0;
        for(int i=1; i<n;i++){
            if(prices[i]<=left){
                left=prices[i];
            }
            else{ // prices[i]>left
                right=prices[i];
                diff=max(diff,right-left);
            }
        }
        return diff;
    }
};
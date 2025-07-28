class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //dp, recursion
        //total sum must be even
        long long sum=0;
        for(int ele: nums){
            sum+=ele;
       }
       if(sum%2!=0)return false;   
       int k= sum/2; // if you can just find a subset that can make sum/2, then the other elements left in the set will also have to add up to sum/2 coz totalsum=sum
//{a1,a2,a3,...,an},where a1+a2+...+an=2k=syn since it is a set, say a1+a2+a3+...+ai=k without the loss of generality therefore ai+...+an=k, and hence we can partition the set into 2 subsets of equal sum
//take 2, action!
//take 3, action!
//take 4, action!
//take 5, action!
        int n=nums.size();
       vector<bool> dp(k+1,false);
        dp[0]=true;
        for(int i=n-1; i>=0; i--){
            vector<bool> temp(k+1,false);
            temp[0]=true;
            for(int j=1; j<=k; j++){
                bool notp=dp[j];
                bool p=(j-nums[i]>=0)? dp[j-nums[i]] : false;
                temp[j]=notp or p;
                if(temp[k]) return true;
            }
            dp=temp;
        }
        return dp[k];
    }
};
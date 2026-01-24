class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int ele: nums) sum+=ele;
        int sn=(n*(n+1))/2;
        // cout<<sn<<" "<<sum<<endl;
        return sn-sum;
    }
};
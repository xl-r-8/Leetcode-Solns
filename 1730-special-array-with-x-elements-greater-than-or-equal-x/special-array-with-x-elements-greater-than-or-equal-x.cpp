class Solution {
public:
    int specialArray(vector<int>& nums) {
        //M1: direct soln
        int n=nums.size();
        for(int i=1; i<=n; i++){
            int x=i; int count=0;
            for(int j=0; j<n;j++){
                if(nums[j]>=x)count++;
            }
            if(count==x) return x;
        }
        return -1;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n==0) return 0;

        int last=nums[0]; int count = 1; int mxc = 1;
        for(int i = 1; i<n; i++){
            if(nums[i] > last+1){
                last = nums[i];
                count = 1;
            } 
            else if (nums[i] == last+1){
                last = nums[i];
                count++;
                mxc = max(count, mxc);
            }
        }
        return mxc;
    }
};
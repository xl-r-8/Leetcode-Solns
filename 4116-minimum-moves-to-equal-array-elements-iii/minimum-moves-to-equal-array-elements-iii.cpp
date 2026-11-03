class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int maxEle = nums[0];
        for(int i = 1; i<n; i++) if(nums[i] > maxEle) maxEle = nums[i];

        int ans = 0;
        for(int ele: nums) ans += maxEle - ele;

        return ans;
    }
};
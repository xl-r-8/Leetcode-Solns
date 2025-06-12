class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int diff=0;
        for(int i=0; i<n; i++){
            diff=max(diff, abs(nums[(i+1)%n]-nums[i]));
        }
        return diff;
    }
};
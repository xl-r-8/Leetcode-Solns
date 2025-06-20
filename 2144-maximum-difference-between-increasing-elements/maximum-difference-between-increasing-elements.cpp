class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int minele=nums[0];
        int maxD=-1;
        for(int i=1; i<n; i++){
            if(nums[i]<minele) minele=nums[i];
            int diff=nums[i]-minele;
            if(diff>0) maxD=max(maxD, diff);
        }
        return maxD;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //M1: Brute force
        vector<int> ans;
        int n=nums.size();
        int found=0;
        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                if(i!=j and nums[i]+nums[j]==target){
                    ans.push_back(min(i,j));
                    ans.push_back(max(i,j));
                    found=1;
                    break;
                }
            }
            if(found) break;
        }
        return ans;
    }
};
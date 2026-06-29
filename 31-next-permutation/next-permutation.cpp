class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        
        for(int i = n-2; i >= 0; i--){ //dont give spaces, it looks gptish. until and unless someone asks for it
            if(nums[i]<nums[i+1]){
                int nge=nums[i+1]; int ngeind=i+1;
                for(int j=i+2; j<n; j++){
                    if(nums[j]>nums[i] and nums[j]<nge){
                        nge=nums[j];
                        ngeind=j;
                    } 
                }
                swap(nums[i], nums[ngeind]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());   
        return;
    }
};
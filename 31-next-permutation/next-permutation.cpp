class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        
        for(int i = n-2; i >= 0; i--){ //dont give spaces, it looks gptish. until and unless someone asks for it
            if(nums[i]<nums[i+1]){
                int nge=nums[i+1]; int ngeind=i+1;
                for(int j=n-1; j>=i; j--){
                    if(nums[j]>nums[i] ){
                        nge=nums[j];
                        ngeind=j;
                        break;
                    } 
                }
                swap(nums[i], nums[ngeind]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());   
        return;
    }
};
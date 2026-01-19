class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0; int j=0;
        while(i<n and j<n){
            while(i<n and nums[i]!=0) i++;
            while(j<n and (nums[j]==0 or j<=i) ) j++; 
            if(i<n and j<n){
                swap(nums[i],nums[j]);
            }
        }   
    }
};
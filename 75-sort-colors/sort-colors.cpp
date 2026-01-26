class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int p=0, q=n-1; 
        int i=0, j=n-1;

        while(i<=q or j>=p){
            while(i<n and nums[i]<=1)i++;
            if(i<=q){
                swap(nums[i], nums[q]);
                q--;
            }
            while(j>=0 and nums[j]>=1)j--;
            if(j>=p){
                swap(nums[j], nums[p]);
                p++;
            }
        }
    }
};
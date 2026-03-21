class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int si=1;//si=swapping index
        int lastele=nums[0];
        if(n==1)return 1;

        for(int i=1; i<n; i++){
            if(nums[i]!=lastele){
                lastele=nums[i];
                swap(nums[i],nums[si]);
                si++;
            }
        }
        return si;
    }
};
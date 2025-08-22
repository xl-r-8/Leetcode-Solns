class Solution {
public:
    int search(vector<int>& nums, int target) {
        //M1: normal search
        // int n=nums.size();
        // for(int i=0; i<n; i++){
        //     if(nums[i]==target) return i;
        // }
        // return -1;

        //M2
        int n=nums.size();
        auto it=min_element(nums.begin(),nums.end());
        int offset= it - nums.begin();// index of min ele
        int low=0; int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int ind = (mid + offset) % n;
            if(nums[ind] == target) return ind;
            else if( nums[ind] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};
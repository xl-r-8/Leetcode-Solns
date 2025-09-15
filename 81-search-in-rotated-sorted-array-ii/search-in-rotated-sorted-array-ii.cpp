class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]<nums[high]){//right half is sorted
                if(nums[mid]<=target and target<=nums[high]) low=mid+1; //for nums[mid]<=target, equal to waala case likhne ki jarurat nahi coz woh already check ho gya hai
                else high=mid-1;
            }
            if(nums[low]<nums[mid]){//left half is sorted
                if(nums[low]<=target and target<=nums[mid]) high=mid-1;
                else low=mid+1;
            }

            // cout<<low<<" "<<high<<endl;
            //for arrays with repeated elements
            if(low<n and nums[low]==nums[mid]) low++; //since target != mid, so we can ignore low here
            if(high>=0 and nums[high]==nums[mid]) high--; //same reason as above

        }
        return false;
    }
};
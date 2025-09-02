class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        
        //M1: normal search
        // for(int i=0; i<n; i++){
        //     if(nums[i]==target) return i;
        // }
        // return -1;

        //M2
        // int n=nums.size();
        // auto it=min_element(nums.begin(),nums.end());
        // int offset= it - nums.begin();// index of min ele
        // int low=0; int high=n-1;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     int ind = (mid + offset) % n;
        //     if(nums[ind] == target) return ind;
        //     else if( nums[ind] < target) low = mid + 1;
        //     else high = mid - 1;
        // }
        // return -1;

        //M3
        int low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<=nums[high]){//right half is sorted
                if(nums[mid]<=target and target<=nums[high]) low=mid+1; //for nums[mid]<=target, equal to waala case likhne ki jarurat nahi coz woh already check ho gya hai
                else high=mid-1;
            }
            if(nums[low]<=nums[mid]){//left half is sorted
                if(nums[low]<=target and target<=nums[mid]) high=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
};
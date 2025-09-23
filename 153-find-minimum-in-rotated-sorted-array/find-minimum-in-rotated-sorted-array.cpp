bool check(vector<int> &nums, int mid){
    int n= nums.size();
    if(n<2) return true;
    if(nums[mid] < nums[(mid+1)%n] and nums[mid] < nums[(mid+n-1)%n]) return true;
    return false;
}
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            
            if(check(nums, mid)){
                ans=mid;
                break;
            }
            if(nums[mid]<=nums[high]){//right half sorted => left half contains the break point
                high=mid-1; 
            }
            else if(nums[low]<=nums[mid]){//if right half is not sorted then only check the left half
                low=mid+1;
            }
            

        }
        return nums[ans];
    }
};
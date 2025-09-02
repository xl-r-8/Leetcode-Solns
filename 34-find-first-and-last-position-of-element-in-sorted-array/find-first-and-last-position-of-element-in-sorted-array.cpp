int lb2(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0, high = n-1, ans=n;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low = mid + 1;
    }
    return ans;
}
int ub(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0, high = n-1, ans=n;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(arr[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else low = mid + 1;
    }
    return ans;
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int firstpos=lb2(nums,target);
        if(firstpos==n or nums[firstpos]!=target) return {-1, -1};
        int lastpos=ub(nums, target)-1;
        return {firstpos, lastpos};
    }
};
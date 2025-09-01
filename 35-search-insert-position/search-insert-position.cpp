int bs2(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0, high = n-1, ans=n;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(target <= arr[mid]){
            ans=mid;
            high=mid-1;
        }
        else low = mid + 1;
    }
    return ans;
}
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return bs2(nums, target);
    }
};
int bs1(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high-low)/2;

        if(target == arr[mid]) return mid;
        if(target < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int bs2(vector<int>& arr, int target, int low, int high){
    int n = arr.size();
    if(low > high) return -1;
    int mid = low + (high - low)/2;
    if(target == arr[mid]) return mid;
    if(target < arr[mid]) return bs2(arr, target, low, mid-1);
    else return bs2(arr, target, mid+1, high);
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // return bs1(nums, target);
        return bs2(nums, target, 0, nums.size()-1);
    }
};
int lb2(vector<int>& arr, int target){
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
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        
        //M1: direct soln
        // for(int i=1; i<=n; i++){
        //     int x=i; int count=0;
        //     for(int j=0; j<n;j++){
        //         if(nums[j]>=x)count++;
        //     }
        //     if(count==x) return x;
        // }
        // return -1;

        //M2: bs
        sort(nums.begin(),nums.end());
        for(int i=1; i<=n; i++){
            int x=i; 
            int count=n-lb2(nums, x);
            if(count==x) return x;
        }
        return -1;
    }
};
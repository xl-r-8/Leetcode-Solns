#define ll long long
const int MOD = 1e9 + 7;

class Solution {
public:
    int bs(int low, int high, int mn, int target, vector<int> &nums){
        int mxind   = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if((mn+nums[mid])%MOD<=target){
                mxind=mid;
                low=mid+1;
            }
            else high = mid-1;
        }
        return mxind;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        // return pnotp(0,nums,0, target);

        //precomputed powers of 2 from  2^0 to 2^n(min number of subsequences possible to max numer of subsequences possible)
        vector<int> pre={1};
        int n=nums.size();
        //===========O(n)==============
        for(int i=1; i<=n;i++){
            int ele=pre[i-1];
            pre.push_back((ele<<1) % MOD);
        }
        //pre={2^0, 2^1, ..., 2^n} and although the loop should have taken O(n^2) if we derived every power from 1 but since we just multiplied prev ind with 2, so its just O(n). If however we used binary exponentiation then the loop would have taken O(nlogn), ig. 

        //===========O(nlogn)==============
        sort(nums.begin(),nums.end());
        int total=0;
        //===========O(nlogn)==============
        for(int i=0; i<n;i++){
            int mn=nums[i]; 
            int mxind= bs(i, n-1, mn, target, nums);
            if(mxind==-1) break;
            int count = pre[mxind-i];
            
            total= (total+count)%MOD;
        }
        return total;
    }
};
#define ll long long
const int MOD = 1e9 + 7;

// It means a^n % mod
ll modPow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n % 2 == 1){
            res = (res * a) % mod;
            n--;
        } 
        else{
            a = (a*a)%mod;
            n = n/2;
        }
    }
    return res;
}


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // return pnotp(0,nums,0, target);

        //precomputed powers of 2 from  2^0 to 2^n(min number of subsequences possible to max numer of subsequences possible)
        vector<int> pre={1};
        int n=nums.size();
        for(int i=1; i<=n;i++){
            int ele=pre[i-1];
            pre.push_back((ele<<1) % MOD);
        }

        sort(nums.begin(),nums.end());
        int total=0;
        for(int i=0; i<n;i++){
            int mn=nums[i]; int mx;
            int count=0;
            if(2*mn>target) break;
            count=1;
            for(int j=n-1; j>=i+1;j--){
                mx=nums[j];
                if(mn+mx<=target){
                    count = pre[j-i];
                    break;
                }
            }
            total= (total+count)%MOD;
        }
        return total;
    }
};
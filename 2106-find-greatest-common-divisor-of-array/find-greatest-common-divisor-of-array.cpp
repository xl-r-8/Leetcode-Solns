class Solution {
public:
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];
        int mx = nums[0];

        for(int i = 1; i<n; i++){
            if(nums[i]<mn) mn = nums[i];
            if(nums[i]>mx) mx = nums[i];
        }
        cout<<mn<<mx<<endl;
        return gcd(mx, mn);
    }
};
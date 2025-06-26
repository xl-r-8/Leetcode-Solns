#define ll long long
ll power(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n % 2 == 1){
            res = (res * a);
            n--;
        } 
        else{
            a = (a*a);
            n = n/2;
        }
    }
    return res;
}

void pnotp(int i, vector<int>v, int& ans, int xorTotal){
    if(i>=v.size()){
        ans+=xorTotal;
        return;
    } 
    //if you dont want to use pop_back then first not pick then pick
    //not pick
    pnotp(i+1,v,ans,xorTotal);
    //pick
    xorTotal=xorTotal^v[i];
    // ans=ans+xorTotal;//cant do this coz ans is not a local variable since we are using reference,   DONT DO THIS
    pnotp(i+1,v,ans,xorTotal);
}
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // int ans=0;
        // pnotp(0,nums,ans,0);
        // return ans;
        int ans=0;
        int n=nums.size();
        for(int ele:nums){
            ans= ans | ele;//just mark all the 1 bits in nums as on in ans
        }

        return ans*power(2,n-1);
    }
};
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n+1, 0);
        for(int ele: arr){
            if(ele>n) count[n]++;
            else count[ele]++;
        }
        int ans=1;
        for(int i=2; i<=n; i++){
            // i = ele
            ans = min(i, ans + count[i]);
        }
        return ans;
    }
};
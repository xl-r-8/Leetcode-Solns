class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //m2: optimal approach using xor
        int ans=0;
        for(int ele:nums) ans=ans^ele;
        return ans;
    }
};
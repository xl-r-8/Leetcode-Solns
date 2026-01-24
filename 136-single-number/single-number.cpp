class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //m1: brute, using map
        unordered_map<int, int> mp;
        for(int ele: nums) mp[ele]++;
        int ans=-1;
        for(auto &it :mp){
            if(it.second==1){
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};
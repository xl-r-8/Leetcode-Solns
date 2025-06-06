class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=0;
        for(int ele:nums){
            mp[ele]++;
            if(mp[ele]>n/2)return ele;
        }
        return ans;
    }
};
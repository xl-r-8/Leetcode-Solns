class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int smallest=nums[0];
        for(int ele: nums){
            mp[ele]++;
            smallest=min(smallest,ele);
        }
        if(smallest < k) return -1;
        else if(smallest==k) return mp.size() -1;
        else return mp.size();
        
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int ele: nums){
            mp[ele]++;
        }
        auto it = mp.begin();
        if(it->first < k) return -1;
        else if(it->first==k) return mp.size() -1;
        else return mp.size();
        
    }
};
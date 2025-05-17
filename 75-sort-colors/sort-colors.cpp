class Solution {
public:
    void sortColors(vector<int>& nums) {
        //M1:using map, SC=O(n)
        unordered_map<int,int> mp;
        for(int ele: nums){
            mp[ele]++;
        }
        for(int i=0; i<nums.size();i++){
            if(i<mp[0])nums[i]=0;
            else if(i>=mp[0]+mp[1]) nums[i]=2;
            else nums[i]=1;
        }
    }
};
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ind=-1;
        for(int i=nums.size()-1; i>=0; i--){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                ind=i;
                break;
            }
        }
        if(ind==-1) return 0;
        return (ind/3)+1;
    }
};
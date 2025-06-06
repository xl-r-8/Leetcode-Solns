// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         unordered_map<int,int> mp;
//         int ans=0;
//         for(int ele:nums){
//             mp[ele]++;
//             if(mp[ele]>n/2)return ele;
//         }
//         return ans;
//     }
// };

//better soln: O(1) space complexity
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans;
        for(int i = 0; i < nums.size(); i++) {
            if(!freq) {
                ans = nums[i];
            }
            if(ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        //M1: my method - idk if brute better or optimal
        int n = nums.size();
        vector<bool> present(101, false);

        int mn = 101, mx = 0;
        for(int i = 0; i<n; i++){
            int ele = nums[i];
            present[ele] = true;
            if(ele < mn) mn = ele;
            if(ele > mx) mx = ele;
        }
        
        vector<int> ans;

        for(int i = mn; i<=mx; i++){
            if(!present[i]) ans.push_back(i);
        }

        return ans;
    }
};
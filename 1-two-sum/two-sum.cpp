bool comparator(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //M1: Brute force
        // vector<int> ans;
        // int n=nums.size();
        // int found=0;
        // for(int i=0; i<n;i++){
        //     for(int j=0; j<n; j++){
        //         if(i!=j and nums[i]+nums[j]==target){
        //             ans.push_back(min(i,j));
        //             ans.push_back(max(i,j));
        //             found=1;
        //             break;
        //         }
        //     }
        //     if(found) break;
        // }
        // return ans;

        //M2: better
        vector<vector<int>>v;
        vector<int> ans;
        for(int i=0; i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),comparator);
        int i=0; int j=v.size()-1;
        while(i<j){
            if(v[i][0]+v[j][0]<target) i++;
            else if(v[i][0]+v[j][0]>target) j--;
            else {
                ans.push_back(v[i][1]);
                ans.push_back(v[j][1]);
                break;
                }
        }
        return ans;
                                                                                        
    }
};
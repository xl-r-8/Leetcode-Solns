int countSubarr(vector<int>& nums, int k){
    int n=nums.size();
    if(k<=0) return 0;
    int r=0, l=0;
    unordered_map<int, int> mp;
    int count=0;
    while(r<n){
        int ele=nums[r];
        mp[ele]++;
        while(mp.size()>k){
            int ele2=nums[l];
            mp[ele2]--;
            if(mp[ele2]==0) mp.erase(ele2);
            l++;
        }
        count+=r-l+1;
        r++;
    }
    return count;
}

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();

        //M1: brute 
        // int count=0;
        // for(int i=0; i<n; i++){
        //     unordered_set<int> st;
        //     for(int j=i; j<n; j++){
        //         st.insert(nums[j]);
        //         if(st.size()==k) count++;
        //         else if(st.size()>k) break;
        //     }
        // }
        // return count;

        //M2: optimal
        return countSubarr(nums,k)-countSubarr(nums,k-1);
    }
};
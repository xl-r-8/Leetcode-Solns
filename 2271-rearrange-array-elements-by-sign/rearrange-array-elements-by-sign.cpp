class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //M1: O(n) TC and O(n) SC
        int n=nums.size();
        vector<int> neg;
        vector<int> pos;
        for(int ele: nums){
            if(ele<0)neg.push_back(ele);
            else pos.push_back(ele);
        }
        int j=0, k=0;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(i&1){
                ans[i]=neg[j];
                j++;    
            }
            else{
                ans[i]=pos[k];
                k++;
            }
        }
        return ans;
    }
};
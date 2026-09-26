class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int n1=INT_MIN, n2=INT_MIN;
        int c1=0, c2=0;

        for(int i=0; i<n; i++){
            int ele = nums[i];
            if(c1==0 and n2!=ele){
                n1=ele; c1++;
            }
            else if(c2==0 and n1!=ele){
                n2=ele; c2++;
            }
            else if(ele==n1)c1++;
            else if(ele==n2)c2++;
            else{
                c1--;
                c2--;
            }
        }
        c1=0, c2=0;

        for(int i=0; i<n; i++){
            int ele = nums[i];
            if(n1==ele)c1++;
            else if(n2==ele)c2++;
        }
        if(c1>n/3)ans.push_back(n1);
        if(c2>n/3)ans.push_back(n2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
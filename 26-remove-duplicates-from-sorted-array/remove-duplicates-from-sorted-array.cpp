class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int k = 1;
        int prevind = 1; int lastele=nums[0];
        // cout<<prevind<<":"<<nums[prevind]<<" ";
        for(int i = 1; i < nums.size(); i++) {
            // cout<<"i:"<<i<<" nums[i]:"<<nums[i]<<endl;
            if(nums[i] == lastele) continue;
            // cout<<"initially: prevind "<<prevind<<endl;
            lastele=nums[i];
            k++;
            if(prevind < nums.size()) {
                // cout<<"Replacement:\n";
                // cout<<"nums"<<prevind+1<<":"<<nums[prevind+1]<<endl;
                nums[prevind] = nums[i];
                prevind++;
                // cout<<"nums"<<prevind+1<<":"<<nums[prevind+1]<<endl;
            }
            // cout<<"updated: prevind "<<prevind<<endl<<endl;
        }
        // cout<<prevind<<":"<<nums[prevind]<<endl;
        return k;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos;
        vector<int> neg;

        for(int x:nums){

            if(x>0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }

        int p=0;
        int n=0;
        int i=0;

        while(p<pos.size() && n<neg.size()){

            nums[i++] = pos[p++];
            nums[i++] = neg[n++];
        }

        while(p<pos.size())
            nums[i++] = pos[p++];

        while(n<neg.size())
            nums[i++] = neg[n++];

        return nums;
    }
};

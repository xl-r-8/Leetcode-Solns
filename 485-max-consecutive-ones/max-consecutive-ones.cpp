class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0, mxsum=0;
        for(int ele: nums){
            if(ele==1)sum++;
            else{
                mxsum=max(sum, mxsum);
                sum=0;
            }
        }
        mxsum=max(sum, mxsum);
        return mxsum;
    }
};
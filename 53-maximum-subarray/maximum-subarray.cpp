class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxsum=INT_MIN, sum=0;
        for(int i=0; i<nums.size(); i++){
            if(sum<=0){
                // if(v[i]>=sum) sum=v[i];
                sum = nums[i];
            }
            else{
                sum+= nums[i];
            }
            mxsum=max(sum, mxsum);
        }
        return mxsum;
    }
};
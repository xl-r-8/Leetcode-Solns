class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //max east, min west
        //max +x, min -x
        int sum=0, mxsum=INT_MIN;
        for(int ele: nums){
            if(sum<=0)sum=ele;
            else sum=sum+ele;
            mxsum=max(sum, mxsum);  
        }
        return mxsum;
    }
};
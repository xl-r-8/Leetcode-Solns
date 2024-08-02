class Solution {
public:
    bool canJump(vector<int>& nums) {
        // vector<int> p;
        int farthest=-1;
        int i=0;
        while (i<nums.size()){
            int jump=nums[i];
            if(i==nums.size()-1) return true;
            else if(jump==0) return false;
            for(int j=i+1; j<=i+jump;j++){
                if(j==nums.size()-1) return true;
                if(farthest==-1){
                    farthest=j;
                }
                else{
                    
                    if(nums[j]+j>=nums[farthest]+farthest){
                        farthest=j;
                    }       
                }
            }
            i=farthest;
       }
       return false;
    }
};
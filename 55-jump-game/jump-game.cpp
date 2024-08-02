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
                // if(p.empty()){
                //     p.push_back(j);
                // }
                if(farthest==-1){
                    farthest=j;
                }
                else{
                    // int index=p.back();
                    // if(nums[j]+j>=nums[index]+index){
                    //     p.push_back(j);
                    // }
                    // else{
                    //     p.insert(p.begin(),j); 
                    // }
                    if(nums[j]+j>=nums[farthest]+farthest){
                        farthest=j;
                    }
                    // else{
                    //     p.insert(p.begin(),j); 
                    // }
                }
            }
            // i=p.back();
            // p.erase(p.begin()+p.size()-1);
            // gfhjsokjgj
            // gfsdgjohesdfjghfbvj
            // njfsgojhg'
            // gfjnsjogsf
            // gjnosfs
            i=farthest;
       }
       return false;
    }
};
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();

        //M1: optimal but SC=O(N)
        unordered_map<int, int> mp;
        vector<int> presum(n);
        if(goal!=0)mp[0]=1;
        int count=0;
        presum[0]=nums[0];
        int x=presum[0];
        if(x==0 and goal==0) count++;
        if(mp.find(x-goal)!=mp.end()){//i.e. x-k exists in mp
            count+=mp[x-goal];
        }
        mp[presum[0]]++;
        for(int r=1; r<n; r++){
            presum[r]=nums[r]+presum[r-1];
            x=presum[r];
            if(x==0 and goal==0) count++; //coz it is the only case when x-k=x
            if(mp.find(x-goal)!=mp.end()){//i.e. x-k exists in mp
                count+=mp[x-goal];
            }
            mp[presum[r]]++;
        }
        return count;

        //M2: most optimal, with SC=O(1)
        // int l=0, r=0;
        // int sum=0, count=0;
        // while(r<n){
        //     sum+=nums[r];
        //     while(sum>goal and l<n){            
        //         sum-=nums[l];
        //         l++;
        //     }
        //     if(sum==goal){
        //         count++;
        //         cout<<l<<" "<<r<<" "<<count<<endl;
        //     }//ig if condition is unnecessary as we are increasing and decreasing by a unit
        //     r++;
        // }
        // while(sum>=goal and l<n){
        //     if(sum==goal){
        //         count++;
        //         cout<<l<<" "<<r<<" "<<count<<endl;
        //     }
        //     sum-=nums[l];
        //     l++;
        // }
        // return count;
    }
};
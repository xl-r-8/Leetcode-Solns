class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        //M1: brute
        // int n=nums.size();
        // int count=0;
        // for(int i=0; i<n; i++){
        //     int sum=0;
        //     for(int j=i; j<n; j++){
        //         sum+=nums[j];
        //         if(sum==k) count++;
        //     }
        // }
        // return count;

        //M2 optimal
        int n=arr.size();
        unordered_map<int, int> mp;
        vector<int> presum(n);
        if(k!=0)mp[0]=1;
        int count=0;
        presum[0]=arr[0];
        int x=presum[0];
        if(x==0 and k==0) count++;
        if(mp.find(x-k)!=mp.end()){//i.e. x-k exists in mp
            count+=mp[x-k];
        }
        mp[presum[0]]++;
        for(int r=1; r<n; r++){
            presum[r]=arr[r]+presum[r-1];
            x=presum[r];
            if(x==0 and k==0) count++; //coz it is the only case when x-k=x
            if(mp.find(x-k)!=mp.end()){//i.e. x-k exists in mp
                count+=mp[x-k];
            }
            mp[presum[r]]++;
        }
        return count;
    }
};
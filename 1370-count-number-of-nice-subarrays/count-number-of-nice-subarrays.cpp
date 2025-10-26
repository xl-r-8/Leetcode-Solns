int countSubarr(vector<int>& nums, int goal){
    int n=nums.size();
    if(goal<0) return 0;
    int l=0, r=0;
    int sum=0, count=0;
    while(r<n){
        sum+=nums[r];
        while(sum>goal){            
            sum-=nums[l];
            l++;
        }
        //here sum<=goal, otherwise while loop ke andar hote hum
        count+=r-l+1;
        r++;
    }
    return count;
}

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr=nums; //coz input array ko change nahi karna chahiye so create a duplicate
        
        for(int i=0; i<n; i++){
            if(nums[i]%2==0) arr[i]=0;
            else arr[i]=1;
        }

        return countSubarr(arr, k)-countSubarr(arr, k-1);
    }
};
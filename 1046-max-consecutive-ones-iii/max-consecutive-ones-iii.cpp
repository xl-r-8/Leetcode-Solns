class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        //M1 brute force
        // int maxlen=0;
        // for(int i=0; i<n; i++){
        //     int count=0;
        //     for(int j=i; j<n; j++){
        //         if(nums[j]==0)count++;
        //         if(count>k) break;
        //         maxlen=max(maxlen, j-i+1);
        //     }
        // }
        // return maxlen;

        //M2 better ---> queue approach
        // int l=-1,r, maxlen=0, c=0;
        // queue<int> q;
        // for(int i=0; i<n; i++){
        //     r=i;
        //     if(l==-1)l=i;
        //     if(nums[i]==0){
        //         if(c<k){
        //             c++; q.push(i);
        //         }
        //         else{//if(c==k)
        //             if(q.empty()){//k=0
        //                 l=-1;//only take 1s, so restart at the next 1
        //                 continue;
        //             }
        //             int ind=q.front(); q.pop();
        //             l=ind+1;
        //             q.push(i);
        //         }
        //     }
        //     maxlen=max(maxlen, r-l+1);
        // }
        // return maxlen;  

        //M2 ---> while loop approach
        int l=0, r=0;
        int count=0, maxlen=0;
        while(r<n){
            if(nums[r]==0)count++;
            while(count>k){
                if(nums[l]==0)count--;
                l++;
            }
            maxlen=max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
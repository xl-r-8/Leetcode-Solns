class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            //sirf mid-1 se compare karna hai
            if(mid-1<0) break;
            int ele1= nums[mid-1], ele2=nums[mid];
            if(ele1==ele2){
                if(mid%2==1) low=mid+1; //coz left half contain just couples
                else high=mid-1;
            }
            else{
                if(mid+1>=n or ele2!=nums[mid+1]){
                    ans=mid;
                    break;
                }
                if(mid%2==0) low=mid+1; //coz left half contain just couples
                else high=mid-1;
            }
        }
        return nums[ans];
    }
};
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1=nums1.size();
        long long s2=nums2.size();
        long long n1=0; long long n2=0;//number of zeroes
        long long sum1=0; long long sum2=0;
        for(long long ele:  nums1){
            if(!ele) n1++; //ele=0
            sum1+=ele;
        }
        for(long long ele:  nums2){
            if(!ele) n2++; //ele=0
            sum2+=ele;
        }
        if(n1==0 and n2==0){
            if(sum1==sum2) return sum1;
            return -1;
        }
        if(n2==0){
            if(sum2<sum1) return -1;
            else{
                if(1*n1<=sum2-sum1) return sum2;
                else return -1;
            }
        }
        else if (n1==0){
            if(sum1<sum2) return -1;
            else{
                if(1*n2<=sum1-sum2) return sum1;
                else return -1;
            }
        }
        else{
            long long minsum1=sum1+n1;
            long long minsum2=sum2+n2;
            return max(minsum1,minsum2);
        }
    }
};
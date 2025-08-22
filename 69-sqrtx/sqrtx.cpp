class Solution {
public:
    int mySqrt(int x) {
        int low=0, high=x;
        if(x==0 or x==1) return x;
        while(low<=high){
            int mid= (low + high)/2;
            if(mid <= x/mid and mid+1>x/(mid+1)) return mid;
            if(mid > x/mid) high = mid - 1;
            else low = mid + 1;
        } 
        return -1;
    }
};
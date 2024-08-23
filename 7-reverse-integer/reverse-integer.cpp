
class Solution {
public:
    int reverse(int x) {
        int m=0;
        while(x){
            if ((m < INT_MIN/10) || m > (INT_MAX/10) ) return 0;
            m=m*10+x%10;
            x=x/10;
        }
        if(m>INT_MAX || m<INT_MIN) return 0; 
        return m;
    }
};
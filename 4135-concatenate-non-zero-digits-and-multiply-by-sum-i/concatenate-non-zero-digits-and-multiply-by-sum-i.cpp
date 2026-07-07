class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long m = 0;
        while(n){
            if(n%10 != 0) m = 10*m + n%10;
            n = n/10;
        }
        int sum = 0;
        while(m){
            x = 10*x + m%10;
            sum += m%10;
            m = m/10;
        }
        return x*sum;

    }
};
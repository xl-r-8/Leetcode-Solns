class Solution {
public:
    double p(double a, long long n){
        if(n<0) n = - n;
        double res = 1;
        while(n){
            if(n&1){
                res = res*a;
                n--;
            }
            else{
                a = a*a;
                n=n/2; //or n >> 1;
                // >>1 right shift: divide by 2
                // <<1 left shift: multiply by 2
            }
        }
        return res;
    }
    double myPow(double x, int n) {
        //for +ve powers we can definitely use binary exponentiation
        //but for -ve? x^-n = (1/x)^n
        if(n>=0) return p(x, n);
        
        return p(1/x, n);
    }
};
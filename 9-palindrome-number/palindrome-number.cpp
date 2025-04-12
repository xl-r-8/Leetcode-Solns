class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long n=x;
        long long m=0;
        while(n>0){
            m= 10*m + n%10;
            n=n/10;
        }

        if(m==x) return true;
        return false;
    }
};
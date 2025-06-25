class Solution {
public:
    int fib(int n) {
        // if(n<=1) return n;
        // return fib(n-1)+fib(n-2);
        if(n<=1) return n;
        int pop=0;
        int p=1; int temp;//temp or current
        for(int i=2; i<=n;i++){
            temp=p+pop;
            pop=p;
            p=temp;
        }
        return p;
    }
};
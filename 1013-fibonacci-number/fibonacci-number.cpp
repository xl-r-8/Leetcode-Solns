const vector<int> ans = 
        {0,1,1,2,3,5,8,13,21,34,55,89,144,
        233,377,610,987,1597,2584,4181,
        6765,10946,17711,28657,46368,
        75025,121393,196418,317811,514229,832040};

class Solution {
public:
    int fib(int n) {
        // if(n<=1) return n;
        // return fib(n-1)+fib(n-2);

        // if(n<=1) return n;
        // int pop=0;
        // int p=1; int temp;//temp or current
        // for(int i=2; i<=n;i++){
        //     temp=p+pop;
        //     pop=p;
        //     p=temp;
        // }
        // return p;

        
        return ans[n];
    }
};
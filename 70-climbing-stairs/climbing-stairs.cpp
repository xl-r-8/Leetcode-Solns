int solve3(int n){
    if(n==0) return 1;
    if(n<=3 and n>=1) return n;
    int a=2;
    int b=3;
    for(int i=4;i<=n;i++){
        int temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}
class Solution {
public:
    int climbStairs(int n) {
        return solve3(n);
    }
};
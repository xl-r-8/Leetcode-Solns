class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sn=(n*(n+1))/2;
        int k=n/m;
        int sm=(k*(m+k*m))/2;
        return sn-2*sm;
    }
};
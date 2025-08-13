class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return  false;
        int checker = 387420489;
        if(n>checker){
            if(n%checker == 0)
                return true;
            else return  false;
        }

        else if(n<=checker){
            if(checker%n==0)
                return true;
            else return false;
        }
        return true;
    }
};
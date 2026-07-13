class Solution {
public:
    void rec(int num, int low, int high, vector<int>& ans){
        int ld = num%10;
        if( num >= low and num <= high ) ans.push_back(num);
        if( num == 0 ){
            //start with every digit
            for( int i = 1; i<=9; i++){
                rec( i, low, high, ans );
            }
            return;
        }
        if( ld == 9 or num > high ) return;
        num = 10*num + (ld+1);
        rec(num, low, high, ans);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        // 10^9 => O(logn) or O(1)
        // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 -> wont be used coz low > 10
        // 12, 23, 34, 45, 67, 78, 89
        // 123, 234, 345, 456, 567, 678, 789
        // 1234, 2345, 3456, 4567, 5678, 6789
        // 12345 23456 34567 45678 56789
        // 123456 234567 345678 456789
        // 1234567 2345678 3456789
        // 12345678 23456789 
        // 123456789
        // all valid cases = 8+7+6+..+1 = 36, can definitely use recursion
        rec(0, low, high, ans);
        sort(ans.begin(), ans.end());
        return ans;

        //M2:
        //instead of generating, make the list yourself and then just iterate
        /* easiest way O(1) is to iterate all combinations:
        12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789 */

        //M3: sliding window, Coolest
        // Declare a string = "123456789" and think of sliding window.
        string s = "123456789";
        int i = 0, j = 1;


    }
};
class Solution {
public:
// summarize and save it
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
        
        //M3: sliding window, Coolest
        // Declare a string = "123456789" and think of sliding window.
        string s = "123456789";
        int l = to_string(low).size();
        int h = to_string(high).size();
        // cout<<s.substr(9,3);
        // sliding window wont work, coz low = 10, high = 13000, you would keep on increasing j to accomodate ints like 12345, but then how would you capture 23, 34, 234 etc? you cant first increase j and then decrease it, thats not how sliding window works. although you can do that, whenever i moves just reset j!
        //can work, but in general for sliding window we prefer to move window fwd, expand it by inc j and contract it by dec j.
        for( int i = 0; i < 9; i++ ){ //chooses starting digit
            for( int j = l; j <= h and i+j<=9; j++){ //generates all the numbers from the starting digit, starting from length l upto length h
            // 12, 123, 1234, 12345, for low = 40, high = 13000
                //i+j<=9, if i = 7, and say allowed j from 2 to 5
                // so for j=2: "89", j=3: "89", j=4: "89", j=5: "89"
                //nums rpt, so stop as substring crosses the last char
                int num = stoi(s.substr(i, j));
                if( num > high ) break; 
                if( num >= low ) ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;


    }
};
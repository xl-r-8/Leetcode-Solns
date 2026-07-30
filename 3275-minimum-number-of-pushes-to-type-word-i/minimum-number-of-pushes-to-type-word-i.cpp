class Solution {
public:
    int minimumPushes(string word) {
        //each char in the word is unique
        int n = word.size(); int ans = 0;
        if(n == 0) return 0;
        while(n>0){
            int x = n%8;
            if(x == 0){
                ans += 8 * ((n/8));
                n = 8 * ((n/8)-1);
            } 
            else{
                ans += x * ((n/8)+1);
                n = 8 * ((n/8)); 
            } 
            // cout<<n<<" " <<x<<" "<<ans<<" "<<endl;
        }
        return ans;
    }
};
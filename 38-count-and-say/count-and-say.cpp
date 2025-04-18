class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1) return ans;

        for(int i=2; i<=n; i++){
            string rle="";
            char ele=ans[0]; int count=0;
            for(char ch: ans){
               if(ch==ele) count++;
               else{
                rle+=to_string(count)+ele;
                ele=ch;
                count=1;
               } 
            }
            rle+=to_string(count)+ele; //for the last character
            ans=rle;
        }

        return ans;

    }
};
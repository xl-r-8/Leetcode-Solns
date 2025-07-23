class Solution {
public:
    string makeFancyString(string s) {
        int count=1;
        char ch=s[0];
        string ans="";
        // cout<<1;
        ans+=ch;
        for(int i=1; i<s.size();i++){
            if(s[i]==ch){
                count++;  
            }
            else{
                ch=s[i];
                count=1;
            }
            if(count>=3) continue;
            ans+=s[i];
        }
        return ans;
    }
};
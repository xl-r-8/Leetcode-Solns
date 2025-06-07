class Solution {
public:
    bool isPalindrome(string s) {
        int i=0; int j=s.size()-1;
        char ch1=' ',ch2=' ';
        while(i<j){
            if((s[i]>=65 and s[i]<=90) ){
                ch1=s[i]+32;
            }
            else if((s[i]>=97 and s[i]<=122) or (s[i]>=48 and s[i]<=57)){
                ch1=s[i];
            }
            else{
                ch1=' ';
                i++;
            }
            if((s[j]>=65 and s[j]<=90) ){
                ch2=s[j]+32;
            }
            else if((s[j]>=97 and s[j]<=122)or (s[j]>=48 and s[j]<=57)){
                ch2=s[j];
            }
            else{
                ch2=' ';
                j--;
            }
            if(ch1!=' ' and ch2!=' '){
                if(ch1!=ch2) return false;
                i++; j--;
            }
        }
        return true;
    }
};
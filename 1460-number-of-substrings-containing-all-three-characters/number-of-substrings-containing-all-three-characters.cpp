class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();

        //M2: optimal   
        int count=0;
        int la=-1, lb=-1, lc=-1;
        for(int i=0; i<n; i++){
            if(s[i]=='a') la=i;
            else if(s[i]=='b') lb=i;
            else lc=i;
            if(la!=-1 and lb!=-1 and lc!=-1) count+=min({la,lb,lc})+1;
        }
        return count;
    }
};
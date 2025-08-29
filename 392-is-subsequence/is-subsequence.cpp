class Solution {
public:
    bool isSubsequence(string s, string t) {
        string::iterator itt=s.begin();
        if(itt==s.end()) return true; //for empty string
        for(string::iterator it=t.begin(); it!=t.end(); it++){
            if(*it == *itt){
                itt++;
                if(itt==s.end()) return true;
            }
        }
        
        return false;
    }
};
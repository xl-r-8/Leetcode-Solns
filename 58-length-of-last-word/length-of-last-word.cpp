class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0; int lastcount=0;
        for(char ch: s){
            if(ch==' '){
                if(count>0)lastcount=count;
                count=0;
            }
            else count++;
        }
        lastcount= (count==0)? lastcount: count;
        return lastcount; 
    }
};
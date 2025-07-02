class Solution {
public:
    int possibleStringCount(string word) {
        int count=0;
        int ch=word[0];
        for(int i=1; i<word.size();i++){
            if(word[i]==ch){
                count++;
            }
            else{
                ch=word[i];
            }
        }
        count++;
        return count;
    }
};
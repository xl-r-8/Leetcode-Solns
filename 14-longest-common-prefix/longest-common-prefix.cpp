class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word=strs[0];
        for(int i=1; i<strs.size();i++){
            string commonWord="";
            int ind=-1;
            for(int k=0; k<strs[i].size();k++){
                char ch=strs[i][k];
                if(k!=ind+1) break;
                for(int j=0; j<word.size();j++){
                    
                    char chh=word[j];
                    if(ch==chh and k==j){
                        ind=k;
                        commonWord+=ch;
                        break;
                    }
                }
            }
            word=commonWord;
        }
        return word;
    }
};
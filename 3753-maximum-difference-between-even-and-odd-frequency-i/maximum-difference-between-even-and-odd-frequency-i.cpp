class Solution {
public:
    int maxDifference(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        for(char ch: s){
            freq[ch-'a']++;
        }
        int oddind=-1; int evenind=-1;

        for(int i=0; i<26;i++){
            if(freq[i]!=0 and freq[i]%2==0){
                if(evenind==-1)evenind=i;
                else{
                    if(freq[i]<freq[evenind])evenind=i;
                }
            }
            else{
                if(oddind==-1)oddind=i;
                else{
                    if(freq[i]>freq[oddind])oddind=i;
                }
            }
        }
        return freq[oddind]-freq[evenind];
    }
};     
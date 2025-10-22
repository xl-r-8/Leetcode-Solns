class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();

        //M1: brute
        // int count=0;
        // for(int i=0; i<n; i++){
        //     // vector<int> freq(3,0);
        //     unordered_map<char, int> mp;
        //     for(int j=i; j<n; j++){
        //         char ch=s[j];
        //         mp[ch]++;
        //         if(mp.size()==3) count++;
        //     }
        // }
        // return count;

        //M2: optimal   
        int count=0;
        int la=-1, lb=-1, lc=-1;
        for(int i=0; i<n; i++){
            if(s[i]=='a') la=i;
            else if(s[i]=='b') lb=i;
            else lc=i;
            if(la!=-1 and lb!=-1 and lc!=-1) count+=min({la,lb,lc})+1;
            //redundant if condition, coz agar if nahi bhi lagaya and koi -1 hua toh min usko select karke +1 add kardega so resultant 0 hee add ho raha hoga
        }
        return count;
    }
};
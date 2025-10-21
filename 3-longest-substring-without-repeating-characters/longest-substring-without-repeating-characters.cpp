class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        //M1: brute force
        int i=0, j;
        int maxlen=0;
        while(i<n){
            vector<int> freq(256, -1);
            j=i;
            while(j<n){//substr starting from index i
                char ch=s[j];
                if(freq[ch]!=-1){
                    j--;
                    break;
                }
                freq[ch]=1;
                j++;
            }
            if(j==n) j--;
            maxlen=max(maxlen,j-i+1);
            i++;
        }
        return maxlen;

        //M2: optimal soln, it was always the most optimal one, the mp.find was the only thing holding it back  
        // vector<int> freq(256, -1);//freq[ch]=-1 means first appearance of ch, otherwise ch has appeared before
        // // unordered_map<char, int> mp;
        // if(n==0) return 0;
        // int l=0, r; 
        // int maxlen=0;     
        // for(int i=0; i<n; i++){
        //     char ch=s[i]; r=i;
        //     if(freq[ch]==-1){
        //         freq[ch]=i;
        //     }
        //     else{
        //         int prevind=freq[ch];
        //         freq[ch]=i;//update prevind of ch which is independent of updation of l
        //         if(prevind>=l){
        //             l=prevind+1;
        //         }
        //     }
        //     maxlen=max(maxlen,r-l+1);

        //     // auto it=mp.find(ch);
        //     // if(it==mp.end()){
        //     //     mp[ch]=i;
        //     // }
        //     // else{
        //     //     int prevind=mp[ch];
        //     //     mp[ch]=i;//update prevind of ch independent of l
        //     //     if(prevind>=l){
        //     //         l=prevind+1;
        //     //     }
        //     // }
        //     // maxlen=max(maxlen,r-l+1);
        //     // cout<<i<<" "<<l<<" "<<r<<" "<<maxlen<<endl;
        // }
        // return maxlen;
    }
};

//why am i here? 
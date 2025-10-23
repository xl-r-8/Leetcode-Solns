class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        if(n==0) return 0; 

        //M1: brute
        // int maxlen=1; //atleast 1 char substring toh you will get which will have the same char for any fucking k
        // for(int i=0; i<n; i++){
        //     int count=0;
        //     char ch=s[i]; 
        //     int window=1;// size of current window
        //     for(int j=i+1; j<n; j++){ //check on the right of ch
        //         if(s[j]!=ch) count++;
        //         if(count>k) break;
        //         window++;
        //     }
        //     for(int j=i-1; j>=0; j--){//check on the left of ch
        //         if(s[j]!=ch) count++;
        //         if(count>k) break;
        //         window++;
        //     }
        //     maxlen=max(maxlen, window);
        // }
        // return maxlen;

        //M1: diff brute

        //M2: better
        // vector<int> freq(26,0); 
        // int l=0, r=0;
        // int maxfreq=0, maxlen=0;

        // while(r<n){
        //     char ch=s[r];
        //     freq[ch-'A']++;
        //     if(freq[ch-'A']>maxfreq)maxfreq=freq[ch-'A'];
        //     int len=r-l+1;
        //     int minchanges=0;
        //     while(minchanges>k){ //=> shrink window by 1 place
        //         char ch2=s[l];
        //         freq[ch2-'A']--;
                 
        //         l++;
        //     }
        //     if(minchanges<=k){
        //         maxlen=max(maxlen, len);
        //     }
        //     r++;
        // }
        // return maxlen;

        //M3: optimal
        vector<int> freq(26,0); 
        int l=0, r=0;
        int maxlen=0;

        while(r<n){
            char ch=s[r];
            freq[ch-'A']++;
            // if(freq[ch-'A']>maxfreq)maxfreq=freq[ch-'A'];//this is wrong
            int maxfreq=0;
            for(int ele: freq){
                maxfreq=max(maxfreq, ele);
            }
            int len=r-l+1;
            int minchanges=len-maxfreq;
            if(minchanges<=k){
                maxlen=max(maxlen, len);
            }
            else{ //if(minchanges>k) => shrink window by 1 place
                char ch2=s[l];
                freq[ch2-'A']--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};
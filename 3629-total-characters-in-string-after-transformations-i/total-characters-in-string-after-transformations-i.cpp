class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // unordered_map<char,long long> mp;
        long long mod=1000000007;
        vector<long long> freq(26,0);
        for(char ch: s){
            // mp[ch]++;
            freq[ch-'a']++;
        }
        for(int k=1; k<=t;k++){
            // unordered_map<char,long long> temp = mp; 
            // for (auto it = temp.begin(); it != temp.end(); ++it) {
            //     int code=it->first;// or int code= (int)it->first;
            //     mp[(char)code]-=it->second%1000000007;
            //     if(code<122){
            //         mp[(char)(code+1)]+=it->second%1000000007;
            //     }
            //     else{
            //         mp['a']+=it->second%1000000007;
            //         mp['b']+=it->second%1000000007;
            //     }
            // }
            vector<long long> temp=freq;
            for(int i=0; i<26;i++){
                // if(temp[i] ==0)continue;
                freq[i]-=temp[i]%mod;
                if(i<25){
                    freq[i+1]+=temp[i]%mod;
                }
                else{
                    freq[0]+=temp[i]%mod;
                    freq[1]+=temp[i]%mod;
                }
            }
        }
        long long sum=0;
        // for (auto it = mp.begin(); it != mp.end(); ++it) {
        //     sum+=it->second;
        // }
        for(long long ele: freq){
            sum+=ele%mod;
        }
        return sum%mod;
    }
};
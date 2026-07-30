class Solution {
public:
    int minimumPushes(string word) {
        //what brute force could be? maybe through recursion, idk.
        //but my approach is to map the first 8 most frequent chars as 1st place in keys, then the next 8 as 2nd and then next 8 as 3rd and remaining 2 as 4th
        //TC = O(nlogn), SC = O(n), idk if its the most optimal, or if its the brute force
        
        vector<int> freq(26, 0);
        for(char ch: word){
            freq[ch-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0; 
        // for(int ele: freq) cout<<ele<<" ";
        // cout <<endl;
        for(int i = 0; i<26; i++){
            ans += freq[i] * (1 + i/8);
            // num of chars * num of keypresses for 1 char
        }

        return ans;
    }
};
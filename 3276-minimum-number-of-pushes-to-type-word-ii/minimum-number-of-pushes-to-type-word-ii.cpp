#include <algorithm>
class Solution {
public:
    int minimumPushes(string word) {
       /* map<char, int, greater<int>>  mp;
        int i=0; //to count unique characters
        // int count=0;
        for(char c: word){
            ++mp[c];
        }       
        // for(pair<char,int> p:mp){
        //     count+=p.second*(i/8+1);
        //     i++;
        // }
        // return count;
        int totalPushes = 0;
        int presses = 1;
        int keysUsed = 0;

        // Iterate through the frequencies in the map
        for (const auto& p : mp) {
            totalPushes += p.second * presses; // Count pushes for this character
            keysUsed++;

            // If 8 keys have been used, move to the next press count
            if (keysUsed%8 == 0) {
                // keysUsed = 0;  // Reset key usage
                presses++;      // Increment presses needed for the next characters
            }
        }

        return totalPushes;*/
        int ans=0;
        vector<int> freq(26,0); // frequenct calculated
        for(auto it: word){
            freq[it-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>()); // sort frequency in decreasing order
        for(int i=0;i<26;i++){
            if(i<8){
                ans+= freq[i]; // map at first positon of all keys
            }
            else if(i<16){
                ans+= freq[i]*2; // map with second position of all keys
            }else if(i<24){
                ans+= freq[i]*3; // map with third position all keys
            }
            else ans+= freq[i]*4; // map with fourth position of all keys
        
        }
        return ans;
    }
};
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> stoArray;
        unordered_map<char,string> mp;
        unordered_map<string,int> seen;

        string val = "";

        s.push_back(' ');

        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                val += s[i];
            }
            else if(s[i] == ' '){
                stoArray.push_back(val);
                val = "";
            }
        }

        if(pattern.size() != stoArray.size())
            return 0;
        
        for(int i=0;i<pattern.size();i++){
            if(mp.find(pattern[i]) == mp.end()){
                if(seen.size() > 0){
                    if(seen.find(stoArray[i]) != seen.end()){
                        return 0;
                    }else if(seen.find(stoArray[i]) == seen.end()){
                        seen[stoArray[i]]++;
                    }
                }
                mp[pattern[i]] = stoArray[i];
                seen[stoArray[i]]++;
            }else if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != stoArray[i])
                    return 0;
            }
        }
        return 1;
    }
};
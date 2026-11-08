class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans; 

        string u = "";
        string v = "";

        int n = s1.size();

        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]){
                u += s1[i];
                v += s2[i];
            }
            else{
                if(u.empty()) continue;
                ans.push_back({u, v});
                u = "";
                v = "";
            }
        }
        
        if(!u.empty()) ans.push_back({u, v});

        return ans;
        
    }
};
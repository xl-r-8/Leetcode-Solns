class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int current = -1;
        vector<string> ans;
        int n=groups.size();
        for(int i=0; i<n; i++){
            if(groups[i]!=current){
                ans.push_back(words[i]);
                current=groups[i];
            }
        }
        return ans;
    }
};
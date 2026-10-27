class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=1; i<=m; i++){
            string s = "";
            for(int j=0; j<n; j++){
                if(i == m) s+='.';
                else{
                    if(j == 0) s+='.';
                    else s+='#';
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};
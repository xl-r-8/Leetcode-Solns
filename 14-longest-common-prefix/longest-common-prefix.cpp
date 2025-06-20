bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b; // lexicographical if lengths match
    return a.size() < b.size(); // shorter string comes first
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        sort(v.begin(), v.end());
        string first=v[0]; int sz=first.size();
        int ind=200; //Max length of string is 200
        for(int i=1; i<v.size(); i++){
            string s=v[i];
            for(int j=0; j<sz; j++){
                if(j>ind) break;
                if(j>=s.size()){
                    ind=min(ind, j-1);
                    break;
                }
                if(first[j]!=s[j]){
                    ind=min(ind, j-1);//i.e. upto j-1th index both strings are same
                    if(ind==-1) return "";
                } 
            }
        }
        string ans=first.substr(0, ind+1); // starts at index 0, length i
        return ans;
    }
};
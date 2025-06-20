bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b; // lexicographical if lengths match
    return a.size() < b.size(); // shorter string comes first
}
class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        // sort(v.begin(), v.end(),cmp);//compare by size first and then lexicographically
        sort(v.begin(), v.end());//compare lexicographically
        int n=v.size();
        string first=v[0]; 
        int ind=200; //Max length of string is 200
        // for(int i=v.size()-1; i>=1; i--){ //start from the last, when comparing lexicographically to get the max difference and hence the min prefix, yk what compare with last only coz that will only differ the most hence min prefix can be obtained by finding whats common b/w first and last
        string last=v[n-1];
        for(int j=0; j<first.size(); j++){
            if(j>ind) break;
            if(j>=last.size()){
                ind=min(ind, j-1);
                break;
            }
            if(first[j]!=last[j]){
                ind=min(ind, j-1);//i.e. upto j-1th index both strings are same
                if(ind==-1) break;
            } 
        }

        string ans=first.substr(0, ind+1); // starts at index 0, length i
        return ans;
    }
};
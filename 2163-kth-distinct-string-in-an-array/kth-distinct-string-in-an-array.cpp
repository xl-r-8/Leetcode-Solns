class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(string s: arr){
            ++mp[s];
        }
        int i=1;
        for(string s:arr){
            if(mp[s]==1){
                if(i==k){
                    return s;
                }
                i++;
            }
        }
        return "";
    }
};
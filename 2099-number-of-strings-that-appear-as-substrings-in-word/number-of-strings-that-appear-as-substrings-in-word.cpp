class Solution {
public:
    bool sub(string &a, string &b){
        int m=a.size(), n= b.size();
        // "tyvqahvzoorg"
        // oorg  org
        for(int i=0; i<m; i++){
            bool found = true; int k=i;
            for(int j=0; j<n; j++){
                if(k>=m or a[k] != b[j]){
                    found = false;
                    break;
                }
                k++;
            }
            if(found)return true;
        }

        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(string s: patterns){
            if(sub(word, s)) {
                // cout<< s<<" "<< word<<endl;
                count++;
            }
        }
        return count;
    }
};
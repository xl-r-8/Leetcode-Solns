class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        //M1: TC= O(2nlogn+n)=O(nlogn)
        // if(target.size()!=arr.size()) return false;
        // sort(target.begin(),target.end());
        // sort(arr.begin(),arr.end());
        // for(int i=0; i<target.size();i++){
        //     if(target[i]!=arr[i]){
        //         return false;
        //     }
        // }
        // return true;

        //M2: TC: O(n)
        if(target.size()!=arr.size()) return false;
        unordered_map<int,int> mp;
        for(int i=0;i<target.size();i++){
            ++mp[target[i]];
        }
        for(int i=0;i<target.size();i++){
            --mp[arr[i]];
        }
        for(pair<int,int> p: mp){
            if(p.second>0) return false;
        }
        return true;


    }
};
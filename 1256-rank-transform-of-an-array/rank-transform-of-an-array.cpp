class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        int n = arr.size();
        vector<int> ranks(n);
        if(n==0) return ranks;
        unordered_map<int, int> mp;
        mp[temp[0]] = 1;
        for(int i = 1; i<n; i++){
            if(mp.find(temp[i]) != mp.end()) continue;
            mp[temp[i]] = mp[temp[i-1]] + 1;
        }
        for(int i = 0; i<n; i++){
            ranks[i] = mp[arr[i]];
        }
        return ranks;
    }
};
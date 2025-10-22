class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int l=0, r=0;
        int maxlen=0, k=2;
        unordered_map<int,int> mp;
        while(r<n){
            int ele=fruits[r];
            mp[ele]++;
            if(mp.size()>k){
//the issue is how do you keep count in set
//and if you cant keep count in set then how would you remove ele from set???
                int ele2=fruits[l];
                mp[ele2]--;
                if(mp[ele2]==0) mp.erase(ele2);
                l++;
            }
            if(mp.size()<=k)maxlen=max(maxlen, r-l+1); //only consider its length if its a valid window, but its a redundant if condition coz even if you dont check it then upar waala if ensures that window stays at maxlen(which was the max size of a valid window previously found)
            r++;
        }
        return maxlen;
    }
};
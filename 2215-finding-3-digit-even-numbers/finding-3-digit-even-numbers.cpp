class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        for(int ele: digits) mp[ele]++;
        vector<int> ans;
        int i=100;
        while(i<=998){
            int h=i/100;// eg: i=230 => h=2
            if(mp[h]==0){
                i=(h+1)*100;
                continue;
            }
            int t=(i-100*h)/10; //eg: (235-200)/10=3
            if(mp[t]==0){
                i=h*100 + (t+1)*10; //eg: 200+40=240
                continue;
            }

            int o=i-100*h-10*t; //eg: 235-200-30=5
            if(mp[o]==0 or o%2==1){
                if(o%2) i++;
                else i+=2;
                continue;
            }
            // Check if the digits are not overused
            mp[h]--; mp[t]--; mp[o]--;
            if(mp[h] >= 0 && mp[t] >= 0 && mp[o] >= 0) {
                ans.push_back(i);
            }
            mp[h]++; mp[t]++; mp[o]++;
            i += 2; // only even numbers
        }
        return ans;
    }
};
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){ //spaces around operators, except i++
            mp[nums[i]]++;
        }
        int mxcnt = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            int cnt = 0;
            long long ele = it->first;
            while(ele <= 1e9){
                if(ele == 1){
                    if(mp[ele] % 2 == 0) cnt += mp[ele]-1;
                    else cnt += mp[ele];
                    break;
                }
                if(mp.find(ele) == mp.end()){//0 count of ele in mp
                    if(cnt%2 == 0) cnt--; //coz x^k doesnt exist and if we have even count then that means we counted x^(k/2) 2 times
                    break; 
                } 
                if(mp[ele] == 1){//1 count
                    cnt++;
                    break;
                }
                //2 or more count
                cnt += 2;
                ele = ele*ele;
            }
            if(cnt % 2 == 0) cnt--;
            mxcnt = max(mxcnt, cnt);
        }
        return mxcnt;
    }
};
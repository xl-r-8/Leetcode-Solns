class Solution {
public:
    static bool comparator(pair<int, int>& a, pair<int, int>& b){
        if(a.first!=b.first) return a.first<b.first;
        else{ //if(a.first==b.first)
            return a.second<b.second;
        }
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int, int>> mp;
        for(int i=0; i<n; i++){
            pair<int,int> p;
            p.first=nums[i];
            p.second=i;
            mp.push_back(p);
        }
        sort(mp.begin(), mp.end(), comparator);
        vector<int> ans;
        // cout<<p1.second<<" "<<p2.first<<endl;
        int i=0, j=n-1;
        while(i<j){
            pair<int, int>p1=mp[i];
            pair<int, int> p2=mp[j];
            if(p1.first+p2.first==target){
                ans.push_back(p1.second);
                ans.push_back(p2.second);
                break;
            }
            else if(p1.first+p2.first<target) i++;
            else{ //(p1.first+p2.first>target)
                j--;
            }
        }
        return ans;
    }
};
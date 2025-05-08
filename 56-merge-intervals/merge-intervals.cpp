class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        int start=intervals[0][0],end=intervals[0][1]; bool merge=false;
        for(int i=0; i<n; i++){
            if(i!=n-1){
                if(end>=intervals[i+1][0]){
                    merge=true;
                    end=max(end,intervals[i+1][1]);
                }
                else{
                    merge=false;
                    ans.push_back({start, end});
                    start=intervals[i+1][0];
                    end=intervals[i+1][1];
                }
            }
            else{
                // if(!merge){
                //     end=intervals[i][1];
                // }
                ans.push_back({start, end});
            }
        }
        return ans;
    }
};
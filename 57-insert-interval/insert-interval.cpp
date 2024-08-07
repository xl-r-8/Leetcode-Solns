// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int i=0; int n=intervals.size();
//         vector<vector<int>> ans;
//         while(i<n and newInterval[0]>intervals[i][1]){
//             ans.push_back(intervals[i]);
//             i++;
//         }
//         int min=(newInterval[0]<=intervals[i][0])?newInterval[0]:intervals[i][0];
//         int max=newInterval[1];
//         while(i<n and newInterval[1]>=intervals[i][0]){
//             if(intervals[i][1]>max) max=intervals[i][1];
//             i++;
//         }
//         ans.push_back({min,max});
//         while(i<n ){
//             ans.push_back(intervals[i]);
//             i++;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        int newStartTime = newInterval[0];
        int newEndTime = newInterval[1];

        //Step 1
        while(i < n && intervals[i][1] < newStartTime){
            result.push_back(intervals[i]);
            i++;
        }
        
        //Step 2
        while(i < n && intervals[i][0] <= newInterval[1]){
            newStartTime = min(intervals[i][0], newStartTime);
            newEndTime = max(intervals[i][1], newEndTime);
            i++;
        }

        //Step 3
        result.push_back({newStartTime, newEndTime});

        //Step 4
        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }

        //Step 5
        return result;
    }
};
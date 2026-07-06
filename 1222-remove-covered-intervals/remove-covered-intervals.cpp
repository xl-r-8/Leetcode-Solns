class Solution {
public:
    static bool comparator(vector<int>& a, vector<int> &b){
        if(a[0] != b[0]) return a[0] < b[0]; 
        else return a[1]  > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        int n = intervals.size();
        int count = n;

        //but what if: { [1 4], [2 8], [3 6], [4 7]}
        vector<int> u = intervals[0]; 
        for(int i =1; i<n; i++){
            vector<int> v = intervals[i];
            if(u[0]<=v[0] and v[1]<=u[1]) count--;
            else u = v; 
        }
        return count;
    }
};
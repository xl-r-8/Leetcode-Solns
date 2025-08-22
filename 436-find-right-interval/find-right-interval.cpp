bool comparator(vector<int>&a, vector<int>&b){
    return a[0]<b[0];
}

int f_ind(int end, vector<vector<int>>& sortedv){
    int n=sortedv.size();
    int low=0; int high=n-1;
    while(low<high){
        int mid= (low+high)/2;
        if(sortedv[mid][0]>=end) high=mid;
        else low=mid+1;
    }
    if(sortedv[high][0]>=end) return sortedv[high][2];
    else return -1;
}


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> sortedv=intervals;
        for(int i=0; i<n; i++){
            sortedv[i].push_back(i);
        }
        sort(sortedv.begin(), sortedv.end(), comparator);
        vector<int> ans;

        for(int i=0; i<n; i++){
            int end=intervals[i][1];
            int ind=f_ind(end,sortedv);
            ans.push_back(ind);
        }

        return ans;
    }
};
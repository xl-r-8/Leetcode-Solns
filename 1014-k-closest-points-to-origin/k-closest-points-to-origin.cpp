bool comparator(vector<double> &a, vector<double> &b){
    return a[2]<b[2];
}

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<double>> d; int n=points.size();
        for(int i=0; i<n; i++){
            double x=points[i][0]; double y=points[i][1];
            double dist=sqrt( x*x + y*y);
            d.push_back({x,y,dist});
        }
        sort(d.begin(), d.end(), comparator);
        for(auto i:d){
           cout<<i[0]<<"->"<<i[1]<<"->"<<i[2];
           cout<<endl;
           
        }
        vector<vector<int>> ans;
        for(int i=0; i<k; i++){
            ans.push_back({(int)d[i][0], (int)d[i][1]});
        }
        return ans;
    }

};
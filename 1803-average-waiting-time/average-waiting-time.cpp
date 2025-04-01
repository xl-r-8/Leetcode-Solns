// bool comparator(vector<int> a, vector<int> b){
//     return a[1]<b[1];
// }

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        // sort(customers.begin(),customers.end(),comparator);
        int currentTime=0;
        double wt=0;
        for(vector<int> v: customers){
            if(currentTime<=v[0]){
                currentTime=v[0]+v[1];//current time=arrival time+time for completion
                wt+=currentTime-v[0];
            }
            else{
                currentTime+=v[1];
                wt+=currentTime-v[0];
            }
        }
        return wt/customers.size();
    }
};
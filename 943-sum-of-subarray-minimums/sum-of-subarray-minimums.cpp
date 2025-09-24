class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> rnse(n); //we just need ind
        rnse[n-1]=n;
        vector<int> lnse(n);
        lnse[0]=-1;
        stack<int> s;
        //rnse
        s.push(n-1);
        for(int i=n-2; i>=0; i--){
            int ind=s.top();
            int ele=arr[ind];
            if(arr[i]>=ele){
                rnse[i]=ind;
                s.push(i);
            }
            else{
                while(!s.empty()){
                    int id=s.top();
                    int el=arr[id];
                    if(arr[i]>=el){
                        rnse[i]=id;
                        s.push(i);
                        break;
                    }
                    else s.pop();
                }
                if(s.empty()){
                    rnse[i]=n;
                    s.push(i);
                }
            }
        }

        //lnse
        stack<int> s2;
        s2.push(0);
        for(int i=1; i<n; i++){
            int ind=s2.top();
            int ele=arr[ind];
            if(arr[i]>ele){
                lnse[i]=ind;
                s2.push(i);
            }
            else{
                while(!s2.empty()){
                    int id=s2.top();
                    int el=arr[id];
                    if(arr[i]>el){
                        lnse[i]=id;
                        s2.push(i);
                        break;
                    }
                    else s2.pop();
                }
                if(s2.empty()){
                    lnse[i]=-1;
                    s2.push(i);
                }
            }
        }

        // int total=0;
        // int mod = 1e9+7;
        // for(int i=0; i<n; i++){
        //     int contrii= arr[i]*(i-lnse[i])*(rnse[i]-i);
        //     cout<<i<<" "<<lnse[i]<<" "<<rnse[i]<<" "<<contrii<<endl;
        //     total=(total+contrii)%mod;
        // }
        // return total;

        long long total = 0;
        int mod = 1e9+7;
        for (int i = 0; i < n; i++) {
            long long left = i - lnse[i];
            long long right = rnse[i] - i;
            long long contrib = ((left * right) % mod * arr[i]) % mod;
            total = (total + contrib) % mod;
        }
        return (int)total;
    }
};
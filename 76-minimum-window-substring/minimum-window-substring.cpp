class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(); int m=t.size();

        //M1: brute
        // vector<int> freq(256,0);
        // for(int i=0; i<m; i++){
        //     int chind=t[i];//index of character t[i], eg if t[i]=A then chind=65
        //     freq[chind]++;
        //     // cout<<chind<<" ";
        // }
        // int minlen=n+1; int startIndex=0; string ans="";
        // for(int i=0; i<n; i++){
        //     vector<int> temp=freq;
        //     int count=0;
        //     for(int j=i; j<n; j++){
        //         int chind2=s[j];
        //         temp[chind2]--;
        //         if(temp[chind2]>=0) count++;
        //         if(count==m){
        //             if(j-i+1<minlen){
        //                 minlen=j-i+1;
        //                 startIndex=i;
        //                 // cout<<startIndex<<" "<<minlen<<endl;
        //                 //ans=s.substr(i, minlen);
        //                 //ofc yeh har baar O(minlen) TC lega and if minlen N ke aas paas hoga then yeh soln O(n^3) tak chale jayega
        //             }
        //         }
        //     }
            
        // }
        // if(minlen<n+1) ans=s.substr(startIndex, minlen);
        // return ans;

        //M2: optimal
        int l=0, r=0; 
        vector<int> freq(256,0);
        for(int i=0; i<m; i++){
            int chind=t[i];//index of character t[i], eg if t[i]=A then chind=65
            freq[chind]++;
            // cout<<chind<<" ";
        }
        int minlen=n+1; int startIndex=0; string ans="";
        int count=0;

        while(r<n){
            int chind2=s[r];
            freq[chind2]--;
            if(freq[chind2]>=0) count++;
            while(count==m){
                minlen=min(minlen, r-l+1);
                if(minlen==r-l+1) startIndex=l;//the only diff that would come here from using if like this is that we are going to get the latter min substring instead of the former one, in the M1 way of using if we would get the former substr if the size of both former and latter are equal.
                int chind3=s[l];
                freq[chind3]++;
                if(freq[chind3]>0) count--;
                l++;
            }
            r++;
        }
        if(minlen<n+1)ans=s.substr(startIndex, minlen);
        return ans;

    }
};
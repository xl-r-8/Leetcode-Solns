class Solution {
public:
    vector<string> divideString(string &s, int k, char fill) {
        auto [q, r]=div(s.size(), k); //q=quotient and r=remainder
        vector<string> ans(q+(r>0)); //size of ans=q when r is 0 otherwise size=r+1
        // s = "abcdefghij", k = 3, fill = "x"
        for (int i=0; i<q; i++){
            ans[i]=s.substr(i*k, k);
        }
        //ans=["abc","def","ghi"]
        if (r>0){
            ans.back()=s.substr(q*k,s.size()-q*k);//or simply s.substr(q*k), it will create a substring from index=q*k to the last index => ans=["abc","def","ghi","j"]
            ans.back()+=string(k-r, fill);//ans=["abc","def","ghi","jxx"]
        }
        return ans;
    }
};
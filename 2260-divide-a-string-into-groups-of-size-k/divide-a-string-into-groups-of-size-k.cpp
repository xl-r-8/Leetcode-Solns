class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int count=k; vector<string> ans; string temp="";
        for(int i=0; i<s.size();i++){
            temp+=s[i];
            count--;
            if(count==0){
                ans.push_back(temp);
                count=k;
                temp="";
            }
        }
        while(count>0 and count!=k){
            temp+=fill;
            count--;
            if(count==0){
                ans.push_back(temp);
                // count=k; //if i reset the count each time it reaches 0 then while loop will never end
                // temp="";
            }
        }
        return ans;
    }
};
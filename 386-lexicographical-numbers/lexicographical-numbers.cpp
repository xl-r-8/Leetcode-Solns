void rec(int i, int n, vector<int> & ans){
    if(i>n) return;
    ans.push_back(i);
    rec(i*10,n,ans);
    if(i+1>n or (i+1)%10==0)return;
    rec(i+1,n,ans);
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        // rec(1,n,ans);
        // return ans;

        int count=1;
        for(int i=1; i<=n;i++){
            ans.push_back(count);
            if(count*10<=n){
                count=count*10;
            }
            else{
                //after completing 101-109 you definitely dont want to go back to 10 coz it will start the same loop again, 10->100->101->...->109->10->100..., so we will add a 1 and go to 11 instead of 10
//but if its 19->191->...199->20->200->201... see we missed the 2

                if(count+1> n  or (count+1)%10==0){
                    count = 1 + count/10;
                    while(count%10==0) {
                        count =  count/10;
                    }
                } 
                else count++;
            }
        }
        return ans;

    }
};
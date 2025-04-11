class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        string lows=to_string(low);
        string highs=to_string(high);
        int ans=0;
        if(low>high) return ans;
        if(lows.size()%2==1 and lows.size()==highs.size()) return ans;

        for(int i=low;i<=high; i++){
            string is=to_string(i);
            if(is.size()%2==0){
                int a=0; int b=is.size()-1;
                int s1=0, s2=0;
                while(a<b){
                    s1+=is[a] - '0';
                    s2+=is[b] - '0';
                    a++; b--;
                }
                if(s1==s2) ans++;
            }
        }
        return ans;

    }
};
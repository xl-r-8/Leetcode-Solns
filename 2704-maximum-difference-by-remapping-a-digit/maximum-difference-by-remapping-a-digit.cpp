class Solution {
public:
    int minMaxDifference(int num) {
        // if(num==0) return 9;
        string s = to_string(num); // n="12345"=> '1' - '0' = 1
        int firstNon9=-1; int firstNon0=-1;
        for(char ch: s){
            if(firstNon9!=-1 and firstNon0!=-1) break;
            if(ch!='9'){
                if(firstNon9==-1)firstNon9= ch-'0';
            } 
            if(ch!='0'){
                if(firstNon0==-1) firstNon0= ch-'0';
            }
        }

        vector<int> maxarr;
        vector<int> minarr;
        int maxm=0; int minm=0; 
        int temp=num;
        while(temp){
            int digit=temp%10; temp=temp/10;
            if(firstNon9==-1){
                maxm=num;
                break;
            }
            if(digit==firstNon9){
                maxarr.push_back(9);
            } 
            else {
                maxarr.push_back(digit);
            }
        }
        temp=num;
        while(temp){
            int digit=temp%10; temp=temp/10;
            if(firstNon0==-1){
                minm=num;
                break;
            }
            if(digit==firstNon0){
                minarr.push_back(0);
            } 
            else {
                minarr.push_back(digit);
            }
        }


        for(int i=maxarr.size()-1; i>=0; i--){
            if(firstNon9!=-1)maxm= maxm*10 + maxarr[i];
            if(firstNon0!=-1)minm= minm*10 + minarr[i];
        }
        return maxm - minm;
    }
};
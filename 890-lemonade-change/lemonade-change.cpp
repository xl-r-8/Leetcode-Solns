class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // sort(bills.begin(),bills.end()); 
        int c5=0,c10=0,c20=0; //c means counter
        for(int i=0; i<bills.size();i++){
            if(bills[i]==5) c5++;//to return change=0 dollars
            else if(bills[i]==10){//to return change=5 dollars
                if(c5==0) return false;
                c5--;c10++;
            }
            else //if(bills[i]==20){//to return change=15 dollars
            {   //It is preferable to give one $10 and one $5 bill as change if possible ,because this leaves us with more $5 bills for future transactions
                if(c10>=1 and c5>=1){
                    c5--;c10--;c20++;
                }
                else if(c5>=3){
                    c5-=3;c20++;
                }
                else return false;
            }
            
        }
    return true;
    }
};
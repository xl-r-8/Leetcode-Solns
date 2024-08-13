class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n);
        candies[0]=1;
        for(int i=1; i<n;i++){
            if(ratings[i]>ratings[i-1]) candies[i]=candies[i-1]+1;
            else candies[i]=1;
        }
        for(int i=n-2; i>=0;i--){
            if(ratings[i]>ratings[i+1] and candies[i]<=candies[i+1]) candies[i]=candies[i+1]+1;
        }
        int sum=0;
        for(int j=0; j<n;j++) sum+=candies[j];

        return sum;
    }
};
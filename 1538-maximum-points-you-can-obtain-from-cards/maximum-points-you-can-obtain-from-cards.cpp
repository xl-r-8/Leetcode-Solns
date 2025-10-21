class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();

        int sum=0;
        for(int i=0; i<k; i++){
            sum+=cardPoints[i];
        }
        
        int mxsum=sum;
        int l=k-1, r=n-1; 
        while(l>=0){
            sum-=cardPoints[l];
            l--;
            sum+=cardPoints[r];
            r--;
            mxsum=max(mxsum,sum);
        }
        return mxsum;
    }
};
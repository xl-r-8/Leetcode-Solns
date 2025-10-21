class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();

        //M1
        // int sum=0;
        // for(int i=0; i<k; i++){
        //     sum+=cardPoints[i];
        // }
        
        // int mxsum=sum;
        // int l=k-1, r=n-1; 
        // while(l>=0){
        //     sum-=cardPoints[l];
        //     l--;
        //     sum+=cardPoints[r];
        //     r--;
        //     mxsum=max(mxsum,sum);
        // }
        // return mxsum;

        //M2
        int total=0;
        for(int i=0; i<n; i++){
            total+=cardPoints[i];
        }

        int mnsum=total;
        int sum=0;
        for(int i=0; i<n-k; i++){
            sum+=cardPoints[i];
        }
        mnsum=min(mnsum, sum);

        int l=0, r=n-k;
        while(r<n){
            sum-=cardPoints[l];
            l++;
            sum+=cardPoints[r];
            r++;
            mnsum=min(mnsum, sum);
        }
        
        return total-mnsum;
    }
};
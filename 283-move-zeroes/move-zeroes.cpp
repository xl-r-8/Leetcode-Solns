class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0; int j=-1;
        while(i<n){
            if(nums[i]==0){
                if(j==-1)j=i;
            }
            else{
                if(j!=-1 and i>j){
                    swap(nums[j],nums[i]);
                    j++;
                }
            }
            i++;
        }
        
        //sunn rishu, you need not move j ptr coz i is already checking 0 and non 0 eles, and to check for 2 states you need max 1 num, and in this case worst TC=O(2n). instead of using j as pointer you can use j as a state and save the 1st index of 0 and just move pointer i, which will ensure TC=O(n).
        //iske notes mein suppose karna that you have k contiguous 0s, and j is the index of 1st 0. 2 cases: C1: k>1 ke liye dekhna j aur i mein swapping kab hoti hai and swap hone ke baad ptrs kaise move karte hai, watch the same for C2
    }
};
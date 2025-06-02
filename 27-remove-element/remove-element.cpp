// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int count=0;
//         int n=nums.size();
//         int i=0; int j=n-1;
//         // if(nums.size()==0) return 0;
//         while(i<=j){
//             while(j>=0 and nums[j]==val){
//                 count++;
//                 j--;
//             }
//             while(i<n and nums[i]!=val){
//                 i++;
//             }
//             if(i>j or i>=n or j<0){
//                 break;
//             }
//             count++;//nums[i]==val
//             nums[i]=nums[j];
//             i++; j--;
//         }
//         // cout<<"count:"<<count<<endl;
//         return n-count;
//     }
// };

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};
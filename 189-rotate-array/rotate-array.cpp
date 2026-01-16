class Solution {
public:
    void rev(vector<int>& nums, int i, int j){
        while(i<j){
            swap(nums[i],nums[j]);
            i++; j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        rev(nums, 0, n-1);
        rev(nums, 0, ((k)%n-1)%n);//(k%n-1)=(k%n-1%n)=(k-1)%n
        rev(nums, (k)%n, n-1);
    }
};
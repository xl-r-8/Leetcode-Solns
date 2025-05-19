class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0]; int b=nums[1]; int c=nums[2];
        if(a+b<=c or b+c<=a or a+c <= b) return "none";
        if(a==b and b==c ) return "equilateral";
        if(a==b or b==c or a==c) return "isosceles";
        return "scalene";
    }
};
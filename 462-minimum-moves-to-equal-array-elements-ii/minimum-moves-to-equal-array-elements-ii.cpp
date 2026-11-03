class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //Level 1: learn implementation of quickselect and know that median minimizes abs dist whereas mean minimizes squared dist
        //Level 2: To Learn exactly why quickselect is implemented this way and measure of central tendency with proofs

        auto mid = nums.begin() + nums.size() / 2;
        ranges::nth_element(nums, mid);
        int med = *mid, moves = 0;
        for (int x : nums) moves += abs(x - med);
        return moves;
    }
};
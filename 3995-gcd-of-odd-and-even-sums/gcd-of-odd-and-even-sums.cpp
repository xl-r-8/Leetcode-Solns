class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // The first n odd numbers sum to n * n
        // Hint 2
        // First n even numbers sum to n * (n + 1)
        // Hint 3
        // gcd(n, n + 1) = 1, so the answer is n
        return n;
    }
};
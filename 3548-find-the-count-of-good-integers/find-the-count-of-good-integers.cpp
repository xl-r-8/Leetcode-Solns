#include <bits/stdc++.h>
using namespace std;

// ✅ Check if a number is palindrome
bool isPalindrome(long long x) {
    if (x < 0) return false;
    long long n = x, m = 0;
    while (n > 0) {
        m = m * 10 + n % 10;
        n /= 10;
    }
    return m == x;
}

// ✅ Precomputed factorials to speed up permutation counts
vector<long long> fact(20, 1);
void precomputeFactorials() {
    for (int i = 1; i < 20; ++i) {
        fact[i] = fact[i - 1] * i;
    }
}

// ✅ Create a unique key for a digit frequency vector
string getKey(const vector<int>& freq) {
    string key = "";
    for (int i = 0; i < 10; ++i) {
        key += to_string(freq[i]) + "#";
    }
    return key;
}

// ✅ Count valid permutations of digits (excluding ones starting with 0)
long long countPermutations(const vector<int>& freq, int n) {
    long long total = fact[n];
    for (int i = 0; i < 10; ++i)
        total /= fact[freq[i]];

    // Remove permutations that start with 0
    if (freq[0] > 0) {
        vector<int> temp = freq;
        temp[0]--;  // assume 0 is leading, fix the rest
        long long invalid = fact[n - 1];
        for (int i = 0; i < 10; ++i)
            invalid /= fact[temp[i]];
        total -= invalid;
    }

    return total;
}

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        precomputeFactorials();  // compute factorials once

        unordered_set<string> seen;  // to store unique digit frequency keys
        long long ans = 0;

        int halfLen = (n + 1) / 2;  // length of half of the palindrome
        int start = pow(10, halfLen - 1);
        int end = pow(10, halfLen);

        for (int half = start; half < end; ++half) {
            string s = to_string(half);
            string rev = s.substr(0, n / 2);  // for even, copy full; for odd, skip middle digit
            reverse(rev.begin(), rev.end());
            string full = s + rev;
            long long num = stoll(full);

            if (num % k != 0) continue;

            vector<int> freq(10, 0);
            for (char ch : full) freq[ch - '0']++;
            string key = getKey(freq);

            if (seen.count(key)) continue;
            seen.insert(key);

            ans += countPermutations(freq, n);
        }

        return ans;
    }
};

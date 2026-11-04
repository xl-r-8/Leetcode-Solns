class Solution {
public:
    multiset<int> low, high;
    long long sumLow = 0, sumHigh = 0;

    void balance() {
        while (low.size() > high.size() + 1) {
            int x = *low.rbegin();
            low.erase(low.find(x));
            sumLow -= x;
            high.insert(x);
            sumHigh += x;
        }

        while (low.size() < high.size()) {
            int x = *high.begin();
            high.erase(high.find(x));
            sumHigh -= x;
            low.insert(x);
            sumLow += x;
        }
    }

    void add(int x) {
        if (low.empty() || x <= *low.rbegin()) {
            low.insert(x);
            sumLow += x;
        } else {
            high.insert(x);
            sumHigh += x;
        }

        balance();
    }

    void remove(int x) {
        if (low.count(x)) {
            low.erase(low.find(x));
            sumLow -= x;
        } else {
            high.erase(high.find(x));
            sumHigh -= x;
        }

        balance();
    }

    long long cost() {
        long long median = *low.rbegin();

        return median * low.size() - sumLow
             + sumHigh - median * high.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> c(n - x + 1);

        // Calculate cost of every window of size x
        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                c[i - x + 1] = cost();
            }
        }

        // dp[i][j] = minimum cost using first i elements
        // to select j non-overlapping subarrays
        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, LLONG_MAX / 2)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                // Do not select a window ending at i-1
                dp[i][j] = dp[i - 1][j];

                // Select the window [i-x, i-1]
                if (i >= x) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + c[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
#include <vector>

class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007;

        // dp[i][j] means the number of valid sequences of length i ending with j consecutive 'L's
        std::vector<std::vector<long>> dp(n + 1, std::vector<long>(3, 0));

        // Initialization for sequences of length 1
        dp[0][0] = 1; // An empty sequence
        dp[1][0] = 1; // "P"
        dp[1][1] = 1; // "L"
        dp[1][2] = 0; // No valid sequence of length 1 ends with 2 'L's

        // Fill the dp table for sequences without 'A'
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
            dp[i][1] = dp[i - 1][0];
            dp[i][2] = dp[i - 1][1];
        }

        // Sum of valid sequences of length n without 'A'
        long total = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;

        // Consider sequences with one 'A'
        for (int i = 0; i < n; ++i) {
            long left = (dp[i][0] + dp[i][1] + dp[i][2]) % MOD;
            long right = (dp[n - i - 1][0] + dp[n - i - 1][1] + dp[n - i - 1][2]) % MOD;
            total = (total + (left * right) % MOD) % MOD;
        }

        return total;
    }
};

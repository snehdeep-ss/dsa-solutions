/*
 * Problem:  343. Integer Break
 * URL:       https://leetcode.com/problems/integer-break/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    8648000  (beats 27.4%)
 * Date:      2026-05-03
 * Context:  Day 31 — Unbounded Knapsack & Coin Change
 */

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }

        return dp[n];
    }
};
/*
 * Problem:  279. Perfect Squares
 * URL:       https://leetcode.com/problems/perfect-squares/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   33 ms  (beats 90.5%)
 * Memory:    13140000  (beats 68.1%)
 * Date:      2026-04-12
 * Context:  Day 31 — Unbounded Knapsack & Coin Change
 */

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0)
            return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
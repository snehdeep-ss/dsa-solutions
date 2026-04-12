/*
 * Problem:  322. Coin Change
 * URL:       https://leetcode.com/problems/coin-change/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   17 ms  (beats 84.0%)
 * Memory:    21992000  (beats 46.9%)
 * Date:      2026-04-12
 * Context:  Day 31 — Unbounded Knapsack & Coin Change
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (auto& c : coins) {
                if (i >= c)
                    dp[i] = min(dp[i - c] + 1, dp[i]);
            }
        }
        return (dp[amount] != INT_MAX) ? (int)dp[amount] : -1;
    }
};
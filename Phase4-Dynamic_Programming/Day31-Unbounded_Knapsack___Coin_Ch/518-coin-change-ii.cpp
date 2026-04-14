/*
 * Problem:  518. Coin Change II (count ways)
 * URL:       https://leetcode.com/problems/coin-change-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   5 ms  (beats 88.6%)
 * Memory:    10308000  (beats 84.5%)
 * Date:      2026-04-14
 * Context:  Day 31 — Unbounded Knapsack & Coin Change
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (auto c : coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] += dp[i - c];
            }
        }
        return (int)dp[amount];
    }
};
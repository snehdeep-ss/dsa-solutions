/*
 * Problem:  70. Climbing Stairs
 * URL:       https://leetcode.com/problems/climbing-stairs/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    8684000  (beats 17.2%)
 * Date:      2026-03-27
 * Context:  Day 29 — DP Foundations — 1D Patterns
 */

class Solution {

    int solve(int n, vector<int>& dp) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};
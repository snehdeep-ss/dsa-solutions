/*
 * Problem:  62. Unique Paths
 * URL:       https://leetcode.com/problems/unique-paths/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    9528000  (beats 28.1%)
 * Date:      2026-04-13
 * Context:  Day 34 — 2D Grid DP + Stock Problems
 */

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i - 1, j, dp) + solve(i, j - 1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};
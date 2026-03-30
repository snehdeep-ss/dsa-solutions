/*
 * Problem:  91. Decode Ways
 * URL:       https://leetcode.com/problems/decode-ways/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    8620000  (beats 67.7%)
 * Date:      2026-03-30
 * Context:  Day 29 — DP Foundations — 1D Patterns
 */

class Solution {
    int helper(vector<int>& dp, int idx, string& s) {
        if (idx >= s.size())
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        int ways = 0;

        if (s[idx] != '0') { // '0' has no single-digit mapping
            ways += helper(dp, idx + 1, s);
        }

        if (idx + 1 < s.size()) { // Need at least 2 characters
            int twoDigit = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                ways += helper(dp, idx + 2, s);
            }
        }

        return dp[idx] = ways;
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return helper(dp, 0, s);
    }
};
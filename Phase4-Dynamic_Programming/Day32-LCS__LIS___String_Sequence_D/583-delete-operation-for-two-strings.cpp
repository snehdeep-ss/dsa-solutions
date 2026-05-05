/*
 * Problem:  583. Delete Operation for Two Strings
 * URL:       https://leetcode.com/problems/delete-operation-for-two-strings/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   9 ms  (beats 75.4%)
 * Memory:    16948000  (beats 22.6%)
 * Date:      2026-05-05
 * Context:  Day 32 — LCS, LIS — String/Sequence DP
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
                
            }
        }

        int lcs = dp[m][n];

        return m + n - (2 * lcs);
    }
};
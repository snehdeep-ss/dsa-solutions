/*
 * Problem:  72. Edit Distance
 * URL:       https://leetcode.com/problems/edit-distance/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   5 ms  (beats 74.5%)
 * Memory:    13272000  (beats 40.0%)
 * Date:      2026-05-05
 * Context:  Day 32 — LCS, LIS — String/Sequence DP
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else {
                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = 1 + min({dp[i - 1][j - 1], 
                                            dp[i - 1][j],
                                            dp[i][j - 1]});
                }
            }
        }

        return dp[m][n];
    }
};
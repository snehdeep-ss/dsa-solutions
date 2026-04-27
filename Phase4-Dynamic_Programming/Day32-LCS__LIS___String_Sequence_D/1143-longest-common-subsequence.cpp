/*
 * Problem:  1143. Longest Common Subsequence
 * URL:       https://leetcode.com/problems/longest-common-subsequence/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   27 ms  (beats 56.4%)
 * Memory:    27376000  (beats 66.4%)
 * Date:      2026-04-27
 * Context:  Day 32 — LCS, LIS — String/Sequence DP
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> memo(text1.size() + 1,
                                 vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1])
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                else
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }

        return memo[text1.size()][text2.size()];
    }
};
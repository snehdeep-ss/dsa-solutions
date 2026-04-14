/*
 * Problem:  139. Word Break
 * URL:       https://leetcode.com/problems/word-break/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   15 ms  (beats 28.0%)
 * Memory:    18388000  (beats 16.4%)
 * Date:      2026-04-14
 * Context:  Day 29 — DP Foundations — 1D Patterns
 */

class Solution {

    int n;
    unordered_set<string> st;
    int dp[301];

    bool solve(int idx, string s) {
        if(idx >= n) return true;

        if(dp[idx] != -1) return dp[idx];
        for(int l = 1; l <= n - idx; l++) {
            string tmp = s.substr(idx, l);
            if(st.find(tmp) != st.end() && solve(idx + l, s)) return dp[idx] = true;
        }

        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n= s.size();
        st.insert(wordDict.begin(), wordDict.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};
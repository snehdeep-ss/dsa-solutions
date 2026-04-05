/*
 * Problem:  338. Counting Bits
 * URL:       https://leetcode.com/problems/counting-bits/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    10684000  (beats 58.1%)
 * Date:      2026-04-05
 * Context:  Day 39 — Bit Manipulation
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);

        for(int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};
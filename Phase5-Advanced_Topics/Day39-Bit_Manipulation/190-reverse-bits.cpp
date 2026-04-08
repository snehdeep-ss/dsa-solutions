/*
 * Problem:  190. Reverse Bits
 * URL:       https://leetcode.com/problems/reverse-bits/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    8228000  (beats 46.4%)
 * Date:      2026-04-08
 * Context:  Day 39 — Bit Manipulation
 */

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n = n >> 1;
        }
        
        return ans;
    }
};
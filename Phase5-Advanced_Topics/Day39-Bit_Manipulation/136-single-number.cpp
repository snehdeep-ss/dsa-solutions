/*
 * Problem:  136. Single Number
 * URL:       https://leetcode.com/problems/single-number/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    20476000  (beats 98.3%)
 * Date:      2026-04-05
 * Context:  Day 39 — Bit Manipulation
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto& it : nums) {
            ans ^= it;
        }
        return ans;
    }
};
/*
 * Problem:  260. Single Number III
 * URL:       https://leetcode.com/problems/single-number-iii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    13944000  (beats 54.8%)
 * Date:      2026-05-08
 * Context:  Day 39 — Bit Manipulation
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        long xor_all = 0;
        for (auto num : nums) {
            xor_all ^= num;
        }

        long diff = xor_all & (-xor_all);

        long gp1 = 0;
        long gp2 = 0;

        for (auto num : nums) {
            if ((long)num & diff) {
                gp1 ^= (long)num;
            } else
                gp2 ^= (long)num;
        }
        return {(int)gp1, (int)gp2};
    }
};
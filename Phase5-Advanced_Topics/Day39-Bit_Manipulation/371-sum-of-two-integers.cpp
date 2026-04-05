/*
 * Problem:  371. Sum of Two Integers Without +
 * URL:       https://leetcode.com/problems/sum-of-two-integers/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    7840000  (beats 33.8%)
 * Date:      2026-04-05
 * Context:  Day 39 — Bit Manipulation
 */

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        if(carry) return getSum(sum, carry);
        return sum;
    }
};
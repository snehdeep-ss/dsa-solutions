/*
 * Problem:  238. Product of Array Except Self
 * URL:       https://leetcode.com/problems/product-of-array-except-self/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   1 ms  (beats 48.9%)
 * Memory:    40156000  (beats 79.8%)
 * Date:      2026-03-21
 * Context:  Day 4 — Hash Maps + Prefix + Intervals
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> output(sz);

        output[0] = 1;

        for (int i = 1; i < sz; i++) {
            output[i] = output[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = sz - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};
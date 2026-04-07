/*
 * Problem:  213. House Robber II (Circular)
 * URL:       https://leetcode.com/problems/house-robber-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    10044000  (beats 96.9%)
 * Date:      2026-04-07
 * Context:  Day 29 — DP Foundations — 1D Patterns
 */

class Solution {

    int robLinear(vector<int>& nums, int lo, int hi) {
        int prev2 = 0;
        int prev1 = 0;

        for(int i = lo; i <= hi; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(robLinear(nums, 0 , n - 2), robLinear(nums, 1, n - 1));
    }
};
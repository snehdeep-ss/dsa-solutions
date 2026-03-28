/*
 * Problem:  198. House Robber
 * URL:       https://leetcode.com/problems/house-robber/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    10712000  (beats 21.3%)
 * Date:      2026-03-28
 * Context:  Day 29 — DP Foundations — 1D Patterns
 */

class Solution {

    int maxRob(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= nums.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int result = max(nums[idx] + maxRob(idx + 2, nums, dp),
                         maxRob(idx + 1, nums, dp));

        return dp[idx] = result;
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return maxRob(0, nums, dp);
    }
};
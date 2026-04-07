/*
 * Problem:  416. Partition Equal Subset Sum
 * URL:       https://leetcode.com/problems/partition-equal-subset-sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   95 ms  (beats 70.3%)
 * Memory:    111364000  (beats 14.6%)
 * Date:      2026-04-07
 * Context:  Day 30 — 0/1 Knapsack & Subset Sum
 */

class Solution {

    bool backtrack(vector<int>& nums, int idx, int tgt,
                   vector<vector<int>>& dp) {
        if (idx >= nums.size() || tgt < 0)
            return false;
        if (tgt == 0)
            return true;
        if (dp[idx][tgt] != -1)
            return dp[idx][tgt];
        return dp[idx][tgt] = backtrack(nums, idx + 1, tgt, dp) ||
                              backtrack(nums, idx + 1, tgt - nums[idx], dp);
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (auto& num : nums)
            total += num;

        if (total % 2 != 0)
            return false;
        int target = total / 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));

        return backtrack(nums, 0, target, dp);
    }
};
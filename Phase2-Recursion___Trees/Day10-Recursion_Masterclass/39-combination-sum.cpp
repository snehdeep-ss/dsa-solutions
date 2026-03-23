/*
 * Problem:  39. Combination Sum
 * URL:       https://leetcode.com/problems/combination-sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    13980000  (beats 92.3%)
 * Date:      2026-03-23
 * Context:  Day 10 — Recursion Masterclass
 */

class Solution {
    void getCombinationSum(vector<int>& nums, int idx, int sum, int target,
                           vector<int>& curr, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }
        if (sum > target || idx >= nums.size())
            return;

        curr.push_back(nums[idx]);
        getCombinationSum(nums, idx, sum + nums[idx], target, curr, ans);
        curr.pop_back();
        getCombinationSum(nums, idx + 1, sum, target, curr, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        getCombinationSum(nums, 0, 0, target, curr, ans);
        return ans;
    }
};
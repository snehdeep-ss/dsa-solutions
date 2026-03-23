/*
 * Problem:  78. Subsets
 * URL:       https://leetcode.com/problems/subsets/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   1 ms  (beats 44.0%)
 * Memory:    10188000  (beats 31.9%)
 * Date:      2026-03-23
 * Context:  Day 10 — Recursion Masterclass
 */

class Solution {
    void generatePowerSet(vector<int> nums, int idx, vector<int>& curr,
                          vector<vector<int>>& ans) {

        ans.push_back(curr); // store current

        for (int i = idx; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            generatePowerSet(nums, i + 1, curr, ans);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        generatePowerSet(nums, 0, curr, ans);
        return ans;
    }
};
/*
 * Problem:  46. Permutations
 * URL:       https://leetcode.com/problems/permutations/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   1 ms  (beats 42.2%)
 * Memory:    10608000  (beats 48.4%)
 * Date:      2026-03-23
 * Context:  Day 10 — Recursion Masterclass
 */

class Solution {

    void generateAllPermutations(vector<int>& nums, vector<int>& curr,
                                 vector<int>& freq, vector<vector<int>>& ans) {
        if (nums.size() == curr.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (freq[i])
                continue;
            freq[i] = 1;
            curr.push_back(nums[i]);
            generateAllPermutations(nums, curr, freq, ans);
            curr.pop_back();
            freq[i] = 0;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> freq(nums.size(), 0);
        vector<int> curr;
        vector<vector<int>> ans;
        generateAllPermutations(nums, curr, freq, ans);
        return ans;
    }
};
/*
 * Problem:  90. Subsets II (with duplicates)
 * URL:       https://leetcode.com/problems/subsets-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   2 ms  (beats 39.5%)
 * Memory:    10376000  (beats 83.5%)
 * Date:      2025-11-20
 * Context:  Day 36 — Backtracking Deep Dive
 */

class Solution {

private:
    void calc(int index, vector<int>& nums, vector<int>& temp,
              vector<vector<int>>& ans) {
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            calc(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        calc(0, nums, temp, ans);
        return ans;
    }
};
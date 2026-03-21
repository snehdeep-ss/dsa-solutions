/*
 * Problem:  448. Find All Missing Numbers
 * URL:       https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   4 ms  (beats 65.3%)
 * Memory:    52940000  (beats 90.3%)
 * Date:      2026-03-21
 * Context:  Day 9 — Phase 1 Consolidation + Sorting
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }

        for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i] << " ";
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
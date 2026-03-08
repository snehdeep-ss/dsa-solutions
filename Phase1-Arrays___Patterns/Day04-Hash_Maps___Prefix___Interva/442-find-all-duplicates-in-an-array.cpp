/*
 * Problem:  442. Find All Duplicates in Array
 * URL:       https://leetcode.com/problems/find-all-duplicates-in-an-array/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   3 ms  (beats 73.4%)
 * Memory:    48552000  (beats 60.8%)
 * Date:      2026-03-08
 * Context:  Day 4 — Hash Maps + Prefix + Intervals
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0)
                ans.push_back(abs(nums[i]));
            else
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return ans;
    }
};
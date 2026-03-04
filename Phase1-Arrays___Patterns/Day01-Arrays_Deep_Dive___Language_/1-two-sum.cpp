/*
 * Problem:  1. Two Sum
 * URL:       https://leetcode.com/problems/two-sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    14900000  (beats 35.9%)
 * Date:      2026-03-02
 * Context:  Day 1 — Arrays Deep Dive + Language Setup
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (mp.find(remain) != mp.end())
                return {mp[remain], i};
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
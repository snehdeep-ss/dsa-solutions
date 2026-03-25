/*
 * Problem:  1. Two Sum (re-attempt from memory)
 * URL:       https://leetcode.com/problems/two-sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   6 ms  (beats 43.5%)
 * Memory:    14944000  (beats 18.2%)
 * Date:      2026-03-25
 * Context:  Day 20 — Phase 1+2 Full Review Day
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if(seen.find(rem) != seen.end()) return {i, seen[rem]};
            seen[nums[i]] = i;
        }
        return {-1, -1};

    }
};
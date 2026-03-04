/*
 * Problem:  1480. Running Sum of 1D Array
 * URL:       https://leetcode.com/problems/running-sum-of-1d-array/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    12480000  (beats 81.6%)
 * Date:      2026-03-03
 * Context:  Day 1 — Arrays Deep Dive + Language Setup
 */

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        ans.resize(nums.size());
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            ans[i] = currSum;
        }

        return ans;
    }
};
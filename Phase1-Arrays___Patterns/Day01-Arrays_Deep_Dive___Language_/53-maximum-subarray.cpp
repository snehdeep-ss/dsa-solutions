/*
 * Problem:  53. Max Subarray (Kadane's)
 * URL:       https://leetcode.com/problems/maximum-subarray/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    71592000  (beats 97.8%)
 * Date:      2026-03-03
 * Context:  Day 1 — Arrays Deep Dive + Language Setup
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(currSum, maxSum);
        }

        return maxSum;
    }
};
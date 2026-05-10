/*
 * Problem:  2770. Maximum Number of Jumps to Reach the Last Index
 * URL:       https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   23 ms  (beats 43.5%)
 * Memory:    68532000  (beats 40.1%)
 * Date:      2026-05-10
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j] != -1 && abs(nums[i] - nums[j]) <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                } 
            }
        }
        return dp.back();
    }
};
/*
 * Problem:  1696. Jump Game VI (DP + Deque)
 * URL:       https://leetcode.com/problems/jump-game-vi/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   7 ms  (beats 93.0%)
 * Memory:    84948000  (beats 80.3%)
 * Date:      2026-05-12
 * Context:  Day 18 — Queues + Deque Patterns
 */

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> dp(nums.size());

        dq.push_back(0);
        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            while(!dq.empty() && dq.front() < i - k) dq.pop_front();
            dp[i] = nums[i] + dp[dq.front()];
            while(!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }

        return dp.back();
    }
};
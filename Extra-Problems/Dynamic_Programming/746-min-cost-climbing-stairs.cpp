/*
 * Problem:  746. Min Cost Climbing Stairs
 * URL:       https://leetcode.com/problems/min-cost-climbing-stairs/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    17644000  (beats 49.9%)
 * Date:      2026-04-12
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp.back();
    }
};
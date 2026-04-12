/*
 * Problem:  509. Fibonacci Number
 * URL:       https://leetcode.com/problems/fibonacci-number/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   3 ms  (beats 64.6%)
 * Memory:    8188000  (beats 16.4%)
 * Date:      2026-04-12
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int fib(int n) {
        if(n < 1) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};
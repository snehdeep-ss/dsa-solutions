/*
 * Problem:  1109. Corporate Flight Bookings
 * URL:       https://leetcode.com/problems/corporate-flight-bookings/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    72112000  (beats 73.9%)
 * Date:      2026-04-14
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);

        for (auto& t : bookings) {
            int start = t[0];
            int end = t[1];
            int cap = t[2];

            ans[start - 1] += cap;
            if (end < n)
                ans[end] -= cap;
        }

        for (int i = 1; i < n; i++) {
            ans[i] += ans[i - 1];
        }

        return ans;
    }
};
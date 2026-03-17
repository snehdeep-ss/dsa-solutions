/*
 * Problem:  739. Daily Temperatures
 * URL:       https://leetcode.com/problems/daily-temperatures/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   14 ms  (beats 87.2%)
 * Memory:    102868000  (beats 81.8%)
 * Date:      2026-03-17
 * Context:  Day 6 — Stacks + Monotonic Stack
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size(), 0);
        stack<int> st;
        for (int i = temps.size() - 1; i >= 0; i--) {
            while (!st.empty() && temps[st.top()] <= temps[i]) {
                st.pop();
            }
            if (!st.empty())
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
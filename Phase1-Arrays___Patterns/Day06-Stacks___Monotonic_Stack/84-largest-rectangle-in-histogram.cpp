/*
 * Problem:  84. Largest Rectangle in Histogram
 * URL:       https://leetcode.com/problems/largest-rectangle-in-histogram/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   7 ms  (beats 98.1%)
 * Memory:    81472000  (beats 60.3%)
 * Date:      2026-03-18
 * Context:  Day 6 — Stacks + Monotonic Stack
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        heights.push_back(0);
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back();
        return maxArea;
    }
};
/*
 * Problem:  503. Next Greater Element II
 * URL:       https://leetcode.com/problems/next-greater-element-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   8 ms  (beats 25.7%)
 * Memory:    28392000  (beats 79.3%)
 * Date:      2026-03-17
 * Context:  Day 6 — Stacks + Monotonic Stack
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ans(sz, -1);

        stack<int> st;

        for (int idx = 2 * sz - 1; idx >= 0; idx--) {
            int i = idx % sz;
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (!st.empty() && i < sz)
                ans[i] = st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};
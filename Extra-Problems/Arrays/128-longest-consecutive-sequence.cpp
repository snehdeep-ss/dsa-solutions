/*
 * Problem:  128. Longest Consecutive Sequence
 * URL:       https://leetcode.com/problems/longest-consecutive-sequence/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   80 ms  (beats 59.3%)
 * Memory:    88968000  (beats 47.3%)
 * Date:      2026-03-06
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        int longest = 0;

        for (auto it : nums) {
            st.insert(it);
        }

        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                while (st.find(it + 1) != st.end()) {
                    count++;
                    it++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
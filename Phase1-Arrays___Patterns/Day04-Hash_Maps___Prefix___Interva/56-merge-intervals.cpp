/*
 * Problem:  56. Merge Intervals
 * URL:       https://leetcode.com/problems/merge-intervals/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   7 ms  (beats 39.9%)
 * Memory:    24720000  (beats 16.1%)
 * Date:      2026-03-07
 * Context:  Day 4 — Hash Maps + Prefix + Intervals
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for (auto interval : intervals) {
            if (output.empty() || output.back()[1] < interval[0]) {
                output.push_back(interval);
            } else {
                output.back()[1] = max(interval[1], output.back()[1]);
            }
        }
        return output;
    }
};
/*
 * Problem:  57. Insert Interval
 * URL:       https://leetcode.com/problems/insert-interval/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    21584000  (beats 94.4%)
 * Date:      2026-03-07
 * Context:  Day 4 — Hash Maps + Prefix + Intervals
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int sz = intervals.size();

        vector<vector<int>> out;

        int i = 0;

        // insert all before newInterval
        while (i < sz && intervals[i][1] < newInterval[0]) {
            out.push_back(intervals[i]);
            i++;
        }

        // merge with newInterval
        while(i < sz && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        out.push_back(newInterval);
        while(i < sz) {
            out.push_back(intervals[i]);
            i++;
        }

        return out;

    }
};
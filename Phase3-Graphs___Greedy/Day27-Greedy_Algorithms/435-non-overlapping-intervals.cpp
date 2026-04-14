/*
 * Problem:  435. Non-overlapping Intervals
 * URL:       https://leetcode.com/problems/non-overlapping-intervals/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   38 ms  (beats 84.4%)
 * Memory:    94044000  (beats 38.6%)
 * Date:      2026-04-14
 * Context:  Day 27 — Greedy Algorithms
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int cnt = 0;

        int lastEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < lastEnd) {
                cnt++;
            }
            else lastEnd = intervals[i][1];
        }
        return cnt;
    }
};
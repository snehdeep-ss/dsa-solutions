/*
 * Problem:  452. Minimum Number of Arrows
 * URL:       https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   48 ms  (beats 54.5%)
 * Memory:    93688000  (beats 99.8%)
 * Date:      2026-04-14
 * Context:  Day 27 — Greedy Algorithms
 */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int cnt = 1;
        int lastEnd = points[0][1];

        for(int i = 1; i < points.size(); i++) {
            if (points[i][0] > lastEnd) {
                // Current balloon starts after last arrow burst range
                cnt++;
                lastEnd = points[i][1];
            }
        }

        return cnt;
        
    }
};
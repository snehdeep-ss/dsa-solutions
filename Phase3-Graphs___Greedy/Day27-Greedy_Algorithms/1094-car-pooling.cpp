/*
 * Problem:  1094. Car Pooling
 * URL:       https://leetcode.com/problems/car-pooling/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    14232000  (beats 80.0%)
 * Date:      2026-04-14
 * Context:  Day 27 — Greedy Algorithms
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> timeline(1001, 0);

        for (auto& t : trips) {
            int num = t[0];
            int from = t[1];
            int to = t[2];

            timeline[from] += num;
            timeline[to] -= num;
        }

        int curr = 0;
        for (int i = 0; i < 1001; i++) {
            curr += timeline[i];
            if (curr > capacity)
                return false;
        }
        return true;
    }
};
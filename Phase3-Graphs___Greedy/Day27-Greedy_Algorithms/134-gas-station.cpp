/*
 * Problem:  134. Gas Station
 * URL:       https://leetcode.com/problems/gas-station/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    112624000  (beats 7.4%)
 * Date:      2026-04-14
 * Context:  Day 27 — Greedy Algorithms
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalFuel = 0;
        int totalCost = 0;

        int n = cost.size();

        for (int i = 0; i < n; i++) {
            totalFuel += gas[i];
            totalCost += cost[i];
        }

        if (totalCost > totalFuel)
            return -1;

        int currFuel = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            currFuel += gas[i] - cost[i];

            if (currFuel < 0) {
                currFuel = 0;
                start = i + 1;
            }
        }
        return start;
    }
};
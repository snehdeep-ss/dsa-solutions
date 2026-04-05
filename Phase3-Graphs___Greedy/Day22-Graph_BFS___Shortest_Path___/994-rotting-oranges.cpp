/*
 * Problem:  994. Rotting Oranges
 * URL:       https://leetcode.com/problems/rotting-oranges/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    16552000  (beats 97.2%)
 * Date:      2026-04-05
 * Context:  Day 22 — Graph BFS — Shortest Path & Grids
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        int maxTime = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2)
                    q.push({i, j, 0});
            }
        }

        while (!q.empty()) {

            auto [row, col, time] = q.front();
            q.pop();
            maxTime = max(time, maxTime);
            if (row + 1 < grid.size() && grid[row + 1][col] == 1) {
                grid[row + 1][col] = 2;
                q.push({row + 1, col, time + 1});
            }

            if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                grid[row - 1][col] = 2;
                q.push({row - 1, col, time + 1});
            }
            if (col + 1 < grid[0].size() && grid[row][col + 1] == 1) {
                grid[row][col + 1] = 2;
                q.push({row, col + 1, time + 1});
            }
            if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                grid[row][col - 1] = 2;
                q.push({row, col - 1, time + 1});
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return maxTime;
    }
};
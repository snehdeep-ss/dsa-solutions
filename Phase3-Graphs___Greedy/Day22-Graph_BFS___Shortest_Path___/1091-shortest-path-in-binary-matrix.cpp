/*
 * Problem:  1091. Shortest Path in Binary Matrix
 * URL:       https://leetcode.com/problems/shortest-path-in-binary-matrix/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   11 ms  (beats 86.1%)
 * Memory:    24768000  (beats 59.5%)
 * Date:      2026-04-15
 * Context:  Day 22 — Graph BFS — Shortest Path & Grids
 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int n = grid.size();

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        grid[0][0] = true;

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1},
                                          {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

        while (!q.empty()) {
            auto [r, c, dist] = q.front();
            q.pop();
            if (r == n - 1 && c == n - 1)
                return dist;

            for (int i = 0; i < directions.size(); i++) {
                auto& t = directions[i];
                int dr = t[0];
                int dc = t[1];

                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc, dist + 1});
                }
            }
        }
        return -1;
    }
};
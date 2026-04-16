/*
 * Problem:  542. 01 Matrix
 * URL:       https://leetcode.com/problems/01-matrix/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   11 ms  (beats 84.2%)
 * Memory:    35920000  (beats 56.6%)
 * Date:      2026-04-16
 * Context:  Day 22 — Graph BFS — Shortest Path & Grids
 */

class Solution {

    int bfs(queue<tuple<int, int>> q, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                    mat[nr][nc] == -1) {
                    mat[nr][nc] = mat[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<tuple<int, int>> q;

        vector<vector<int>> ans(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        bfs(q, ans);
        return ans;
    }
};
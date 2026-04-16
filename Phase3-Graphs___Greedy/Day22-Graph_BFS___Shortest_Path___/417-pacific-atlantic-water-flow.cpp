/*
 * Problem:  417. Pacific Atlantic Water Flow
 * URL:       https://leetcode.com/problems/pacific-atlantic-water-flow/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   6 ms  (beats 67.5%)
 * Memory:    23336000  (beats 49.0%)
 * Date:      2026-04-16
 * Context:  Day 22 — Graph BFS — Shortest Path & Grids
 */

class Solution {

    void bfs(queue<pair<int, int>> tmpQ, vector<vector<bool>>& mp,
             vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while (!tmpQ.empty()) {
            auto [r, c] = tmpQ.front();
            tmpQ.pop();

            for (auto& [dr, dc] : directions) {

                int nr = r + dr;
                int nc = c + dc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    mp[nr][nc] == false && heights[r][c] <= heights[nr][nc]) {
                    mp[nr][nc] = true;
                    tmpQ.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        queue<pair<int, int>> pacQ, atlQ;

        for (int i = 0; i < m; i++) {
            pacific[i][0] = true;
            pacQ.push({i, 0});

            atlantic[i][n - 1] = true;
            atlQ.push({i, n - 1});
        }

        for (int i = 0; i < n; i++) {
            pacific[0][i] = true;
            pacQ.push({0, i});

            atlantic[m - 1][i] = true;
            atlQ.push({m-1, i});
        }

        bfs(pacQ, pacific, heights);
        bfs(atlQ, atlantic, heights);

        vector<vector<int>> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
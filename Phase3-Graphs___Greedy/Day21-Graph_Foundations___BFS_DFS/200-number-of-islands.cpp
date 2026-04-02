/*
 * Problem:  200. Number of Islands
 * URL:       https://leetcode.com/problems/number-of-islands/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   21 ms  (beats 92.2%)
 * Memory:    16264000  (beats 78.1%)
 * Date:      2026-03-31
 * Context:  Day 21 — Graph Foundations + BFS/DFS
 */

class Solution {

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] != '1')
            return;

        grid[row][col] = '2';

        dfs(grid, row + 1, col);
        dfs(grid, row - 1, col);
        dfs(grid, row, col + 1);
        dfs(grid, row, col - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                char ch = grid[i][j];
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
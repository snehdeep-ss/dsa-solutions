/*
 * Problem:  695. Max Area of Island
 * URL:       https://leetcode.com/problems/max-area-of-island/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    27592000  (beats 68.4%)
 * Date:      2026-04-02
 * Context:  Day 21 — Graph Foundations + BFS/DFS
 */

class Solution {

    void dfs(int row, int col, int& ans, vector<vector<int>>& grid) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != 1) return;
        ans++;
        
        grid[row][col] = 2;
        dfs(row + 1, col, ans, grid);
        dfs(row - 1, col, ans, grid);
        dfs(row, col + 1, ans, grid);   
        dfs(row, col - 1, ans, grid);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, area, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
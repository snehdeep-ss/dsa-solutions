/*
 * Problem:  733. Flood Fill
 * URL:       https://leetcode.com/problems/flood-fill/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    17952000  (beats 89.5%)
 * Date:      2026-04-02
 * Context:  Day 21 — Graph Foundations + BFS/DFS
 */

class Solution {

    void dfs(vector<vector<int>>& image, int row, int col, int og, int color) {
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != og) return;

        image[row][col] = color;
        dfs(image, row + 1, col, og, color);
        dfs(image, row - 1, col, og, color);
        dfs(image, row, col + 1, og, color);
        dfs(image, row, col - 1, og, color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og = image[sr][sc];
        if(og == color) return image;
        dfs(image, sr, sc, og, color);
        return image;
    }
};
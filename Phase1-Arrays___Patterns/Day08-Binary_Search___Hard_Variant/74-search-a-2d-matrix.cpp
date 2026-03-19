/*
 * Problem:  74. Search a 2D Matrix
 * URL:       https://leetcode.com/problems/search-a-2d-matrix/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    13332000  (beats 44.5%)
 * Date:      2026-03-19
 * Context:  Day 8 — Binary Search — Hard Variants
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = (matrix.size() * matrix[0].size()) - 1;

        while(low <= high) {
            int mid = low + (high-low) / 2;

            int x = mid / matrix[0].size();
            int y = mid % matrix[0].size();

            int num = matrix[x][y];

            if(num == target) return true;
            else if(num < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
/*
 * Problem:  37. Sudoku Solver
 * URL:       https://leetcode.com/problems/sudoku-solver/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   373 ms  (beats 44.6%)
 * Memory:    8768000  (beats 70.4%)
 * Date:      2026-01-28
 * Context:  Day 37 — Backtracking — Hard Problems
 */

class Solution {

private:
    bool isSafe(int row, int col, char d, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == d)
                return false;
            if (board[i][col] == d)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == d)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char i = '1'; i <= '9'; i++) {
                        if (isSafe(row, col, i, board)) {
                            board[row][col] = i;
                            if (solve(board))
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
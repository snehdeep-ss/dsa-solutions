/*
 * Problem:  51. N-Queens
 * URL:       https://leetcode.com/problems/n-queens/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   2 ms  (beats 73.3%)
 * Memory:    10116000  (beats 75.0%)
 * Date:      2026-04-03
 * Context:  Day 36 — Backtracking Deep Dive
 */

class Solution {

    bool isSafe(int row, int col, vector<string>& board) {

        // check column
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // check left diagonal
        for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 'Q')
                return false;
        }

        // check right diagonal
        for (int r = row - 1, c = col + 1; r >= 0 && c < board.size();
             r--, c++) {
            if (board[r][c] == 'Q')
                return false;
        }

        return true;
    }

    void backtrack(int row, int n, vector<string>& board,
                   vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board)) {
                board[row][col] = 'Q';
                backtrack(row + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        backtrack(0, n, board, ans);
        return ans;
    }
};
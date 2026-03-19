/*
 * Problem:  367. Valid Perfect Square
 * URL:       https://leetcode.com/problems/valid-perfect-square/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    7720000  (beats 53.1%)
 * Date:      2026-03-19
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int low = 0;
        int high = num;

        while(low <= high) {
            long long mid = low + (high - low)/2;
            long long square = mid * mid;
            if(square == (long long)num) return true;
            else if(square < num) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};
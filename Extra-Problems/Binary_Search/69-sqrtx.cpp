/*
 * Problem:  69. Sqrt(x)
 * URL:       https://leetcode.com/problems/sqrtx/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    8656000  (beats 13.8%)
 * Date:      2026-03-19
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int res = 0;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(mid * mid == (long long)x) return mid;
            if(mid * mid < (long long)x) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};
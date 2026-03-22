/*
 * Problem:  50. Pow(x, n)
 * URL:       https://leetcode.com/problems/powx-n/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    8652000  (beats 44.3%)
 * Date:      2026-03-22
 * Context:  Day 10 — Recursion Masterclass
 */

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;

        if (n % 2 == 0) {
            if (n < 0)
                return (1 / myPow(x * x, abs(n / 2)));
            else
                return myPow(x * x, abs(n / 2));
        } else {
            if (n < 0)
                return  (1 / (x* myPow(x * x, (abs(n) - 1) / 2)));
            else
                return (x * myPow(x * x, abs((n - 1) / 2)));
        }

        return -1;
    }
};
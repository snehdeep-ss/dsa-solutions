/*
 * Problem:  875. Koko Eating Bananas
 * URL:       https://leetcode.com/problems/koko-eating-bananas/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   4 ms  (beats 87.4%)
 * Memory:    23008000  (beats 12.3%)
 * Date:      2026-03-17
 * Context:  Day 7 — Binary Search — All Patterns
 */

class Solution {

    long long findHours(vector<int>& piles, int mid) {
        long long hours = 0;
        for (auto p : piles) {
            hours += ((long long)p + (long long)mid - 1) / (long long)mid;
        }
        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long hours = findHours(piles, mid);

            if (hours <= h) {
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return left;
    }
};
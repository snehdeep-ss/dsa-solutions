/*
 * Problem:  1011. Capacity To Ship Packages Within D Days
 * URL:       https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   11 ms  (beats 67.4%)
 * Memory:    35032000  (beats 53.8%)
 * Date:      2026-03-20
 * Context:  Extra / Personal Practice
 */

class Solution {

    int getDays(vector<int>& weights, int wt) {
        int sum = 0;
        int count = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > wt) {
                sum = weights[i];
                count++;
            }
            else sum += weights[i];
        }
        return count;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (getDays(weights, mid) <= days) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};
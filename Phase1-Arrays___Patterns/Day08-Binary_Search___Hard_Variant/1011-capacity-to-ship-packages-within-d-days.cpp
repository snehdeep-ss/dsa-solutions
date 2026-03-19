/*
 * Problem:  1011. Capacity to Ship Packages
 * URL:       https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   12 ms  (beats 52.0%)
 * Memory:    34972000  (beats 87.2%)
 * Date:      2026-03-19
 * Context:  Day 8 — Binary Search — Hard Variants
 */

class Solution {

    int getDays(vector<int>& nums, int capacity) {
        int count = 1;
        int idx = 0;
        int sum = 0;
        while (idx < nums.size()) {
            if (sum + nums[idx] > capacity) {
                sum = 0;
                count++;
            }
            sum += nums[idx++];
        }
        return count;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            int currDays = getDays(weights, mid);

            if (currDays <= days)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
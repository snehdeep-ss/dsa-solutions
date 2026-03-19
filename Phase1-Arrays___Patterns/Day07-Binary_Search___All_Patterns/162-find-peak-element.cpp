/*
 * Problem:  162. Find Peak Element
 * URL:       https://leetcode.com/problems/find-peak-element/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    12572000  (beats 70.5%)
 * Date:      2026-03-19
 * Context:  Day 7 — Binary Search — All Patterns
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if ( nums[mid + 1] > nums[mid])
                low = mid + 1;
            else 
                high = mid;
        }
        return low;
    }
};
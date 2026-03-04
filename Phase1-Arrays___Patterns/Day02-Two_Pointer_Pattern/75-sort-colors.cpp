/*
 * Problem:  75. Sort Colors (Dutch Flag)
 * URL:       https://leetcode.com/problems/sort-colors/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    11696000  (beats 48.2%)
 * Date:      2026-03-04
 * Context:  Day 2 — Two Pointer Pattern
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
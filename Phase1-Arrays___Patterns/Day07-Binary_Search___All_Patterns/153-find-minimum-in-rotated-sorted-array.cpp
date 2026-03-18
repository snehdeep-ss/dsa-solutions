/*
 * Problem:  153. Find Minimum in Rotated Sorted Array
 * URL:       https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    13968000  (beats 97.6%)
 * Date:      2026-03-18
 * Context:  Day 7 — Binary Search — All Patterns
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int sz = nums.size() - 1;
        int firstIdx = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= nums[sz]) {
                firstIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nums[firstIdx];
    }
};
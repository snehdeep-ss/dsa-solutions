/*
 * Problem:  33. Search in Rotated Sorted Array
 * URL:       https://leetcode.com/problems/search-in-rotated-sorted-array/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    15140000  (beats 67.2%)
 * Date:      2026-03-18
 * Context:  Day 7 — Binary Search — All Patterns
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else {
                if (target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
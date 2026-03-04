/*
 * Problem:  80. Remove Duplicates from Sorted Array II
 * URL:       https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   7 ms  (beats 72.3%)
 * Memory:    19628000  (beats 23.0%)
 * Date:      2026-03-04
 * Context:  Day 2 — Two Pointer Pattern
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (curr < 2 || nums[i] != nums[curr - 2]) {
                nums[curr] = nums[i];
                curr++;
            }
        }
        return curr;
    }
};
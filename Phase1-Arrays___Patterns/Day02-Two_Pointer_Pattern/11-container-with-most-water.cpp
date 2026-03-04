/*
 * Problem:  11. Container With Most Water
 * URL:       https://leetcode.com/problems/container-with-most-water/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   3 ms  (beats 35.2%)
 * Memory:    62780000  (beats 97.4%)
 * Date:      2026-03-04
 * Context:  Day 2 — Two Pointer Pattern
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int currArea = (right - left) * min(height[left], height[right]);
            maxArea = max(maxArea, currArea);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};
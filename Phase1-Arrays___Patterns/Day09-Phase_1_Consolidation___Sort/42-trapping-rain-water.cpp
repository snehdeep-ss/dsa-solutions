/*
 * Problem:  42. Trapping Rain Water
 * URL:       https://leetcode.com/problems/trapping-rain-water/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    25976000  (beats 78.1%)
 * Date:      2026-03-11
 * Context:  Day 9 — Phase 1 Consolidation + Sorting
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int ans = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
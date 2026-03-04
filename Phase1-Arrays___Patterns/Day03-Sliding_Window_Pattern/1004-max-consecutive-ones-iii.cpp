/*
 * Problem:  1004. Max Consecutive Ones III
 * URL:       https://leetcode.com/problems/max-consecutive-ones-iii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    69476000  (beats 91.9%)
 * Date:      2026-03-04
 * Context:  Day 3 — Sliding Window Pattern
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0;
        int cnt = 0;
        int left = 0;
        int right = 0;

        while (left <= right && right < nums.size()) {
            if (nums[right] == 0)
                cnt++;

            if (cnt > k) {
                if (nums[left] == 0)
                    cnt--;
                left++;
            }

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
/*
 * Problem:  1004. Max Consecutive Ones III
 * URL:       https://leetcode.com/problems/max-consecutive-ones-iii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    69644000  (beats 26.5%)
 * Date:      2026-03-06
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int cnt = 0;
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0)
                cnt++;

            while (cnt > k) {
                if (nums[left] == 0)
                    cnt--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
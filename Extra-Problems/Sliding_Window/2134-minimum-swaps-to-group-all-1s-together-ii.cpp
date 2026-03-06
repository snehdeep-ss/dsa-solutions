/*
 * Problem:  2134. Minimum Swaps to Group All 1's Together II
 * URL:       https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   4 ms  (beats 75.2%)
 * Memory:    84164000  (beats 74.8%)
 * Date:      2026-03-06
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int oneCount = 0;
        for (auto it : nums) {
            oneCount += it & 1;
        }
        int ans = INT_MAX;

        int right = 0;
        int left = 0;

        int zeroCount = 0;

        for (; right < oneCount; right++) {
            zeroCount += nums[right] ? 0 : 1;
        }

        while (right < nums.size() + oneCount) {
            if (nums[right % nums.size()] == 0)
                zeroCount++;

            if (right - left + 1 > oneCount) {
                if (nums[left % nums.size()] == 0)
                    zeroCount--;
                left++;
            }
            ans = min(ans, zeroCount);
            right++;
        }
        return ans;
    }
};
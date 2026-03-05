/*
 * Problem:  2461. Maximum Sum of Distinct Subarrays With Length K
 * URL:       https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   107 ms  (beats 47.3%)
 * Memory:    95356000  (beats 62.7%)
 * Date:      2026-03-05
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freqMap;
        long long maxSum = 0;
        long long currSum = 0;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            currSum += (long long)nums[right];
            freqMap[nums[right]]++;

            while (right - left + 1 > k || freqMap[nums[right]] > 1) {
                currSum -= (long long)nums[left];

                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0)
                    freqMap.erase(nums[left]);

                left++;
            }

            if (right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};
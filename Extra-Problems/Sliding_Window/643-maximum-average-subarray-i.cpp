/*
 * Problem:  643. Maximum Average Subarray I
 * URL:       https://leetcode.com/problems/maximum-average-subarray-i/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    113872000  (beats 27.6%)
 * Date:      2026-03-06
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double ans = 0;
        int maxSum = INT_MIN;
        int left = 0;
        int currSum = 0;

        for(int right = 0; right < nums.size(); right++) {
            currSum += nums[right];

            while (right - left + 1 > k) {
                currSum -= nums[left];
                left++;
            }

            if(right - left + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
        }

        ans = (double)maxSum / k;
        return ans;

    }
};
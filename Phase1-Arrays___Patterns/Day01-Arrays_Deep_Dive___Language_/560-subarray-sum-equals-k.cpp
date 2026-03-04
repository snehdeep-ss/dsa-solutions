/*
 * Problem:  560. Subarray Sum Equals K
 * URL:       https://leetcode.com/problems/subarray-sum-equals-k/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   37 ms  (beats 78.1%)
 * Memory:    45568000  (beats 39.2%)
 * Date:      2026-03-03
 * Context:  Day 1 — Arrays Deep Dive + Language Setup
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        int currSum = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            if (mp.find(currSum - k) != mp.end())
                ans += mp[currSum - k];
            mp[currSum]++;
        }
        return ans;
    }
};
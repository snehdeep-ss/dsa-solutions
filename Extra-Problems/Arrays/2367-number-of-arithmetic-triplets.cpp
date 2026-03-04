/*
 * Problem:  2367. Number of Arithmetic Triplets
 * URL:       https://leetcode.com/problems/number-of-arithmetic-triplets/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   3 ms  (beats 54.4%)
 * Memory:    12064000  (beats 25.6%)
 * Date:      2026-03-04
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> seen;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i] - diff) && seen.count(nums[i] - 2 * diff))
                ans++;
            seen.insert(nums[i]);
        }
        return ans;
    }
};
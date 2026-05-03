/*
 * Problem:  300. Longest Increasing Subsequence
 * URL:       https://leetcode.com/problems/longest-increasing-subsequence/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    14128000  (beats 74.8%)
 * Date:      2026-05-03
 * Context:  Day 32 — LCS, LIS — String/Sequence DP
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for(auto num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if(it == tails.end()) tails.push_back(num);
            else *it = num;
        }

        return tails.size();
    }
};
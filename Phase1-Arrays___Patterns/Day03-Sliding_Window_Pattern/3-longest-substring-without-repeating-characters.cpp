/*
 * Problem:  3. Longest Substring Without Repeating
 * URL:       https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    11484000  (beats 85.6%)
 * Date:      2026-03-04
 * Context:  Day 3 — Sliding Window Pattern
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int charCount[128] = {0};
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            charCount[s[right]]++;

            while (charCount[s[right]] > 1) {
                charCount[s[left]]--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
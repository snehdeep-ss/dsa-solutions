/*
 * Problem:  76. Minimum Window Substring
 * URL:       https://leetcode.com/problems/minimum-window-substring/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   4 ms  (beats 70.7%)
 * Memory:    11496000  (beats 63.7%)
 * Date:      2026-03-06
 * Context:  Day 3 — Sliding Window Pattern
 */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int counter = t.size();
        int startIndex = 0;
        int ans = INT_MAX;
        int left = 0;

        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]--;

            if (mp[s[right]] >= 0)
                counter--;

            while (counter == 0) {
                if (right - left + 1 < ans) { // guard the update
                    ans = right - left + 1;
                    startIndex = left;
                }
                mp[s[left]]++;
                if (mp[s[left]] > 0)
                    counter++;
                left++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(startIndex, ans);
    }
};
/*
 * Problem:  49. Group Anagrams
 * URL:       https://leetcode.com/problems/group-anagrams/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   17 ms  (beats 53.5%)
 * Memory:    26140000  (beats 37.9%)
 * Date:      2026-03-08
 * Context:  Day 4 — Hash Maps + Prefix + Intervals
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> ans;
        for (auto st : strs) {
            string temp = st;
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(st);
        }

        for (auto it : hashMap) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
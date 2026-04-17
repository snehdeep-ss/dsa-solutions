/*
 * Problem:  763. Partition Labels
 * URL:       https://leetcode.com/problems/partition-labels/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    8880000  (beats 67.3%)
 * Date:      2026-04-17
 * Context:  Day 28 — Greedy — Hard Variants + MST
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence;
        vector<int> ans;
        
        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            lastOccurrence[s[i]] = i;
        }
        
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.size(); i++) {
            end = max(end, lastOccurrence[s[i]]);
            
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};
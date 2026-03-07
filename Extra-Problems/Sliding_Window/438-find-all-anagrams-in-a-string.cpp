/*
 * Problem:  438. Find All Anagrams in a String
 * URL:       https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    11520000  (beats 62.9%)
 * Date:      2026-03-07
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size())
            return {};
        vector<int> freqS(26, 0), freqP(26, 0), ans;

        for (int i = 0; i < p.size(); i++) {
            freqS[s[i] - 'a']++;
            freqP[p[i] - 'a']++;
        }

        if (freqS == freqP)
            ans.push_back(0);
        int k = p.size();
        for (int i = k; i < s.size(); i++) {

            freqS[s[i - k] - 'a']--;
            freqS[s[i] - 'a']++;

            if (freqS == freqP)
                ans.push_back(i - k + 1);
        }
        return ans;
    }
};
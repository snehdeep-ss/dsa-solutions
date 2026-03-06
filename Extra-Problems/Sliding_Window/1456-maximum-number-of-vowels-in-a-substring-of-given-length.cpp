/*
 * Problem:  1456. Maximum Number of Vowels in a Substring of Given Length
 * URL:       https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   4 ms  (beats 74.6%)
 * Memory:    13288000  (beats 29.6%)
 * Date:      2026-03-06
 * Context:  Extra / Personal Practice
 */

class Solution {

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    int maxVowels(string s, int k) {

        int ans = 0;
        int count = 0;

        int right = 0;

        for (; right < k; right++) {
            if (isVowel(s[right]))
                count++;
        }

        ans = count;

        while (right < s.size()) {
            if (isVowel(s[right]))
                count++;

            if (isVowel(s[right - k]))
                count--;

            right++;
            ans = max(ans, count);
        }

        return ans;
    }
};
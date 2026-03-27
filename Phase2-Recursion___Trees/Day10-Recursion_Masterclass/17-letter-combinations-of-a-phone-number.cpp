/*
 * Problem:  17. Letter Combinations of Phone Number
 * URL:       https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    9184000  (beats 75.7%)
 * Date:      2026-03-27
 * Context:  Day 10 — Recursion Masterclass
 */

class Solution {
private:
    void backtrack(int idx, string& digits, vector<string>& ans, string& temp,
                   unordered_map<char, string>& mp) {
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < mp[digits[idx]].size(); i++) {
            temp.push_back(mp[digits[idx]][i]);
            backtrack(idx + 1, digits, ans, temp, mp);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> ans;
        string temp;

        backtrack(0, digits, ans, temp, mp);
        return ans;
    }
};

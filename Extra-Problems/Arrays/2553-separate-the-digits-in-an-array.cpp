/*
 * Problem:  2553. Separate the Digits in an Array
 * URL:       https://leetcode.com/problems/separate-the-digits-in-an-array/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   8 ms  (beats 28.5%)
 * Memory:    16616000  (beats 5.1%)
 * Date:      2026-05-11
 * Context:  Extra / Personal Practice
 */

class Solution {
    void solve(vector<int>& ans, int k) {
        if(k <= 9) {
            ans.push_back(k);
            return;
        }

        vector<int> digits;
        while(k > 0) {
            digits.push_back(k % 10);
            k /= 10;
        }

        reverse(digits.begin(), digits.end());
        ans.insert(ans.end(), digits.begin(), digits.end());
        return;
    }

public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(auto& num : nums) {
            solve(ans, num);
        }

        return ans;
    }
};
/*
 * Problem:  414. Third Maximum Number
 * URL:       https://leetcode.com/problems/third-maximum-number/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    12988000  (beats 50.0%)
 * Date:      2026-03-22
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for (auto& num : nums) {

            if (first == num || second == num || third == num)
                continue;
            if (num >= first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            }

            else if (num > third) {
                third = num;
            }
        }
        if (third == LONG_MIN)
            return first;
        return third;
    }
};
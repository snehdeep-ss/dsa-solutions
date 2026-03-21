/*
 * Problem:  55. Jump Game
 * URL:       https://leetcode.com/problems/jump-game/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    52336000  (beats 57.3%)
 * Date:      2026-03-21
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int sz = nums.size();
        for(int i = 0; i < sz; i++) {
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex, nums[i] + i);
        }
        return true;
    }
};
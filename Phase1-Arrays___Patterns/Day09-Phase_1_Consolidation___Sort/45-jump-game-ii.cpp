/*
 * Problem:  45. Jump Game II
 * URL:       https://leetcode.com/problems/jump-game-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    20444000  (beats 61.4%)
 * Date:      2026-03-21
 * Context:  Day 9 — Phase 1 Consolidation + Sorting
 */

class Solution {
public:
    int jump(vector<int>& nums) {

        int l = 0;
        int r = 0;
        int jumps = 0;

        while (r < nums.size() - 1) {
            int farthest = 0;

            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            jumps++;
        }

        return jumps;
    }
};
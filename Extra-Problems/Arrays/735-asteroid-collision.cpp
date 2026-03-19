/*
 * Problem:  735. Asteroid Collision
 * URL:       https://leetcode.com/problems/asteroid-collision/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   2 ms  (beats 33.2%)
 * Memory:    21604000  (beats 77.8%)
 * Date:      2026-03-19
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (auto asteroid : asteroids) {
            if (asteroid > 0 || ans.empty() || ans.back() < 0)
                ans.push_back(asteroid);
            else {
                while (!ans.empty() && ans.back() > 0 && ans.back() < -asteroid) {
                    ans.pop_back();
                }

                if (!ans.empty() && ans.back() > 0) {
                    if (ans.back() == -asteroid) {
                        ans.pop_back();
                    }
                    continue;

                } else
                    ans.push_back(asteroid);
            }
        }
        return ans;
    }
};
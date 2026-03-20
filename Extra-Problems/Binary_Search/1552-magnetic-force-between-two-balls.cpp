/*
 * Problem:  1552. Magnetic Force Between Two Balls
 * URL:       https://leetcode.com/problems/magnetic-force-between-two-balls/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   67 ms  (beats 5.6%)
 * Memory:    61704000  (beats 34.2%)
 * Date:      2026-03-20
 * Context:  Extra / Personal Practice
 */

class Solution {

    bool canPick(vector<int>& position, int m, int force) {
        int lastPos = 0;
        int count = 1;

        for (int i = 0; i < position.size(); i++) {
            if (position[i] - position[lastPos] >= force) {
                count++;
                lastPos = i;
            }
        }
        
        if (count >= m)
            return true;
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 0;
        int high = position.back() - position.front();
        int ans = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPick(position, m, mid)) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};
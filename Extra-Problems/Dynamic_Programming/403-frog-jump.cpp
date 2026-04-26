/*
 * Problem:  403. Frog Jump
 * URL:       https://leetcode.com/problems/frog-jump/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   49 ms  (beats 90.1%)
 * Memory:    28448000  (beats 82.7%)
 * Date:      2026-04-26
 * Context:  Extra / Personal Practice
 */

class Solution {
    unordered_set<int> st;
    map<pair<int, int>, bool> dp;

    bool solve(vector<int>& stones, int pos, int k) {
        if(pos == stones.back()) return true;

        if(dp.count({pos, k})) return dp[{pos, k}];
        bool result = false;
        for(auto jump : {k-1, k, k+1}) {
            if(jump > 0 && st.count(pos + jump)) {
                if(solve(stones, pos + jump, jump)) {
                    result = true;
                    break;
                }
            }
        }
        return dp[{pos, k}] = result;
    }

public:
    bool canCross(vector<int>& stones) {
        // st.insert(stones.begin(), stones.end());
        for(auto s : stones) st.insert(s);

        return solve(stones, 0, 0);
    }
};
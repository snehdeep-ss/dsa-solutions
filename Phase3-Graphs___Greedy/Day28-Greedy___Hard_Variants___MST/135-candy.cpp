/*
 * Problem:  135. Candy Distribution
 * URL:       https://leetcode.com/problems/candy/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    22928000  (beats 51.7%)
 * Date:      2026-05-06
 * Context:  Day 28 — Greedy — Hard Variants + MST
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> dist(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1])
                dist[i] = dist[i - 1] + 1;
        }

        for (int i = (int)ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1])
                dist[i] = max(dist[i], dist[i + 1] + 1);
        }

        int res = std::accumulate(dist.begin(), dist.end(), 0);
        return res;
    }
};
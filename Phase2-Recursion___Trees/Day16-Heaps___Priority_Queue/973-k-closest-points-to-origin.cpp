/*
 * Problem:  973. K Closest Points to Origin
 * URL:       https://leetcode.com/problems/k-closest-points-to-origin/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   902 ms  (beats 5.0%)
 * Memory:    254048000  (beats 5.0%)
 * Date:      2026-03-22
 * Context:  Day 16 — Heaps / Priority Queue
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        auto comp = [](vector<int> first, vector<int> second) {
            return ((first[0] * first[0]) + (first[1] * first[1])) <
                   ((second[0] * second[0]) + (second[1] * second[1]));
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        for (auto& vec : points) {
            pq.push(vec);
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
/*
 * Problem:  1584. Min Cost to Connect All Points (Prim's)
 * URL:       https://leetcode.com/problems/min-cost-to-connect-all-points/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   75 ms  (beats 70.8%)
 * Memory:    18152000  (beats 76.3%)
 * Date:      2026-05-02
 * Context:  Day 28 — Greedy — Hard Variants + MST
 */

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int min_cost = 0;
        std::vector<bool> visited(n, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;  // {cost, vertex}
        std::unordered_map<int, int> cache;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto edge = pq.top();
            pq.pop();
            int cost = edge.first;
            int u = edge.second;

            if (visited[u]) {
                continue;
            }

            visited[u] = true;
            min_cost += cost;

            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = std::abs(points[u][0] - points[v][0]) + std::abs(points[u][1] - points[v][1]);
                    if (cache.find(v) == cache.end() || dist < cache[v]) {
                        cache[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }

        return min_cost;
    }
};
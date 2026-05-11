/*
 * Problem:  743. Network Delay Time (Dijkstra)
 * URL:       https://leetcode.com/problems/network-delay-time/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   95 ms  (beats 24.5%)
 * Memory:    48028000  (beats 18.1%)
 * Date:      2026-05-11
 * Context:  Day 25 — Shortest Path Algorithms
 */

class Solution {
public:
    using p = pair<int, int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> adj(n + 1);
        for(const auto t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            const auto [currDist, node] = pq.top(); 
            pq.pop();

            if(currDist > dist[node]) continue;

            for(const auto [adjNode, weight] : adj[node]) {
                int newDist = currDist + weight;

                if(newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    pq.push({newDist, adjNode});
                }
            }
        }

        int time = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            time = max(time, dist[i]);
        }

        return time;
    }
};
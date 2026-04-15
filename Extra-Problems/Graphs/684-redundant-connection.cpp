/*
 * Problem:  684. Redundant Connection
 * URL:       https://leetcode.com/problems/redundant-connection/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   17 ms  (beats 7.9%)
 * Memory:    22548000  (beats 7.4%)
 * Date:      2026-04-15
 * Context:  Extra / Personal Practice
 */

class Solution {

    bool pathExists(int node, int tgt, vector<vector<int>>& adj, int n) {
        if(node == tgt) return true;
        
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            for (auto nei : adj[curr]) {

                if (nei == tgt)
                    return true;

                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (pathExists(u, v, adj, n))
                return {u, v};
            else {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        return {-1, -1};
    }
};
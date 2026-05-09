/*
 * Problem:  684. Redundant Connection
 * URL:       https://leetcode.com/problems/redundant-connection/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    13300000  (beats 53.6%)
 * Date:      2026-05-09
 * Context:  Day 24 — Union-Find (Disjoint Set Union)
 */

class Solution {

    int find(vector<int>& parents, int i) {
        if(i == parents[i]) return i;
        return parents[i] = find(parents, parents[i]);
    }

    bool unite(vector<int>& parents, vector<int>& size, int i, int j) {
        int i_par = find(parents, i);
        int j_par = find(parents, j);

        if(i_par == j_par) return false;

        if(size[i_par] < size[j_par]) swap(i_par, j_par);

        size[i_par] += size[j_par];
        parents[j_par] = i_par;

        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents, size;
        parents.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 1; i <= n; i++) {
            parents[i] = i;
        }

        for(auto& pair : edges) {
            if(!unite(parents, size, pair[0], pair[1])) return pair;
        }

        return {-1, -1};
    }
};
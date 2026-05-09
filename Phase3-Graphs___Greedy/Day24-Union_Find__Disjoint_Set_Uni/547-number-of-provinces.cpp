/*
 * Problem:  547. Number of Provinces
 * URL:       https://leetcode.com/problems/number-of-provinces/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    19276000  (beats 92.9%)
 * Date:      2026-05-09
 * Context:  Day 24 — Union-Find (Disjoint Set Union)
 */

class Solution {

    int find(vector<int>& parents, int i) {
        if(i == parents[i]) return i;
        return parents[i] = find(parents, parents[i]);
    }

    void unite(vector<int>& parents, vector<int>& rank, int i, int j) {
        int i_parent = find(parents, i);
        int j_parent = find(parents, j);

        if(i_parent == j_parent) return;

        if(rank[i_parent] < rank[j_parent]) {
            swap(i_parent, j_parent);
        }
        parents[j_parent] = i_parent;

        if(rank[i_parent] == rank[j_parent]) rank[i_parent]++;

    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> parents, rank;
        parents.resize(n);
        rank.resize(n);
        

        for(int i = 0; i < n; i++) {
            parents[i] = i;
            rank[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) {
                    unite(parents, rank, i, j);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < parents.size(); i++) {
            if(i == parents[i]) cnt++;
        }

        return cnt;
    }
};
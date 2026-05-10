/*
 * Problem:  207. Course Schedule
 * URL:       https://leetcode.com/problems/course-schedule/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   4 ms  (beats 63.6%)
 * Memory:    19344000  (beats 53.3%)
 * Date:      2026-05-10
 * Context:  Day 23 — Topological Sort
 */

class Solution {
    vector<int> state; // 0: Unvisited 1: Visiting 2: Visited
    vector<vector<int>> adj;

    bool dfs(int i) {
        state[i] = 1;
        for(auto neighbour : adj[i]) {
            if(state[neighbour] == 1) return false;
            if(state[neighbour] == 0) {
                if(!dfs(neighbour)) return false;
            }
        }
        state[i] = 2;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses, {});
        state.resize(numCourses, 0);

        for(auto& vec : prerequisites) {
            adj[vec[1]].push_back(vec[0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(state[i] != 0) continue;
            if(!dfs(i)) return false;
        }

        return true;
    }
};
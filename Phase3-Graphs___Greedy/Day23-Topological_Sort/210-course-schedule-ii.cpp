/*
 * Problem:  210. Course Schedule II
 * URL:       https://leetcode.com/problems/course-schedule-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   7 ms  (beats 33.0%)
 * Memory:    18352000  (beats 55.2%)
 * Date:      2026-05-10
 * Context:  Day 23 — Topological Sort
 */

class Solution {
    vector<int> state; // 0: Unvisited 1: Visiting 2: Visited
    vector<vector<int>> adj;
    stack<int> st;

    bool dfs(int i) {
        state[i] = 1;
        for(auto neighbour : adj[i]) {
            if(state[neighbour] == 1) {
                return false;
            }
            if(state[neighbour] == 0) {
                if(!dfs(neighbour)) return false;
            }
        }
        state[i] = 2;
        st.push(i);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses, {});
        state.resize(numCourses, 0);

        for(auto& vec : prerequisites) {
            adj[vec[1]].push_back(vec[0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(state[i] != 0) continue;
            if(!dfs(i)) return {};
        }

        vector<int> ans;

        while(!st.empty()) {
            int tmp = st.top();
            st.pop();
            ans.push_back(tmp);
        }

        return ans;
    }
};
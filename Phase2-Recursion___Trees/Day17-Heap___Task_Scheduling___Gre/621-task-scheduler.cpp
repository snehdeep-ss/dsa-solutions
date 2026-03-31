/*
 * Problem:  621. Task Scheduler
 * URL:       https://leetcode.com/problems/task-scheduler/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   2 ms  (beats 71.8%)
 * Memory:    42868000  (beats 53.9%)
 * Date:      2026-03-31
 * Context:  Day 17 — Heap — Task Scheduling & Greedy
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        priority_queue<int> pq;
        queue<pair<int, int>> q;

        for (auto& t : tasks) {
            mp[t - 'A']++;
        }

        for (auto el : mp) {
            if(el > 0)
            pq.push(el);
        }

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                int curr = pq.top();
                pq.pop();

                if (curr - 1 > 0) {
                    q.push({curr - 1, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
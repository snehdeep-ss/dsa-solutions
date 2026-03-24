/*
 * Problem:  347. Top K Frequent Elements
 * URL:       https://leetcode.com/problems/top-k-frequent-elements/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    17972000  (beats 62.2%)
 * Date:      2026-03-22
 * Context:  Day 17 — Heap — Task Scheduling & Greedy
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto& num : nums)
            mp[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto& [key, val] : mp) {
            pq.push({val, key});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
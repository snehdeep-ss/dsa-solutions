/*
 * Problem:  767. Reorganize String
 * URL:       https://leetcode.com/problems/reorganize-string/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    8484000  (beats 53.3%)
 * Date:      2026-03-25
 * Context:  Day 17 — Heap — Task Scheduling & Greedy
 */

class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;

        unordered_map<char, int> mp;
        for (auto& ch : s) {
            mp[ch]++;
        }

        for (auto [ch, freq] : mp) {
            pq.push({freq, ch});
        }
        cout << pq.top().first << " " << pq.top().second << endl;

        if (pq.top().first > ceil(s.length() + 1) / 2)
            return "";

        string ans = "";
        pair<int, char> prev = {0, ' '};

        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();

            ans += ch;
            freq--;

            if (prev.first > 0)
                pq.push(prev);
            prev = {freq, ch};
        }

        return ans;
    }
};
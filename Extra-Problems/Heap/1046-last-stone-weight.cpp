/*
 * Problem:  1046. Last Stone Weight
 * URL:       https://leetcode.com/problems/last-stone-weight/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    9676000  (beats 100.0%)
 * Date:      2026-04-26
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();

            if(top1 == top2) continue;
            else {
                pq.push(top1 - top2);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
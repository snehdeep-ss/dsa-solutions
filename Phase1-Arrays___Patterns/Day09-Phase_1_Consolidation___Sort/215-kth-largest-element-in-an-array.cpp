/*
 * Problem:  215. Kth Largest Element in Array
 * URL:       https://leetcode.com/problems/kth-largest-element-in-an-array/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   38 ms  (beats 34.5%)
 * Memory:    61600000  (beats 49.6%)
 * Date:      2026-03-21
 * Context:  Day 9 — Phase 1 Consolidation + Sorting
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto num : nums) {
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
        
        return pq.top();
    }
};
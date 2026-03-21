/*
 * Problem:  703. Kth Largest Element in a Stream
 * URL:       https://leetcode.com/problems/kth-largest-element-in-a-stream/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    33152000  (beats 24.7%)
 * Date:      2026-03-21
 * Context:  Extra / Personal Practice
 */

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz;

public:
    KthLargest(int k, vector<int>& nums) : sz(k) {
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > sz)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > sz)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
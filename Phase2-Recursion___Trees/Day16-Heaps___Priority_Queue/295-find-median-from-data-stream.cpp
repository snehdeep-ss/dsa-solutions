/*
 * Problem:  295. Find Median from Data Stream
 * URL:       https://leetcode.com/problems/find-median-from-data-stream/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   48 ms  (beats 96.8%)
 * Memory:    148496000  (beats 91.3%)
 * Date:      2026-04-06
 * Context:  Day 16 — Heaps / Priority Queue
 */

class MedianFinder {

    priority_queue<int> leftPile;
    priority_queue<int, vector<int>, greater<int>> rightPile;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftPile.empty() || num <= leftPile.top()) leftPile.push(num);
        else rightPile.push(num);

        if(leftPile.size() > rightPile.size() + 1) {
            int tmp = leftPile.top();
            leftPile.pop();
            rightPile.push(tmp);
        }

        if(leftPile.size() < rightPile.size()) {
            int tmp = rightPile.top();
            rightPile.pop();
            leftPile.push(tmp);
        }
    }
    
    double findMedian() {
        if(leftPile.size() == rightPile.size()) {
            return ((double)leftPile.top() + (double)rightPile.top()) / 2;
        }
        return (double)leftPile.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
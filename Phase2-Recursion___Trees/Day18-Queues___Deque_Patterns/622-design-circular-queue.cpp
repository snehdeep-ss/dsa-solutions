/*
 * Problem:  622. Design Circular Queue
 * URL:       https://leetcode.com/problems/design-circular-queue/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    23488000  (beats 79.6%)
 * Date:      2026-04-05
 * Context:  Day 18 — Queues + Deque Patterns
 */

class MyCircularQueue {
    vector<int> v;
    int head;
    int tail;
    int cap;
    int cnt;

public:
    MyCircularQueue(int k) : head(0), tail(0), cap(k), cnt(0) {
        v = vector<int>(k);
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        v[tail] = value;
        tail = (tail + 1) % cap;
        cnt++;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        head = (head + 1) % cap;
        cnt--;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return v[head];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        int ele = (tail == 0) ? cap - 1 : tail - 1;
        return v[ele];
    }

    bool isEmpty() { return cnt == 0; }

    bool isFull() { return cnt == cap; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
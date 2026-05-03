/*
 * Problem:  225. Implement Stack using Queues
 * URL:       https://leetcode.com/problems/implement-stack-using-queues/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    9460000  (beats 80.4%)
 * Date:      2026-05-03
 * Context:  Extra / Personal Practice
 */

class MyStack {
    queue<int> q;
    int top_el;

public:
    MyStack() {}

    void push(int x) {
        if (q.empty())
            top_el = x;
        q.push(x);
    }

    int pop() {
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        int last = q.front();
        q.pop();
        return last;
    }

    int top() { return q.back(); }

    bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
/*
 * Problem:  232. Implement Queue using Stacks
 * URL:       https://leetcode.com/problems/implement-queue-using-stacks/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    9656000  (beats 68.3%)
 * Date:      2026-05-03
 * Context:  Extra / Personal Practice
 */

class MyQueue {
    stack<int> st;
    int top_element;

    void pop_element(int& k) {
        if (st.size() == 1) {
            k = st.top();
            st.pop();
            top_element = -1;
            return;
        } else {
            int curr = st.top();
            st.pop();
            pop_element(k);
            st.push(curr);
            if (st.size() == 1)
                top_element = curr;
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        if (st.empty())
            top_element = x;
        st.push(x);
    }

    int pop() {
        int k;
        pop_element(k);
        return k;
    }

    int peek() { return top_element; }

    bool empty() { return st.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
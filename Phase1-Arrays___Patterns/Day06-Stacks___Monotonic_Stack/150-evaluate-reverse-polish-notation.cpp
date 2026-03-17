/*
 * Problem:  150. Evaluate Reverse Polish Notation
 * URL:       https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    16040000  (beats 90.8%)
 * Date:      2026-03-17
 * Context:  Day 6 — Stacks + Monotonic Stack
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "*" || tokens[i] == "-" ||
                tokens[i] == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int val;
                if (tokens[i] == "+") {
                    val = num1 + num2;
                } else if (tokens[i] == "*") {
                    val = num1 * num2;
                } else if (tokens[i] == "/") {
                    val = num1 / num2;
                } else if (tokens[i] == "-") {
                    val = num1 - num2;
                } else {
                    // default case - do nothing
                }
                st.push(val);
            } else {
                int k = stoi(tokens[i]);
                st.push(k);
            }
        }
        return st.top();
    }
};
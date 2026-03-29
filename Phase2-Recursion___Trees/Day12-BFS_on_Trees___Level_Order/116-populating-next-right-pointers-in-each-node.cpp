/*
 * Problem:  116. Populating Next Right Pointers
 * URL:       https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   8 ms  (beats 93.2%)
 * Memory:    19036000  (beats 64.3%)
 * Date:      2026-03-29
 * Context:  Day 12 — BFS on Trees + Level Order
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;

        Node* curr = root;
        Node* next = root->left ? root->left : nullptr;

        while (curr && next) {
            curr->left->next = curr->right;
            if (curr->next)
                curr->right->next = curr->next->left;

            curr = curr->next;
            if (!curr) {
                curr = next;
                next = curr->left;
            }
        }
        return root;
    }
};
/*
 * Problem:  100. Same Tree
 * URL:       https://leetcode.com/problems/same-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    12928000  (beats 13.0%)
 * Date:      2026-01-19
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;  // Handle null cases
        return p->val == q->val && 
               isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};
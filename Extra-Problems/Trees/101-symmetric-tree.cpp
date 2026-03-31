/*
 * Problem:  101. Symmetric Tree
 * URL:       https://leetcode.com/problems/symmetric-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    18640000  (beats 8.8%)
 * Date:      2026-03-31
 * Context:  Extra / Personal Practice
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    bool mirror(TreeNode* L, TreeNode* R) {
        if (!L && !R)
            return true;
        if (!L || !R)
            return false;
        return L->val == R->val && mirror(L->left, R->right) &&
               mirror(L->right, R->left);
    }

public:
    bool isSymmetric(TreeNode* root) { return mirror(root->left, root->right); }
};
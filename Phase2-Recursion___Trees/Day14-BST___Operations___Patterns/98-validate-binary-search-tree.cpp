/*
 * Problem:  98. Validate Binary Search Tree
 * URL:       https://leetcode.com/problems/validate-binary-search-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    22092000  (beats 16.3%)
 * Date:      2026-03-26
 * Context:  Day 14 — BST — Operations & Patterns
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
    long lo = LONG_MIN;
    long hi = LONG_MAX;

    bool validate(TreeNode* root, long lo, long hi) {
        if (!root)
            return true;
        if (root->val >= hi || root->val <= lo)
            return false;
        return validate(root->left, lo, root->val) &&
               validate(root->right, root->val, hi);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, lo, hi);
    }
};
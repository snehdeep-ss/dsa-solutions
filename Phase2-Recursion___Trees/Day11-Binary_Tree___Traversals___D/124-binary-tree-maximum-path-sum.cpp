/*
 * Problem:  124. Binary Tree Maximum Path Sum
 * URL:       https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    28012000  (beats 21.5%)
 * Date:      2026-03-26
 * Context:  Day 11 — Binary Tree — Traversals & DFS
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
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root)
            return 0;

        int L = max(0, dfs(root->left));
        int R = max(0, dfs(root->right));

        ans = max(ans, L + R + root->val);

        return root->val + max(L, R);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
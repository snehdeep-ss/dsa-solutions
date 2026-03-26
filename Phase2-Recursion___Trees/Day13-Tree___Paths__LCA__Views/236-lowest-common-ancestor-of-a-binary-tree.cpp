/*
 * Problem:  236. LCA of Binary Tree
 * URL:       https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   3 ms  (beats 99.8%)
 * Memory:    17308000  (beats 64.6%)
 * Date:      2026-03-26
 * Context:  Day 13 — Tree — Paths, LCA, Views
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;

        TreeNode* L = lca(root->left, p, q);
        TreeNode* R = lca(root->right, p, q);

        if (L && R)
            return root;
        return L ? L : R;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};
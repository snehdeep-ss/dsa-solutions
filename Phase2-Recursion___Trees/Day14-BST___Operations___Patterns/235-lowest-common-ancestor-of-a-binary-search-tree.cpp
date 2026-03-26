/*
 * Problem:  235. LCA of BST
 * URL:       https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   31 ms  (beats 7.0%)
 * Memory:    23476000  (beats 64.7%)
 * Date:      2026-03-26
 * Context:  Day 14 — BST — Operations & Patterns
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q)
            return nullptr;
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
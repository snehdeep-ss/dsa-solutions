/*
 * Problem:  1448. Count Good Nodes in Binary Tree
 * URL:       https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   90 ms  (beats 84.9%)
 * Memory:    88348000  (beats 65.0%)
 * Date:      2026-03-29
 * Context:  Day 13 — Tree — Paths, LCA, Views
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

int recurse(TreeNode* root, int maxSoFar) {
    if(!root) return 0;
    bool isGood = root->val >= maxSoFar;
    maxSoFar = max(maxSoFar, root->val);
    int L = recurse(root->left, maxSoFar);
    int R = recurse(root->right, maxSoFar);

    return (isGood ? 1 : 0) + L + R;
}
public:
    int goodNodes(TreeNode* root) {
        return recurse(root, INT_MIN);
    }
};
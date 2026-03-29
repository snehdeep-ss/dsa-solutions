/*
 * Problem:  114. Flatten Binary Tree to Linked List
 * URL:       https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    17428000  (beats 77.6%)
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

TreeNode* recurse(TreeNode* node) {
    if(!node) return nullptr;
    TreeNode* root = node;
    TreeNode* temp = root->right;
    root->right = recurse(root->left);
    root->left = nullptr;

    while(root->right) {
        root = root->right;
    }

    root->right = recurse(temp);
    return node;

}
public:
    void flatten(TreeNode* root) {
        recurse(root);
    }
};
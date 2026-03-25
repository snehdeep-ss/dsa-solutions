/*
 * Problem:  110. Balanced Binary Tree
 * URL:       https://leetcode.com/problems/balanced-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    23236000  (beats 20.4%)
 * Date:      2026-03-25
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    int checkHeight(TreeNode* root) {
        if(!root) return 0;

        int left = checkHeight(root->left);
        if(left == -1) return -1;

        int right = checkHeight(root->right);
        if(right == -1) return -1;

        if(abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
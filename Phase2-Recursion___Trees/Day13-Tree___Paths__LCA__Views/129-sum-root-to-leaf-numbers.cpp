/*
 * Problem:  129. Sum Root to Leaf Numbers
 * URL:       https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    11756000  (beats 90.2%)
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

    void calc(TreeNode* root, int& ans, int curr) {
        if(!root) return;

        curr = curr * 10 + root->val;
        if(!root->left && !root->right) {
            ans += curr;
        }

        calc(root->left, ans, curr);
        calc(root->right, ans, curr);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        calc(root, ans, 0);
        return ans;
    }
};
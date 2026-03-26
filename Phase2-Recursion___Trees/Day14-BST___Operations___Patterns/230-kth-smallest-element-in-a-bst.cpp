/*
 * Problem:  230. Kth Smallest Element in BST
 * URL:       https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    24332000  (beats 66.2%)
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void kth(TreeNode* root, int& k, int& ans) {
        if(!root) return;
        kth(root->left, k, ans);
        if(--k == 0) {
            ans = root->val;
            return;
        }
        kth(root->right, k, ans);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        kth(root, k, ans);
        return ans;
    }
};
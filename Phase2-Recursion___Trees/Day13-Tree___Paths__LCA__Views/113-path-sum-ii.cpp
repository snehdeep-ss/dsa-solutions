/*
 * Problem:  113. Path Sum II
 * URL:       https://leetcode.com/problems/path-sum-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   14 ms  (beats 21.8%)
 * Memory:    40792000  (beats 7.2%)
 * Date:      2026-03-26
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    vector<vector<int>> ans;

    void dfs(TreeNode* root, vector<int> curr, int targetSum) {
        if (!root)
            return;
        curr.push_back(root->val);

        if (!root->left && !root->right && targetSum - root->val == 0)
            ans.push_back(curr);

        dfs(root->left, curr, targetSum - root->val);
        dfs(root->right, curr, targetSum - root->val);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, {}, targetSum);
        return ans;
    }
};
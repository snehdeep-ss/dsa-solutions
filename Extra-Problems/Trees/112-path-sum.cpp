/*
 * Problem:  112. Path Sum
 * URL:       https://leetcode.com/problems/path-sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    21580000  (beats 34.6%)
 * Date:      2026-03-26
 * Context:  Extra / Personal Practice
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
    bool pathSum(TreeNode* root, int target) {
        if (!root)
            return false;

        if (!root->left && !root->right)
            return root->val == target;

        return pathSum(root->left, target - root->val) ||
               pathSum(root->right, target - root->val);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root, targetSum);
    }
};
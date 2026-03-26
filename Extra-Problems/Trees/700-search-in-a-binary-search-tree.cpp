/*
 * Problem:  700. Search in a Binary Search Tree
 * URL:       https://leetcode.com/problems/search-in-a-binary-search-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    35576000  (beats 30.4%)
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

public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val)
            return root;
        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
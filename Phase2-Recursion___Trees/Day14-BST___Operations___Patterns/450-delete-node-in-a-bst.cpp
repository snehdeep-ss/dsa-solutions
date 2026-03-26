/*
 * Problem:  450. Delete Node in BST
 * URL:       https://leetcode.com/problems/delete-node-in-a-bst/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    34404000  (beats 14.5%)
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;

            auto suc = root->right;
            while (suc->left)
                suc = suc->left;
            root->val = suc->val;
            root->right = deleteNode(root->right, suc->val);
        }
        return root;
    }
};
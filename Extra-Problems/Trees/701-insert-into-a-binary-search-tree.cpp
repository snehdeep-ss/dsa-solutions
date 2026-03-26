/*
 * Problem:  701. Insert into a Binary Search Tree
 * URL:       https://leetcode.com/problems/insert-into-a-binary-search-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    59260000  (beats 92.0%)
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val < val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        return root;
        
    }
};
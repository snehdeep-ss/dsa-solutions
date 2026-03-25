/*
 * Problem:  543. Diameter of Binary Tree
 * URL:       https://leetcode.com/problems/diameter-of-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    23708000  (beats 42.8%)
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

int ans = INT_MIN; 

int getHt(TreeNode* root) {
    if(!root) return 0;

    int left = getHt(root->left);
    int right = getHt(root->right);

    ans = max(ans, left+right);
    return 1 + max(left, right);
}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getHt(root);
        return ans;
    }
};
/*
 * Problem:  662. Maximum Width of Binary Tree
 * URL:       https://leetcode.com/problems/maximum-width-of-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    19604000  (beats 74.1%)
 * Date:      2026-04-01
 * Context:  Day 19 — Trees + Heap — Mixed Hard Problems
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        unsigned long long maxWidth = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int levelSz = q.size();

            unsigned long long rightMost = q.back().second;
            unsigned long long leftMost = q.front().second;

            maxWidth = max(maxWidth, rightMost - leftMost + 1);

            for (int i = 0; i < levelSz; i++) {
                auto [node, idx] = q.front();
                q.pop();

                if (node->left)
                    q.push({node->left, 2 * idx + 0});
                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }
        }
        return (int)maxWidth;
    }
};
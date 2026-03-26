/*
 * Problem:  111. Minimum Depth of Binary Tree
 * URL:       https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    146732000  (beats 74.2%)
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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int depth = 0;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            depth++;

            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();

                if (!node->left && !node->right)
                    return depth;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return depth;
    }
};
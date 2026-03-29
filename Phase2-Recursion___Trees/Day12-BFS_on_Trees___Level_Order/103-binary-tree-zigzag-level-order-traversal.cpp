/*
 * Problem:  103. Binary Tree Zigzag Level Order
 * URL:       https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    15172000  (beats 49.1%)
 * Date:      2026-03-29
 * Context:  Day 12 — BFS on Trees + Level Order
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool leftToRight = true;
        q.push(root);
        while (!q.empty()) {

            int sz = q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();

                int idx = leftToRight ? i : (sz - i - 1);
                level[idx] = curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};
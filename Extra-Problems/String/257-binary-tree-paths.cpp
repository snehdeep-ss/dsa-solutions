/*
 * Problem:  257. Binary Tree Paths
 * URL:       https://leetcode.com/problems/binary-tree-paths/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    18396000  (beats 12.9%)
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

    void getPaths(TreeNode* root, vector<string>& ans, string curr) {
        if (!root)
            return;

        if (curr.empty()) {
            curr += to_string(root->val);
        } else {
            curr += "->";
            curr += to_string(root->val);
        }

        if (!root->left && !root->right) {
            ans.push_back(curr);
        }

        getPaths(root->left, ans, curr);
        getPaths(root->right, ans, curr);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        getPaths(root, ans, "");
        return ans;
    }
};
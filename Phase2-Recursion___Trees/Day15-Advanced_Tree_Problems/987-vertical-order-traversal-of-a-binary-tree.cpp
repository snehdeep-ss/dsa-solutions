/*
 * Problem:  987. Vertical Order Traversal
 * URL:       https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   4 ms  (beats 20.9%)
 * Memory:    16124000  (beats 53.2%)
 * Date:      2026-03-31
 * Context:  Day 15 — Advanced Tree Problems
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

    void dfs(TreeNode* root, int row, int col,
             map<int, vector<pair<int, int>>>& mp) {
        if (!root)
            return;

        mp[col].push_back({row, root->val});

        dfs(root->left, row + 1, col - 1, mp);
        dfs(root->right, row + 1, col + 1, mp);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int, int>>> colMap;
        dfs(root, 0, 0, colMap);

        for (auto [col, vec] : colMap) {
            sort(vec.begin(), vec.end(),
                 [](const pair<int, int>& a, const pair<int, int>& b) {
                     if (a.first != b.first)
                         return a.first < b.first;
                     return a.second < b.second;
                 });

            vector<int> colVec;
            for (auto [idx, val] : vec) {
                colVec.push_back(val);
            }
            ans.push_back(colVec);
        }
        return ans;
    }
};
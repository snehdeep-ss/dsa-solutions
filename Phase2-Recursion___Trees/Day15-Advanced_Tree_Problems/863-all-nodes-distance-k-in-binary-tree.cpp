/*
 * Problem:  863. All Nodes Distance K in Binary Tree
 * URL:       https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    15732000  (beats 23.0%)
 * Date:      2026-03-31
 * Context:  Day 15 — Advanced Tree Problems
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void buildParentMap(TreeNode* node, TreeNode* fa,
                        unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!node)
            return;

        mp[node] = fa;
        buildParentMap(node->left, node, mp);
        buildParentMap(node->right, node, mp);
    }

    void findAtK(TreeNode* curr, TreeNode* prev, int k,
                 unordered_map<TreeNode*, TreeNode*>& mp, vector<int>& ans) {
        if (!curr)
            return;

        if (k == 0) {
            ans.push_back(curr->val);
            return;
        }

        if (curr->left != prev) {
            findAtK(curr->left, curr, k - 1, mp, ans);
        }

        if (curr->right != prev) {
            findAtK(curr->right, curr, k - 1, mp, ans);
        }

        if (mp[curr] != prev) {
            findAtK(mp[curr], curr, k - 1, mp, ans);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        vector<int> ans;
        buildParentMap(root, nullptr, parentMap);
        findAtK(target, nullptr, k, parentMap, ans);
        return ans;
    }
};
/*
 * Problem:  105. Construct BT from Preorder and Inorder
 * URL:       https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   7 ms  (beats 36.4%)
 * Memory:    27424000  (beats 53.1%)
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

    TreeNode* build(vector<int>& pre, vector<int>& in, int preL, int preR,
                    int inL, int inR, unordered_map<int, int>& idxMap) {
        if (preL > preR)
            return nullptr;

        TreeNode* root = new TreeNode(pre[preL]);

        int inIdx = idxMap[pre[preL]];
        int leftSz = inIdx - inL;

        root->left =
            build(pre, in, preL + 1, preL + leftSz, inL, inIdx, idxMap);
        root->right =
            build(pre, in, preL + leftSz + 1, preR, inIdx + 1, inR, idxMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (preorder.empty() || inorder.empty() ||
            preorder.size() != inorder.size()) {
            return nullptr;
        }

        int inSz = inorder.size();
        int preSz = preorder.size();

        unordered_map<int, int> idxMap;
        for (int i = 0; i < inSz; i++) {
            idxMap[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, preSz - 1, 0, inSz - 1, idxMap);
    }
};
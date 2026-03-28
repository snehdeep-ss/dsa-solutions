/*
 * Problem:  108. Convert Sorted Array to BST
 * URL:       https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    23012000  (beats 20.4%)
 * Date:      2026-03-28
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    TreeNode* insert(vector<int>& nums, int lo, int hi) {
        if(lo > hi) return nullptr;
        if(lo == hi) return new TreeNode(nums[lo]);

        int mid = lo + (hi - lo) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = insert(nums, lo, mid - 1);
        curr->right = insert(nums, mid + 1, hi);

        return curr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(nums, 0, nums.size() - 1);
        
    }
};
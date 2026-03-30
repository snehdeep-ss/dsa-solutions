/*
 * Problem:  99. Recover BST
 * URL:       https://leetcode.com/problems/recover-binary-search-tree/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    62420000  (beats 5.1%)
 * Date:      2026-03-30
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

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;


    void helper(TreeNode* root) {
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr || !st.empty()) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if(prev && prev->val > curr->val) {
                if(!first) first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        }
    }
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }
};


// class Solution {
// public:
//     TreeNode* first = nullptr;
//     TreeNode* second = nullptr;
//     TreeNode* prev = nullptr;

//     void helper(TreeNode* node) {
//         if(!node) return;

//         helper(node->left);

//         if(prev && prev->val > node->val) {
//             if(!first) first = prev;
//             second = node;
//         }

//         prev = node;
//         helper(node->right);

//     }

//     void recoverTree(TreeNode* root) {
//         helper(root);
//         swap(first->val, second->val);
//     }
// };
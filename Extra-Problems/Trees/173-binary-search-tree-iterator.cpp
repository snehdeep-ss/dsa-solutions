/*
 * Problem:  173. Binary Search Tree Iterator
 * URL:       https://leetcode.com/problems/binary-search-tree-iterator/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   1 ms  (beats 80.7%)
 * Memory:    32052000  (beats 32.7%)
 * Date:      2026-03-31
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> st;

    void pushLeft(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right) pushLeft(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
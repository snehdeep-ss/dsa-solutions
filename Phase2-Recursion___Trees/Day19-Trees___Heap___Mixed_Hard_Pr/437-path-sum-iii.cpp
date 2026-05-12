/*
 * Problem:  437. Path Sum III
 * URL:       https://leetcode.com/problems/path-sum-iii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   20 ms  (beats 12.8%)
 * Memory:    18952000  (beats 76.4%)
 * Date:      2026-05-09
 * Context:  Day 19 — Trees + Heap — Mixed Hard Problems
 */

class Solution {
    long long solve(TreeNode* root, long long remain) 
    { 
        if(!root) return 0;
        
        long long count = 0;
        long long val = root->val;
        
        if(val == remain) count++;
        
        count += solve(root->left, remain - val);
        count += solve(root->right, remain - val);
        
        return count;
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) 
    {
        if(!root) return 0;
        
        long long curr = solve(root, (long long)targetSum);
        long long skipLeft = pathSum(root->left, targetSum);
        long long skipRight = pathSum(root->right, targetSum);
        
        return (int)(curr + skipLeft + skipRight);
    }
};
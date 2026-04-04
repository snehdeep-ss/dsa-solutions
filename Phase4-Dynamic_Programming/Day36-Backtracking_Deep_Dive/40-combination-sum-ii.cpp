/*
 * Problem:  40. Combination Sum II
 * URL:       https://leetcode.com/problems/combination-sum-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   1 ms  (beats 48.8%)
 * Memory:    14128000  (beats 33.7%)
 * Date:      2026-01-21
 * Context:  Day 36 — Backtracking Deep Dive
 */

class Solution {
private:
    void comboSum(int idx, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        //if(idx == candidates.size() || target < 0) return;
        
       
        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            comboSum(i+1, target - candidates[i], candidates, ans, temp);
            temp.pop_back();
        }
    }

    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int start = 0;
        sort(candidates.begin(), candidates.end());
        comboSum(start, target, candidates, ans, temp);
        return ans;
    }
};
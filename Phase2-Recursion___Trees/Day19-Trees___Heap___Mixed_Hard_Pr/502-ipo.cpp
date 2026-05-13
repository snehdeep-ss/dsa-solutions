/*
 * Problem:  502. IPO — Pick Max Profit Projects
 * URL:       https://leetcode.com/problems/ipo/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   73 ms  (beats 64.7%)
 * Memory:    131468000  (beats 49.9%)
 * Date:      2026-05-13
 * Context:  Day 19 — Trees + Heap — Mixed Hard Problems
 */

#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        
        std::vector<std::pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        std::sort(projects.begin(), projects.end());
        
        std::priority_queue<int> maxHeap;
        
        int i = 0;
        for (int count = 0; count < k; count++) {
            while (i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            
            if (maxHeap.empty()) {
                break;
            }
            
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};
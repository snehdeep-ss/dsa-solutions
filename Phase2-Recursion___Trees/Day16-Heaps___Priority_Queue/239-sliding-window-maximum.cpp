/*
 * Problem:  239. Sliding Window Maximum
 * URL:       https://leetcode.com/problems/sliding-window-maximum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   71 ms  (beats 14.0%)
 * Memory:    153264000  (beats 15.5%)
 * Date:      2026-04-06
 * Context:  Day 16 — Heaps / Priority Queue
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        auto comp = [](pair<int, int>& a, pair<int, int>& b){
            return a.first <= b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> hp(comp);
        for(int i = 0; i < k; i++) {
            hp.push({nums[i], i});
        }
        ans.push_back(hp.top().first);
        for(int i = k; i < nums.size(); i++) {
            hp.push({nums[i], i});
            while(!(i - hp.top().second < k)) hp.pop();
            ans.push_back(hp.top().first);
        }

        return ans;
    }
};
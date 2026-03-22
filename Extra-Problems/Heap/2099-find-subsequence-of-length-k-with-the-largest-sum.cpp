/*
 * Problem:  2099. Find Subsequence of Length K With the Largest Sum
 * URL:       https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    13556000  (beats 97.4%)
 * Date:      2026-03-22
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        auto comp = [](pair<int, int> first, pair<int, int> second) {
            return first.second < second.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            ans[i] = nums[ans[i]];

        return ans;
    }
};
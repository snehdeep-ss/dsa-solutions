/*
 * Problem:  904. Fruit Into Baskets
 * URL:       https://leetcode.com/problems/fruit-into-baskets/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   59 ms  (beats 7.6%)
 * Memory:    84940000  (beats 35.1%)
 * Date:      2026-03-06
 * Context:  Day 3 — Sliding Window Pattern
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int, int> mp;
        int ans = 0;
        int left = 0;

        for(int right = 0; right < (int)fruits.size(); right++) {
            mp[fruits[right]]++;

            while(mp.size() > 2) {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
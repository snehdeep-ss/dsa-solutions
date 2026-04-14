/*
 * Problem:  1854. Maximum Population Year
 * URL:       https://leetcode.com/problems/maximum-population-year/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    11044000  (beats 78.4%)
 * Date:      2026-04-14
 * Context:  Extra / Personal Practice
 */

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> temp(101, 0);

        for(auto& t : logs) {
            int birth = t[0];
            int death = t[1];

            temp[birth - 1950] += 1;
            temp[death - 1950] -= 1;
        }

        for(int i = 1; i < temp.size(); i++) temp[i] += temp[i-1];
        return 1950 + max_element(temp.begin(), temp.end()) - temp.begin();
    }
};
/*
 * Problem:  18. 4Sum
 * URL:       https://leetcode.com/problems/4sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    17312000  (beats 83.2%)
 * Date:      2026-03-05
 * Context:  Day 9 — Phase 1 Consolidation + Sorting
 */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;  // Early return

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Optimization: if smallest possible sum > target, break
            if ((long long)nums[i] + (long long)nums[i+1] + (long long)nums[i+2] + (long long)nums[i+3] > target) 
                break;
            // Optimization: if largest possible sum with current i < target, continue
                if ((long long)nums[i] + (long long)nums[nums.size()-3] + (long long)nums[nums.size()-2] + (long long)nums[nums.size()-1] < target) 
                continue;

            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long rem = (long long)target - (long long)nums[i] - (long long)nums[j];

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {

                    long long sum = (long long)nums[left] + (long long)nums[right];

                    if (sum == rem) {

                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1]) left++;

                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }

                    else if (sum < rem) left++;
                    
                    else right--;
                }
            }
        }
        return ans;
    }
};
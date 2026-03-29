/*
 * Problem:  410. Split Array Largest Sum
 * URL:       https://leetcode.com/problems/split-array-largest-sum/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    10664000  (beats 10.6%)
 * Date:      2026-03-29
 * Context:  Day 8 — Binary Search — Hard Variants
 */

class Solution {

    bool getNum(vector<int>& nums, int lim, int k) {
        int ans = 1;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currSum + nums[i] <= lim) {
                currSum += nums[i];
            } else {
                ans++;
                currSum = nums[i];
                if (ans > k)
                    return false;
            }
        }
        return true;
    }

    int getLargestSum(vector<int> nums, int k) {
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        int ans = hi;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (getNum(nums, mid, k)) {
                hi = mid;
                ans = min(ans, mid);
            } else
                lo = mid + 1;
        }
        return ans;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        return getLargestSum(nums, k);
    }
};
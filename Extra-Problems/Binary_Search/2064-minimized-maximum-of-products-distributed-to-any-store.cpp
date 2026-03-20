/*
 * Problem:  2064. Minimized Maximum of Products Distributed to Any Store
 * URL:       https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   30 ms  (beats 59.5%)
 * Memory:    88396000  (beats 80.7%)
 * Date:      2026-03-20
 * Context:  Extra / Personal Practice
 */

class Solution {

    bool canDistribute(vector<int>& quantities, int sz, int n) {
        int count = 0;
        for (auto qty : quantities) {
            count += (qty + sz - 1) / sz;
        }
        if (count > n)
            return false;
        return true;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int ans = 1;
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDistribute(quantities, mid, n)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};
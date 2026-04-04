/*
 * Problem:  658. Find K Closest Elements
 * URL:       https://leetcode.com/problems/find-k-closest-elements/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   3 ms  (beats 54.8%)
 * Memory:    35904000  (beats 65.2%)
 * Date:      2026-04-04
 * Context:  Day 41 — Google-Style Mixed Round
 */

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
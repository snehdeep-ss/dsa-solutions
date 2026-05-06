/*
 * Problem:  846. Hand of Straights
 * URL:       https://leetcode.com/problems/hand-of-straights/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   34 ms  (beats 72.8%)
 * Memory:    32340000  (beats 38.3%)
 * Date:      2026-05-06
 * Context:  Day 28 — Greedy — Hard Variants + MST
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }
        
        vector<int> uniqueCards;
        for (auto& [card, count] : freq) {
            uniqueCards.push_back(card);
        }
        sort(uniqueCards.begin(), uniqueCards.end());
        
        for (int card : uniqueCards) {
            int count = freq[card];
            if (count > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (freq[card + i] < count) {
                        return false;
                    }
                    freq[card + i] -= count;
                }
            }
        }
        
        return true;
    }
};
/*
 * Problem:  142. Linked List Cycle II
 * URL:       https://leetcode.com/problems/linked-list-cycle-ii/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   7 ms  (beats 65.9%)
 * Memory:    11144000  (beats 99.1%)
 * Date:      2026-03-05
 * Context:  Day 5 — Linked List Mastery
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        auto slow = head;
        auto fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
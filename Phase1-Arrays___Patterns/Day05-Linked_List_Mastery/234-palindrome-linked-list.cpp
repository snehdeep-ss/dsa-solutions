/*
 * Problem:  234. Palindrome Linked List
 * URL:       https://leetcode.com/problems/palindrome-linked-list/
 * Language:  C++
 * Status:    Accepted
 * Runtime:   0 ms  (beats 100.0%)
 * Memory:    118064000  (beats 66.3%)
 * Date:      2026-03-09
 * Context:  Day 5 — Linked List Mastery
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast)
            slow = slow->next;
        ListNode* rev = reverse(slow);

        ListNode* hd = head;

        while (rev) {
            if (rev->val != hd->val)
                return false;
            rev = rev->next;
            hd = hd->next;
        }
        return true;
    }
};